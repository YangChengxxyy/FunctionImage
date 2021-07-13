#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QPainter>
#include <QPen>
#include <QPointF>

#include "mainwindow.h"

class MainWindow;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
protected:
    void paintEvent(QPaintEvent *); //重写函数，函数定义在源文件中

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog() {}
    MainWindow *parent;

private:
    Ui::Dialog *ui;
    const double minWidth = 1920 - 200;
    const double minHeight = 1080 - 200;
};

#endif // DIALOG_H
