#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<random>
class Character
{
protected:
    int attack = 0;

public:
    virtual ~Character() = default;
    virtual void setAttack() = 0;
    int getAttack() const
    {
        return attack;
    }
};