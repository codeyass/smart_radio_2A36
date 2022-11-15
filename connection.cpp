#include "connection.h"

Connection::Connection()
{}

bool Connection::ouvrirconnection()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("DataSource");
db.setUserName("MedAziz");//inserer nom de l'utilisateur
db.setPassword("19032002");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
    return  test;
}
void Connection::closeConnection(){db.close();}
