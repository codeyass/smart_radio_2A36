#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

employe::employe(int id,QString NOM_P, QString PRENOM_P, int NUMTEL, int AGE)
{
    this->ID_P=id;
    this->NOM_P=NOM_P;
    this->PRENOM_P=PRENOM_P;
    this->NUMTEL=NUMTEL;
    this->AGE=AGE;

}

 QString employe::getNOM_P(){return NOM_P;}
 QString employe::getPRENOM_P(){return PRENOM_P;}
 int employe::getID_P(){return ID_P;}
 int employe::getNUMTEL(){return NUMTEL;}
 int employe::getAGE(){return AGE;}

 void employe::setNOM_P(QString n){this->NOM_P=n;}
 void employe::setPRENOM_P(QString p){this->PRENOM_P=p;}
 void employe::setID_P(int id){this->ID_P=id;}
 void employe::setNUMTEL(int NUMTEL){this->NUMTEL=NUMTEL;}
 void employe::setAGE(int AGE){this->AGE=AGE;}

bool employe::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(ID_P);
    query.prepare("INSERT INTO EMPLOYES(ID_P,PRENOM_P,NOM_P,NUMTEL,AGE)"
                  "VALUES (:ID_P,:PRENOM_P,:NOM_P,:NUMTEL,:AGE)");
    query.bindValue(":ID_P",id_string);
    query.bindValue(":PRENOM_P",PRENOM_P);
    query.bindValue(":NOM_P",NOM_P);
    query.bindValue(":NUMTEL",NUMTEL);
    query.bindValue(":AGE",AGE);

    return query.exec();

}

QSqlQueryModel * employe :: afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM EMPLOYES ORDER BY AGE");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_P"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM_P"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM_P"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("AGE"));


    return model;
}

bool employe::supprimer(int ID_P)
{
    QSqlQuery query;
    QString id_string= QString::number(ID_P);
    query.prepare("Delete from EMPLOYES where ID_P=:ID_P");
    query.bindValue(":ID_P",id_string);

    return query.exec();

}

bool employe::modifier(int id)
 {
    QSqlQuery query;

    QString id_string=QString::number(id);


       query.prepare( "UPDATE EMPLOYES SET ID_P=:id_string, PRENOM_P=:PRENOM_P, NOM_P=:NOM_P, NUMTEL=:NUMTEL, AGE=:AGE"
                         "WHERE id_string=:ID_P");

             query.bindValue(":ID_P",id_string);
             query.bindValue(":PRENOM_P",PRENOM_P);
             query.bindValue(":NOM_P", NOM_P);
             query.bindValue(":NUMTEL",NUMTEL);
             query.bindValue(":AGE",AGE);

   return query.exec();

}

