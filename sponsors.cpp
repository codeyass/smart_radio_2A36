#include "sponsors.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include<QObject>



Sponsors::Sponsors()
{
ID_S=0;
PERIODE=0;
PRIX=0;
NOM_P="";
TYPE="";

}

Sponsors::Sponsors(int ID_S,QString NOM_P ,QString TYPE,int PERIODE,float PRIX)
{
    this->ID_S=ID_S;
    this->NOM_P=NOM_P;
    this->TYPE=TYPE;
    this->PERIODE=PERIODE;
    this->PRIX=PRIX;


}

int Sponsors::getid_s()
{return ID_S;
}

QString Sponsors::gettype()
{
  return TYPE ;
}


QString Sponsors::getnom_p() {return NOM_P;}
float Sponsors::getprix(){return PRIX;}
int Sponsors::getperiode(){return PERIODE;}

void Sponsors::setid_s(int)
{
   this->ID_S=ID_S;
}
void Sponsors::setperiode(int)
{

    this->PERIODE=PERIODE;
}

void Sponsors::setprix(float)
{
     this->PRIX=PRIX;
}
void Sponsors::setnom_p(QString)
{
      this->NOM_P=NOM_P;

}
void Sponsors::settype(QString)
{
     this->TYPE=TYPE;
}

bool Sponsors::ajouter()
{
    QSqlQuery query;
       QString id_string=QString::number(ID_S);
       QString periode_string=QString::number(PERIODE);
        QString prix_string=QString::number(PRIX);

             query.prepare("INSERT INTO sponsors (ID_S, NOM_P, TYPE,PERIODE,PRIX) "
                           "VALUES (:id, :forename, :surname, :surname1, :surname2)");
             query.bindValue(":id", id_string);
             query.bindValue(":forename", NOM_P);
             query.bindValue(":surname", TYPE);
             query.bindValue(":surname1", periode_string);
             query.bindValue(":surname2", prix_string);

             return  query.exec();
}

/*bool Sponsors::supprimer(int ID_S)
{
    QSqlQuery query;

          query.prepare("Delete from sponsors where ID_S=:ID_S");

          query.bindValue(0, ID_S);

          return  query.exec();
}
*/


bool Sponsors::supprimer(int selected){

    QSqlQuery query;
    query.prepare("Delete from sponsors where ID_S =: ID_S ");
    query.bindValue(0, selected);
    return    query.exec();


}



QSqlQueryModel * Sponsors::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

             model->setQuery("SELECT *  FROM sponsors");
             model->setHeaderData(0, Qt::Horizontal, QObject::tr("identenfiant"));
             model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("Periode"));


        return model;
}

bool Sponsors::modifier()
{
    QSqlQuery query;

    QString id_string=QString::number(ID_S);
    QString periode_string=QString::number(PERIODE);
     QString prix_string=QString::number(PRIX);

       query.prepare( "UPDATE sponsors SET ID_S=:ID_S  , NOM_P=:NOM_P  ,"
                        " TYPE=:TYPE, PERIODE=:PERIODE, PRIX=:PRIX  WHERE ID_S=:ID_S ");

             query.bindValue(":ID_S",id_string);
             query.bindValue(":NOM_P", NOM_P);
             query.bindValue(":TYPE",TYPE);
             query.bindValue(":PERIODE",periode_string);
             query.bindValue(":PRIX",prix_string);



   return query.exec();

}

QSqlQueryModel* Sponsors::search_sponsor(QString  chaine_search,QString variable)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="ID_S")
     {
     model->setQuery("SELECT * FROM sponsors WHERE  (ID_S like '"+chaine_search+"%""')  ");
     }
    if(variable=="NOM_P")
     {
     model->setQuery("SELECT * FROM sponsors WHERE  (NOM_P like '"+chaine_search+"%""')  ");  //CHAINE ELI NEKTEB FEHA FEL LINE EDIT
     }
    if(variable=="TYPE")
     {
     model->setQuery("SELECT * FROM sponsors WHERE  (TYPE like '"+chaine_search+"%""')  ");
     }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_S"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_P"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));


        return  model;
}



QSqlQueryModel*  Sponsors:: trier(QString variable)
{

QSqlQueryModel* model =new QSqlQueryModel();
QSqlQuery query;



if(variable=="ID_S")
 {
 model->setQuery("SELECT * FROM sponsors order by ID_S  ");
 }
if(variable=="NOM_P")
 {
 model->setQuery("SELECT * FROM sponsors order by NOM_P  ");  //CHAINE ELI NEKTEB FEHA FEL LINE EDIT
 }
if(variable=="TYPE")
 {
 model->setQuery("SELECT * FROM sponsors order by TYPE  ");
 }

if(variable=="PERIODE")
 {
 model->setQuery("SELECT * FROM sponsors order by PERIODE  ");
 }

if(variable=="PRIX")
 {
 model->setQuery("SELECT * FROM sponsors order by PRIX  ");
 }



model->setHeaderData(0,Qt::Horizontal,QObject::tr("id sponsor"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom partenaire"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("PERIODE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("PRIX"));

return model;
}






