#pragma once
#include "Menu.h"
class SubMenu :
    public Menu
{
public:

    SubMenu() {};
    ~SubMenu() = default;

public:
    void showMenu();
};

