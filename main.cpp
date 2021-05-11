#include <iostream>
#include <regex>
#include <cmath>

#include "Expression.h"

int main()
{
    Expression e{"ln(3.3)/2+tan(x)^2", 3};
    cout << e << endl;
    clock_t start, end;

    double x[100];
    for (int i = 0; i < 100; i++)
    {
        x[i] = i * 0.01;
    }
    double sum[100];
    start = clock();
    for (int i = 0; i < 100; i++)
    {
        sum[i] = e.getValue(x[i]);
    }
    end = clock();
    cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    for (int i = 0; i < 100; i++)
    {
        printf("%.2lf\t%.8lf\n",x[i],sum[i]);
    }

    return 0;
}
