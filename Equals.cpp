#include "Equals.h"

std::set<double> Equals::solve(int min, int max, double pre)
{
    std::set<double> s{};
    int size = round((max - min) / pre) + 1;
    for (int i = 0; i < size; i++)
    {
        double j = min + i * pre;
        if (fabs(left.getValue(j) - right.getValue(j)) <= pre)
        {
            s.insert(j);
        }
    }
    return s;
}

void testEquals()
{
    Expression left("3");
    Expression right("2 * x + 1");
    Equals e(left, right);
    auto s = e.solve(-5, 5, 0.0001);
    for (std::set<double>::iterator it = s.begin(); it != s.end(); it++)
    {
        printf("%lf\n", *it);
    }
}