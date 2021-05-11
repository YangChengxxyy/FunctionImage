#include "Expression.h"
#include <cmath>

Expression::Expression(string exp)
{
    this->exp = trim(exp);
}

Expression::Expression(string exp, double x)
{
    this->exp = trim(exp);
    this->x = x;
}

regex Expression::priority[15]{
    regex("(.*)\\+(.*)"),            //0
    regex("(.*)\\-(.*)"),            //1
    regex("(.*)\\*(.*)"),            //2
    regex("(.*)/(.*)"),              //3
    regex("(.*)\\^(.*)"),            //4
    regex("sin\\((.*)\\)"),          //5
    regex("cos\\((.*)\\)"),          //6
    regex("tan\\((.*)\\)"),          //7
    regex("arcsin\\((.*)\\)"),       //8
    regex("arccos\\((.*)\\)"),       //9
    regex("arctan\\((.*)\\)"),       //10
    regex("log\\((.*),(.*)\\)"),     //11
    regex("ln\\((.*)\\)"),           //12
    regex("(^(-?\\d+)(\\.\\d+)?$)"), //13
    regex("x")                       //14
};

double Expression::getValue(double x)
{
    smatch m;
    if (regex_search(this->exp, m, priority[0]))
    {
        // cout << "+" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1(m[1].str(), x);
        Expression e2{m[2].str(), x};
        return e1 + e2;
    }
    if (regex_search(this->exp, m, priority[1]))
    {
        // cout << "-" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return e1 - e2;
    }

    if (regex_search(this->exp, m, priority[2]))
    {
        // cout << "*" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return e1 * e2;
    }
    if (regex_search(this->exp, m, priority[3]))
    {
        // cout << "/" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return e1 / e2;
    }
    if (regex_search(this->exp, m, priority[4]))
    {
        // cout << "^" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return pow(e1, e2);
    }

    if (regex_search(this->exp, m, priority[5]))
    {
        // cout << "sin" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return sin(e);
    }

    if (regex_search(this->exp, m, priority[6]))
    {
        // cout << "cos" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;

        Expression e{m[1].str(), x};
        return cos(e);
    }

    if (regex_search(this->exp, m, priority[7]))
    {
        // cout << "tan" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return tan(e);
    }

    if (regex_search(this->exp, m, priority[8]))
    {
        // cout << "arcsin" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return asin(e);
    }

    if (regex_search(this->exp, m, priority[9]))
    {
        // cout << "arccos" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;

        Expression e{m[1].str(), x};
        return acos(e);
    }

    if (regex_search(this->exp, m, priority[10]))
    {
        // cout << "arctan" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return atan(e);
    }

    if (regex_search(this->exp, m, priority[11]))
    {
        // cout << "log10" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return log10(e2) / log10(e1);
    }
    if (regex_search(this->exp, m, priority[12]))
    {
        // cout << "ln" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return log(e);
    }

    if (regex_search(this->exp, m, priority[13]))
    {
        // cout << "atof" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        return atof(m[1].str().c_str());
    }
    if (regex_search(this->exp, m, priority[14]))
    {
        // cout << "x:" << x << endl;
        // cout << "-------------" << endl;
        return x;
    }

    return 0;
}

Expression::operator double()
{
    return getValue(this->x);
}

void Expression::getValueList(List &x)
{
    for (int i = 0; i < x.size; i++)
    {
        x.data[i] = this->getValue(x.data[i]);
    }
}