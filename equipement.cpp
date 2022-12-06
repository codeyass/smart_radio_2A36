#include "equipement.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include<QPdfWriter>
#include<QPainter>
#include "arduino.h"
#include <QDateTime>

Equipement::Equipement()
{
    etat=0;id=0; nom="";marque="";type="";
}
Equipement::Equipement(int id,int etat,QString nom,QString marque,QString type)
{this->id=id;this->etat=etat;this->nom=nom;this->marque=marque;this->type=type;}
int Equipement::getid(){return id;}
int Equipement:: getetat(){return etat;};
QString Equipement::getnom(){return nom;}
QString Equipement:: gettype(){return type;}
QString Equipement::getmarque(){return marque;}


void Equipement::setid(int id){this->id=id;}
void Equipement::setetat(int etat){this->etat=etat;}
void Equipement::setnom(QString nom){this->nom=nom;}
void Equipement::settype(QString type){this->type=type;}
void Equipement::setmarque(QString marque){this->marque=marque;}


bool Equipement::ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(id);
    QString etat_string = QString::number(etat);

    query.prepare("INSERT INTO EQUIPMENTS(ID,NOM,TYPE,MARQUE,ETAT)"
                  "values (:ID,:NOM,:TYPE,:MARQUE,:ETAT)");
    query.bindValue(":ID",id_string);
    query.bindValue(":NOM",nom);
    query.bindValue(":TYPE",type);
    query.bindValue(":MARQUE",marque);
    query.bindValue(":ETAT",etat_string);

    query.exec();


    QString sDate = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
    QString action = "un equipement avec identifiant id = "+ id_string+" est ajoute";
    query.prepare("INSERT INTO LOG(DATE_ACTION,ACTION)"
                  "values (:DATE_ACTION,:ACTION)");
    query.bindValue(":DATE_ACTION",sDate);
    query.bindValue(":ACTION",action);

    return query.exec();

}
bool Equipement::supprimer(int id)
{
    QSqlQuery query;
    QString id_string = QString::number(id);

    query.prepare("DELETE FROM EQUIPMENTS where id=:id");
    query.bindValue(":id",id_string);

    query.exec();

    QString sDate = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
    QString action = "un equipement avec identifiant id = "+ id_string+" est supprime";
    query.prepare("INSERT INTO LOG(DATE_ACTION,ACTION)"
                  "values (:DATE_ACTION,:ACTION)");
    query.bindValue(":DATE_ACTION",sDate);
    query.bindValue(":ACTION",action);

    return query.exec();


}
QSqlQueryModel* Equipement::afficher()
{

    QSqlQueryModel* model= new QSqlQueryModel;
    model->setQuery("SELECT ID, NOM,TYPE, MARQUE,ETAT FROM EQUIPMENTS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Marque"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Etat"));



    return model;

}
bool Equipement::modifier(int id,int etat)
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(etat);

    query.prepare("Update EQUIPMENTS set ID = :ID , NOM = :NOM , TYPE = :type , MARQUE  = :marque , ETAT = :etat  where ID = :ID ");
    query.bindValue(":ID", res);
    query.bindValue(":NOM", nom);
    query.bindValue(":type", type);
    query.bindValue(":marque", marque);
    query.bindValue(":etat", res1);
    query.exec();

    QString sDate = QDateTime::currentDateTime().toString("dd-MM-yyyy hh:mm:ss");
    QString action = "un equipement avec identifiant id = "+ res +" est modifie";
    query.prepare("INSERT INTO LOG(DATE_ACTION,ACTION)"
                  "values (:DATE_ACTION,:ACTION)");
    query.bindValue(":DATE_ACTION",sDate);
    query.bindValue(":ACTION",action);

    return query.exec();
}
void recherche(QTableView * table, QString);


 void Equipement::recherche(QTableView * table, QString rech)

 {

     QSqlQueryModel *model= new QSqlQueryModel();

     QSqlQuery *query=new QSqlQuery;

         query->prepare("select * from EQUIPMENTS where ID like '%"+rech+"%' or MARQUE like '%"+rech+"%' ;");

         query->exec();

         model->setQuery(*query);

         table->setModel(model);

         table->show();

 }




  QSqlQueryModel * Equipement::trienom()

  {

      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM EQUIPMENTS ORDER BY NOM");

      model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID"));

      model->setHeaderData(1, Qt::Horizontal, QObject:: tr("NOM"));

      model->setHeaderData(2, Qt::Horizontal, QObject:: tr("TYPE"));

      model->setHeaderData(3, Qt::Horizontal, QObject:: tr("MARQUE"));

      model->setHeaderData(4, Qt::Horizontal, QObject:: tr("ETAT"));




      return model;

  }
  void  Equipement::telechargerPDF(){

                        QPdfWriter pdf("C:/Users/amena/OneDrive/Bureau/Export PDF/PDF.pdf");



                        QPainter painter(&pdf);
                       int i = 4000;



                            painter.setPen(Qt::blue);
                             painter.setFont(QFont("Century Gothic",35,QFont::Bold));
                            painter.drawText(2000,1500,"LISTES DES EQUIPMENTS");
                            painter.setPen(Qt::black);
                            painter.drawRect(0,2700,9600,500);
                            painter.setFont(QFont("Calibri",14,QFont::Bold));
                            painter.drawText(200,3000,"id");
                            painter.drawText(1800,3000,"nom");
                            painter.drawText(3100,3000,"type");
                            painter.drawText(4900,3000,"marque");
                            painter.drawText(6800,3000,"etat");


                            QSqlQuery query;

                            query.prepare("select ID, NOM,TYPE,MARQUE,ETAT from EQUIPMENTS");
                            query.exec();
                            while (query.next())
                            {
                                   painter.setFont(QFont("Calibri",13));
                                painter.drawText(200,i,query.value(1).toString());
                                painter.drawText(1800,i,query.value(0).toString());
                                painter.drawText(3200,i,query.value(2).toString());
                                painter.drawText(4900,i,query.value(3).toString());
                                painter.drawText(6900,i,query.value(4).toString());
                                painter.drawText(8600,i,query.value(5).toString());



                               i = i + 500;
                            }}
  QSqlQueryModel * Equipement::suivie()

  {

      QSqlQueryModel * model=new QSqlQueryModel();

      model->setQuery("SELECT type, COUNT(ETAT) as Panne FROM EQUIPMENTS where ETAT = 0 GROUP BY TYPE");

    //
      model->setHeaderData(0, Qt::Horizontal, QObject:: tr("TYPE"));





      return model;

  }

