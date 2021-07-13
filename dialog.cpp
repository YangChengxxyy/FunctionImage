#include "dialog.h"
#include "ui_dialog.h"

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

    double offsetX = 0;
    double offsetY = 0;

    double width = x[size - 1] - x[0];

    double height = 0;

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

    // double w = maxX - minX;
    // double h = maxY - minY;

    if (maxX > this->width())
    {
        maxX = this->width();
    }
    if (maxY > this->height())
    {
        maxY = this->height();
    }

    height = maxY - minY;

    offsetY = -minY;
    offsetX = -minX;

    int zoomOutX = this->width() * 0.9 / width;
    int zoomOutY = this->height() * 0.9 / height;

    int zoomOut = zoomOutX < zoomOutY ? zoomOutX : zoomOutY;

    QPointF *points = new QPointF[size];

    for (int i = 0; i < size; i++)
    {
        points[i].setX((x[i] + offsetX) * zoomOut + this->width() * 0.05);
        points[i].setY((y[i] + offsetY) * zoomOut + this->height() * 0.05);
    }

    double originX = offsetX * zoomOut + this->width() * 0.05;
    double originY = offsetY * zoomOut + this->height() * 0.05;

    minX = (minX + offsetX) * zoomOut + this->width() * 0.05;
    maxX = (maxX + offsetX) * zoomOut + this->width() * 0.05;
    minY = (minY + offsetY) * zoomOut + this->height() * 0.05;
    maxY = (maxY + offsetY) * zoomOut + this->height() * 0.05;

    //x y轴
    QLine xLine(minX, originY, maxX, originY);
    QLine yLine(originX, minY, originX, maxY);

    qPainter.drawText(QPointF(originX, originY), "o");
    qPainter.drawText(QPointF(maxX, originY), "x");
    qPainter.drawText(QPointF(originX, maxY), "y");

    qPainter.drawLine(xLine);
    qPainter.drawLine(yLine);

    qPainter.setPen(QColor(255, 0, 0));
    qPainter.drawPolyline(points, size);
    delete[] x, y, points;
}
