#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_expressionEdit_textEdited(const QString &arg1)
{
    this->exp=arg1;
}

void MainWindow::on_minXEdit_textEdited(const QString &arg1)
{
    this->min=arg1.toDouble();
}

void MainWindow::on_maxXEdit_textEdited(const QString &arg1)
{
    this->max = arg1.toDouble();
}
