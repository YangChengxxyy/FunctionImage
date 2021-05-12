#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
    initTable();
    QDoubleValidator *q = new QDoubleValidator();
    this->ui->maxXEdit->setValidator(q);
    this->ui->minXEdit->setValidator(q);
    this->ui->preEdit->setValidator(q);
}

void MainWindow::initTable()
{
    this->model = new QStandardItemModel();
    this->ui->tableView->setModel(model);
    this->model->setHorizontalHeaderItem(0, new QStandardItem("x"));
    this->ui->tableView->setColumnWidth(0, 374);
    this->model->setHorizontalHeaderItem(1, new QStandardItem("f(x)"));
    this->ui->tableView->setColumnWidth(1, 395);
}

MainWindow::~MainWindow()
{
    delete this->ui;
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

void MainWindow::on_pushButton_clicked()
{
    Expression e{this->exp.toStdString()};
    this->model->setHorizontalHeaderItem(1, new QStandardItem("f(x)=" + this->exp));
    int size = qRound((max - min) / pre) + 1;
    double x[size];
    for (int i = 0; i < size; i++)
    {
        x[i] = i * pre + min;
    }
    List l{x, size};
    e.getValueList(l);
    for (int i = 0; i < size; i++)
    {
        this->model->setItem(i, 0, new QStandardItem(QString::number(i * pre + min)));
        this->model->setItem(i, 1, new QStandardItem(QString::number(l.data[i], 'f', 10)));
    }
}

void MainWindow::on_preEdit_textEdited(const QString &arg1)
{
    this->pre = arg1.toDouble();
}