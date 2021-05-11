#include <iostream>
#include <regex>
#include <cmath>

#include "Expression.h"

int main()
{
    string s;
    cin >> s;
    Expression e{s, 3};

    double x[100];
    for (int i = 0; i < 100; i++)
    {
        x[i] = i * 0.01;
    }

    List xx{x, 100};
    
    e.getValueList(xx);

    for (int i = 0; i < 100; i++)
    {
        printf("%.2lf\t%.8lf\n", 0.01*i, xx.data[i]);
    }

    return 0;
}
