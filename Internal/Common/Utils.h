#pragma once

#include <RakNet/BitStream.h>

#include "Structs/ServerParts/Database.h"
#include "Structs/ServerParts/Config.h"

#include <string>
#include <sstream>
#include <memory>
#include <fstream>

namespace Utils {
	inline void SetTitle(std::string Title) {
#ifdef _WIN32
		std::system(std::string("title " + Title).c_str());
#endif
	}

	inline std::vector<std::u16string> SplitU16String(std::u16string Value, char16_t SplitChar) {
		std::basic_stringstream<char16_t> ss;
		ss.str(Value);
		std::u16string item;
		std::vector<std::u16string> elems;
		while (std::getline(ss, item, SplitChar)) elems.push_back(item);
		return elems;
	}
	inline std::vector<std::string> SplitU8String(std::string Value, char SplitChar) {
		std::basic_stringstream<char> ss;
		ss.str(Value);
		std::string item;
		std::vector<std::string> elems;
		while (std::getline(ss, item, SplitChar)) elems.push_back(item);
		return elems;
	}

	inline std::unique_ptr<unsigned char[]> ReadFileCompletely(std::string filename, uint32_t* fsize = 0) {
		FILE* file = fopen(filename.c_str(), "rb");
		if (file == nullptr) return nullptr;
		fseek(file, 0, SEEK_END);
		long int size = ftell(file);
		std::unique_ptr<unsigned char[]> data = std::make_unique<unsigned char[]>(size);
		fseek(file, 0, SEEK_SET);
		int bytes_read = fread(data.get(), sizeof(unsigned char), size, file);
		fclose(file);
		if (fsize != nullptr) *fsize = bytes_read;
		return data;
	}

	inline std::string ReadLineOfTextFile(std::string FileName, uint32_t line) {
		std::fstream file(FileName);

		file.seekg(std::ios::beg);
		for (int i = 0; i < line - 1; ++i) {
#undef max
			file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		std::string data;
		file >> data;
		return data;
	}

	inline void WriteConstruct(RakNet::BitStream& bs, uint16_t rct, uint32_t ipid) {
		bs.Write<uint8_t>(0x53);
		bs.Write<uint16_t>(rct);
		bs.Write<uint32_t>(ipid);
		bs.Write<uint8_t>(0x00);
	}

	inline void SavePacket(const std::string& filename, const char* data, size_t length) {
		std::ofstream file(filename, std::ios::binary);
		if (!file.is_open()) return;
		file.write(data, length);
		file.close();
	}

	inline void FillZero(RakNet::BitStream* bs, int count) {
		bs->Write(std::string(count, 0x00).c_str(), count);
	}

	inline void BufferedStringToBitStream(RakNet::BitStream* bitstream, std::string text, unsigned int len = 33) {
		if (text.length() > len) text = text.substr(0, len);
		bitstream->Write(text.c_str(), static_cast<const unsigned int>(text.length()));
		FillZero(bitstream, len - static_cast<unsigned int>(text.length()));
	}

	template<class T>
	inline void StringToBitStream(RakNet::BitStream* bitstream, const std::string& text) {
		std::uint32_t size = text.size();
		bitstream->Write<T>(size);

		bitstream->Write(text.c_str(), text.size());
	}

	inline void BufferedWStringToBitStream(RakNet::BitStream* bitstream, std::u16string text, unsigned int len = 33) {
		if (text.length() > len) text = text.substr(0, len);
		bitstream->Write(reinterpret_cast<const char*>(text.c_str()), text.length() * 2);
		FillZero(bitstream, (len - text.length()) * 2);
	}

	template<class T>
	inline void WStringToBitStream(RakNet::BitStream* bitstream, const std::u16string& text, bool writeSizeOfBytes = false) {
		T size = text.size();
		if (writeSizeOfBytes) size *= 2;
		bitstream->Write<T>(size);
		bitstream->Write(reinterpret_cast<const char*>(text.c_str()), text.size() * 2);
	}

	template<class T>
	inline std::u16string WStringFromBitStream(RakNet::BitStream* bitstream, bool SizeOfBytes = false) {
		std::uint32_t size = bitstream->Read<T>().second;
		if (SizeOfBytes) size / 2;
		std::unique_ptr<char[]> buff = std::make_unique<char[]>(size * 2);
		bitstream->Read(buff.get(), size * 2);
		auto* data = reinterpret_cast<char16_t*>(buff.get());

		return std::u16string(data, size);
	}

	template<class T>
	inline std::string StringFromBitStream(RakNet::BitStream* bitstream) {
		std::uint32_t size; bitstream->Read<T>(size);
		std::unique_ptr<char[]> buff = std::make_unique<char[]>(size);
		bitstream->Read(buff.get(), size);
		char* data = static_cast<char*>(buff.get());

		return std::string(data, size);
	}

	inline std::u16string WStringFromBitStream(RakNet::BitStream* bs, size_t len) {
		std::unique_ptr<char[]> buff = std::make_unique<char[]>(len * 2);
		bs->Read(buff.get(), len * 2);
		auto* data = reinterpret_cast<char16_t*>(buff.get());
		int i;
		for (i = 0; i < len; ++i) { if (*(data + i) == 0x0000) break; }
		std::u16string returnValue = std::u16string(reinterpret_cast<char16_t*>(buff.get()), i);
		return returnValue;
	};

	inline std::string StringFromBitStream(RakNet::BitStream* bitstream, int len) {
		std::unique_ptr<char[]> buff = std::make_unique<char[]>(len);
		bitstream->Read(buff.get(), len);
		char* data = reinterpret_cast<char*>(buff.get());
		int i;
		for (i = 0; i < len; ++i) { if (*(data + i) == 0x00) break; }
		std::string returnValue = std::string(reinterpret_cast<char*>(buff.get()), i);
		return returnValue;
	};

	// Temporary way for GameServers to load other instances and transfer users to them.

	inline uint32_t GetGameInstance(Database* db, Config* config, uint32_t WorldID) {
		uint16_t EarlyPort = db->GetServer(WorldID);

		if (EarlyPort != 0) {
			return EarlyPort;
		}

		uint32_t Active = db->GetServerCount();

		std::string PortRange = config->m_Reader->Get("Master", "PortRange", "0-0");

		uint32_t NextPort = std::stoul(PortRange.substr(0, PortRange.find("-"))) + Active - 1;
		uint32_t WorldServerPortRangeEnd = std::stoul(PortRange.substr(PortRange.find("-") + 1, PortRange.length()));

		if (NextPort > WorldServerPortRangeEnd || NextPort == 0) {
			// TODO: some sort of error, possibly not though
		}

		std::system(std::string("start GameServer.exe " + std::to_string(NextPort) + " " + std::to_string(WorldID)).c_str());

		return NextPort;
	}
}
