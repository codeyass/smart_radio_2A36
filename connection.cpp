#include "connection.h"
#include <QSqlDatabase>


connection::connection()
{

}


bool connection::createconnect()
{bool test=false;
 db = QSqlDatabase::addDatabase("QODBC");

db.setDatabaseName("DataSource");
db.setUserName("MedAziz");//inserer nom de l'utilisateur
db.setPassword("19032002");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void connection::closeconnection(){db.close();}
