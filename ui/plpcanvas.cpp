#include "plpcanvas.h"

PlpCanvas::PlpCanvas(QWidget *parent, PlpSettings *settings)
    : QWidget{parent}, m_settings(settings)
{
    img = new QImage(settings->document->currentLayer->copy());
    setMouseTracking(true);
    m_drawing = false;
    m_invert = m_settings->transform.inverted();
}

void PlpCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect=img->rect();
    painter.setTransform(m_settings->transform);
    painter.drawImage(rect,*img);
    painter.drawRect(rect);
}

void PlpCanvas::mousePressEvent(QMouseEvent *event)
{
    m_drawing = true;
    m_last_point = m_settings->transform.inverted().map(event->pos());
    QPainter painter(img);
    painter.drawImage(img->rect(),*m_settings->document->currentLayer);
}

void PlpCanvas::mouseMoveEvent(QMouseEvent *event)
{

}

void PlpCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    m_drawing = false;
    QPainter painter(m_settings->document->currentLayer);
    painter.drawImage(img->rect(),*img);
}

void PlpCanvas::tabletEvent(QTabletEvent *event)
{
    QPainter painter(img);
    QPoint dest = m_invert.map(QPoint(event->position().x(),event->position().y()));
    int size = m_settings->pen->size();
    painter.setPen(QPen(Qt::black,size*event->pressure()));
    painter.drawLine(m_last_point,dest);
    m_last_point = dest;
    repaint();
}

void PlpCanvas::keyPressEvent(QKeyEvent *event)
{
    m_settings->transform.translate(m_settings->rotation_center.x(),m_settings->rotation_center.y());
    switch(event->key())
    {
    case Qt::Key_Q:
         m_settings->transform.rotate(-30);
         break;
    case Qt::Key_E:
         m_settings->transform.rotate(30);
         break;
    case Qt::Key_1:
         m_settings->transform.scale(2,2);
         break;
    case Qt::Key_2:
         m_settings->transform.scale(0.5,0.5);
         break;
    case Qt::Key_W:
         m_settings->transform=m_settings->transform*QTransform().translate(0,-10);
         break;
    case Qt::Key_A:
         m_settings->transform=m_settings->transform*QTransform().translate(-10,0);
         break;
    case Qt::Key_S:
         m_settings->transform=m_settings->transform*QTransform().translate(0,10);
         break;
    case Qt::Key_D:
         m_settings->transform=m_settings->transform*QTransform().translate(10,0);
         break;
    }
    m_settings->transform.translate(-m_settings->rotation_center.x(),-m_settings->rotation_center.y());
    m_invert = m_settings->transform.inverted();
    repaint();
}
