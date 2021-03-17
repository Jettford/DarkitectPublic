#include "LUZScene.h"

void LUZScene::Read(std::string Path) {
	uint32_t Size = 0;

	auto fuckingDanglingPointers = Utils::ReadFileCompletely(Path, &Size);
	char* data = reinterpret_cast<char*>(fuckingDanglingPointers.get());
	uint32_t i = 0;
	while (i < Size) {
		i += (i % 16);

		char* ChunkMagic = (data + i);
		if (std::string(ChunkMagic, 4) != "CHNK") {
			if (i != 0) {
				throw "We appear to have hit a invalid chunk or the alignment is incorrect";
			}
			
			std::uint32_t Offset = 0;
			std::uint16_t Version = *reinterpret_cast<std::uint16_t*>(data + Offset);
			Offset += 4;
			std::uint32_t Version32 = Version;
			++Offset;

			if (Version >= 37) {
				std::uint32_t* Revision = reinterpret_cast<std::uint32_t*>(data + Offset);
				Info.Revision = *Revision;
				Offset += 4;
			}

			if (Version >= 45) {
				Offset += 4;
			}

			Offset += 3 * 4 * 4;

			if (Version >= 31) {
				if (Version >= 39) {
					Offset += 4 * 12;
					if (Version >= 40) {
						std::uint32_t Count = *reinterpret_cast<std::uint32_t*>(data + Offset);
						Offset += 4;
						Offset += 3 * 4 * Count;
					}
				}

				else {
					Offset += 2 * 4;
				}

				Offset += 12;
			}

			if (Version >= 36) {
				Offset += 12;
			}

			if (Version < 42) {
				Offset += 4 * 3;
				if (Version >= 33) {
					Offset += 4 * 4;
				}
			}

			for (int j = 0; j < 6; ++j) {
				std::uint32_t Count = *reinterpret_cast<std::uint32_t*>(data + Offset);
				Offset += 4 + Count;
			}

			Offset += 4;

			std::uint32_t Count = *reinterpret_cast<std::uint32_t*>(data + Offset);
			Offset += 4 + Count * 4 * 3;

			this->Objects.ReadChunk(this->Info.Version, data + Offset);

			return;
		}

		ChunkHeader header = *reinterpret_cast<ChunkHeader*>(data + i + 4);
		
		switch (header.Type) {
		case 1000: this->Info = *reinterpret_cast<InfoChunk*>(data + header.Offset); break;
		case 2001: this->Objects.ReadChunk(this->Info.Version, data + header.Offset); break;
		}

		i += header.Length;
	}
}