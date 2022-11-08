#include "emission.h"

Emission::Emission()
{
}
Emission::Emission(int id,QString nomEm,QString typeEm ,QDate dateEm,int duree)
{
this->id=id;
this->nomEm=nomEm;
this->typeEm=typeEm;
this->dateEm=dateEm;
this->duree=duree;
}
bool Emission:: ajouter()
{

    QSqlQuery query;



          query.prepare("INSERT INTO EMISSIONS "
                        "VALUES (:id, :nomem, :typeem, :dateem, :duree)");
          query.bindValue(":id", id);
          query.bindValue(":nomem", nomEm);
          query.bindValue(":typeem", typeEm);
           query.bindValue(":dateem", dateEm);
            query.bindValue(":duree", duree);


          return query.exec();
}

QSqlQueryModel* Emission::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM Emissions");

    return model;
}

bool Emission::supprimer(int id)
{
    QSqlQuery query;

          query.prepare("DELETE FROM Emissions where id=:id ");
          query.bindValue(":id", id);

    return query.exec();
}
bool Emission::modifier()
{


    QSqlQuery query;

    query.prepare("UPDATE emissions set  nomEm=:nomem ,typeEm =:typeem,dateEm=:dateem, duree=:duree WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":nomem", nomEm);
    query.bindValue(":typeem", typeEm);
     query.bindValue(":dateem", dateEm);
      query.bindValue(":duree", duree);
    return query.exec();
}



QSqlQueryModel *Emission::GetAllId()
{
    QSqlQueryModel * model =new QSqlQueryModel();
          model->setQuery("select id from emissions ");
          return model ;
}

Emission* Emission::readEmission (QString val)
{

 QSqlQuery query;
    query.prepare("Select * FROM Emissions where id='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {
               setId(query.value(0).toInt());
              setNom(query.value(1).toString());
             setType(query.value(2).toString());
             setDate(query.value(3).toDate());
              setDuree(query.value(4).toInt());
            }
        }
     return this;
}








