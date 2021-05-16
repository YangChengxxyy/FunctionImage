#include "Equals.h"

set<double> Equals::solve(int min, int max, double pre)
{
    set<double> s{};
    int size = round((max - min) / pre) + 1;
    for (int i = 0; i < size; i++)
    {
        double j = min + i * pre;
        if (fabs(left.getValue(j) - right.getValue(j)) <= pre)
        {
            s.insert(j);
            s.insert(j);
        }
    }
    return s;
}