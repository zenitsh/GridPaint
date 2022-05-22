#ifndef PLPCOLORFORM_H
#define PLPCOLORFORM_H

#include <QWidget>
#include <QListWidgetItem>
#include "plpsettings.h"

namespace Ui {
class PlpColorForm;
}

class PlpColorForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlpColorForm(QWidget *parent = nullptr, PlpSettings* settings = nullptr);
    ~PlpColorForm();

private slots:
    void on_sl_h_sliderMoved(int position);

    void on_sl_s_sliderMoved(int position);

    void on_sl_v_sliderMoved(int position);

    void on_sl_a_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::PlpColorForm *ui;
    PlpSettings *m_settings;
    void refresh();
};

#endif // PLPCOLORFORM_H
