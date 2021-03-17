#pragma once

#include <string>
#include <vector>
#include <list>

#include <Common/Structs/Mission.h>

namespace Missions {
	class MissionRequirementParser { // This was yoinked from Simon https://github.com/SimonNitzsche/OpCrux-Server/blob/master/src/Missions/MissionRequirementParser.hpp
	private:
		std::uint32_t inputIndex = 0;
		std::uint32_t openBrackets = 0;
		static const std::uint32_t openBracketsLimit = 12;
		bool isOperatorOR = true;
		std::vector<Mission> m_availableMissions;
	public:
		bool result = false;
		bool parseSucceeded = false;
	private:

		void err(const char* msg) {
			parseSucceeded = false;
			std::cout << msg << std::endl;
		}

		inline static std::pair<std::int32_t, std::int32_t> splitMission(std::string sv) {
			int m, t;
			size_t it = sv.find(":");
			if (it != std::string::npos) {
				m = std::stoi(static_cast<std::string>(sv.substr(0, it)));
				t = std::stoi(static_cast<std::string>(sv.substr(it + 1, sv.length() - it - 1)));
			}
			else {
				m = std::stoi(static_cast<std::string>(sv));
				t = 8;
			}
			return std::pair<std::int32_t, std::int32_t>{m, t};
		}

		inline bool hasMissionFromBuffer(std::string missionAndOrTask) {
			auto mt = splitMission(missionAndOrTask);
			for (auto it = m_availableMissions.begin(); it != m_availableMissions.end(); ++it) {
				auto mm = *it;
				if (mm.MissionID == mt.first) {
					return mm.State == mt.second;
				}
			}
			return false;
		}

		inline bool doBitOperation(bool leftHand, bool rightHand) {
			return isOperatorOR ? (leftHand | rightHand) : (leftHand & rightHand);
		}

		bool parse(std::string statement) {
			if (!parseSucceeded) return false;

			bool bufferResult = false;
			std::uint32_t bufferBegin = inputIndex;
			std::uint32_t bufferLength = 0;

			for (; inputIndex < statement.length(); ++inputIndex) {
				switch (statement.at(inputIndex)) {
				case ' ': {
					++bufferLength;
					break;
				}
				case ',':
				case '&':
				case '|': {

					if (bufferLength != 0) {
						isOperatorOR = (statement.at(inputIndex) != '&');
						bufferResult = doBitOperation(bufferResult, hasMissionFromBuffer(statement.substr(bufferBegin, bufferLength)));
						bufferLength = 0;

						while (statement.at(inputIndex + 1) == ' ') { ++inputIndex; }
						bufferBegin = inputIndex + 1;
					}

					break;
				}
				case '(': {
					if (openBrackets < openBracketsLimit) {
						++openBrackets;
						++inputIndex;
						bufferResult = doBitOperation(bufferResult, parse(statement));
						if (!parseSucceeded) return false;
						bufferBegin = inputIndex + 1;
						bufferLength = 0;
					}
					else {
						err("Too many brackets opened.");
						return false;
					}
					break;
				}
				case ')': {
					if (openBrackets != 0) {
						--openBrackets;
						return doBitOperation(bufferResult, hasMissionFromBuffer(statement.substr(bufferBegin, bufferLength)));
					}
					else {
						err("Tried to close bracket without an open bracket");
						return false;
					}

					break;
				}
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case ':': {
					++bufferLength;
					break;
				}
				default: {
					err("Unknown operator: " + statement.at(inputIndex));
					return false;
				}
				}
			}
			if (parseSucceeded) {
				if (bufferLength != 0) {
					bufferResult = doBitOperation(bufferResult, hasMissionFromBuffer(statement.substr(bufferBegin, bufferLength)));
				}
				return bufferResult;
			}
			return false;
		}

	public:

		static std::vector<std::string> sweepMissionList(std::string statement) {
			std::vector<std::string> result = std::vector<std::string>();
			std::uint32_t buffer_begin = 0;
			std::uint32_t buffer_end = 0;
			for (int i = 0; i <= statement.size(); ++i) {
				switch ((i < statement.size()) ? statement.at(i) : '\0') {
				case '0':
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
				case ':': {
					++buffer_end;
					break;
				}
				default: {
					if (buffer_end != 0) {
						std::string newEntry = statement.substr(buffer_begin, buffer_end);
						bool isDuplicate = false;
						if (result.size() != 0) {
							auto resultEnd = result.end();
							auto newEntryBegin = newEntry.begin();
							for (auto it = result.begin(); it != resultEnd; ++it) {
								if (*it == newEntry) {
									isDuplicate = true;
									break;
								}
							}
						}
						if (!isDuplicate) {
							result.push_back(newEntry);
						}
						buffer_end = 0;
					}
					buffer_begin = i;
					++buffer_begin;
					break;
				}
				}
			}
			return result;
		}

		static std::vector<std::int32_t> sweepMissionListNumerical(std::string statement) {
			std::vector<std::int32_t> result = std::vector<std::int32_t>();
			std::vector<std::string> sRes = sweepMissionList(statement);

			for (auto it1 = sRes.begin(); it1 != sRes.end(); ++it1) {
				std::string svE = *it1;
				result.push_back(splitMission(svE).first);
			}

			return result;
		}

		MissionRequirementParser(std::string statement, std::vector<Mission> availableMissions) : m_availableMissions(availableMissions) {
			parseSucceeded = true;

			result = parse(statement);
		}
	};
}