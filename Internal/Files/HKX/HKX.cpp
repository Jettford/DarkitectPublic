#include "HKX.h"

void HKXFile::ReadFile(std::string FileName) {
	uint32_t FileSize;

	auto data = Utils::ReadFileCompletely(FileName, &FileSize);

	Logger::Log("HKX", "Loaded file: " + FileName);

	RakNet::BitStream* bs = new RakNet::BitStream((unsigned char*)data.get(), FileSize, false);

	if (bs->Read<int32_t>().second != 0x57e0e057) {
		Logger::Log("HKX", "HKX file had invalid magic");
		return;
	}

	if (bs->Read<int32_t>().second == 0x10c0c010) {
		bs->Read<int32_t>();
	}
	else {
		bs->SetReadOffset((bs->GetReadOffset() / 8) - 4);
	}
	uint32_t Version; 
	bs->Read(Version); 
	Logger::Log("HKX", "Version: " + std::to_string(Version));
	
	if (Version == 7) {
		int8_t PointerLength = bs->Read<int8_t>().second;
		bool LittleEndian = bs->Read<int8_t>().second == 1;
		int8_t ReusePaddingOptimization = bs->Read<int8_t>().second;
		int8_t EmptyBaseClassOptimization = bs->Read<int8_t>().second;

		int32_t SectionCount = bs->Read<int32_t>().second;

		int32_t ContentsSectionIndex = bs->Read<int32_t>().second;
		int32_t ContentsSectionOffset = bs->Read<int32_t>().second;
		int32_t ContentsClassNameSectionIndex = bs->Read<int32_t>().second;
		int32_t ContentsClassNameSectionOffset = bs->Read<int32_t>().second;

		const char* ContentVersion = (char*)malloc(16);

		bs->ReadAlignedBytes((unsigned char*)ContentVersion, 16);

		Logger::Log("HKX", "Havok version: " + std::string(ContentVersion));

		bs->IgnoreBytes(8);
		for (uint32_t i = 0; i < 3; i++) {
			bs->SetReadOffset((0x40 + (i * 0x30)) * 8 + 1);

			char* SectionName;

			SectionName = (char*)(data.get() + bs->GetReadOffset() / 8);
			bs->IgnoreBytes(20);

			HKX::Section Section;
			Section.SectionName = std::string(SectionName);

			Logger::Log("HKX", "Found section: " + Section.SectionName);

			Section.GeneralOffset = bs->Read<uint32_t>().second;
			Section.Part1 = bs->Read<uint32_t>().second;
			Section.Part2 = bs->Read<uint32_t>().second;
			Section.Part3 = bs->Read<uint32_t>().second;
			Section.Part4 = bs->Read<uint32_t>().second;
			Section.Part5 = bs->Read<uint32_t>().second;
			Section.Part6 = bs->Read<uint32_t>().second;

			if (Section.SectionName == "__data__") Data = Section;
			if (Section.SectionName == "__classnames__") Classnames = Section;
			if (Section.SectionName == "__types__") Types = Section;
		}
		bs->SetReadOffset(Data.GeneralOffset * 8);

		int32_t PositionLimit = Classnames.GeneralOffset + Classnames.Part1;

		while (bs->GetReadOffset() * 8 < PositionLimit) {
			std::string UUID;
			uint32_t UUIDRaw = bs->Read<uint32_t>().second;
			std::stringstream ss;
			ss << std::hex << UUIDRaw;
			UUID = ss.str();

			Logger::Log("HKX", "Found class " + UUID);

			bs->IgnoreBytes(4);

			uint32_t ClassPointer = bs->Read<uint32_t>().second;

			BitSize_t BeforeMove = bs->GetReadOffset();

			bs->SetReadOffset(ClassPointer);

			std::cout << bs->Read<char>().second << std::endl;

			bs->SetReadOffset(BeforeMove);

			//Logger::Log("HKX", "Found Class with UUID: " + uuidS + " with name: " + clsStr + " at " + std::to_string(bs->GetReadOffset() / 8));

		}
	}
}