#pragma once 

#include <string>
#include <locale>
#include <algorithm>

namespace Strings {
    std::u16string StringToU16String(const std::string& string);

    std::string u16StringToString(const std::u16string& u16string);

    std::string RandomString(size_t length);
}