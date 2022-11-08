#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include "sponsors.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    Dialog();
   ~Dialog();




private slots:


    void on_Ajouter_2_clicked();



    void on_pushButton_supp_2_clicked();

   // void on_pushButton_a_clicked();

    void on_pushButton_update_2_clicked();

    void on_Chercher_clicked();

    void on_PDF_clicked();

private:
    Ui::Dialog *ui;
    Sponsors S1;
    Dialog * dialog;
};

#endif // DIALOG_H
