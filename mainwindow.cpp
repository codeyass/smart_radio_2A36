#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "sponsors.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QPixmap>
#include <QtSql>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QSqlTableModel>

#include <QtWidgets/QApplication>
  #include <QtWidgets/QMainWindow>
  #include <QtCharts/QChartView>
  #include <QtCharts/QPieSeries>
  #include <QtCharts/QPieSlice>
  #include <QtCore/QDebug>
  QT_CHARTS_USE_NAMESPACE



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


   ui->tableView->setModel(S1.afficher());

   ui->labelstat->setWindowFlags(Qt::FramelessWindowHint);

 ui->labelstat->setMask((new QPixmap("C:/Users/MSI/Documents/semestre 1-2A/RADIO - Copie - Copie/IMG/stat.gif")) ->mask());
 QMovie * movie= new QMovie ("C:/Users/MSI/Documents/semestre 1-2A/RADIO - Copie - Copie/IMG/stat.gif");
 ui->labelstat->setMovie(movie);
 movie->start();


 ui->labelmic->setWindowFlags(Qt::FramelessWindowHint);

ui->labelmic->setMask((new QPixmap("C:/Users/MSI/Documents/semestre 1-2A/RADIO - Copie - Copie/IMG/MICGIF.gif")) ->mask());
QMovie * movie1= new QMovie ("C:/Users/MSI/Downloads/MICGIF.gif");
ui->labelmic->setMovie(movie1);
movie1->start();




   //stat





/*   QPieSeries *series = new QPieSeries();
         series->setHoleSize(0);
         series->append("JUMIA 6.82%", 6.82);
         QPieSlice *slice = series->append("DELICE 54.17%", 54.17);
         slice->setExploded();
         slice->setLabelVisible();
         series->append("CARREFOUR 39.003%", 39.003);
         //series->append("Carbs 56.4%", 56.4);

         QChartView *chartView = new QChartView();
         chartView->setRenderHint(QPainter::Antialiasing);
         chartView->chart()->setTitle("Rentabilite des sponsors");
         chartView->chart()->addSeries(series);
         chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
         chartView->chart()->setTheme(QChart::ChartThemeQt);
         chartView->chart()->legend()->setFont(QFont("Arial", 9));
         chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);


         QVBoxLayout *layout2 = new QVBoxLayout(ui->frame_S);
         layout2->addWidget(chartView);
         */

//pics
   QPixmap pix(":/image/IMG/Yellow Black Modern Podcast  Instagram Story.png");
  ui->label_pic->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));

  QPixmap pix1(":/image/IMG/loginicon.jpg");
 ui->login->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));

 QPixmap pix3(":/image/IMG/Yellow Black Modern Podcast  Instagram Story.png");
 ui->label_pic_2->setPixmap(pix3.scaled(500,500,Qt::KeepAspectRatio));

//image to data


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Ajouter_3_clicked()
{


    int ID_S=ui->lineEdit_id_5->text().toInt();
    QString NOM_P=ui->lineEdit_nomp_5->text();
    QString TYPE=ui->comboBox_stat->currentText();
    int PERIODE=ui->lineEdit_periode_5->text().toInt();
    float PRIX=ui->lineEdit_prix_5->text().toFloat();

    Sponsors S(ID_S,NOM_P,TYPE,PERIODE,PRIX);
    bool test=S.ajouter();

    if(test)
    {


        ui->tableView->setModel(S1.afficher());
       QMessageBox::information(nullptr, QObject::tr("OK"),
               QObject::tr("Ajout effectué\n"
                           "Click cancel to exit"), QMessageBox::Cancel);






    }
    else
    {
          ui->tableView->setModel(S1.afficher());
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                QObject::tr("Ajout non effectué\n"
                            "Click cancel to exit"), QMessageBox::Cancel);



    }


    ui->lineEdit_id_5->clear();
    ui->lineEdit_nomp_5->clear();

    ui->lineEdit_periode_5->clear();
    ui->lineEdit_prix_5->clear();


        }



void MainWindow::on_pushButton_supp_3_clicked()
{

        int ID_S=ui->lineEdit_supp_3->text().toInt();


        bool test=S1.supprimer(ID_S);
        if(test)
        {

  ui->tableView->setModel(S1.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                      QObject::tr("suppression effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


            }



else
{
              ui->tableView->setModel(S1.afficher());
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                        QObject::tr("suppression non effectuee.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


        }


        ui->lineEdit_supp_3->clear();


}




void MainWindow::on_pushButton_update_3_clicked()
{

        int ID_S=ui->lineEdit_id_6->text().toInt();
        QString NOM_P=ui->lineEdit_nomp_6->text();
         QString TYPE=ui->comboBox_stat_2->currentText();
          int PERIODE=ui->lineEdit_periode_6->text().toInt();
          float PRIX=ui->lineEdit_prix_6->text().toFloat();

          Sponsors S(ID_S,NOM_P,TYPE,PERIODE,PRIX);
         bool test= S.modifier();
         if(test)
         {
               ui->tableView->setModel(S1.afficher());

             QMessageBox::information(nullptr, QObject::tr("ok"),
                         QObject::tr("modification effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);




     }
         else
         {
               ui->tableView->setModel(S1.afficher());
             QMessageBox::critical(nullptr, QObject::tr("not ok"),
                         QObject::tr("modification non effectue.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


         }


         ui->lineEdit_id_6->clear();
         ui->lineEdit_nomp_6->clear();

         ui->lineEdit_periode_6->clear();
         ui->lineEdit_prix_6->clear();

}


void MainWindow::on_Chercher_2_clicked()
{

    QString variable;
                if(ui->comboBox_sponsor_2->currentText()=="id sponsor")
                {
                 variable="ID_S";
                }
                if(ui->comboBox_sponsor_2->currentText()=="nom partenaire")
                {
                 variable="NOM_P";
                }
                if(ui->comboBox_sponsor_2->currentText()=="type")
                {
                 variable="TYPE";
                }


                Sponsors s;
                QSqlQueryModel *model =s.search_sponsor(ui->lineEdit_ch_2->text(),variable);
                ui->tableView->setModel(model);



             //  ui->tableView->setModel(s.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr("Generation PDF avec succes.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


    QString ID_S;
                QString NOM_P,TYPE;
                QString PERIODE;
                QString PRIX;
                ID_S=ui->lineEdit_id_5->text();
                NOM_P=ui->lineEdit_nomp_5->text();
                 TYPE=ui->comboBox_stat->currentText();
                 PERIODE=ui->lineEdit_periode_5->text();
                 PRIX=ui->lineEdit_prix_5->text();

                QPdfWriter pdf("C:/Users/MSI/Documents/semestre 1-2A/RADIO - Copie - Copie/sponsor.pdf");
                QPainter painter(&pdf);

                painter.setPen(Qt::red);
                painter.drawText(4000,400,"sponsor N°:  "+ID_S+"" );

                painter.setPen(Qt::black);
                painter.drawText(3500,2100,"Nom partenaire : "+NOM_P+"" );
                painter.drawText(3500,2500,"Type : "+TYPE+"" );
                painter.drawText(3500,2900,"Periode : "+PERIODE+"" );
                painter.drawText(3500,3200,"Prix : "+PRIX+"" );


                painter.end();
}




void MainWindow::on_TRI_2_clicked()
{
    QString variable;
    if(ui->comboBox_tri_2->currentText()=="id sponsor")
    {
     variable="ID_S";
    }
    if(ui->comboBox_tri_2->currentText()=="nom partenaire")
    {
     variable="NOM_P";
    }

    if(ui->comboBox_tri_2->currentText()=="Type")
    {
     variable="TYPE";
    }

    if(ui->comboBox_tri_2->currentText()=="Periode")
    {
     variable="PERIODE";
    }

    if(ui->comboBox_tri_2->currentText()=="Prix")
    {
     variable="PRIX";
    }


    Sponsors s;
    QSqlQueryModel *model =s.trier(variable);
    ui->tableView->setModel(model);

}

void MainWindow::on_menu_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::on_pushButton_login_clicked()
{
    QString username=ui->lineEdit_username_1->text();
        QString password=ui->lineEdit_password->text();

        if(username=="test" && password=="test")
        {


            QMessageBox::information(this,"Login","Username and Password are correct");
            //hide();
             ui->stackedWidget->setCurrentIndex(0);


        }

        else


            QMessageBox::warning(this,"Login","Username and Password are not correct");

        ui->lineEdit_password->clear();
        ui->lineEdit_username_1->clear();
}




void MainWindow::on_pushButton_S_clicked()
{

   ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_menu_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_commandLinkButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}





void MainWindow::on_photo_2_clicked()
{


QString NOM_P=ui->lineEdit_im->text();

   if(NOM_P=="JUMIA")
   {
       QSqlQuery query;



  if ( !query.exec( "SELECT (IMG1) from IMG_SPONSORS" ))

                          qDebug() << "Error getting image from table:\n" << query.lastError();
                      query.first();


                      // Display image
                      QPixmap p("C:/Users/MSI/Desktop/SQL_loader/jumia.png");
                      ui->mylabel->setPixmap( p );



   }

   if(NOM_P=="CARREFOUR")
   {

  QSqlQuery query;

                  if( !query.exec( "SELECT IMG2 from IMG_SPONSORS" ))
                          qDebug() << "Error getting image from table:\n" << query.lastError();
                      query.first();
                     /* QByteArray outByteArray = query.value( 0 ).toByteArray();
                      QPixmap outPixmap = QPixmap();
                      outPixmap.loadFromData( outByteArray );

*/
                      // Display image
                      QPixmap p("C:/Users/MSI/Desktop/SQL_loader/carrefour.png");


                      ui->mylabel->setPixmap( p );
                     // QLabel myLabel;
                    //  myLabel.setPixmap( outPixmap );
                      //myLabel.show();

   }

   if(NOM_P=="DELICE")
   {

  QSqlQuery query;

                  if( !query.exec( "SELECT IMG3 from IMG_SPONSORS" ))
                          qDebug() << "Error getting image from table:\n" << query.lastError();
                      query.first();
                     /* QByteArray outByteArray = query.value( 0 ).toByteArray();
                      QPixmap outPixmap = QPixmap();
                      outPixmap.loadFromData( outByteArray );


                      // Display image
                      QLabel myLabel;
                      myLabel.setPixmap( outPixmap );
                      myLabel.show();
                      */

                      QPixmap p("C:/Users/MSI/Desktop/SQL_loader/delice.png");


                      ui->mylabel->setPixmap( p.scaled(1700,1000,Qt::KeepAspectRatio) );

   }

}

void MainWindow::on_spot_clicked()
{
    QString NOM_P=ui->lineEdit_im->text();

       if(NOM_P=="JUMIA")
       {
           QMediaPlayer* player= new QMediaPlayer;
           QVideoWidget* vw=new QVideoWidget;

           player->setVideoOutput(vw);
           player->setMedia(QUrl::fromLocalFile("C:/Users/MSI/Desktop/mediaC++/videojumia.mpg"));
           vw->setGeometry(100,100,300,400);
           vw->show();
           player->play();
           qDebug() <<player->state();

       }


       if(NOM_P=="CARREFOUR")
       {
           QMediaPlayer* player= new QMediaPlayer;
           QVideoWidget* vw=new QVideoWidget;

           player->setVideoOutput(vw);
           player->setMedia(QUrl::fromLocalFile("C:/Users/MSI/Desktop/mediaC++/videocarrefour.mpg"));
           vw->setGeometry(100,100,300,400);
           vw->show();
           player->play();
           qDebug() <<player->state();

       }


       if(NOM_P=="DELICE")
       {
           QMediaPlayer* player= new QMediaPlayer;
           QVideoWidget* vw=new QVideoWidget;

           player->setVideoOutput(vw);
           player->setMedia(QUrl::fromLocalFile("C:/Users/MSI/Desktop/mediaC++/videodelice.mpg"));
           vw->setGeometry(100,100,300,400);
           vw->show();
           player->play();
           qDebug() <<player->state();

       }



}



void MainWindow::on_pushButton_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from sponsors where TYPE='Alimentaire' ");
     int number1=model->rowCount();

     model->setQuery("select * from sponsors where TYPE='Site de vente' ");
     int number2=model->rowCount();

     model->setQuery("select * from sponsors where TYPE='Centre commercial' ");
     int number3=model->rowCount(); // calculer le nombre de metier pour diercteur



     int total=number1+number2+number3;

     QString a = QString("Alimentaire"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Site de vente"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Centre commercial"+QString::number((number3*100)/total,'f',2)+"%" );



     QPieSeries *series = new QPieSeries();
     series->setHoleSize(0.3);


     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);


     if (number1!= 0)
     {


         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());



     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              //slice1->setExploded();
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              //slice1->setExploded();
              slice2->setLabelVisible();
     }


             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage Par TYPE de Sponsor :" " Nbr totale des sponsors :"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
             chartView->chart()->setTheme(QChart::ChartThemeQt);
              chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
              chartView->chart()->legend()->setFont(QFont("Arial", 9));
             chartView->show();


}


//try


