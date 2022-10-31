#include "connection.h"
#include <QSqlDatabase>


connection::connection()
{

}


bool connection::createconnect()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("Projet2A");
db.setUserName("Yasmine");//inserer nom de l'utilisateur
db.setPassword("yasmine");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void connection::closeconnection(){db.close();}
