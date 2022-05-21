#include "plpsettings.h"

PlpSettings::PlpSettings()
{
    pen = nullptr;
    rotation_center = QPoint(512,384);
    transform.translate(rotation_center.x(),rotation_center.y());
    transform.scale(0.5,0.5);
    transform.translate(-rotation_center.x(),-rotation_center.y());
    current_state = PLPSTATE_DRAWING;

    document = new PlpDocument();
}
