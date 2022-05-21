#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    layout = new QHBoxLayout(ui->centralwidget);
    canvas = new PlpCanvas(this);
    layout->addWidget(canvas);
    pen_manager = new PlpPenManager();
    status = new QLabel();
    status->setText("OK");
    this->statusBar()->addWidget(status);
}

MainWindow::~MainWindow()
{
    delete pen_manager;
    delete ui;
}


void MainWindow::on_action_Pen_triggered()
{
    PlpPenEditingDialog *dialog = new PlpPenEditingDialog();
    dialog->init(pen_manager);
    dialog->show();
}

