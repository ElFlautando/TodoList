#pragma once

#include <ctime>
#include <string>
#include <array>


std::string_view timeToStr(const std::time_t time)
{
    std::tm localTime{*std::localtime(&time)};

    static std::array<char, 11> buffer;
    std::strftime(buffer.data(), buffer.size(), "%d/%m/%Y", &localTime);

    return std::string_view{buffer.data()};
}
