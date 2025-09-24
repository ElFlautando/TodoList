#pragma once

#include <iostream>
#include <ctime>
#include <array>

#include "todo_status.h"

class TodoItem
{
private:

    void setTimestamp(std::time_t &time);

public:

    std::string m_title{};
    std::string m_comment{};

    std::time_t m_timestampCreation{};
    std::time_t m_timestampCompleted{};

    TodoStatus status { TodoStatus::None};

    TodoItem() {}

    TodoItem(std::string title, std::string comment)
        : m_title{title}, m_comment{comment}
    {
        setTimestamp(m_timestampCreation);
    }
};