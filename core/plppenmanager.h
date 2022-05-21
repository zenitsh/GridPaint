#ifndef GPPENMANAGER_H
#define GPPENMANAGER_H

#include <QList>
#include "plppen.h"

class PlpPenManager
{
public:
    PlpPenManager();
    void addPen(PlpPen *pen);
    QList<PlpPen*> getList();
    PlpPen *getPen(QString name);

private:
    QList<PlpPen*> m_list;
};

#endif // GPPENMANAGER_H
