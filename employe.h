#ifndef EMPLOYE_H
#define EMPLOYE_H


#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class employe
{
   QString NOM_P, PRENOM_P;
   int ID_P, NUMTEL, AGE,id;
public:
   employe(){};
   employe(int,QString,QString,int,int);

   QString getNOM_P();
   QString getPRENOM_P();
   int getID_P();
   int getNUMTEL();
   int getAGE();

   void setNOM_P(QString n);
   void setPRENOM_P(QString p);
   void setID_P(int ID_P);
   void setNUMTEL(int NUMTEL);
   void setAGE(int AGE);

   bool ajouter();
   QSqlQueryModel * afficher();
   bool supprimer(int);
   bool modifier (int id);

};

#endif // EMPLOYE_H