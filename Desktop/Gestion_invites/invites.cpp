#include "INVITES.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

INVITES::INVITES()
{
    MAIL_I="%.%@%.%";

}
INVITES::INVITES(int cin,QString nom,QString prenom,QString metier,int Num_tel,QDate dt,QString mail,int duree)
{
    this->CIN_I=cin;
    this->NOM_I=nom;
    this->PRENOM_I=prenom;
    this->METIER_I=metier;
    this->DATE_I=dt;
    this->NUM_TEL_I=Num_tel;
    this->MAIL_I=mail;
    this->DUREE_I=duree;
}


int INVITES::getCIN_I(){return CIN_I;}
QString INVITES::getNOM_I(){return NOM_I;}
QString INVITES::getPRENOM_I(){return PRENOM_I;}
QString INVITES::getMETIER_I(){return METIER_I;}
int INVITES::getNUM_TEL_I(){return NUM_TEL_I;}
QDate INVITES::getDATE_I(){return DATE_I;}
QString INVITES::getMAIL_I() {return MAIL_I;}
int INVITES::getDUREE_I(){return DUREE_I;}


void INVITES::setCIN_I(int cin) {this->CIN_I=cin;}
void INVITES::setNOM_I(QString nom){this->NOM_I=nom;}
void INVITES::setPRENOM_I(QString prenom){this->PRENOM_I=prenom;}
void INVITES::setMETIER_I(QString metier){this->METIER_I=metier;}
void INVITES::setNUM_TEL_I(int Num_tel){this->NUM_TEL_I=Num_tel;}
void INVITES::setDATE_I(QDate dt){this->DATE_I=dt;}
void INVITES::setMAIL_I(QString mail){this->MAIL_I=mail;}
void INVITES::setDUREE_I(int duree){this->DUREE_I=duree;}

bool INVITES::ajouter()
{
    QSqlQuery query;
    QString CIN_I_string=QString::number(CIN_I);
    QString NUM_TEL_I_string=QString::number(NUM_TEL_I);
    QString DUREE_I_string=QString::number(DUREE_I);
          query.prepare("insert into INVITES (CIN_I, NOM_I, PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I) "
                        "values (:CIN_I, :NOM_I, :PRENOM_I, :METIER_I, :NUM_TEL_I, :DATE_I, :MAIL_I, :DUREE_I)");
          query.bindValue(":CIN_I",CIN_I_string);
          query.bindValue(":NOM_I",NOM_I);
          query.bindValue(":PRENOM_I",PRENOM_I);
          query.bindValue(":METIER_I",METIER_I);
          query.bindValue(":NUM_TEL_I",NUM_TEL_I_string);
          query.bindValue(":DATE_I",DATE_I);
          query.bindValue(":MAIL_I",MAIL_I);
          query.bindValue(":DUREE_I",DUREE_I_string);
          return query.exec();
}

QSqlQueryModel* INVITES::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(" SELECT * from INVITES");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("METIER"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("MAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("DUREE"));
    return model;
}

bool INVITES::supprimer(int CIN_I)
{
    QSqlQuery query;
    QString CIN_I_string=QString::number(CIN_I);
    query.prepare("Delete from INVITES where CIN_I= :CIN_I");
    query.bindValue(":CIN_I",CIN_I_string);
    return query.exec();

}

bool INVITES::modifier()
{

        QSqlQuery query;
        QString CIN_I_string=QString::number(CIN_I);
        QString DUREE_I_string=QString::number(DUREE_I);
        QString NUM_TEL_I_string=QString::number(NUM_TEL_I);
        query.prepare("update INVITES set DATE_I=:DATE_I, DUREE_I= :DUREE_I , MAIL_I= :MAIL_I , NUM_TEL_I= :NUM_TEL_I where CIN_I=:CIN_I");
        query.bindValue(":CIN_I",CIN_I_string);
        query.bindValue(":DATE_I",DATE_I);
        query.bindValue(":DUREE_I",DUREE_I_string);
        query.bindValue(":MAIL_I",MAIL_I);
        query.bindValue(":NUM_TEL_I",NUM_TEL_I_string);
       return query.exec();



}


QSqlQueryModel*  INVITES:: tri(QString variable)
{

    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="CIN_I")
     {
     model->setQuery("SELECT * FROM INVITES order by CIN_I  ");
     }
    if(variable=="NOM_I")
     {
     model->setQuery("SELECT * FROM INVITES order by NOM_I ");
     }
    if(variable=="PRENOM_I")
    {
    model->setQuery("SELECT * FROM INVITES order by PRENOM_I ");
    }
    if(variable=="METIER_I")
     {
     model->setQuery("SELECT * FROM INVITES order by METIER_I ");
     }
    if(variable=="DATE_I")
     {
     model->setQuery("SELECT * FROM INVITES order by DATE_I  ");
     }
    if(variable=="MAIL_I")
     {
     model->setQuery("SELECT * FROM INVITES order by MAIL_I  ");
     }
    if(variable=="NUM_TEL_I")
     {
     model->setQuery("SELECT * FROM INVITES order by NUM_TEL_I ");
     }
    if(variable=="DUREE_I")
     {
     model->setQuery("SELECT * FROM INVITES order by DUREE_I  ");
     }

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("METIER"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("MAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("NUM_TEL"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("DUREE"));

return model;
}

QSqlQueryModel* INVITES::recherche(QString chaine_search,QString variable)

{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    if(variable=="CIN_I")
     {
     model->setQuery("SELECT * FROM INVITES WHERE  (CIN_I like '"+chaine_search+"%""')  ");
     }
    if(variable=="NOM_I")
     {
     model->setQuery("SELECT * FROM INVITES WHERE  (NOM_I like '"+chaine_search+"%""')  ");  //CHAINE ELI NEKTEB FEHA FEL LINE EDIT
     }
    if(variable=="PRENOM_I")
     {
     model->setQuery("SELECT * FROM INVITES WHERE  (PRENOM_I like '"+chaine_search+"%""')  ");  //CHAINE ELI NEKTEB FEHA FEL LINE EDIT
     }
    if(variable=="DATE_I")
     {
     model->setQuery("SELECT * FROM INVITES WHERE  (DATE_I like '"+chaine_search+"%""')  ");
     }
    if(variable=="METIER_I")
     {
     model->setQuery("SELECT * FROM INVITES WHERE  (METIER_I like '"+chaine_search+"%""')  ");
     }


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("METIER"));


        return  model;
}

