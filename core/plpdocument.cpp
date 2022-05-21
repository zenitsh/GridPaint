#include "plpdocument.h"

PlpDocument::PlpDocument()
{
    currentLayer = new QImage(1024,768,QImage::Format_RGBA64);
}
