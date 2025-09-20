#include <iostream>
#include "TodoItem.h"
#include "utils.h"

int main()
{

    TodoItem t1{TodoItem("Title", "Comment")};
    std::cout << "Date:" <<  timeToStr(t1.m_timestampCreation) << std::endl;

    return 0;
}