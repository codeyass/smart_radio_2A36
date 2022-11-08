#ifndef EMISSION_H
#define EMISSION_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
class Emission
{
private:
    int id,duree;
QString nomEm, typeEm;
QDate dateEm;
public:
    Emission();
    Emission(int,QString,QString,QDate,int);


    //getters
    int getId(){return id;}
    int getDuree(){return duree;}
    QString getNom(){return nomEm;}
    QString getType(){return typeEm;}
    QDate getDate(){return dateEm;}

    //Setters
    void setId(int id){this->id=id;}
    void setNom(QString nomEm){this->nomEm=nomEm;}
    void setType(QString typeEm){this->typeEm=typeEm;}
    void setDate(QDate dateEm){this->dateEm=dateEm;}
    void setDuree(int duree){this->duree=duree;}

   bool ajouter();
   QSqlQueryModel* afficher();
   bool supprimer(int);
   bool modifier();
   QSqlQueryModel * GetAllId();
   Emission* readEmission (QString val);


};

#endif // EMISSION_H
