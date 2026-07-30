#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<random>
class Character
{
protected:
    int attack=10;
    std::string name;
public:
    virtual ~Character() = default;
    virtual void setAttack(int& value) = 0;
    virtual std::string getName() const = 0;
    int getAttack() const
    {
        return attack;
    }
};