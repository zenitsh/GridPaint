#ifndef PLPCANVAS_H
#define PLPCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QTransform>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QTabletEvent>
#include "plpsettings.h"

class PlpCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit PlpCanvas(QWidget *parent = nullptr, PlpSettings *settings=nullptr);
    QImage *img;

signals:

public slots:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void tabletEvent(QTabletEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    PlpSettings *m_settings;
    bool m_drawing;
    QPoint m_last_point;
    QTransform m_invert;
};

#endif // PLPCANVAS_H
