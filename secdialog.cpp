#include "secdialog.h"
#include "ui_secdialog.h"
#include "arduino.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include "dialog.h"

Secdialog::Secdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Secdialog)
{

    ui->setupUi(this);

    //datas=A1.read_from_arduino();

    //if(datas=="1")
    //{


        QSqlQuery query;

        if(query.exec("SELECT ETAT FROM LOGIN"))
        {
            while (query.next())
            {
               //int Et= query.value("ETAT").toInt();
               // qDebug() << Et;
               ui->label_etat->setText(query.value("ETAT").toString());



            }


        }
     //}



}



Secdialog::~Secdialog()
{
    delete ui;
}



void Secdialog::on_continuer_clicked()
{
    Dialog d;
     d.setModal(true);
     d.exec();
 hide();
}
