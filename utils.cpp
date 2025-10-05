#include "utils.h"


const char* timeToStr(const std::time_t time)
{
    std::tm localTime{*std::localtime(&time)};

    constexpr size_t dateStrLen {11};
    //static std::array<char, 11> buffer;
    static  char buffer[dateStrLen];
    std::strftime(buffer, dateStrLen, "%d/%m/%Y", &localTime);

    return buffer;
}
