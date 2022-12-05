#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "dialog.h"
#include "secdialog.h"

#include <QString>
#include "sponsors.h"
#include "invites.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
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
#include <QIntValidator>

#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSqlQueryModel>
#include <QLineSeries>
#include "qrcode.hpp"
#include "smtp.h"

using namespace qrcodegen;
  QT_CHARTS_USE_NAMESPACE



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

// arduino yassmine
    int ret=A1.connect_arduino();
    switch (ret)
    {
    case(0):qDebug() <<"arduino is available and connected to :" <<A1.getarduino_port_name();
        break;
        case(1) :qDebug() <<"arduino is available but not connected to :" <<A1.getarduino_port_name();
        break;
    case(-1) : qDebug() <<"arduino is not available";

    }
     QObject::connect(A1.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


 //  arduinoo nousseiba et chaimaa

    int ret1=A.connect_arduino(); // lancer la connexion à arduino
      switch(ret1)
      {
      case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
          break;
      case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
         break;
      case(-1):qDebug() << "arduino is not available";
      }
       QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label_I())); // permet de lancer
       //le slot update_label suite à la reception du signal readyRead (reception des données).



   ui->tableView->setModel(S1.afficher());



   ui->afficher->setModel(I.afficher());
      ui->le_cin->setValidator(new QIntValidator(0,99999999,this));
      ui->num_tel->setValidator(new QIntValidator(0,99999999,this));
      ui->num_tel_modif->setValidator(new QIntValidator(0,99999999,this));
      ui->la_duree->setValidator(new QIntValidator(0,99,this));
      ui->la_duree_modif->setValidator(new QIntValidator(0,99,this));
      ui->cin_supp->setModel(I.afficher());
      ui->le_cin_modif->setModel(I.afficher());

//pics
   QPixmap pix(":/image/IMG/Yellow Black Modern Podcast  Instagram Story.png");
  ui->label_pic->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));

  QPixmap pix1(":/image/IMG/LOGIN.jpg");
 ui->login->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));

 QPixmap pix3(":/image/IMG/Yellow Black Modern Podcast  Instagram Story.png");
 ui->label_pic_2->setPixmap(pix3.scaled(500,500,Qt::KeepAspectRatio));

//gif
 ui->labelstat->setWindowFlags(Qt::FramelessWindowHint);

     ui->labelstat->setMask((new QPixmap("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/stat.gif")) ->mask());
     QMovie * movie= new QMovie ("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/stat.gif");
     ui->labelstat->setMovie(movie);
     movie->start();

     ui->label_stat2->setWindowFlags(Qt::FramelessWindowHint);
     ui->label_stat2->setMask((new QPixmap("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/IMG/stat.gif")) ->mask());
     QMovie * movie2= new QMovie ("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/stat.gif");
     ui->label_stat2->setMovie(movie2);
     movie2->start();


     ui->label_mailgif->setWindowFlags(Qt::FramelessWindowHint);
     ui->label_mailgif->setMask((new QPixmap("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/MAIL.gif")) ->mask());
     QMovie * movie3= new QMovie ("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/MAIL.gif");
     ui->label_mailgif->setMovie(movie3);
     movie3->start();


     ui->labelmic->setWindowFlags(Qt::FramelessWindowHint);
    ui->labelmic->setMask((new QPixmap("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/MICGIF.gif")) ->mask());
    QMovie * movie1= new QMovie ("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/MICGIF.gif");
    ui->labelmic->setMovie(movie1);
    movie1->start();

    ui->label_qrcode->setWindowFlags(Qt::FramelessWindowHint);
    ui->label_qrcode->setMask((new QPixmap("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/qrcode.gif")) ->mask());
    QMovie * movie4= new QMovie ("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/qrcode.gif");
    ui->label_qrcode->setMovie(movie4);
    movie4->start();


}

//arduinoo yassmine

void MainWindow::update_label()
{
    dataS=A1.read_from_arduino();

   if(dataS=="1")
    {


       // d.setModal(true);
        //d.exec();

       sec.setModal(true);
               sec.exec();
    }

       // ui->labelarduino->setText("ON AIR"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

}

// arduino chaima et nousseibaa
void MainWindow::update_label_I()
{
    dataI=A.read_from_arduino();

    qDebug() << dataI;

    if(c.length()+dataI.length()>12)
    {int j=0;
        for(int i=c.length();i<12;i++)
        {
            if(dataI[j]!='/' || dataI[j]!='r' || dataI[j]!='n' )
            c[i]=dataI[j];
            j++;
        }
        t++;
    }
    else
    {
        c+=dataI;
    }
    qDebug()<<c;
    QSqlQuery query;

    query =I.request(c);
    bool test = false;
    if(query.exec())
    {
        while(query.next())
        {
            test = true;
        }
    }
    if(test)
    {
        QMessageBox::information(this,"Login","Acess granted");
        //hide();
         ui->stackedWidget->setCurrentIndex(0);
         A.write_to_arduino("1");

    }
    else {
        if (c.length()==12)
        {
            A.write_to_arduino("2");
        }
    }

    if(c.length()>=12)
    {
        t=0;
        c="";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


//rest of the code

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

                QPdfWriter pdf("C:/Users/21627/Desktop/RADIO + arduino yassss/sponsor.pdf");
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

        ui->lineEdit_username_1->clear();
       ui->lineEdit_password->clear();
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
    ui->stackedWidget->setCurrentIndex(3);
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
                      QPixmap p("C:/Users/21627/Desktop/RADIO + arduino yass/affiche_video/jumia.png");
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
                      QPixmap p("C:/Users/21627/Desktop/RADIO + arduino yass/affiche_video/carrefour.png");


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

                      QPixmap p("C:/Users/21627/Desktop/RADIO + arduino yass/affiche_video/delice.png");


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
           player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Desktop/RADIO + arduino yass/affiche_video/videojumia.mpg"));
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
           player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Desktop/RADIO + arduino yass/affiche_video/videocarrefour.mpg"));
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
           player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Desktop/RADIO + arduino yass/affiche_video/videodelice.mpg"));
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


//*********************************************   INVITES  *********************************************************************************************
void MainWindow::on_pushButton_S_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_menu_3_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_ajouter_clicked()
{
int CIN_I=ui->le_cin->text().toInt();
QString NOM_I=ui->le_nom->text();
QString PRENOM_I=ui->le_prenom->text();
QString METIER_I=ui->le_metier->currentText();
int NUM_TEL_I=ui->num_tel->text().toInt();
QDate DATE_I=ui->la_date->date();
QString MAIL_I=ui->mail->text();
int DUREE_I=ui->la_duree->text().toInt();

INVITES I(CIN_I,NOM_I,PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I);
bool test=I.ajouter();
if(test)
{       ui->afficher->setModel(I.afficher());

    QMessageBox::information(nullptr,QObject::tr("Ajout d'un invité"),QObject::tr("Ajout effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
    ui->cin_supp->setModel(I.afficher());
    ui->le_cin_modif->setModel(I.afficher());
    ui->le_cin->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_metier->clear();
    ui->num_tel->clear();
    ui->la_date->clear();
    ui->mail->clear();
    ui->la_duree->clear();
}
else
    QMessageBox::critical(nullptr,QObject::tr("Ajout d'un invité"),QObject::tr("Ajout non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
}

void MainWindow::on_supprimer_clicked()
{
int CIN_I=ui->cin_supp->currentText().toInt();
bool test=I.supprimer(CIN_I);
if(test)
{
    ui->afficher->setModel(I.afficher());

    QMessageBox::information(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
    ui->le_cin_modif->setModel(I.afficher());
    ui->cin_supp->setModel(I.afficher());
}
else
    QMessageBox::critical(nullptr,QObject::tr("Suppression d'un invité"),QObject::tr("Suppression non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);

}

void MainWindow::on_modifier_clicked()
{
       int CIN_I=ui->le_cin_modif->currentText().toInt();
        QString NOM_I=ui->le_nom->text();
        QString PRENOM_I=ui->le_prenom->text();
        QString METIER_I=ui->le_metier->currentText();
        int NUM_TEL_I=ui->num_tel_modif->text().toInt();
        QDate DATE_I=ui->la_date_modif->date();
        QString MAIL_I=ui->mail_modif->text();
        int DUREE_I=ui->la_duree_modif->text().toInt();
        INVITES I(CIN_I,NOM_I,PRENOM_I,METIER_I,NUM_TEL_I,DATE_I,MAIL_I,DUREE_I);
        bool test=I.modifier();
        if(test)
        {
            ui->le_cin_modif->setModel(I.afficher());
            ui->afficher->setModel(I.afficher());

            QMessageBox::information(nullptr,QObject::tr("Modification d'un invité"),QObject::tr("Modification effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
            ui->le_cin_modif->setModel(I.afficher());
            ui->num_tel_modif->clear();
            ui->la_date_modif->clear();
            ui->mail_modif->clear();
            ui->la_duree_modif->clear();

        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Modification d'un invité"),QObject::tr("Modification non effectuée\n" "Click Cancel to quit"),QMessageBox::Cancel);
}

void MainWindow::on_PDF_clicked()
{
QMessageBox::information(nullptr,QObject::tr("GENERATION PDF"),QObject::tr("PDF CREATED\n" "Click Cancel to quit"),QMessageBox::Cancel);
int CIN_I=ui->le_cin->text().toInt();
QString cin = QString::number(CIN_I);

QString NOM_I=ui->le_nom->text();
QString PRENOM_I=ui->le_prenom->text();
QString METIER_I=ui->le_metier->currentText();

int NUM_TEL_I=ui->num_tel->text().toInt();
QString num = QString::number(NUM_TEL_I);

QDate DATE_I=ui->la_date->date();
QString d=DATE_I.toString("dd.MM.yyyy");

QString MAIL_I=ui->mail->text();

int DUREE_I=ui->la_duree->text().toInt();
QString duree = QString::number(DUREE_I);

  QPdfWriter pdf("C:/Users/21627/Desktop/RADIO + arduino yassss/invites.pdf");
  QPainter painter(&pdf);

  painter.setPen(Qt::red);
  painter.drawText(4000,400,"CIN:  "+cin+"" );

  painter.setPen(Qt::black);
  painter.drawText(3500,2100,"Nom  : "+NOM_I+"" );
  painter.drawText(3500,2500,"Prenom : "+PRENOM_I+"" );
  painter.drawText(3500,2900,"Metier : "+METIER_I+"" );
  painter.drawText(3500,3200,"Numero de tel : "+num+"" );
  painter.drawText(3500,3500,"Date de l'interview : "+d+"" );
  painter.drawText(3500,3900,"Adresse e_mail : "+MAIL_I+"" );
  painter.drawText(3500,4200,"Duree de l'interview : "+duree+" min" );
      ui->le_cin->clear();
      ui->le_nom->clear();
      ui->le_prenom->clear();
      ui->le_metier->clear();
      ui->num_tel->clear();
      ui->la_date->clear();
      ui->mail->clear();
      ui->la_duree->clear();

      painter.end();
}

void MainWindow::on_chercher_clicked()
{
    QString variable;
                if(ui->cher->currentText()=="CIN")
                {
                 variable="CIN_I";
                }
                if(ui->cher->currentText()=="NOM")
                {
                 variable="NOM_I";
                }
                if(ui->cher->currentText()=="PRENOM")
                {
                 variable="PRENOM_I";
                }
                if(ui->cher->currentText()=="DATE")
                {
                 variable="DATE_I";
                }
                if(ui->cher->currentText()=="METIER")
                {
                 variable="METIER_I";
                }

                INVITES I;
                QSqlQueryModel *model =I.recherche(ui->lineedit_ch->text(),variable);
                ui->afficher->setModel(model);

                ui->lineedit_ch->clear();

}

void MainWindow::on_button_tri_clicked()
{
    QString variable;
                if(ui->tri->currentText()=="CIN")
                {
                 variable="CIN_I";
                }
                if(ui->tri->currentText()=="NOM")
                {
                 variable="NOM_I";
                }
                if(ui->tri->currentText()=="PRENOM")
                {
                 variable="PRENOM_I";
                }
                if(ui->tri->currentText()=="METIER")
                {
                 variable="METIER_I";
                }
                if(ui->tri->currentText()=="DATE")
                {
                 variable="DATE_I";
                }
                if(ui->tri->currentText()=="MAIL")
                {
                 variable="MAIL_I";
                }
                if(ui->tri->currentText()=="NUM_TEL")
                {
                 variable="NUM_TEL_I";
                }
                if(ui->tri->currentText()=="DUREE")
                {
                 variable="DUREE_I";
                }
                INVITES I;
                QSqlQueryModel *model =I.tri(variable);
                ui->afficher->setModel(model);

}


// stat sur les metiers

void MainWindow::on_statsmed_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from INVITES where METIER_I='Etudiant' ");
     int number1=model->rowCount(); //  calculer le nombre de metier pour etudiant

     model->setQuery("select * from INVITES where METIER_I='Professeur' ");
     int number2=model->rowCount(); // calculer le nombre de metier pour professeur

     model->setQuery("select * from INVITES where METIER_I='Directeur' ");
     int number3=model->rowCount(); // calculer le nombre de metier pour directeur

     model->setQuery("select * from INVITES where METIER_I='Autre' ");
     int number4=model->rowCount(); // calculer le nombre de metier pour autre

     int total=number1+number2+number3+number4; //calculer le nombre totale des metiers

     QString a = QString("Etudiant"+QString::number((number1*100)/total,'f',2)+"%" ); // calculer le pourcentage pour etudiant
     QString b = QString("Professeur"+QString::number((number2*100)/total,'f',2)+"%" );  // calculer le pourcentage pour professeur
     QString c = QString("Directeur"+QString::number((number3*100)/total,'f',2)+"%" );  // calculer le pourcentage pour directeur
     QString d = QString("Autre "+QString::number((number4*100)/total,'f',2)+"%" );  // calculer le pourcentage pour autre


     QPieSeries *series = new QPieSeries();
     //series->setHoleSize(0.2);
     series->append(a,number1); // concatenate a et number 1
     series->append(b,number2); // concatenate b et number 2
     series->append(c,number3); // concatenate c et number 3
     series->append(d,number4); // concatenate d et number 4

     if (number1!= 0)
     {
         QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();  // slice label change
         slice->setPen(QPen());     // pen used to draw the slice border changes
     }
     if (number2!=0)
     {
              // Add label, explode and define brush for 2nd slice
              QPieSlice *slice1 = series->slices().at(1);
              slice1->setExploded(); // tba3ed slice
              slice1->setLabelVisible();
     }
     if(number3!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice2 = series->slices().at(2);
              slice2->setLabelVisible();
     }
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              slice3->setLabelVisible();
     }

             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage Par Metier de l'invite :" " Nbr totale des invités :"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->chart()->setAnimationOptions(QChart::SeriesAnimations);
             chartView->show();

}

void MainWindow::on_qrcodegen_clicked()
{   int CIN_I=ui->le_cin->text().toInt();
    QString cin = QString::number(CIN_I);

    QString NOM_I=ui->le_nom->text();
    QString PRENOM_I=ui->le_prenom->text();
    QString METIER_I=ui->le_metier->currentText();

    int NUM_TEL_I=ui->num_tel->text().toInt();
    QString num = QString::number(NUM_TEL_I);

    QDate DATE_I=ui->la_date->date();
    QString d=DATE_I.toString("dd.MM.yyyy");

    QString MAIL_I=ui->mail->text();

    int DUREE_I=ui->la_duree->text().toInt();
    QString duree = QString::number(DUREE_I);

    int tabeq=ui->afficher->currentIndex().row();
           QVariant idd=ui->afficher->model()->data(ui->afficher->model()->index(tabeq,0));
           QString id= idd.toString();
           QSqlQuery qry;
           qry.prepare("select * from INVITES where CIN_I=:id");
           qry.bindValue(":CIN_I",id);
           qry.exec();

           while(qry.next()){
               cin=qry.value(1).toString();
               NOM_I=qry.value(2).toString();
               PRENOM_I=qry.value(3).toString();
               METIER_I=qry.value(4).toString();
               num=qry.value(5).toString();
               d=qry.value(6).toString();
               MAIL_I=qry.value(7).toString();
               duree=qry.value(8).toString();

           }

                  id="CIN_I:"+cin+"NOM_I:"+NOM_I+"PRENOM_I:"+PRENOM_I,"METIER_I:"+METIER_I,"NUM_TEL_I:"+num,"DATE_I:"+d,"MAIL_I:"+MAIL_I,"DUREE_I:"+d;
           QrCode qr = QrCode::encodeText(id.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);

           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_envoyer_mail_clicked()
{
    if(ui->destinataire->text()!= "" && ui->objectmail->text()!="" && ui->contenuemail->toPlainText() != "" )
           sendMail();
    ui->destinataire->clear();
    ui->objectmail->clear();
    ui->contenuemail->clear();
}

void MainWindow::sendMail()
{
       Smtp* smtp = new Smtp("nousseiba.kaabi@esprit.tn", "211JFT9334", "smtp.gmail.com", 465);
       //connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

       smtp->sendMail("nousseiba.kaabi@esprit.tn", ui->destinataire->text(),ui->objectmail->text(),ui->contenuemail->toPlainText());
       QMessageBox::information(nullptr,QObject::tr("Mailing"),QObject::tr("Mail Sent\n" "Click Cancel to quit"),QMessageBox::Cancel);

}

void MainWindow::mailSent(QString status)
{
       if(status == "Message sent")
           QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}

