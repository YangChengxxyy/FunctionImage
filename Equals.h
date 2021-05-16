#ifndef EQUALS_H
#define EQUALS_H

#include <cmath>
#include <set>

#include "Utils.h"
#include "Expression.h"

using std::set;

class Equals
{
private:
    Expression left;
    Expression right;

public:
    Equals(Expression &Cleft, Expression &Cright) : left(Cleft), right(Cright){};
    /**
     * @brief
     * @details 仅使用x作为方程未知数
     * @author YangChengxxyy
     * @return multiset
     */
    set<double> solve(int min = -10, int max = 10, double pre = 0.01);
};

#endif