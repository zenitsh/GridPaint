#include "plppenmanager.h"

PlpPenManager::PlpPenManager()
{
    PlpPen *pen1 = new PlpPen();
    pen1->setSize(10.0f);
    pen1->setAlpha(1.0f);
    pen1->setName("Good Pen");
    addPen(pen1);
    PlpPen *pen2 = new PlpPen();
    pen2->setSize(2.0f);
    pen2->setAlpha(0.5f);
    pen2->setName("Bad Pen");
    addPen(pen2);
}

void PlpPenManager::addPen(PlpPen *pen)
{
    m_list.append(pen);
}

PlpPen *PlpPenManager::getPen(QString name)
{
    QList<PlpPen*>::Iterator i=m_list.begin();
    while(i!=m_list.end())
    {
        if(name==(*i)->name())
            return *i;
        i++;
    }
    return nullptr;
}

QList<PlpPen*> PlpPenManager::getList()
{
    return m_list;
}
