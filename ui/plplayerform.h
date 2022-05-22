#ifndef PLPLAYERFORM_H
#define PLPLAYERFORM_H

#include <QWidget>
#include <plpsettings.h>

namespace Ui {
class PlpLayerForm;
}

class PlpLayerForm : public QWidget
{
    Q_OBJECT

public:
    explicit PlpLayerForm(QWidget *parent = nullptr, PlpSettings *settings = nullptr);
    ~PlpLayerForm();

private slots:
    void repaintTimer();

    void on_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::PlpLayerForm *ui;
    PlpSettings *m_settings;
};

#endif // PLPLAYERFORM_H
