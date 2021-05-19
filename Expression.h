#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <regex>
#include "Utils.h"

using std::cout;
using std::cin;
using std::endl;

using std::cmatch;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;
using std::string;

class Expression
{
public:
    string exp;

    double x;

    bool isConst = true;

    static regex priority[15];

    Expression(string exp);

    Expression(string exp, double x);

    Expression(const Expression &e);

    Expression& operator=(const Expression &e);

    double getValue(double x);

    operator double();

    void getValueList(List &data);
};

#endif