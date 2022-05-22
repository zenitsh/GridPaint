#include "plpcanvas.h"
#include <QtMath>
#include <QTimer>

PlpCanvas::PlpCanvas(QWidget *parent, PlpSettings *settings)
    : QWidget{parent}, m_settings(settings)
{
    setMouseTracking(true);
    m_drawing = false;
    m_invert = m_settings->transform.inverted();
    QTimer *timer = new QTimer();
    timer->setInterval(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(repaintTimer()));
    timer->start();
    img = new QImage(*m_settings->document->currentLayer->img);
}

void PlpCanvas::repaintTimer()
{
    repaint();
}

void PlpCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect=m_settings->document->currentLayer->img->rect();
    painter.setTransform(m_settings->transform);
    for(int i=0;i<m_settings->document->layers.size();++i)
    {
        painter.drawImage(rect,*m_settings->document->layers.at(i)->img);
    }
    painter.drawRect(rect);
}

void PlpCanvas::mousePressEvent(QMouseEvent *event)
{
    setFocus();
    m_drawing = true;
    m_last_point = m_settings->transform.inverted().map(event->pos());
}

void PlpCanvas::mouseMoveEvent(QMouseEvent *event)
{
    if(m_settings->mouse_input)
    {
        if(!m_drawing)
            return;
        QPointF dest = m_invert.map(event->position());
        draw(dest.x(),dest.y());
    }
}

void PlpCanvas::draw(int x,int y,float pressure)
{
    QPoint dest = QPoint(x,y);
    QImage *cimg = m_settings->document->currentLayer->img;
    ulong *bits = (ulong*)cimg->bits();
    int width = cimg->width();//+img->width()%4?(4-img->width()%4):0;
    int size = m_settings->pen->size();
    int sx = dest.x()-size/2;
    if(sx<0)sx=0;
    int ex = dest.x()+(size+1)/2;
    if(ex>=cimg->width())ex=cimg->width()-1;
    int sy = dest.y()-size/2;
    if(sy<0)sy=0;
    int ey = dest.y()+(size+1)/2;
    if(ey>=cimg->height())ey=cimg->height()-1;
    for(int i=sx;i<=ex;i++)
    {
        int dy=sqrt(size*size/4-(i-dest.x())*(i-dest.x()));
        int rsy = dest.y()-dy;
        if(sy>rsy)rsy=sy;
        int rey = dest.y()+dy;
        if(ey<rey)rey=ey;
        QColor color = m_settings->pen_color_1;
        color.setAlpha(color.alpha()*pressure);
        QColor tmp;
        for(int j=rsy;j<=rey;j++)
        {
            if(m_settings->erazing){
                tmp=Qt::black;
                tmp.setAlpha(0);
            }else{
                tmp=bits[j*width+i];
                tmp.setRed(color.red()*color.alpha()/255+tmp.red()*tmp.alpha()*(255-color.alpha())/65535);
                tmp.setGreen(color.green()*color.alpha()/255+tmp.green()*tmp.alpha()*(255-color.alpha())/65535);
                tmp.setBlue(color.blue()*color.alpha()/255+tmp.blue()*tmp.alpha()*(255-color.alpha())/65535);
                tmp.setAlpha(255-(255-tmp.alpha())*(255-color.alpha())/255);
            }
            bits[j*width+i]=tmp.rgba();
        }
    }
    m_last_point=dest;
}

void PlpCanvas::mouseReleaseEvent(QMouseEvent *event)
{
    m_drawing = false;
}

void PlpCanvas::tabletEvent(QTabletEvent *event)
{
    if(!m_drawing)
        return;
    QPointF dest = m_invert.map(event->position());
    draw(dest.x(),dest.y(),event->pressure());
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
    case Qt::Key_F:
         m_settings->transform.scale(-1,1);
         break;
    case Qt::Key_M:
         m_settings->mouse_input = !m_settings->mouse_input;
         break;
    case Qt::Key_X:
         m_settings->erazing = !m_settings->erazing;
         break;
    }
    m_settings->transform.translate(-m_settings->rotation_center.x(),-m_settings->rotation_center.y());
    m_invert = m_settings->transform.inverted();
    repaint();
}
