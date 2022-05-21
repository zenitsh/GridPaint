#include "plpcanvas.h"

PlpCanvas::PlpCanvas(QWidget *parent)
    : QWidget{parent}
{

}

void PlpCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
}
