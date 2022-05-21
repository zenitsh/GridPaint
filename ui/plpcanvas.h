#ifndef GPCANVAS_H
#define GPCANVAS_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class PlpCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit PlpCanvas(QWidget *parent = nullptr);

signals:

public slots:
    void paintEvent(QPaintEvent *event);

};

#endif // GPCANVAS_H
