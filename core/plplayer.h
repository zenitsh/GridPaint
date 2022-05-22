#ifndef PLPLAYER_H
#define PLPLAYER_H

#include <QImage>

#define PLPLAYER_IMAGE 0

class PlpLayer
{
public:
    PlpLayer(QImage*);
    ~PlpLayer();
    QImage *img;
    QString name;
    int type;
};

#endif // PLPLAYER_H
