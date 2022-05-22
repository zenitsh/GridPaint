#include "plplayeritem.h"
#include <QHBoxLayout>

PlpLayerItem::PlpLayerItem(QWidget *parent,PlpLayer *l)
    : QWidget{parent},layer(l)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    this->setLayout(layout);

    imglabel = new QLabel(this);
    layout->addWidget(imglabel);
    imglabel->show();
    label = new QLabel(this);
    layout->addWidget(label);
    label->show();
    refresh();
}

PlpLayerItem::~PlpLayerItem()
{
    delete label;
}

void PlpLayerItem::refresh()
{
    label->setText(layer->name);
    imglabel->setPixmap(QPixmap::fromImage(*layer->img).scaledToHeight(64));
}
