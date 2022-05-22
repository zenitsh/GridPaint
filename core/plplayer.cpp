#include "plplayer.h"

PlpLayer::PlpLayer(QImage *_img)
{
    img = _img;
    name = "颜色图层";
    type = PLPLAYER_IMAGE;
}

PlpLayer::~PlpLayer()
{
    delete img;
}
