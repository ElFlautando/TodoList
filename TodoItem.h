#include <iostream>
#include <ctime>
#include <array>

#include "TodoStatus.h"

class TodoItem
{
private:

    std::string m_title{};
    std::string m_comments{};

    void setTimestamp(std::time_t &time);

public:

    std::time_t m_timestampCreation{};
    std::time_t m_timestampCompleted{};

    TodoStatus status { TodoStatus::None};

    TodoItem() {}

    TodoItem(std::string title, std::string comments)
        : m_title{title}, m_comments{comments}
    {
        setTimestamp(m_timestampCreation);
    }
};