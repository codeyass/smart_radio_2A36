#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>


class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool ouvrirconnection();
    void closeConnection();
};

#endif // CONNECTION_H

