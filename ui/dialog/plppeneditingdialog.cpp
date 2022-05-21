#include "plppeneditingdialog.h"
#include "ui_plppeneditingdialog.h"

PlpPenEditingDialog::PlpPenEditingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlpPenEditingDialog)
{
    ui->setupUi(this);
    listwidget = ui->listWidget;
    m_c_pen = nullptr;
}

PlpPenEditingDialog::~PlpPenEditingDialog()
{
    delete ui;
}

void PlpPenEditingDialog::init(PlpPenManager *mgr)
{
    m_mgr = mgr;
    QList<PlpPen*> penlist = m_mgr->getList();
    QList<PlpPen*>::iterator i = penlist.begin();
    while(i!=penlist.end())
    {
        listwidget->addItem((*i)->name());
        i++;
    }
    listwidget->setCurrentRow(0);
}

void PlpPenEditingDialog::on_listWidget_currentRowChanged(int currentRow)
{
    QString name=listwidget->item(currentRow)->text();
    PlpPen *pen = m_mgr->getPen(name);
    m_c_pen = pen;
    ui->sizev->setValue(pen->size());
    ui->alphav->setValue(pen->alpha());
}


void PlpPenEditingDialog::on_sizev_valueChanged(double arg1)
{
    if(m_c_pen)
    {
        m_c_pen->setSize(arg1);
    }
}


void PlpPenEditingDialog::on_alphav_valueChanged(double arg1)
{
    if(m_c_pen)
    {
        m_c_pen->setAlpha(arg1);
    }
}

