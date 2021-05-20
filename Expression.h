#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <regex>
#include "Utils.h"

class Expression
{
public:
    string exp;

    double x;

    bool isConst = true;

    double con = 0;

    static std::regex priority[15];

    Expression(string exp);

    Expression(string exp, double x);

    Expression(const Expression &e);

    Expression& operator=(const Expression &e);

    double getValue(double x);

    operator double();

    void getValueList(List &data);
};

#endif