#pragma once

#include "../Global.h"

struct Mission {
	uint32_t ID;
	uint32_t MissionID;
	uint32_t State;
	uint32_t CompletionCount = 0;
	uint64_t LastCompletion = 0;
	LWOOBJID MissionOwner;
};