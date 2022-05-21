#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pen_manager = new PlpPenManager();
    settings = new PlpSettings();
    settings->pen = pen_manager->getPen("Good Pen");

    layout = new QHBoxLayout(ui->centralwidget);
    canvas = new PlpCanvas(this,settings);
    layout->addWidget(canvas);

    status = new QLabel();
    status->setText("笔刷: \""+settings->pen->name()+"\"");
    this->statusBar()->addWidget(status);
    this->statusBar()->addWidget(new QLabel("试试WASDQE12这些键！暂时不支持切换画笔，笔刷大小在编辑里改"));
}

MainWindow::~MainWindow()
{
    delete pen_manager;
    delete ui;
}


void MainWindow::on_action_Pen_triggered()
{
    PlpPenEditingDialog *dialog = new PlpPenEditingDialog(this);
    dialog->init(pen_manager);
    dialog->show();
}

void MainWindow::on_action_Save_triggered()
{
    canvas->img->save(QFileDialog::getSaveFileName(this,"保存"),"PNG");
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    this->canvas->keyPressEvent(event);
}

