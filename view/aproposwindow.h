#ifndef APROPOSWINDOW_H
#define APROPOSWINDOW_H

#include <QDialog>

namespace Ui {
class AProposWindow;
}

class AProposWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AProposWindow(QWidget *parent = nullptr);
    ~AProposWindow();

private slots:


    void on_btnRetour_clicked();

    void on_btnExporter_clicked();

private:
    Ui::AProposWindow *ui;
};

#endif // APROPOS_H
