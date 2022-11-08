#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "INVITES.h"
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->afficher->setModel(I.afficher());
    ui->le_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->num_tel->setValidator(new QIntValidator(0,99999999,this));
    ui->num_tel_modif->setValidator(new QIntValidator(0,99999999,this));
    ui->la_duree->setValidator(new QIntValidator(0,99,this));
    ui->la_duree_modif->setValidator(new QIntValidator(0,99,this));
    ui->cin_supp->setModel(I.afficher());
    ui->le_cin_modif->setModel(I.afficher());
    //ui->cher_2->setModel(I.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouter_clicked()
{
int CIN_I=ui->le_cin->text().toInt();
QString NOM_I=ui->le_nom->text();
QString PRENOM_I=ui->le_prenom->text();
QString METIER_I=ui->le_metier->text();
int NUM_TEL_I=ui->num_tel->text().toInt();
QDate DATE_I=ui->la_date->date();
QString MAIL_I=ui->mail->text();
int DUREE_I=ui->la_duree->text().toInt();

INVITES I(CIN_I,NOM_I,PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I);
bool test=I.ajouter();
if(test)
{       ui->afficher->setModel(I.afficher());

    QMessageBox::information(nullptr,QObject::tr("Ajout d'un invité"),QObject::tr("Ajout effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
    //ui->cher_2->setModel(I.afficher());
    ui->cin_supp->setModel(I.afficher());
    ui->le_cin_modif->setModel(I.afficher());
    ui->le_cin->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_metier->clear();
    ui->num_tel->clear();
    ui->la_date->clear();
    ui->mail->clear();
    ui->la_duree->clear();
}
else
    QMessageBox::critical(nullptr,QObject::tr("Ajout d'un invité"),QObject::tr("Ajout non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
int CIN_I=ui->cin_supp->currentText().toInt();

bool test=I.supprimer(CIN_I);
if(test)
{
    ui->afficher->setModel(I.afficher());
    QMessageBox::information(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
    //ui->cher_2->setModel(I.afficher());
    ui->le_cin_modif->setModel(I.afficher());
    ui->cin_supp->setModel(I.afficher());


}
else
    QMessageBox::critical(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
       int CIN_I=ui->le_cin_modif->currentText().toInt();
        QString NOM_I=ui->le_nom->text();
        QString PRENOM_I=ui->le_prenom->text();
        QString METIER_I=ui->le_metier->text();
        int NUM_TEL_I=ui->num_tel_modif->text().toInt();
        QDate DATE_I=ui->la_date_modif->date();
        QString MAIL_I=ui->mail_modif->text();
        int DUREE_I=ui->la_duree_modif->text().toInt();
        INVITES I(CIN_I,NOM_I,PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I);
        bool test=I.modifier();
        if(test)
        {
            ui->le_cin_modif->setModel(I.afficher());
            ui->afficher->setModel(I.afficher());
            QMessageBox::information(nullptr,QObject::tr("Modification d'un invité"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
            //ui->cher_2->setModel(I.afficher());
            ui->le_cin_modif->setModel(I.afficher());
            ui->num_tel_modif->clear();
            ui->la_date_modif->clear();
            ui->mail_modif->clear();
            ui->la_duree_modif->clear();

        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Modification d'un invité"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

}


void MainWindow::on_PDF_clicked()
{
QPrinter printer;

int CIN_I=ui->le_cin->text().toInt();
QString cin = QString::number(CIN_I);

QString NOM_I=ui->le_nom->text();
QString PRENOM_I=ui->le_prenom->text();
QString METIER_I=ui->le_metier->text();

int NUM_TEL_I=ui->num_tel->text().toInt();
QString num = QString::number(NUM_TEL_I);

QDate DATE_I=ui->la_date->date();
QString d=DATE_I.toString("dd.MM.yyyy");

QString MAIL_I=ui->mail->text();

int DUREE_I=ui->la_duree->text().toInt();
QString duree = QString::number(DUREE_I);


      printer.setOutputFormat(QPrinter::PdfFormat);
      printer.setOutputFileName("C:/Users/21627/Desktop/Gestion_invites/test.pdf");
      QPainter painter;
      if (! painter.begin(&printer))
      { // failed to open file
          qWarning("failed to open file, is it writable?");

      }

      painter.setPen(Qt::red);
      painter.drawText(10, 10, "CIN: ");
      painter.setPen(Qt::black);
      painter.drawText(70, 10, cin);
      painter.setPen(Qt::red);
      painter.drawText(10, 20, "Nom : ");
      painter.setPen(Qt::black);
      painter.drawText(70, 20, NOM_I);
      painter.setPen(Qt::red);
      painter.drawText(10, 30, "Prenom : ");
      painter.setPen(Qt::black);
      painter.drawText(70, 30, PRENOM_I);
      painter.setPen(Qt::red);
      painter.drawText(10, 40, "Metier : ");
      painter.setPen(Qt::black);
      painter.drawText(70, 40, METIER_I);
      painter.setPen(Qt::red);
      painter.drawText(10,50,"Date:");
      painter.setPen(Qt::black);
      painter.drawText(70,50, d);
      painter.setPen(Qt::red);
      painter.drawText(10,60, "MAIL:");
      painter.setPen(Qt::black);
      painter.drawText(70, 60, MAIL_I);
      painter.setPen(Qt::red);
      painter.drawText(10,70,"Num_tel:");
      painter.setPen(Qt::black);
      painter.drawText(70,70, num);
      painter.setPen(Qt::red);
      painter.drawText(10,80, "Durée:");
      painter.setPen(Qt::black);
      painter.drawText(70, 80,duree);

      QMessageBox::information(nullptr,QObject::tr("GENERATION PDF"),QObject::tr("PDF CREATED\n" "Click Cancel to quit"),QMessageBox::Cancel);

      if (! printer.newPage())

      {
          qWarning("failed in flushing page to disk, disk full?");
          painter.drawText(10, 10, "Test 2");
          QMessageBox::critical(nullptr,QObject::tr("GENERATION PDF"),QObject::tr("PDF NOT CREATED\n" "Click Cancel to quit"),QMessageBox::Cancel);
      }


      painter.end();
}


void MainWindow::on_chercher_clicked()
{
    QString variable;
                if(ui->cher->currentText()=="CIN")
                {
                 variable="CIN_I";

                }
                if(ui->cher->currentText()=="NOM")
                {
                 variable="NOM_I";

                }
                if(ui->cher->currentText()=="PRENOM")
                {
                 variable="PRENOM_I";


                }
                if(ui->cher->currentText()=="DATE")
                {
                 variable="DATE_I";


                }
                if(ui->cher->currentText()=="METIER")
                {
                 variable="METIER_I";


                }


                INVITES I;
                QSqlQueryModel *model =I.recherche(ui->cher_2->currentText(),variable);
                ui->afficher->setModel(model);
                //ui->cher_2->setModel(I.afficher());

                ui->lineedit_ch->clear();

}


void MainWindow::on_button_tri_clicked()
{
    QString variable;
                if(ui->tri->currentText()=="CIN")
                {
                 variable="CIN_I";
                }
                if(ui->tri->currentText()=="NOM")
                {
                 variable="NOM_I";
                }
                if(ui->tri->currentText()=="PRENOM")
                {
                 variable="PRENOM_I";
                }
                if(ui->tri->currentText()=="METIER")
                {
                 variable="METIER_I";
                }
                if(ui->tri->currentText()=="DATE")
                {
                 variable="DATE_I";
                }
                if(ui->tri->currentText()=="MAIL")
                {
                 variable="MAIL_I";
                }
                if(ui->tri->currentText()=="NUM_TEL")
                {
                 variable="NUM_TEL_I";
                }
                if(ui->tri->currentText()=="DUREE")
                {
                 variable="DUREE_I";
                }
                INVITES I;
                QSqlQueryModel *model =I.tri(variable);
                ui->afficher->setModel(model);
}
