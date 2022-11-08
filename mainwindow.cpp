#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDate>
#include <QDateTime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_em->setModel(C.afficher());
    ui->cb_id_supp->setModel(C.GetAllId());
    ui->cb_id_modif->setModel(C.GetAllId());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajout_clicked()
{
    int id=ui->le_id->text().toInt();
       int duree=ui->le_duree->text().toInt();
       QString nom=ui->le_nom->text();
       QString type=ui->le_type->text();
       QDate date=ui->le_date->date();
        Emission C(id,nom,type,date,duree);
        bool test1 = ((controlId(id))&&(controlDuree(duree))&&(controlVide(nom))&&(controlVide(type)));

        if(test1)
        {
       bool test=C.ajouter();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("ajouter une emission"),
                                      QObject::tr("emission ajouté.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_em->setModel(C.afficher());
    ui->cb_id_supp->setModel(C.GetAllId());
    ui->cb_id_modif->setModel(C.GetAllId());
       }
       }       else
   { QMessageBox::critical(nullptr, QObject::tr("ajouter une emission"),
                              QObject::tr("emission non ajouté, vérifier les champs.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

void MainWindow::on_pushButton_2_clicked()
{
    int duro=ui->le_duree_modif->text().toInt();
       int id=ui->cb_id_modif->currentText().toInt();
       QString nom=ui->le_nom_modif->text();
       QString type=ui->le_type_modif->text();
       QDate date=ui->le_date_modif->date();
   Emission C(id,nom,type,date,duro);
   bool test1 = ((controlId(id))&&(controlDuree(duro))&&(controlVide(nom))&&(controlVide(type)));
        if(test1)
        {
       bool test=C.modifier();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("modifier un emission"),
                                      QObject::tr("emission modifié.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_em->setModel(C.afficher());
           ui->cb_id_supp->setModel(C.GetAllId());
           ui->cb_id_modif->setModel(C.GetAllId());

       }
       } else
   { QMessageBox::information(nullptr, QObject::tr("ajouter un emission"),
                              QObject::tr("emission non modifié, vérifier les champs.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

void MainWindow::on_pb_supprimer_clicked()
{
    QMessageBox msgBox;
       Emission C1;


C1.setId(ui->cb_id_supp->currentText().toInt());
           bool test=C1.supprimer(C1.getId());
       if(test)
         {  msgBox.setText("supprission avec succes.");
           ui->tab_em->setModel(C.afficher());
           ui->cb_id_supp->setModel(C.GetAllId());
           ui->cb_id_modif->setModel(C.GetAllId());
       }else
       { msgBox.setText("Echec de supprission");}
           msgBox.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    close();
}

void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_pushButton_5_clicked()
{
    close();
}





//control de saisie:

bool MainWindow::controlId(int id)
{
    QString id_string= QString::number(id);
    for(int i=0;i<id_string.length();i++)
    {
        if (id_string.length()==8)
        {
            return true;
        }
    }
    return false;
}





bool MainWindow::controlDuree(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()<=3)
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::controlVide(QString test)
{
    if(test!="")
        return  true;
    return false;
}












void MainWindow::on_cb_id_modif_activated(const QString &arg1)
{
    QString val=ui->cb_id_modif->currentText();
        Emission *EM;
        EM=C.readEmission(val);
          int id=EM->getId();
          int duree=EM->getDuree();
          QString id_string=QString::number(id);
          QString duree_string=QString::number(duree);


                ui->le_nom_modif->setText(EM->getNom());
                ui->le_type_modif->setText(EM->getType());
                ui->le_duree_modif->setText(duree_string);
}

void MainWindow::on_pushButton_13_clicked()
{

}

void MainWindow::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{

}
