#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <plppenmanager.h>
#include <QLabel>
#include <QKeyEvent>
#include <QDockWidget>
#include "plpsettings.h"
#include "ui/plpcanvas.h"
#include "plpcolorform.h"
#include "plplayerform.h"
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

    void on_action_Color_triggered();

    void on_action_Layer_triggered();

private:
    Ui::MainWindow *ui;
    QHBoxLayout *layout;
    QLabel *status;
    PlpSettings *settings;
    PlpCanvas *canvas;
    PlpPenManager *pen_manager;
    QDockWidget *dock_color_form;
    PlpColorForm *color_form;
    QDockWidget *dock_layer_form;
    PlpLayerForm *layer_form;
};
#endif // MAINWINDOW_H
