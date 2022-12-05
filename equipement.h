#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include<QSqlQueryModel>
#include <QString>
#include<QTableView>
#include "arduino.h"

class Equipement
{
public:
    Equipement();
    Equipement(int,int,QString,QString,QString);
    int getid();
    int getetat();
    QString getnom();
    QString gettype();
    QString getmarque();

    void setid(int);
    void setetat(int);
    void setnom(QString);
    void settype(QString);
    void setmarque(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int);
    void recherche(QTableView * table, QString);
    QSqlQueryModel * trienom();
    void telechargerPDF();
    QSqlQueryModel * suivie();
    void on_refreshButton_clicked();
    void on_offButton_clicked();



private:
    int id,etat;
    QString nom,marque,type;

};

#endif // EQUIPEMENT_H
