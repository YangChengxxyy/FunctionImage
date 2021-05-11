#pragma once
#include <iostream>
#include <regex>
#include "Utils.h"

using std::string;
using std::cin;
using std::cmatch;
using std::cout;
using std::endl;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;

class Expression
{
public:
    string exp;

    double x;

    static regex priority[11];

    Expression(string exp);

    Expression(string exp,double x);

    double getValue(double x);

    operator double();
};
