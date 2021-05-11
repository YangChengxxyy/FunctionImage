#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Expression.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_expressionEdit_textEdited(const QString &arg1);

    void on_minXEdit_textEdited(const QString &arg1);

    void on_maxXEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString exp;
    double min;
    double max;
};
#endif // MAINWINDOW_H
