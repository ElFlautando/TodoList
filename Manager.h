#pragma once

#include <string>
#include <vector>

#include "TodoItem.h"

class Manager{
    private:

    std::vector<TodoItem> todoItems;

    public:

    Manager();

    void createTodo(std::string title, std::string comment);
    void printTodoItem(int index);
};