#include "Manager.h"

Manager::Manager(){};

void Manager::createTodo(std::string title, std::string comment)
{
    todoItems.emplace_back(TodoItem{title, comment});
}

void Manager::printTodoItem(int index)
{
    const TodoItem &item{todoItems.at(index)};
    fmt::print("Created: {} \n Title : {}\n Comment : {}\n ", timeToStr(item.m_timestampCreation), item.m_title, item.m_comment);
}