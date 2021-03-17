#pragma once

#include <fstream>

#include "../../INIReader.h"

class Config {
	std::string FileName;
public:
	INIReader* m_Reader;

	void Load() {
		m_Reader = new INIReader("config.ini");

		if (m_Reader->ParseError() != 0) {
			Logger::Log("Config", "Config failed to be loaded closing....");
			exit(0);
		}
	}
};