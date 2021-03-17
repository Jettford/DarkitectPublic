#pragma once

#include "BitStream.h"

namespace RakNet {
	class ISerializable {
	public:
		virtual void Serialize(BitStream* bs);
	};
}