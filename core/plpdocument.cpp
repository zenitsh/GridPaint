#include "plpdocument.h"

PlpDocument::PlpDocument()
{
    currentLayer = new PlpLayer(new QImage(1024,768,QImage::Format_ARGB32));
    for(int i=0;i<1024;++i)
    {
        for(int j=0;j<768;++j)
        {
            ((ulong*)(currentLayer->img->bits()))[i*768+j]=0xffffffff;
        }
    }
    layers.append(currentLayer);
}

PlpDocument::~PlpDocument()
{
    delete currentLayer;
}

void PlpDocument::addLayer()
{
    int w = currentLayer->img->width();
    int h = currentLayer->img->height();
    currentLayer = new PlpLayer(new QImage(w,h,QImage::Format_ARGB32));
    for(int i=0;i<w;++i)
    {
        for(int j=0;j<h;++j)
        {
            ((ulong*)(currentLayer->img->bits()))[i*h+j]=0x00ffffff;
        }
    }
    layers.append(currentLayer);
}

void PlpDocument::setCurrentLayer(PlpLayer *layer)
{
    currentLayer = layer;
}
