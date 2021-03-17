#pragma once

#include <cstdint>

namespace Enums {
	enum class ERemoteConnection : uint16_t {
		GENERAL = 0,
		AUTH,
		CHAT,
		MASTER,
		SERVER,
		CLIENT
	};
}