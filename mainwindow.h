#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStandardItemModel>
#include <QMainWindow>
#include <QDoubleValidator>

#include "Expression.h"
#include "dialog.h"

class Dialog;

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
    List *data = nullptr;
    double *x = nullptr;
private slots:
    void initTable();

    void on_expressionEdit_textEdited(const QString &arg1);

    void on_minXEdit_textEdited(const QString &arg1);

    void on_maxXEdit_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_preEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;

    QString exp;
    double pre = 0.01;
    double min = -10;
    double max = 10;

    Dialog *dialog;

};
#endif // MAINWINDOW_H
