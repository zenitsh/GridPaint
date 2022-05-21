#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <plppenmanager.h>
#include <QLabel>
#include <QKeyEvent>
#include "plpsettings.h"
#include "ui/plpcanvas.h"
#include "dialog/plppeneditingdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_Pen_triggered();

    void on_action_Save_triggered();

    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QHBoxLayout *layout;
    QLabel *status;
    PlpSettings *settings;
    PlpCanvas *canvas;
    PlpPenManager *pen_manager;
};
#endif // MAINWINDOW_H
