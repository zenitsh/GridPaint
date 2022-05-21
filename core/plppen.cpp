#include "plppen.h"

PlpPen::PlpPen()
{
    m_size = 1.0f;
    m_alpha = 1.0f;
}

float PlpPen::alpha()
{
    return m_alpha;
}

float PlpPen::size()
{
    return m_size;
}

QString PlpPen::name()
{
    return m_name;
}

void PlpPen::setAlpha(float a)
{
    m_alpha = a;
}

void PlpPen::setSize(float s)
{
    m_size = s;
}

void PlpPen::setName(QString n)
{
    m_name = n;
}
