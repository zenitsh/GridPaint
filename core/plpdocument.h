#ifndef PLPDOCUMENT_H
#define PLPDOCUMENT_H

#include <QImage>
#include <QList>
#include "plplayer.h"

class PlpDocument
{
public:
    PlpDocument();
    ~PlpDocument();
    QList<PlpLayer*> layers;
    void addLayer();
    void setCurrentLayer(PlpLayer *layer);
    PlpLayer *currentLayer;
};

#endif // PLPDOCUMENT_H
