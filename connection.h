#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtDebug>
class Connection
{
public:
    Connection();
    bool createconnect();
};

#endif // CONNECTION_H