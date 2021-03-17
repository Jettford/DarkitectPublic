#pragma once

#include <cstdint>
#include <string>

namespace HKX {
	struct Section {
		std::string SectionName;

		uint32_t GeneralOffset;
		uint32_t Part1;
		uint32_t Part2;
		uint32_t Part3;
		uint32_t Part4;
		uint32_t Part5;
		uint32_t Part6;
	};
}