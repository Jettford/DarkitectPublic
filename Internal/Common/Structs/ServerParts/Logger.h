#pragma once

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <filesystem>

namespace Logger {
	static std::string GetTime(time_t t, const char* format) {
		struct tm local_time;
#ifdef __unix__
		localtime_r(&t, &local_time);
#elif _WIN32
		localtime_s(&local_time, &t);
#endif
		char buffer[256];
		auto len = strftime(buffer, 256, format, &local_time);
		buffer[len] = '\0';

		return buffer;
	}


	inline std::fstream FileStream;
	static bool DoLog = true;
	static time_t ServerStart;
	static const char* ServerName;

	static bool LoggingEnabled() { return DoLog; }

	static void Log(const std::string& from, const std::string& message) {
		if (DoLog) {
			std::string LogValue = std::string("[" + GetTime(time(0), "%H:%M:%S") + "] [" + from + "] " + message);
			puts(LogValue.c_str());
			LogValue += '\n';
			FileStream.write(LogValue.c_str(), LogValue.length());
			FileStream.flush();
		}
	}

	static void LoadLogger() {
		FileStream = std::fstream();
		if (std::filesystem::exists("./logs")) {
			std::filesystem::create_directory("logs");
		}
		std::string TimePath = std::string("./logs/" + std::string(ServerName) + "_" + GetTime(ServerStart, "%H-%M-%S") + ".log");
		FileStream.open(TimePath, std::fstream::out);
		Log("Logger", "Opened log file at " + TimePath);
	}
	
	static void Log(const std::string& from, std::exception& ex) { Log(from, ex.what()); }
}