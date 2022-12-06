#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include <QtSql>
#include <QPixmap>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {
        w.show();
qDebug()<<"connection etablie";

}

     return a.exec();
}
