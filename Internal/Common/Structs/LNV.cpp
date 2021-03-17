#include "LNV.h"

#include "../Utils.h"
#include "../Strings.h"

void LWONameValue::Serialize(RakNet::BitStream* bs, std::u16string Name) {
	Utils::WStringToBitStream<uint8_t>(bs, Name, true);
	bs->Write<uint8_t>(Type);
	switch (Type) {
	case 0: {
		Utils::WStringToBitStream<uint32_t>(bs, std::any_cast<std::u16string>(Data));
	} break;
	case 1:
	case 2: {
		bs->Write<int32_t>(std::any_cast<int32_t>(Data));
	} break;
	case 3: {
		bs->Write<float_t>(std::any_cast<float_t>(Data));
	} break;
	case 4: {
		bs->Write<double_t>(std::any_cast<double_t>(Data));
	} break;
	case 5:
	case 6: {
		bs->Write<uint32_t>(std::any_cast<uint32_t>(Data));
	} break;
	case 7: {
		bs->Write<uint8_t>(std::any_cast<bool>(Data) ? 1 : 0);
	} break;
	case 8:
	case 9: {
		bs->Write<int64_t>(std::any_cast<int64_t>(Data));
	} break;
	case 13: {
		Utils::StringToBitStream<uint32_t>(bs, std::any_cast<std::string>(Data));
	} break;
	}
}

LWONameValue::LWONameValue(uint8_t _type, std::any _data) : Type(_type) {
	Data.swap(_data);
}

void LWONameValueGroup::FromBitStream(RakNet::BitStream* bs) {
	for (int i = 0; i < bs->Read<uint32_t>().second; ++i) {
		auto Key = Utils::WStringFromBitStream<uint8_t>(bs, true);
		auto DataType = bs->Read<uint8_t>().second;
		std::any Value = std::any();
		switch (DataType) {
		case 0: {
			Value = Utils::WStringFromBitStream<uint32_t>(bs);
		} break;
		case 1:
		case 2: {
			Value = bs->Read<int32_t>().second;
		} break;
		case 3: {
			Value = bs->Read<float_t>().second;
		} break;
		case 4: {
			Value = bs->Read<double_t>().second;
		} break;
		case 5:
		case 6: {
			Value = bs->Read<uint32_t>().second;
		} break;
		case 7: {
			Value = bs->Read<uint8_t>().second >= 1 ? true : false;
		} break;
		case 8:
		case 9: {
			Value = bs->Read<int64_t>().second;
		} break;
		case 13: {
			Value = Utils::StringFromBitStream<uint32_t>(bs);
		} break;
		default: {
			return;
		} break;
		}
		this->Insert(Key, LWONameValue(DataType, Value));
	}
}

LWONameValueGroup::LWONameValueGroup() {
	Values = std::unordered_map<std::u16string, LWONameValue>();
}

void LWONameValueGroup::Insert(std::u16string Name, LWONameValue Value) {
	Values.insert({ Name, Value });
}

void LWONameValueGroup::Insert(std::u16string Name, std::any Value, uint8_t Type) {
	Values.insert({ Name, LWONameValue(Type, Value) });
}

void LWONameValueGroup::Serialize(RakNet::BitStream* bs) {
	RakNet::BitStream uncompressed = RakNet::BitStream();
	uncompressed.Write<uint32_t>(Values.size());

	for (auto item : Values) {
		item.second.Serialize(&uncompressed, item.first);
	}

	bs->Write<uint32_t>(uncompressed.GetNumberOfBytesUsed() + 1);
	bs->Write<uint8_t>(0);
	bs->Write((char*)uncompressed.GetData(), uncompressed.GetNumberOfBytesUsed());
}

void LWONameValueGroup::FromU16String(std::u16string Value) {
	std::vector<std::u16string> Entries = Utils::SplitU16String(Value, 0x000a);
	for (int i = 0; i < Entries.size(); ++i) {
	LOOPSTART:
		std::u16string Entry = Entries.at(i);
		std::vector<std::u16string> KeyTypeValues = Utils::SplitU16String(Entry, 0x003d);
		std::vector<std::u16string> TypeValues = Utils::SplitU16String(KeyTypeValues.at(1), 0x003a);

		int32_t type = std::stoi(Strings::u16StringToString(TypeValues.at(0)));

		if (TypeValues.size() == 1) TypeValues.push_back(u"");

		std::u16string valFinal = TypeValues.at(1);
		for (int j = 2; j < TypeValues.size(); ++j) {
			valFinal += u":" + TypeValues.at(j);
		}

		LWONameValue* LNVEntry = nullptr;

		switch (type) {
		case 0: {
			LNVEntry = new LWONameValue(type, valFinal);
		} break;
		case 1:
		case 2: {
			LNVEntry = new LWONameValue(type, (int32_t)std::stoi(Strings::u16StringToString(valFinal)));
		} break;
		case 3: {
			LNVEntry = new LWONameValue(type, (float_t)std::stof(Strings::u16StringToString(valFinal)));
		} break;
		case 4: {
			LNVEntry = new LWONameValue(type, (double_t)std::stod(Strings::u16StringToString(valFinal)));
		} break;
		case 5:
		case 6: {
			LNVEntry = new LWONameValue(type, (uint32_t)std::stoul(Strings::u16StringToString(valFinal)));
		} break;
		case 7: {
			LNVEntry = new LWONameValue(type, (bool)(valFinal == u"1"));
		} break;
		case 8:
		case 9: {
			LNVEntry = new LWONameValue(type, (LWOOBJID)std::stoll(Strings::u16StringToString(valFinal)));
		} break;
		case 13: {
			LNVEntry = new LWONameValue(type, Strings::u16StringToString(valFinal));
		} break;
		default: {
			i += 1;
			goto LOOPSTART;
		} break;
		}

		this->Insert(KeyTypeValues.at(0), *LNVEntry);
	}
}