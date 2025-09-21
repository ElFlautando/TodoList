#include <iostream>

#include "TodoItem.h"
#include "utils.h"
#include "Manager.h"

int main()
{
    Manager m;

    m.createTodo("Tittle 1", "com 1");
    m.createTodo("Tittle 2", "com 2");
    m.createTodo("Tittle 3", "com 3");

    //TodoItem t1{TodoItem("Title", "Comment")};
    //TodoItem t2{TodoItem("Title", "Comment")};
    //t2.m_timestampCreation += 86400;

    m.printTodoItem(0);
    m.printTodoItem(2);

    return 0;
}