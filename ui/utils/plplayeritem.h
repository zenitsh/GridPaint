#ifndef PLPLAYERITEM_H
#define PLPLAYERITEM_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include "plplayer.h"

class PlpLayerItem : public QWidget
{
    Q_OBJECT
public:
    explicit PlpLayerItem(QWidget *parent = nullptr,PlpLayer *l = nullptr);
    ~PlpLayerItem();
    PlpLayer *layer;
    QLabel *label;
    QLabel *imglabel;
    void refresh();

signals:

};

#endif // PLPLAYERITEM_H
