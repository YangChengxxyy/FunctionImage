#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initTable();
}

void MainWindow::initTable()
{
    this->model = new QStandardItemModel();
    this->ui->tableView->setModel(model);
    this->model->setHorizontalHeaderItem(0, new QStandardItem("x"));
    this->ui->tableView->setColumnWidth(0, 197);
    this->model->setHorizontalHeaderItem(1, new QStandardItem("f(x)"));
    this->ui->tableView->setColumnWidth(1, 394);
    //测试数据
    Expression e{"sin(x)"};
    double x[1000];
    for (int i = 0; i < 1000; i++)
    {
        x[i] = i * 0.01;
    }
    List l{x, 1000};
    e.getValueList(l);
    for (int i = 0; i < 1000; i++)
    {
        this->model->setItem(i, 0, new QStandardItem(QString::number(i * 0.01)));
        this->model->setItem(i, 1, new QStandardItem(QString::number(l.data[i], 'f', 10)));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_expressionEdit_textEdited(const QString &arg1)
{
    this->exp = arg1;
}

void MainWindow::on_minXEdit_textEdited(const QString &arg1)
{
    this->min = arg1.toDouble();
}

void MainWindow::on_maxXEdit_textEdited(const QString &arg1)
{
    this->max = arg1.toDouble();
}
