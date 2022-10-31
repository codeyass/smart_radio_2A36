#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>
#include "sponsors.h"
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //ui->tableView_S->setModel(S1.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_Ajouter_clicked()
{
    int ID_S=ui->lineEdit_id->text().toInt();
    QString NOM_P=ui->lineEdit_nomp->text();
    QString TYPE=ui->lineEdit_type->text();
    int PERIODE=ui->lineEdit_periode->text().toInt();
    float PRIX=ui->lineEdit_prix->text().toFloat();

    Sponsors S(ID_S,NOM_P,TYPE,PERIODE,PRIX);
    bool test=S.ajouter();
    if(test)
    {
       QMessageBox::information(nullptr, QObject::tr("OK"),
               QObject::tr("Ajout effectué\n"
                           "Click cancel to exit"), QMessageBox::Cancel);
       ///
ui->tableView_S->setModel(S.afficher());
dialog = new Dialog(this);
dialog->show();

hide();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("Ajout non effectué\n"
                            "Click cancel to exit"), QMessageBox::Cancel);
        ui->tableView_S->setModel(S.afficher());
        dialog = new Dialog(this);
        dialog->show();

    }

        }



void Dialog::on_pushButton_supp_clicked()
{

        int ID_S=ui->lineEdit_supp->text().toInt();

        bool test=S1.supprimer(ID_S);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_S->setModel(S1.afficher());
            dialog = new Dialog(this);
            dialog->show();
            hide();

            }



else
{
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_S->setModel(S1.afficher());
            dialog = new Dialog(this);
            dialog->show();

        }

}

void Dialog::on_pushButton_a_clicked()
{
    ui->tableView_S->setModel(S1.afficher());
}

void Dialog::on_pushButton_update_clicked()
{

        int ID_S=ui->lineEdit_id_2->text().toInt();
        QString NOM_P=ui->lineEdit_nomp_2->text();
          QString TYPE=ui->lineEdit_type_2->text();
          int PERIODE=ui->lineEdit_periode_2->text().toInt();
          float PRIX=ui->lineEdit_prix_2->text().toFloat();

          Sponsors S(ID_S,NOM_P,TYPE,PERIODE,PRIX);
         bool test= S.modifier();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("modification effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_S->setModel(S.afficher());
             dialog = new Dialog(this);
             dialog->show();
             hide();


     }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("modification non effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_S->setModel(S.afficher());
             dialog = new Dialog(this);
             dialog->show();

         }

}

