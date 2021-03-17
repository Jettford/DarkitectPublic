#pragma once

#include <Common/Utils.h>
#include <RakNet/BitStream.h>
#include <string>

#include "Sections/GlobalHeader.h"
#include "Sections/Sections.h"

class HKXFile {
public:

	HKX::Section Classnames;
	HKX::Section Types;
	HKX::Section Data;

	void ReadFile(std::string FileName);
};