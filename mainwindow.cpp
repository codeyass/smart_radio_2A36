#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QLineEdit>
#include <QPdfWriter>
#include <QPainter>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0, 9999999, this));
    ui->tabEmploye->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int ID_P=ui->lineEdit->text().toInt();
    QString PRENOM_P=ui->lineEdit_3->text();
    QString NOM_P=ui->lineEdit_2->text();
    int NUMTEL=ui->lineEdit_6->text().toInt();
    int AGE=ui->lineEdit_5->text().toInt();

    employe E(ID_P,PRENOM_P,NOM_P,NUMTEL,AGE);
    bool test=E.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué§\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{   employe E1;
    int id=ui->lineEdit_4->text().toInt();
    bool test=E1.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectué§\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Supprission non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
        int id= ui->lineEdit->text().toInt();
        QString PRENOM_P=ui->lineEdit_3->text();
        QString NOM_P=ui->lineEdit_2->text();
        int NUMTEL=ui->lineEdit_6->text().toInt();
        int AGE=ui->lineEdit_5->text().toInt();
        employe E(id,PRENOM_P,NOM_P,NUMTEL,AGE);

        bool test=E.modifier(id);
        if(test)
            {

                QMessageBox::information(nullptr,QObject::tr(" OK"),
                                         QObject::tr("Modification effectuée\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);

               ui->tabEmploye->setModel(E.afficher());
            }
            else
               QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                         QObject::tr("Modification non effectué\n"
                                                     "Click Cancel to exit."),QMessageBox::Cancel);
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
}



void MainWindow::on_PDF_pb_clicked()
{
    QString id=ui->lineEdit->text();
        QString nom=ui->lineEdit_2->text();
        QString prenom=ui->lineEdit_3->text();
         QString numtel =ui->lineEdit_6->text();
         QString age =ui->lineEdit_5->text();

        QPdfWriter pdf("C:/Users/MSI/Desktop/Employe/CRUD.pdf");
         QPainter painter(&pdf);


        int i = 4000;

             painter.setPen(Qt::blue);
             painter.setFont(QFont("Century Gothic",35,QFont::Bold));
             painter.drawText(2000,1500,"LISTES DES EMPLOYE");
             painter.setPen(Qt::black);
             painter.drawRect(0,2700,9600,500);
             painter.setFont(QFont("Calibri",14,QFont::Bold));
             painter.drawText(200,3000,"ID_P");
             painter.drawText(1800,3000,"NOM_P");
             painter.drawText(3100,3000,"PRENOM_P");
             painter.drawText(4900,3000,"NUMERO TEL");
             painter.drawText(6800,3000,"AGE");




             QSqlQuery query;

             query.prepare("select * from EMPLOYES");
             query.exec();
             while (query.next())
             {
                    painter.setFont(QFont("Calibri",13));
                 painter.drawText(200,i,query.value(1).toString());
                 painter.drawText(1800,i,query.value(0).toString());
                 painter.drawText(3200,i,query.value(2).toString());
                 painter.drawText(4900,i,query.value(3).toString());
                 painter.drawText(6900,i,query.value(4).toString());


                i = i + 500;
             }

}

void MainWindow::on_pushButton_clicked()
{
    int num= ui->lineEdit_7->text().toInt();
    bool test=E.envoyersms(num);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("message envoyé.\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
          ui->textEdit->clear();
          ui->lineEdit_7->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Message non envoyé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
