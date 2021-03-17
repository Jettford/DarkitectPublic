#pragma once

#include <string>
#include <memory>
#include <random>

#include <RakNet/BitStream.h>

#include "Enums/SessionType.h"
#include "Structs/Character.h"

#define BITSTREAM RakNet::BitStream bs;
#define LOG_AT_LINE Logger::Log("Debug", "Debug Log triggered at L" + std::to_string(__LINE__) + std::string(__FILE__));
#define PADDING(x) Utils::FillZero(&bs, x);

#define SERVER_VERSION 171022
#define DARKITECT_VERSION "v0.1"

// Random engine
static std::random_device RandomDevice;
static std::mt19937 MersenneTwister{ RandomDevice() };

template <class T>
static T RandomFromRange(T Min, T Max) {
    if (std::is_same<T, uint32_t>::value) {
        std::uniform_int_distribution<uint32_t> URD(Min, Max);
        return URD(MersenneTwister);
    }
    else if (std::is_same<T, float>::value) {
        std::uniform_real_distribution<float> URD(Min, Max);
        return URD(MersenneTwister);
    }
}

typedef int64_t LWOOBJID;

struct Session {
    std::string m_Name;
    SessionType m_type;
    Character m_Char;
};

static uint32_t ObjectIDCounter = 1;

inline LWOOBJID GenerateObjectIDFromFlags(bool Persistent = false, bool Client = false, bool Spawned = false, bool Character = false) {
    LWOOBJID Value = 1000000000 + (uint64_t)ObjectIDCounter;

    if (Persistent) Value |= (1ULL << 32);
    if (Client) Value |= (1ULL << 46);
    if (Spawned) Value |= (1ULL << 58);
    if (Character) Value |= (1ULL << 60);

    ObjectIDCounter += 1;

    return Value;
}