#include "historique.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QFileDialog>
#include <QTextDocument>
#include <QObject>
#include<QDate>
historique::historique()
{

}

historique::historique(QString b)
 {
    operation=b;
 }

void historique::Ajouter1()
{
    QSqlQuery query;


    query.prepare("INSERT INTO EQUIPMENTS(ID,NOM,TYPE,MARQUE,ETAT)"
                  "values (:ID,:NOM,:TYPE,:MARQUE,:ETAT)");
   query.bindValue(":ETAT",operation);


 query.exec();
}
QSqlQueryModel * historique::Afficher1( )
{
  QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("SELECT DATE_ACTION, ACTION FROM LOG");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("DATE_ACTION"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("ACTION"));



 return model;
}



