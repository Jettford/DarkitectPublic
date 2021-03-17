#include "Strings.h"

std::u16string Strings::StringToU16String(const std::string& string) {
    return std::u16string(string.begin(), string.end());
}

std::string Strings::u16StringToString(const std::u16string& u16string) {
    return std::string(u16string.begin(), u16string.end());
}

std::string Strings::RandomString(size_t length)
{
    auto RandomCharacter = []() -> char
    {
        const char CharacterSet[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        const size_t MaxIndex = (sizeof(CharacterSet) - 1);
        return CharacterSet[rand() % MaxIndex];
    };
    std::string String(length, 0);
    std::generate_n(String.begin(), length, RandomCharacter);
    return String;
}