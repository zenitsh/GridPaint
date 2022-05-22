#include "plplayerform.h"
#include "ui_plplayerform.h"
#include "utils/plplayeritem.h"
#include <QTimer>

PlpLayerForm::PlpLayerForm(QWidget *parent,PlpSettings *settings) :
    QWidget(parent),
    ui(new Ui::PlpLayerForm),m_settings(settings)
{
    ui->setupUi(this);
    QList<PlpLayer*>::Iterator i = m_settings->document->layers.begin();
    while(i!=m_settings->document->layers.end())
    {
        QListWidgetItem *item = new QListWidgetItem();
        PlpLayerItem *widget = new PlpLayerItem(this,*i);
        item->setSizeHint(QSize(0,64));
        widget->setSizeIncrement(0,64);
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,widget);
        i++;
    }
    QTimer *timer = new QTimer();
    timer->setInterval(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(repaintTimer()));
    timer->start();
}

PlpLayerForm::~PlpLayerForm()
{
    delete ui;
}

void PlpLayerForm::repaintTimer()
{
    for(int i=0;i<ui->listWidget->count();++i)
    {
        ((PlpLayerItem*)ui->listWidget->itemWidget(ui->listWidget->item(i)))->refresh();
    }
}

void PlpLayerForm::on_pushButton_clicked()
{
    m_settings->document->addLayer();
    QListWidgetItem *item = new QListWidgetItem();
    PlpLayerItem *widget = new PlpLayerItem(this,m_settings->document->currentLayer);
    item->setSizeHint(QSize(0,64));
    widget->setSizeIncrement(0,64);
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item,widget);
}


void PlpLayerForm::on_listWidget_currentRowChanged(int currentRow)
{
    PlpLayerItem *item = (PlpLayerItem*)ui->listWidget->itemWidget(ui->listWidget->item(currentRow));
    if(item)
        m_settings->document->setCurrentLayer((item->layer));
}

