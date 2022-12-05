#include "connection.h"
#include <QSqlDatabase>


connection::connection()
{

}


bool connection::createconnect()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("Source_Projet_2A");
db.setUserName("nousseiba");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void connection::closeconnection(){db.close();}
