#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    this->ui->setupUi(this);
}

void Dialog::paintEvent(QPaintEvent *)
{
    QPainter qPainter(this);
    this->parent = (MainWindow *)this->parentWidget();
    int size = this->parent->data->size;

    double *y = new double[size];
    memcpy(y, this->parent->data->data, sizeof(double) * size);
    double *x = new double[size];
    memcpy(x, this->parent->x, sizeof(double) * size);

    double width = x[size - 1] - x[0];

    double minX = x[0], maxX = x[size - 1];

    double minY = -y[0], maxY = -y[0];

    y[0] = -y[0];

    for (int i = 1; i < size; i++)
    {
        if (-y[i] < minY)
        {
            minY = -y[i];
        }
        if (-y[i] > maxY)
        {
            maxY = -y[i];
        }
        y[i] = -y[i];
    }

    if (maxX > this->width())
    {
        maxX = this->width();
    }
    if (maxY > this->height())
    {
        maxY = this->height();
    }

    double height = maxY - minY;

    //y偏移量
    double offsetY = -minY;
    //x偏移量
    double offsetX = -minX;

    //x放大倍数
    int zoomOutX = this->width() * 0.9 / width;
    //y放大倍数
    int zoomOutY = this->height() * 0.9 / height;
    //放大倍数
    int zoomOut = zoomOutX < zoomOutY ? zoomOutX : zoomOutY;

    QPointF *points = new QPointF[size];

    for (int i = 0; i < size; i++)
    {
        points[i].setX((x[i] + offsetX) * static_cast<double>(zoomOut) + this->width() * 0.05);
        points[i].setY((y[i] + offsetY) * static_cast<double>(zoomOut) + this->height() * 0.05);
    }
    //原点x
    double originX = offsetX * zoomOut + this->width() * 0.05;
    //原点y
    double originY = offsetY * zoomOut + this->height() * 0.05;

    minX = (minX + offsetX) * zoomOut + this->width() * 0.05;
    maxX = (maxX + offsetX) * zoomOut + this->width() * 0.05;
    minY = (minY + offsetY) * zoomOut + this->height() * 0.05;
    maxY = (maxY + offsetY) * zoomOut + this->height() * 0.05;
    this->resize(this->width(), this->width() * (maxY - minY) / (maxX - minX));

    //x轴
    QLine xLine(minX, originY, maxX, originY);
    //y轴
    QLine yLine(originX, minY, originX, maxY);

    qPainter.drawLine(xLine);
    qPainter.drawLine(yLine);

    qPainter.drawText(QPointF(originX + 2, originY - 2), "O");
    qPainter.drawText(QPointF(maxX, originY - 7), "x");
    qPainter.drawText(QPointF(originX + 7, maxY), "y");

    //箭头
    QLineF *arrows = new QLineF[4]{{maxX, originY, maxX - 5, originY - 5},
                                   {maxX, originY, maxX - 5, originY + 5},
                                   {originX, minY, originX - 5, minY + 5},
                                   {originX, minY, originX + 5, minY + 5}};

    qPainter.drawLines(arrows, 4);

    int xLength = 80;
    int yLength = 40;

    const int xCount = this->width() / xLength;
    const int yConnt = (this->width() * (maxY - minY) / (maxX - minX)) / yLength;
    int w = maxX - minX;
    int h = maxY - minY;

    int wSpacer = w / xCount;
    int hSpacer = h / yConnt;

    for (int i = 0; i < size; i++)
    {
        int xx = points[i].x();
        int yy = points[i].y();
        if (xx % wSpacer == 0)
        {
            qPainter.drawLine(xx, originY, xx, originY - 3);
            qPainter.drawText(QPoint(xx, originY - 13), QString::number(x[i]));
        }
        if (yy % hSpacer == 0)
        {
            qPainter.drawLine(originX, yy, originX + 3, yy);
            qPainter.drawText(QPoint(originX + 13, yy + 5), QString::number(-y[i], 'f', 2));
        }
    }

    qPainter.setPen(QColor(255, 0, 0));
    qPainter.drawPolyline(points, size);

    this->resize(this->width(), this->width() * (maxY - minY) / (maxX - minX));

    delete[] x, y, points, arrows;
}
