#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui1(new Ui::Dialog)
{
    ui1->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui1;
}

void Dialog::on_retourner_clicked()
{
  QSqlQuery query;

  if(query.exec("SELECT MDP FROM LOGIN"))
  {while (query.next())
      {
         QString mdp= query.value("MDP").toString();
          qDebug() << mdp;

          QString MDP_s=ui1->lineEditMDP->text();
          if(mdp==MDP_s)
          {

               MainWindow w;
               w.show();
               hide();
               ui1->lineEditMDP->clear();

          }

}
  }

}
