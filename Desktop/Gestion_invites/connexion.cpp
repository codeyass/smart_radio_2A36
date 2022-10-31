#include "connexion.h"
//test connexion
connexion::connexion(){}

bool connexion::createconnexion()
{
    db=QSqlDatabase::addDatabase("QODBC");
    bool test=false;
    db.setDatabaseName("Gestion_invites");
    db.setUserName("nousseiba");
    db.setPassword("esprit18");

    if(db.open())
        test=true;
    return test;
}

void connexion::closeconnexion()
{
    db.close();
}
