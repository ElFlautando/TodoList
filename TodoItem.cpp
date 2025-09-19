#include "TodoItem.h"

void TodoItem::setTimestamp(std::time_t& time)
{
    std::time(&time);
}