#ifndef SPONSORS_H
#define SPONSORS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Sponsors
{
public:
    Sponsors();
    Sponsors(int,QString,QString,int,float);
    int getid_s();
    QString gettype();
    QString getnom_p();
    float getprix();
    int getperiode();

    void setid_s(int);
    void setperiode(int);
    void setprix(float);
    void setnom_p(QString);
    void settype(QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* search_sponsor(QString ,QString);
    QSqlQueryModel*   trier(QString);

bool afficher_image(QString);

private:

int ID_S;
float PRIX;
int PERIODE;
QString TYPE;
QString NOM_P;




};

#endif // SPONSORS_H
