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

Expression::Expression(const Expression &e)
{
    this->exp = e.exp;
    this->x = e.x;
}

std::regex Expression::priority[15]{
    std::regex("(.*)\\+(.*)"),            //0
    std::regex("(.*)\\-(.*)"),            //1
    std::regex("(.*)\\*(.*)"),            //2
    std::regex("(.*)/(.*)"),              //3
    std::regex("(.*)\\^(.*)"),            //4
    std::regex("sin\\((.*)\\)"),          //5
    std::regex("cos\\((.*)\\)"),          //6
    std::regex("tan\\((.*)\\)"),          //7
    std::regex("arcsin\\((.*)\\)"),       //8
    std::regex("arccos\\((.*)\\)"),       //9
    std::regex("arctan\\((.*)\\)"),       //10
    std::regex("log\\((.*),(.*)\\)"),     //11
    std::regex("ln\\((.*)\\)"),           //12
    std::regex("(^(-?\\d+)(\\.\\d+)?$)"), //13
    std::regex("x")                       //14
};

double Expression::getValue(double x)
{
    if(isConst)
    {
        return con;
    }
    std::smatch m;
    if (std::regex_search(this->exp, m, priority[0]))
    {
        // cout << "+" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1(m[1].str(), x);
        Expression e2{m[2].str(), x};
        return e1 + e2;
    }

    if (std::regex_search(this->exp, m, priority[1]))
    {
        // cout << "-" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return e1 - e2;
    }

    if (std::regex_search(this->exp, m, priority[2]))
    {
        // cout << "*" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return e1 * e2;
    }

    if (std::regex_search(this->exp, m, priority[3]))
    {
        // cout << "/" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return e1 / e2;
    }

    if (std::regex_search(this->exp, m, priority[4]))
    {
        // cout << "^" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return pow(e1, e2);
    }

    if (std::regex_search(this->exp, m, priority[5]))
    {
        // cout << "sin" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return sin(e);
    }

    if (std::regex_search(this->exp, m, priority[6]))
    {
        // cout << "cos" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;

        Expression e{m[1].str(), x};
        return cos(e);
    }

    if (std::regex_search(this->exp, m, priority[7]))
    {
        // cout << "tan" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return tan(e);
    }

    if (std::regex_search(this->exp, m, priority[8]))
    {
        // cout << "arcsin" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return asin(e);
    }

    if (std::regex_search(this->exp, m, priority[9]))
    {
        // cout << "arccos" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;

        Expression e{m[1].str(), x};
        return acos(e);
    }

    if (std::regex_search(this->exp, m, priority[10]))
    {
        // cout << "arctan" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return atan(e);
    }

    if (std::regex_search(this->exp, m, priority[11]))
    {
        // cout << "log10" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "m2:" << m[2].str() << endl;
        // cout << "-------------" << endl;
        Expression e1{m[1].str(), x};
        Expression e2{m[2].str(), x};
        return log10(e2) / log10(e1);
    }

    if (std::regex_search(this->exp, m, priority[12]))
    {
        // cout << "ln" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        Expression e{m[1].str(), x};
        return log(e);
    }

    if (std::regex_search(this->exp, m, priority[13]))
    {
        // cout << "atof" << endl;
        // cout << "m1:" << m[1].str() << endl;
        // cout << "-------------" << endl;
        return atof(m[1].str().c_str());
    }

    if (std::regex_search(this->exp, m, priority[14]))
    {
        // cout << "x:" << x << endl;
        // cout << "-------------" << endl;
        isConst = false;
        return x;
    }

    return 0;
}

Expression::operator double()
{
    if (isConst)
    {
        return con;
    }
    return getValue(this->x);
}

void Expression::getValueList(List &x)
{
    x.data[0] = this->getValue(x.data[0]);
    if (isConst)
    {
        con = x.data[0];
        for (int i = 1; i < x.size; i++)
        {
            x.data[i] = x.data[0];
        }
    }
    else
    {
        for (int i = 1; i < x.size; i++)
        {

            x.data[i] = this->getValue(x.data[i]);
        }
    }
}