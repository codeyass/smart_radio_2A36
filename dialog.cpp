#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>
#include "sponsors.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


   ui->tableView_S_3->setModel(S1.afficher());
   QPixmap pix2(":/image/IMG/search.jpg");
  ui->search->setPixmap(pix2.scaled(30,20,Qt::KeepAspectRatio));

          QPixmap pix3(":/image/IMG/pdf.jpg");
         ui->pdf->setPixmap(pix3.scaled(45,40,Qt::KeepAspectRatio));

}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_Ajouter_2_clicked()
{
    int ID_S=ui->lineEdit_id_3->text().toInt();
    QString NOM_P=ui->lineEdit_nomp_3->text();
    QString TYPE=ui->lineEdit_type_3->text();
    int PERIODE=ui->lineEdit_periode_3->text().toInt();
    float PRIX=ui->lineEdit_prix_3->text().toFloat();

    Sponsors S(ID_S,NOM_P,TYPE,PERIODE,PRIX);
    bool test=S.ajouter();
    if(test)
    {
       QMessageBox::information(nullptr, QObject::tr("OK"),
               QObject::tr("Ajout effectué\n"
                           "Click cancel to exit"), QMessageBox::Cancel);
       ///
ui->tableView_S_3->setModel(S.afficher());
dialog = new Dialog(this);
dialog->show();

hide();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("Ajout non effectué\n"
                            "Click cancel to exit"), QMessageBox::Cancel);
        ui->tableView_S_3->setModel(S.afficher());
        dialog = new Dialog(this);
        dialog->show();

    }

        }



void Dialog::on_pushButton_supp_2_clicked()
{

        int ID_S=ui->lineEdit_supp_2->text().toInt();

        bool test=S1.supprimer(ID_S);
        if(test)
        {

            QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_S_3->setModel(S1.afficher());
            dialog = new Dialog(this);
            dialog->show();
            hide();

            }



else
{
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_S_3->setModel(S1.afficher());
            dialog = new Dialog(this);
            dialog->show();

        }

}

/*void Dialog::on_pushButton_a_clicked()
{
    ui->tableView_S->setModel(S1.afficher());
}*/

void Dialog::on_pushButton_update_2_clicked()
{

        int ID_S=ui->lineEdit_id_4->text().toInt();
        QString NOM_P=ui->lineEdit_nomp_4->text();
          QString TYPE=ui->lineEdit_type_4->text();
          int PERIODE=ui->lineEdit_periode_4->text().toInt();
          float PRIX=ui->lineEdit_prix_4->text().toFloat();

          Sponsors S(ID_S,NOM_P,TYPE,PERIODE,PRIX);
         bool test= S.modifier();
         if(test)
         {
             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("modification effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_S_3->setModel(S.afficher());
             dialog = new Dialog(this);
             dialog->show();
             hide();


     }
         else
         {
             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("modification non effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tableView_S_3->setModel(S.afficher());
             dialog = new Dialog(this);
             dialog->show();

         }

}


void Dialog::on_Chercher_clicked()
{
    QString variable;
                if(ui->comboBox_sponsor->currentText()=="id sponsor")
                {
                 variable="ID_S";
                }
                if(ui->comboBox_sponsor->currentText()=="nom partenaire")
                {
                 variable="NOM_P";
                }
                if(ui->comboBox_sponsor->currentText()=="type")
                {
                 variable="TYPE";
                }


                Sponsors s;
                QSqlQueryModel *model =s.search_sponsor(ui->lineEdit_ch->text(),variable);
                ui->tableView_S_3->setModel(model);
}

void Dialog::on_PDF_clicked()
{
    QString ID_S;
                QString NOM_P,TYPE;
                QString PERIODE;
                QString PRIX;
                ID_S=ui->lineEdit_id_3->text();
                NOM_P=ui->lineEdit_nomp_3->text();
                 TYPE=ui->lineEdit_type_3->text();
                 PERIODE=ui->lineEdit_periode_3->text();
                 PRIX=ui->lineEdit_prix_3->text();

                QPdfWriter pdf("C:/Users/MSI/Desktop/RADIO - Copie/sponsor.pdf");
                QPainter painter(&pdf);

                painter.setPen(Qt::red);
                painter.drawText(4000,400,"sponsor N°:  "+ID_S+"" );
                painter.setPen(Qt::black);
                painter.drawText(3500,2100,"Nom partenaire : "+NOM_P+"" );
                painter.drawText(3500,2500,"Type : "+TYPE+"" );
                painter.drawText(3500,2900,"Periode : "+PERIODE+"" );
                painter.drawText(3500,3200,"Prix : "+PRIX+"" );


                painter.end();
}
