#include <iostream>

#include "todo_item.h"
#include "utils.h"
#include "manager.h"

#include "gui.h"

int main()
{
    Manager m;

    m.createTodo("Title 1", "com 1");
    m.createTodo("Title 2", "com 2");
    m.createTodo("Title 3", "com 3");

    m.printTodoItem(2);


    GUI gui { GUI()};
    gui.runGUI(m);

    return 0;
}