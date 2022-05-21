#ifndef PLPSETTINGS_H
#define PLPSETTINGS_H

#include "plppen.h"
#include <QTransform>
#include <QPoint>
#include "plpdocument.h"

#define PLPSTATE_NONE 0
#define PLPSTATE_DRAWING 1

class PlpSettings
{
public:
    PlpSettings();
    PlpPen *pen;
    QTransform transform;
    QPoint rotation_center;
    int current_state;

    PlpDocument *document;
};

#endif // PLPSETTINGS_H
