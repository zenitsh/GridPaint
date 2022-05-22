#include "plpcolorform.h"
#include "ui_plpcolorform.h"

PlpColorForm::PlpColorForm(QWidget *parent, PlpSettings *settings) :
    QWidget(parent),
    ui(new Ui::PlpColorForm), m_settings(settings)
{
    ui->setupUi(this);
    ui->listWidget->setFlow(QListView::LeftToRight);
    ui->listWidget->setWrapping(true);
}

PlpColorForm::~PlpColorForm()
{
    delete ui;
}

void PlpColorForm::on_sl_h_sliderMoved(int position)
{
    refresh();
}


void PlpColorForm::on_sl_s_sliderMoved(int position)
{
    refresh();
}


void PlpColorForm::on_sl_v_sliderMoved(int position)
{
    refresh();
}


void PlpColorForm::on_sl_a_sliderMoved(int position)
{
    refresh();
}

void PlpColorForm::refresh()
{
    QColor color = QColor::fromHsv(ui->sl_h->value(),ui->sl_s->value(),ui->sl_v->value(),ui->sl_a->value());
    ui->colorv->setText(color.name());
    m_settings->pen_color_1 = color;
}

void PlpColorForm::on_pushButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    item->setSizeHint(QSize(32,32));
    item->setBackground(m_settings->pen_color_1);
    ui->listWidget->addItem(item);
}


void PlpColorForm::on_listWidget_currentRowChanged(int currentRow)
{
    QColor color = ui->listWidget->item(currentRow)->background().color();
    ui->colorv->setText(color.name());
    m_settings->pen_color_1 = color;
    ui->sl_h->setValue(color.hue());
    ui->sl_s->setValue(color.saturation());
    ui->sl_v->setValue(color.value());
    ui->sl_a->setValue(color.alpha());
}

