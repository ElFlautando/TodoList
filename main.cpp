#include <iostream>
#include "TodoItem.h"
#include "utils.h"

int main()
{

    TodoItem t1{TodoItem("Title", "Comment")};
    TodoItem t2{TodoItem("Title", "Comment")};
    t2.m_timestampCreation += 86400;

    return 0;
}