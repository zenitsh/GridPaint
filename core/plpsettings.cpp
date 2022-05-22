#include "plpsettings.h"

PlpSettings::PlpSettings()
{
    pen = nullptr;
    rotation_center = QPoint(512,512);
    transform.scale(0.5,0.5);
    current_state = PLPSTATE_DRAWING;
    pen_color_1 = Qt::black;
    mouse_input = false;
    erazing = false;

    document = new PlpDocument();
}
