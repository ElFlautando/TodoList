#include "todo_item.h"

void TodoItem::setTimestamp(std::time_t& time)
{
    time = std::time(nullptr);
}