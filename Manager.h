#include <string>
#include <vector>

#include "TodoItem.h"
#include "Manager.h"

class Manager{
    private:

    std::vector<TodoItem> todoItems;

    public:

    void createTodo(std::string title, std::string comment);
    void Manager::printTodoItem(int index);
};