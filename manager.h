#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fmt/core.h>

#include "todo_item.h"
#include "utils.h"

class Manager{
    private:


    public:

    Manager();

    std::vector<TodoItem> todoItems;
    void createTodo(std::string title, std::string comment);
    void printTodoItem(int index);
};