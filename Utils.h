#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

enum class Computer
{
    SIN,
    COS,
    TAN,
    POWER,
    MULTIPY,
    DIVIDE,
    ADD,
    SUB
};

inline string &trim(string &s)
{
    auto index = 0;
    if (!s.empty())
    {
        while ((index = s.find(' ', index)) != string::npos)
        {
            s.erase(index, 1);
        }
    }
    return s;
}

struct List
{
public:
    double *data;
    int size;
    List(double *data, int size)
    {
        this->data = data;
        this->size = size;
    }
    void show()
    {
        for (int i = 0; i < this->size; i++)
        {
            printf("%.3lf\n", *(data + i));
        }
    }
};

#endif