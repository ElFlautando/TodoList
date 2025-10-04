#include <iostream>

#include "todo_item.h"
#include "utils.h"
#include "manager.h"

#include "gui.h"

int main()
{
    Manager m;

    m.createTodo("Tittle 1", "com 1");
    m.createTodo("Tittle 2", "com 2");
    m.createTodo("Tittle 3", "com 3");

    m.printTodoItem(2);


    GUI gui { GUI()};
    gui.runGUI();

    return 0;
}