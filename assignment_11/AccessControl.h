#pragma once
#include <iostream>
using namespace std;

class User {
public:
    virtual void accessLevel();
};

class Employee : public User {
public:
    void accessLevel() override;
};

class InventoryManager : public Employee {
public:
    void accessLevel() override;
};
