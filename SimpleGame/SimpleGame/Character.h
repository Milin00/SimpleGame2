#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include<random>
class Character
{
protected:
    int attack;

public:
    virtual ~Character() = default;
    int getAttack() const
    {
        return attack;
    }
};