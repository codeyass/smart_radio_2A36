#ifndef INVITES_H
#define INVITES_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QDate>
//HEADER

class INVITES
{
public:
    //constructeurs

    INVITES();
    INVITES(int,QString,QString,QString,int,QDate,QString,int);

    //getters
    int getCIN_I();
    QString getNOM_I();
    QString getPRENOM_I();
    QString getMETIER_I();
    int getNUM_TEL_I();
   QDate getDATE_I();
   QString getMAIL_I();
   int getDUREE_I();

    //setters
    void setCIN_I(int);
    void setNOM_I(QString);
    void setPRENOM_I(QString);
    void setMETIER_I(QString);
     void setNUM_TEL_I(int);
    void setDATE_I(QDate);
    void setMAIL_I(QString);
    void setDUREE_I(int);

    //fonctions
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    //bool quitter_ajout();

private:
    int CIN_I;
    QString NOM_I;
    QString PRENOM_I;
    QString METIER_I;
    int NUM_TEL_I;
    QDate DATE_I;
    QString MAIL_I;
    int DUREE_I;
};

#endif // INVITES_H
