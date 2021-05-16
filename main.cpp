#include "mainwindow.h"

#include <QApplication>
#include "Equals.h"

void testEquals();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    testEquals();
    return a.exec();
}

void testEquals()
{
    Expression left("3");
    Expression right("2 * x + 1");
    Equals e(left, right);
    auto s = e.solve(-5, 5, 0.0001);
    for (set<double>::iterator it = s.begin(); it != s.end(); it++)
    {
        printf("%lf\n", *it);
    }
}
