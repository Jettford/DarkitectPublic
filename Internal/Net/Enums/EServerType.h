#pragma once

#include <cstdint>

namespace Enums {
	enum class EServerType : uint8_t {
		MASTER = 0,
		AUTH,
		WORLD,
		CHAT,
	};
}