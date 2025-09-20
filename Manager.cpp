#include <iostream>
#include <format>

#include "Manager.h"
#include "TodoItem.h"
#include "utils.h"

void Manager::createTodo(std::string title, std::string comment)
{
    todoItems.emplace_back(TodoItem{title, comment});
}

void Manager::printTodoItem(int index)
{
    const TodoItem &item{todoItems.at(index)};
    std::cout << std::format("Created: {} \n
                             Title : {}\n Comment : {}\n ", 
                             timeToStr(item.m_timestampCreation),
                             item.m_title, item.n_comment);
}