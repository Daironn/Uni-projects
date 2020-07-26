#include "pch.h"
#include "Info.h"

void Info::showMoves()
{
    std::queue<std::string> temp = moves;
        while (!temp.empty())
        {
           temp.pop();
           std::cout << temp.front()<<std::endl;
           temp.pop();
        }

}
