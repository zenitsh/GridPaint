#ifndef PLPPENEDITINGDIALOG_H
#define PLPPENEDITINGDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <plppenmanager.h>

namespace Ui {
class PlpPenEditingDialog;
}

class PlpPenEditingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PlpPenEditingDialog(QWidget *parent = nullptr);
    ~PlpPenEditingDialog();
    void init(PlpPenManager *mgr);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

    void on_sizev_valueChanged(double arg1);

    void on_alphav_valueChanged(double arg1);

private:
    Ui::PlpPenEditingDialog *ui;
    PlpPenManager *m_mgr;
    QListWidget *listwidget;
    PlpPen *m_c_pen;
};

#endif // PLPPENEDITINGDIALOG_H
