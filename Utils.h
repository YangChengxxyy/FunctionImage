#pragma once
#include <iostream>

using std::string;


enum class Computer
{
    SIN, COS, TAN, POWER, MULTIPY, DIVIDE, ADD, SUB
};

inline string& trim(string& s)
{
    int index = 0;
    if (!s.empty())
    {
        while ((index = s.find(' ', index)) != string::npos)
        {
            s.erase(index, 1);
        }
    }
    return s;
}
