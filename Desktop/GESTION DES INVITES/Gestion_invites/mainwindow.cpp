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
    ui->le_cin->setValidator(new QIntValidator(0,999999,this));
    ui->le_cin_modif->setValidator(new QIntValidator(0,999999,this));
    ui->Num_tel->setValidator(new QIntValidator(0,99999999,this));
    ui->la_duree->setValidator(new QIntValidator(0,99,this));
    ui->le_cin_supp->setValidator(new QIntValidator(0,999999,this));
    ui->afficher->setModel(I.afficher());
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
    int NUM_TEL_I=ui->Num_tel->text().toInt();
    QDate DATE_I=ui->la_date->date();
    QString MAIL_I=ui->mail->text();
    int DUREE_I=ui->la_duree->text().toInt();

    INVITES I(CIN_I,NOM_I,PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I);
    bool test=I.ajouter();
    if(test)
   {
        ui->afficher->setModel(I.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajout d'un invité"),QObject::tr("Ajout effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
   }
    else
        QMessageBox::critical(nullptr,QObject::tr("Ajout d'un invité"),QObject::tr("Ajout non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
    int CIN_I=ui->le_cin_supp->text().toInt();
    bool test=I.supprimer(CIN_I);
    if(test)
    {
        ui->afficher->setModel(I.afficher());
        QMessageBox::information(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
    int CIN_I=ui->le_cin_modif->text().toInt();
    QString NOM_I=ui->le_nom->text();
    QString PRENOM_I=ui->le_prenom->text();
    QString METIER_I=ui->le_metier->text();
    int NUM_TEL_I=ui->Num_tel->text().toInt();
    QDate DATE_I=ui->la_date_modif->date();
    QString MAIL_I=ui->mail->text();
    int DUREE_I=ui->la_duree_modif->text().toInt();
    INVITES I(CIN_I,NOM_I,PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I);
    bool test=I.modifier();
    if(test)
    {
        ui->afficher->setModel(I.afficher());
        QMessageBox::information(nullptr,QObject::tr("Modification d'un invité"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Modification d'un invité"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);


}

void MainWindow::on_quitter_ajout_clicked()
{
   close();
}

void MainWindow::on_quitter_supp_clicked()
{
    close();
}

void MainWindow::on_quitter_modif_clicked()
{
    close();
}
