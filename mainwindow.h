#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItemModel>
#include <QMainWindow>
#include "Expression.h"
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void initTable();

    void on_expressionEdit_textEdited(const QString &arg1);

    void on_minXEdit_textEdited(const QString &arg1);

    void on_maxXEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;

    QString exp;
    double min;
    double max;
};
#endif // MAINWINDOW_H
