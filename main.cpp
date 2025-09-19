#include <iostream>
#include "TodoItem.h"
#include "utils.h"

int main()
{

    TodoItem t1{TodoItem("Title", "Comment")};
    std::cout << "Date:" <<  timeToStr(t1.m_timestampCompleted) << std::endl;
    std::cout << "Date:" <<  t1.m_timestampCompleted << std::endl;

    return 0;
}