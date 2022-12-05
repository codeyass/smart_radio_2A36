#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arduino.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "dialog.h"
#include "secdialog.h"
#include "employe.h"
#include <QString>
#include "sponsors.h"
#include "invites.h"
#include "emission.h"
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
#include<QFileDialog>
#include<QTextDocument>
#include<QTextStream>
#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QMessageBox>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>

#include <QPixmap>

#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>

#include<QString>
#include<QStatusBar>

#include <QSound>

#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QtWidgets>
#include<QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include <QPainter>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>
#include<QTimer>
#include<QDateTime>
 #include <QApplication>

#include<QCamera>
#include <QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>
#include<QFileDialog>









#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "historique.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTableView>
#include <QPixmap>
#include<QPrinter>
#include<QPainter>
#include<QPrintDialog>
#include <QPrintPreviewDialog>
#include <QPdfWriter>
#include <QtCharts>
#include <QDesktopServices>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QPieSlice>
#include <QPieSeries>
#include <QChartView>
#include "arduino.h"


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

// nousseibaaaaaaaaaaaaaaa

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

      ui->labelstat3->setWindowFlags(Qt::FramelessWindowHint);
      ui->labelstat3->setMask((new QPixmap("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/IMG/stat.gif")) ->mask());
      QMovie * movie5= new QMovie ("C:/Users/21627/Desktop/integration nousseiba et yassmine/IMG/stat.gif");
      ui->labelstat3->setMovie(movie5);
      movie5->start();


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


// chaimaaaaaaaaaaaaa
 mCamera = new QCamera (this);
 mCameraViewfinder= new QCameraViewfinder(this);
 mCameraImageCapture= new QCameraImageCapture(mCamera,this);
 mLayout=new QVBoxLayout;
 mOpcionesMenu =new QMenu("Allumer",this);
mEncenderAction=new QAction("Ouvrir",this);
mApagarAction=new QAction("Eteindre",this);
mCapturarAction =new QAction ("Capturer",this);
mOpcionesMenu->addActions({mEncenderAction,mApagarAction,
                       mCapturarAction});
ui->opcionesPushButton->setMenu(mOpcionesMenu);
mCamera->setViewfinder(mCameraViewfinder);

mLayout->addWidget(mCameraViewfinder);
mLayout->setMargin(0);


ui->scrollArea->setLayout(mLayout);
connect(mEncenderAction,&QAction::triggered,[&]() {
 mCamera->start();

});
connect(mApagarAction,&QAction::triggered,[&]() {
 mCamera->stop();
});
connect(mCapturarAction, &QAction::triggered, [&]() {
auto filename= QFileDialog::getSaveFileName(this,"Capturer","/",
                              "Imagen(*.jpg;*.jpeg)");
if (filename.isEmpty()) {
    return;
}
mCameraImageCapture->setCaptureDestination(
            QCameraImageCapture::CaptureToFile);
QImageEncoderSettings imageEcoderSettings;
imageEcoderSettings.setCodec("image/jpeg");
imageEcoderSettings.setResolution(1600,1200);
mCameraImageCapture->setEncodingSettings(imageEcoderSettings);
mCamera->setCaptureMode(QCamera::CaptureStillImage);
mCamera->start();
mCamera->searchAndLock();
mCameraImageCapture->capture(filename);
mCamera->unlock();

});

 ui->tab_em->setModel(C.afficher());
 ui->cb_id_supp->setModel(C.GetAllId());
 ui->cb_id_modif->setModel(C.GetAllId());
ui->cb_id_rech->setModel(C.GetAllId());

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
    ui->stackedWidget->setCurrentIndex(6);
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
                      QPixmap p("C:/Users/21627/Desktop/RADIO + arduino yassss/affiche_video/jumia.png");
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
                      QPixmap p("C:/Users/21627/Desktop/RADIO + arduino yassss/affiche_video/carrefour.png");


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

                      QPixmap p("C:/Users/21627/Desktop/RADIO + arduino yassss/affiche_video/delice.png");


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
           player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Desktop/RADIO + arduino yassss/affiche_video/videojumia.mpg"));
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
           player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Desktop/RADIO + arduino yassss/affiche_video/videocarrefour.mpg"));
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
           player->setMedia(QUrl::fromLocalFile("C:/Users/21627/Desktop/RADIO + arduino yassss/affiche_video/videodelice.mpg"));
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
    ui->stackedWidget->setCurrentIndex(3);
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



// **************************** Emission ***************************

void MainWindow::on_pushButton_S_E_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_menu_6_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_ajout_clicked()
{
    int id=ui->le_id->text().toInt();
       int duree=ui->le_duree->text().toInt();
       QString nom=ui->le_nom->text();
       QString type=ui->le_type->currentText();
       QDate date=ui->le_date->date();
        Emission C(id,nom,type,date,duree);
        bool test1 = ((controlId(id))&&(controlDuree(duree))&&(controlVide(nom))&&(controlVide(type)));

        if(test1)
        {
       bool test=C.ajouter();
       if(test)
       {

    ui->tab_em->setModel(C.afficher());
    ui->cb_id_supp->setModel(C.GetAllId());
    ui->cb_id_modif->setModel(C.GetAllId());
    QMessageBox::information(nullptr, QObject::tr("ajouter une emission"),
                               QObject::tr("emission ajouté.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
       }
        else

   { QMessageBox::critical(nullptr, QObject::tr("ajouter une emission"),
                              QObject::tr("emission non ajouté, vérifier les champs.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
   }
        }
}

void MainWindow::on_modifEm_clicked()
{
    int duro=ui->le_duree_modif->text().toInt();
       int id=ui->cb_id_modif->currentText().toInt();
       QString nom=ui->le_nom_modif->text();
       QString type=ui->le_type_modif->currentText();
       QDate date=ui->le_date_modif->date();
   Emission C(id,nom,type,date,duro);
   bool test1 = ((controlId(id))&&(controlDuree(duro))&&(controlVide(nom))&&(controlVide(type)));
        if(test1)
        {
       bool test=C.modifier();
       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("modifier un emission"),
                                      QObject::tr("emission modifié.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tab_em->setModel(C.afficher());
           ui->cb_id_supp->setModel(C.GetAllId());
           ui->cb_id_modif->setModel(C.GetAllId());

       }else

   { QMessageBox::information(nullptr, QObject::tr("ajouter un emission"),
                              QObject::tr("emission non modifié, vérifier les champs.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
   }
        }
}

void MainWindow::on_pb_supprimer_clicked()
{
    QMessageBox msgBox;
       Emission C1;


C1.setId(ui->cb_id_supp->currentText().toInt());
           bool test=C1.supprimer(C1.getId());
       if(test)
         {  msgBox.setText("supprission avec succes.");
           ui->tab_em->setModel(C.afficher());
           ui->cb_id_supp->setModel(C.GetAllId());
           ui->cb_id_modif->setModel(C.GetAllId());
       }
       else
       { msgBox.setText("Echec de supprission");}
           msgBox.exec();
}

void MainWindow::on_pushButton_10_clicked()
{
    close();
}

void MainWindow::on_pushButton_11_clicked()
{
    close();
}

void MainWindow::on_pushButton_5_clicked()
{
    close();
}


//control de saisie:

bool MainWindow::controlId(int id)
{
    QString id_string= QString::number(id);
    for(int i=0;i<id_string.length();i++)
    {
        if (id_string.length()==8)
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::controlDuree(int test)
{
    QString num= QString::number(test);
    for(int i=0;i<num.length();i++)
    {
        if (num.length()<=3)
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::controlVide(QString test)
{
    if(test!="")
        return  true;
    return false;
}

void MainWindow::on_cb_id_modif_activated(const QString &arg1)
{
    QString val=ui->cb_id_modif->currentText();
        Emission *EM;
        EM=C.readEmission(val);
          int id=EM->getId();
          int duree=EM->getDuree();
          QString id_string=QString::number(id);
          QString duree_string=QString::number(duree);


                ui->le_nom_modif->setText(EM->getNom());
                //ui->le_type_modif->Text(EM->getType());
                ui->le_duree_modif->setText(duree_string);
}

void MainWindow::on_rechercher_button_clicked()
{
    QString rech =ui->cb_id_rech->currentText();
        ui->tab_em->setModel(C.rechercher(rech));
}


void MainWindow::on_radioButton_croissant_clicked()
{
     ui->tab_em->setModel(C.tri());
}

void MainWindow::on_radioButton_dcroissant_clicked()
{
     ui->tab_em->setModel(C.trid());
}

void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from EMISSIONS where TYPEEM='Sketch' ");//afficher tous les colonnes
     int number1=model->rowCount();
     model->setQuery("select * from EMISSIONS where TYPEEM='Documentaire' ");
     int number2=model->rowCount();
     model->setQuery("select * from EMISSIONS where TYPEEM='Social' ");
     int number3=model->rowCount();
     model->setQuery("select * from EMISSIONS where TYPEEM='Musical' ");
     int number4=model->rowCount();
     model->setQuery("select * from EMISSIONS where TYPEEM='Art' ");
     int number5=model->rowCount();
     model->setQuery("select * from EMISSIONS where TYPEEM='Autre' ");
     int number6=model->rowCount();
     int total=number1+number2+number3+number4+number5+number6;
     QString a = QString("Sketch"+QString::number((number1*100)/total,'f',2)+"%" );
     QString b = QString("Documentaire"+QString::number((number2*100)/total,'f',2)+"%" );
     QString c = QString("Social"+QString::number((number3*100)/total,'f',2)+"%" );
     QString d = QString("Musical"+QString::number((number4*100)/total,'f',2)+"%" );
     QString e = QString("Art"+QString::number((number5*100)/total,'f',2)+"%" );
     QString f = QString("Autre "+QString::number((number6*100)/total,'f',2)+"%" );


     QPieSeries *series = new QPieSeries();
     series->append(a,number1);
     series->append(b,number2);
     series->append(c,number3);
     series->append(d,number4);
     series->append(e,number5);
     series->append(f,number6);

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
     if(number4!=0)
     {
              // Add labels to rest of slices
              QPieSlice *slice3 = series->slices().at(3);
              //slice1->setExploded();
              slice3->setLabelVisible();
     }
     if (number5!= 0)
     {
         QPieSlice *slice = series->slices().at(4);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }
     if (number6!= 0)
     {
         QPieSlice *slice = series->slices().at(5);
         slice->setLabelVisible();
         slice->setPen(QPen());
     }

             // Create the chart widget
             QChart *chart = new QChart();
             // Add data to chart with title and hide legend
             chart->addSeries(series);
             chart->setTitle("Pourcentage Par TYPE EMISSION"+ QString::number(total));
             chart->legend()->hide();
             // Used to display the chart
             QChartView *chartView = new QChartView(chart);
             chartView->setRenderHint(QPainter::Antialiasing);
             chartView->resize(1000,500);
             chartView->show();

}

void MainWindow::on_btn_imp_clicked()
{

        QString strStream;
                                 QTextStream out(&strStream);

                                 const int rowCount = ui->tab_em->model()->rowCount();
                                 const int columnCount = ui->tab_em->model()->columnCount();
                                 QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                                 out <<"<html>\n"
                                       "<head>\n"
                                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                     << "<title>ERP - COMmANDE LIST<title>\n "
                                     << "</head>\n"
                                     "<body bgcolor=#ffffff link=#5000A0>\n"
                                     "<h1 style=\"text-align: center;\"><strong> *****LISTE DES EMISSIONS*****"+TT+" </strong></h1>"
                                     "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                       "</br> </br>";
                                 // headers
                                 out << "<thead><tr bgcolor=#d6e5ff>";
                                 for (int column = 0; column < columnCount; column++)
                                     if (!ui->tab_em->isColumnHidden(column))
                                         out << QString("<th>%1</th>").arg(ui->tab_em->model()->headerData(column, Qt::Horizontal).toString());
                                 out << "</tr></thead>\n";

                                 // data table
                                 for (int row = 0; row < rowCount; row++) {
                                     out << "<tr>";
                                     for (int column = 0; column < columnCount; column++) {
                                         if (!ui->tab_em->isColumnHidden(column)) {
                                             QString data =ui->tab_em->model()->data(ui->tab_em->model()->index(row, column)).toString().simplified();
                                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                         }
                                     }
                                     out << "</tr>\n";
                                 }
                                 out <<  "</table>\n"
                                     "</body>\n"
                                     "</html>\n";

                                 QTextDocument *document = new QTextDocument();
                                 document->setHtml(strStream);

                                 QPrinter printer;

                                 QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                                 if (dialog->exec() == QDialog::Accepted) {
                                     document->print(&printer);
                                 }

                                 delete document;




}

void MainWindow::on_pushButton_encrypt_clicked()
{

    QString plainText = ui->plainTextEdit_plain->toPlainText();
    QString encryptedText = "to be implemented";

    if(ui->comboBox->currentIndex() == 0)
    {
        int key = ui->lineEdit_CC_key->text().toInt();
        encryptedText = ewCaesarCipher(plainText, key);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        QString secret = ui->lineEdit_PF_Secret->text();
        encryptedText = ewPlayfair(plainText, secret);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        QString key = ui->lineEdit_DES_key_3->text();
        encryptedText = ewDES(plainText, key.toStdString());
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
      double p = ui->RSA_lineEdit_p_2->text().toDouble();
      double q = ui->RSA_lineEdit_q_2->text().toDouble();
       double dbl = ewRSA(plainText.toDouble(), p, q);

        std::ostringstream strs;
        strs << dbl;
        encryptedText = QString::fromStdString(strs.str());

        std::pair<double, double> pair = RSAKeys(p, q);
        std::ostringstream strPrK;
        strPrK << pair.first;
        ui->RSA_lineEdit_prkey_2->setText(QString::fromStdString(strPrK.str()));
        std::ostringstream strPuK;
        strPuK << pair.second;
      ui->RSA_lineEdit_pukey_2->setText(QString::fromStdString(strPuK.str()));
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
        QString key = ui->lineEdit_rc4_key_3->text();
        encryptedText = ewRC4(plainText, key);
    }
    else if(ui->comboBox->currentIndex() == 5)
    {
        QString key = ui->lineEdit_DES_key_3->text();
        encryptedText = ewIDES(plainText, key.toStdString());
    }
    ui->plainTextEdit_encrypted->document()->setPlainText(encryptedText);
}

void MainWindow::on_pushButton_decrypt_clicked()
{
    QString encryptedText = ui->plainTextEdit_encrypted->toPlainText();
    QString plainText = "to be implemented";

    if(ui->comboBox->currentIndex() == 0)
    {
        int key = ui->lineEdit_CC_key->text().toInt();
        plainText = dwCaesarCipher(encryptedText, key);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        QString secret = ui->lineEdit_PF_Secret->text();
        plainText = dwPlayfair(encryptedText, secret);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
        QString key = ui->lineEdit_DES_key_3->text();
        plainText = dwDES(encryptedText, key.toStdString());
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
       double p = ui->RSA_lineEdit_p_2->text().toDouble();
     double q = ui->RSA_lineEdit_q_2->text().toDouble();

        std::ostringstream pstr;
        pstr << dwRSA(encryptedText.toDouble(), p, q);
        plainText = QString::fromStdString(pstr.str());
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
        QString key = ui->lineEdit_rc4_key_3->text();
        plainText = dwRC4(encryptedText, key);
    }
    else if(ui->comboBox->currentIndex() == 5)
    {
        QString key = ui->lineEdit_DES_key_3->text();
        plainText = dwIDES(encryptedText, key.toStdString());
    }
    ui->plainTextEdit_plain->document()->setPlainText(plainText);
}

void MainWindow::on_actionReset_Fields_triggered()
{
    ui->plainTextEdit_plain->clear();
    ui->plainTextEdit_encrypted->clear();
    ui->lineEdit_CC_key->clear();
}

void MainWindow::on_actionClear_Plain_Text_triggered()
{
    ui->plainTextEdit_plain->clear();
}

void MainWindow::on_actionClear_Encrypted_Text_triggered()
{
    ui->plainTextEdit_encrypted->clear();
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this);
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Caesar Cipher")
    {
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else if(arg1 == "Playfair")
    {
        ui->stackedWidget_3->setCurrentIndex(1);
    }
    else if(arg1 == "DES")
    {
        ui->stackedWidget_3->setCurrentIndex(2);
    }
    else if(arg1 == "RSA")
    {
        ui->stackedWidget_3->setCurrentIndex(3);
    }
    else if(arg1 == "RC4")
    {
        ui->stackedWidget_3->setCurrentIndex(4);
    }
    else if(arg1 == "DES with Text")
    {
        ui->stackedWidget_3->setCurrentIndex(2);
    }
}





// Caesar Cipher Methods

QString MainWindow::ewCaesarCipher(QString plainText, int key)
{
    std::string result = "";
    std::string plainStdText = plainText.toStdString();

    for (int i=0;i<plainText.length();i++)
    {
        if(plainStdText[i] == ' ')
        {
            result += ' ';
        }
        else if(std::isalpha(plainStdText[i]))
        {
            if (std::isupper(plainStdText[i]))
                result += char(int(plainStdText[i]+key-65)%26 +65);
            else
                result += char(int(plainStdText[i]+key-97)%26 +97);
        }
    }

    return QString::fromStdString(result);
}

QString MainWindow::dwCaesarCipher(QString encryptedText, int key)
{
    return ewCaesarCipher(encryptedText, 26-key);
}





// playfair Methods

QString MainWindow::ewPlayfair(QString plainText, QString secret)
{
    std::string plainStdText = plainText.toStdString();
    std::string secretStdText = secret.toStdString();

    normalizePFSecret(secretStdText);
    populatePFMatrix(secretStdText);
    normalizePFString(plainStdText);

    std::string encryptedText = encryptPFString(plainStdText);

    return QString::fromStdString(encryptedText);
}

QString MainWindow::dwPlayfair(QString encryptedText, QString secret)
{
    std::string encryptedStdText = encryptedText.toStdString();
    std::string secretStdText = secret.toStdString();

    normalizePFSecret(secretStdText);
    populatePFMatrix(secretStdText);

    std::string plainText = decryptPFString(encryptedStdText);

    return QString::fromStdString(plainText);
}

bool MainWindow::inSameRow(Position p1, Position p2)
{
    if(p1.x == p2.x)
        return true;
    return false;
}

bool MainWindow::inSameColumn(Position p1, Position p2)
{
    if(p1.y == p2.y)
        return true;
    return false;
}

void MainWindow::normalizePFString(std::string &str)
{
    std::string pure_str= "";
    // remove any non-alphabetical characters
    // convert string to lower case
    for(int i=0;i<str.size();++i)
    {
        if(isalpha(str[i]))
        {
            if(std::isupper(str[i]))
                str[i] = std::tolower(str[i]);
            pure_str += str[i];
        }
    }

    // separate duplicate characters
    for(int i=0 ; i<pure_str.size()-1 ; i+=2)
    {
        if(pure_str[i] == pure_str[i+1])
            pure_str.insert(pure_str.begin()+i+1, 'x');
    }

    // make string even
    if(pure_str.size()%2 !=0)
        pure_str += 'x';

    str = pure_str;
}

std::string MainWindow::encryptPFString(std::string plainStdText)
{
    std::string result = "";

    for(int i=0;i<plainStdText.size(); i+=2)
    {
        Position p1 = findPositionByChar(plainStdText[i]);
        Position p2 = findPositionByChar(plainStdText[i+1]);

        if(inSameRow(p1, p2))
        {
            if(p1.y == 4)
                p1.y = 0;
            else
                p1.y +=1;

            if(p2.y == 4)
                p2.y = 0;
            else
                p2.y +=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else if(inSameColumn(p1, p2))
        {
            if(p1.x == 4)
                p1.x = 0;
            else
                p1.x +=1;

            if(p2.x == 4)
                p2.x = 0;
            else
                p2.x +=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else
        {
            Position t1, t2;

            t1.x = p1.x;
            t1.y = p2.y;

            t2.x = p2.x;
            t2.y = p1.y;

            result += findCharByPosition(t1);
            result += findCharByPosition(t2);
        }
    }

    return result;
}

std::string MainWindow::decryptPFString(std::string encryptedStdText)
{
    std::string result = "";

    for(int i=0;i<encryptedStdText.size(); i+=2)
    {
        Position p1 = findPositionByChar(encryptedStdText[i]);
        Position p2 = findPositionByChar(encryptedStdText[i+1]);

        if(inSameRow(p1, p2))
        {
            if(p1.y == 0)
                p1.y = 4;
            else
                p1.y -=1;

            if(p2.y == 0)
                p2.y = 4;
            else
                p2.y -=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else if(inSameColumn(p1, p2))
        {
            if(p1.x == 0)
                p1.x = 4;
            else
                p1.x -=1;

            if(p2.x == 0)
                p2.x = 4;
            else
                p2.x -=1;

            result += findCharByPosition(p1);
            result += findCharByPosition(p2);
        }
        else
        {
            Position t1, t2;

            t1.x = p1.x;
            t1.y = p2.y;

            t2.x = p2.x;
            t2.y = p1.y;

            result += findCharByPosition(t1);
            result += findCharByPosition(t2);
        }
    }

    return result;
}

void MainWindow::normalizePFSecret(std::string &secret)
{
    std::string result = "";
    secret += "abcdefghiklmnopqrstuvwxyz";
    for(int i=0;i<secret.size();++i)
    {
        if(result.find(secret[i]) == std::string::npos)
            result += secret[i];
    }
    secret = result;
}

void MainWindow::populatePFMatrix(std::string secret)
{
    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5 ; ++j)
        {
            pfMatrix[i][j] = secret[j+5*i];
        }
    }
}

Position MainWindow::findPositionByChar(char ch)
{
    Position p;

    for(int i=0; i<5; ++i)
    {
        for(int j=0; j<5; ++j)
        {
            if(pfMatrix[i][j] == ch)
            {
                p.x = i;
                p.y = j;
            }
        }
    }

    return p;
}

char MainWindow::findCharByPosition(Position p)
{
    return pfMatrix[p.x][p.y];
}





// data 0000000100100011010001010110011110001001101010111100110111101111
// key  0001001100110100010101110111100110011011101111001101111111110001

// DES Methods

QString MainWindow::ewDES(QString plainText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);

    QString encryptedText = DESEncryption(plainText.toStdString(), keys);

    return encryptedText;
}

QString MainWindow::dwDES(QString encryptedText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);

    std::reverse(keys.begin(), keys.end());

    QString plainText = DESEncryption(encryptedText.toStdString(), keys);

    return plainText;
}

std::vector< std::string > MainWindow::keyPreparation(std::string key)
{
    // 0001001100110100010101110111100110011011101111001101111111110001

    std::string permutedKey = "";
    int PC1_permutations[56] = {
        57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4
    };

    for(int i=0;i<56; ++i)
    {
        permutedKey += key[PC1_permutations[i]-1];
    }

//    std::cout << key << std::endl;
//    std::cout << permutedKey << std::endl;
//    std::cout << permutedKey.length() << std::endl;


    int shifts[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

    std::vector< std::pair<std::string, std::string> > keys;

    std::string C0 = permutedKey.substr(0,28);
    std::string D0 = permutedKey.substr(28,56);

//    std::cout << "C0 : " << C0 << std::endl;
//    std::cout << "D0 : " << D0 << std::endl;

    keys.push_back(std::make_pair(C0, D0));

    for(int i=1 ; i<17 ; ++i)
    {
        std::string C = keys[i-1].first;
        std::string D = keys[i-1].second;

        C = C.substr(shifts[i-1], C.length()) + C.substr(0, shifts[i-1]);
        D = D.substr(shifts[i-1], D.length()) + D.substr(0, shifts[i-1]);

        keys.push_back(std::make_pair(C, D));

//        std::cout << "C" << i << " : " << C << std::endl;
//        std::cout << "D" << i << " : " << D << std::endl;
    }


    int PC2_permutations[48] = {
        14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10,
        23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
    };

    std::vector<std::string> finalKeys;

    for(int i=0;i<16;++i)
    {
        std::string k = keys[i+1].first + keys[i+1].second;
        std::string fk = "";

        for(int j=0;j<48;++j)
        {
            fk += k[PC2_permutations[j]-1];
        }
        finalKeys.push_back(fk);
//        std::cout << fk << std::endl;
    }

    std::cout << std::endl << ">[BEGIN] Keys generated Successfully" << std::endl << std:: endl;

    for(int i=0; i<finalKeys.size(); ++i)
    {
        std::cout << "Key " << i+1 << ": " << finalKeys[i] << std::endl;
    }

    std::cout << std::endl << ">[END] Keys generated Successfully" << std::endl << std:: endl;


    return finalKeys;
}

QString MainWindow::DESEncryption(std::string dataBlock, std::vector< std::string > keys)
{
    // 0000000100100011010001010110011110001001101010111100110111101111

    std::string permutedBlock = "";

    int initPermutation[64] = {
        58,    50,   42,    34,    26,   18,    10,    2,
        60,    52,   44,    36,    28,   20,    12,    4,
        62,    54,   46,    38,    30,   22,    14,    6,
        64,    56,   48,    40,    32,   24,    16,    8,
        57,    49,   41,    33,    25,   17,     9,    1,
        59,    51,   43,    35,    27,   19,    11,    3,
        61,    53,   45,    37,    29,   21,    13,    5,
        63,    55,   47,    39,    31,   23,    15,    7
    };

    for(int i=0 ; i<64 ; ++i)
    {
        permutedBlock += dataBlock[initPermutation[i]-1];
    }

    std::string L0 = permutedBlock.substr(0, 32);
    std::string R0 = permutedBlock.substr(32, 64);


    std::cout << "L0 : " << L0 << std::endl;
    std::cout << "R0 : " << R0 << std::endl;

    std::vector< std::pair<std::string, std::string> > data;
    data.push_back(std::make_pair(L0, R0));

    for(int i=1;i<17;++i)
    {
        std::string L = data[i-1].second;

        std::string R = apply_xor(
            data[i-1].first,
            apply_func_F(apply_func_E(data[i-1].second), keys[i-1])
        );

        data.push_back(std::make_pair(L, R));

        std::cout << "L" << i << " : " << L << std::endl;
        std::cout << "R" << i << " : " << R << std::endl;
    }

    std::string encryptedDataReversedKey = "";
    encryptedDataReversedKey += data[data.size()-1].second;
    encryptedDataReversedKey += data[data.size()-1].first;

    std::string finalPermutedBlock = "";

    int finalPermutation[64] = {
        40, 8, 48, 16, 56, 24, 64, 32,
        39, 7, 47, 15, 55, 23, 63, 31,
        38, 6, 46, 14, 54, 22, 62, 30,
        37, 5, 45, 13, 53, 21, 61, 29,
        36, 4, 44, 12, 52, 20, 60, 28,
        35, 3, 43, 11, 51, 19, 59, 27,
        34, 2, 42, 10, 50, 18, 58, 26,
        33, 1, 41,  9, 49, 17, 57, 25
    };

    for(int i=0 ; i<64 ; ++i)
    {
        finalPermutedBlock += encryptedDataReversedKey[finalPermutation[i]-1];
    }

    return QString(finalPermutedBlock.c_str());
}

std::string MainWindow::apply_xor(std::string str1, std::string str2)
{
    if(str1.length() != str2.length())
        std::cout << "Error in XORed Strings, Length Not Equal" << std::endl;

    std::string result = "";
    for(int i=0;i<str1.length();++i)
    {
        if(str1[i] == str2[i])
            result += '0';
        else
            result += '1';
    }

    return result;
}

std::string MainWindow::apply_func_F(std::string str1, std::string str2)
{
    // result is 48 bit
    std::string result = apply_xor(str1, str2);

    int sboxes[8][4][16] =
    {
        {
            { 14,  4,  13,  1,   2, 15,  11,  8,   3, 10,   6, 12,   5,  9,   0,  7 },
            {  0, 15,   7,  4,  14,  2,  13,  1,  10,  6,  12, 11,   9,  5,   3,  8 },
            {  4,  1,  14,  8,  13,  6,   2, 11,  15, 12,   9,  7,   3, 10,   5,  0 },
            { 15, 12,   8,  2,   4,  9,   1,  7,   5, 11,   3, 14,  10,  0,   6, 13 }
        },
        {
            { 15,  1,   8, 14,   6, 11,   3,  4,   9,  7,   2, 13,  12,  0,   5, 10 },
            {  3, 13,   4,  7,  15,  2,   8, 14,  12,  0,   1, 10,   6,  9,  11,  5 },
            {  0, 14,   7, 11,  10,  4,  13,  1,   5,  8,  12,  6,   9,  3,   2, 15 },
            { 13,  8,  10,  1,   3, 15,   4,  2,  11,  6,   7, 12,   0,  5,  14,  9 }
        },
        {
            { 10,  0,   9, 14,   6,  3,  15,  5,   1, 13,  12,  7,  11,  4,   2,  8 },
            { 13,  7,   0,  9,   3,  4,   6, 10,   2,  8,   5, 14,  12, 11,  15,  1 },
            { 13,  6,   4,  9,   8, 15,   3,  0,  11,  1,   2, 12,   5, 10,  14,  7 },
            {  1, 10,  13,  0,   6,  9,   8,  7,   4, 15,  14,  3,  11,  5,   2, 12 }
        },
        {
            {  7, 13,  14,  3,   0,  6,   9, 10,   1,  2,   8,  5,  11, 12,   4, 15 },
            { 13,  8,  11,  5,   6, 15,   0,  3,   4,  7,   2, 12,   1, 10,  14,  9 },
            { 10,  6,   9,  0,  12, 11,   7, 13,  15,  1,   3, 14,   5,  2,   8,  4 },
            {  3, 15,   0,  6,  10,  1,  13,  8,   9,  4,   5, 11,  12,  7,   2, 14 }
        },
        {
            {  2, 12,   4,  1,   7, 10,  11,  6,   8,  5,   3, 15,  13,  0,  14,  9 },
            { 14, 11,   2, 12,   4,  7,  13,  1,   5,  0,  15, 10,   3,  9,   8,  6 },
            {  4,  2,   1, 11,  10, 13,   7,  8,  15,  9,  12,  5,   6,  3,   0, 14 },
            { 11,  8,  12,  7,   1, 14,   2, 13,   6, 15,   0,  9,  10,  4,   5,  3 }
        },
        {
            { 12,  1,  10, 15,   9,  2,   6,  8,   0, 13,   3,  4,  14,  7,   5, 11 },
            { 10, 15,   4,  2,   7, 12,   9,  5,   6,  1,  13, 14,   0, 11,   3,  8 },
            {  9, 14,  15,  5,   2,  8,  12,  3,   7,  0,   4, 10,   1, 13,  11,  6 },
            {  4,  3,   2, 12,   9,  5,  15, 10,  11, 14,   1,  7,   6,  0,   8, 13 }
        },
        {
            {  4, 11,   2, 14,  15,  0,   8, 13,   3, 12,   9,  7,   5, 10,   6,  1 },
            { 13,  0,  11,  7,   4,  9,   1, 10,  14,  3,   5, 12,   2, 15,   8,  6 },
            {  1,  4,  11, 13,  12,  3,   7, 14,  10, 15,   6,  8,   0,  5,   9,  2 },
            {  6, 11,  13,  8,   1,  4,  10,  7,   9,  5,   0, 15,  14,  2,   3, 12 }
        },
        {
            { 13,  2,   8,  4,   6, 15,  11,  1,  10,  9,   3, 14,   5,  0,  12,  7 },
            {  1, 15,  13,  8,  10,  3,   7,  4,  12,  5,   6, 11,   0, 14,   9,  2 },
            {  7, 11,   4,  1,   9, 12,  14,  2,   0,  6,  10, 13,  15,  3,   5,  8 },
            {  2,  1,  14,  7,   4, 10,   8, 13,  15, 12,   9,  0,   3,  5,   6, 11 }
        }
    };

    std::string output = "";
    std::string outerBits = "";
    std::string innerBits = "";

    for(int i=0, s=0 ; i<48 ; i+=6, s++)
    {
        outerBits += result[i];
        outerBits += result[i+5];

        innerBits += result[i+1];
        innerBits += result[i+2];
        innerBits += result[i+3];
        innerBits += result[i+4];

        int row = std::stoi(outerBits, nullptr, 2);
        int column = std::stoi(innerBits, nullptr, 2);

        int valInSBox = sboxes[s][row][column];

        output += std::bitset<4>(valInSBox).to_string();

        outerBits = "";
        innerBits = "";
    }

    std::string permutedOutput = "";

    int permutations[32] = {
        16,  7, 20, 21,
        29, 12, 28, 17,
         1, 15, 23, 26,
         5, 18, 31, 10,
         2,  8, 24, 14,
        32, 27,  3,  9,
        19, 13, 30,  6,
        22, 11,  4, 25
    };

    for(int i=0; i<32; ++i)
    {
        permutedOutput += output[permutations[i]-1];
    }

    return permutedOutput;
}

std::string MainWindow::apply_func_E(std::string str)
{
    std::string result = "";

    int ePermutations[48] = {
         32,     1,    2,     3,     4,    5,
          4,     5,    6,     7,     8,    9,
          8,     9,   10,    11,    12,   13,
         12,    13,   14,    15,    16,   17,
         16,    17,   18,    19,    20,   21,
         20,    21,   22,    23,    24,   25,
         24,    25,   26,    27,    28,   29,
         28,    29,   30,    31,    32,    1
    };

    for(int i=0;i<48;++i)
    {
        result += str[ePermutations[i]-1];
    }

    return result;
}


// improved DES with text Methods
QString MainWindow::ewIDES(QString plainText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);
    std::vector< std::string > blocks = textToBinaryAscii(plainText.toStdString());

    QString encryptedText;

    for(int i=0; i<blocks.size(); ++i)
        encryptedText += DESEncryption(blocks[i], keys);

//    encryptedText = QString::fromStdString(binaryAsciiToText(encryptedText.toStdString()));

    return encryptedText;
}

QString MainWindow::dwIDES(QString encryptedText, std::string key)
{
    std::vector< std::string > keys = keyPreparation(key);
    std::reverse(keys.begin(), keys.end());

    std::string stdPlainText = encryptedText.toStdString();
    std::string allPlainText = "";

    for(int i=0; i<encryptedText.size()/64; ++i)
    {
        allPlainText += DESEncryption(stdPlainText.substr(i*64, 64), keys).toStdString();
    }

    return QString::fromStdString(binaryAsciiToText(allPlainText));
}

std::vector< std::string > MainWindow::textToBinaryAscii(std::string str)
{
    std::vector< std::string > blocksOfData;

    for(int i=0; i<str.size()/8; ++i)
    {
        std::string blockStr = str.substr(i*8, 8);
        std::string block = "";

        for(int i=0; i<8; ++i)
            block += charToBinaryAscii(blockStr[i]);

        blocksOfData.push_back(block);
    }

    if(str.size()%8 != 0)
    {
        int start = ((int)str.size()/8)*8;
        int length = (int)str.size()- start;

        std::string blockStr = str.substr(start, length);
        for(int i=0; i<(8-length); ++i)
            blockStr += " ";

        std::string block = "";
        for(int i=0; i<8; ++i)
            block += charToBinaryAscii(blockStr[i]);
        blocksOfData.push_back(block);
    }

    return blocksOfData;
}

std::string MainWindow::binaryAsciiToText(std::string str)
{
    std::string blocksOfData = "";

    for(int i=0; i<str.size()/64; ++i)
    {
        std::string blockStr = str.substr(i*64, 64);
        std::string block = "";

        for(int i=0; i<8; ++i)
        {
           std::string ascii = blockStr.substr(i*8, 8);
           block += binaryAsciiToChar(ascii);
        }
        blocksOfData += block;
    }

    return blocksOfData;
}

std::string MainWindow::charToBinaryAscii(char ch)
{
    return std::bitset<8>(int(ch)).to_string();
}

char MainWindow::binaryAsciiToChar(std::string binaryAscii)
{
    return char(std::bitset<8>(binaryAscii).to_ulong());
}





// RSA Methods

double MainWindow::ewRSA(double msg, double p, double q)
{
    // generate public as first, private as second key
    std::pair<double,double> keys = RSAKeys(p, q);

    double n = p*q;
    double e = keys.first;

    return RSAEncryption(msg, n, e);
}

double MainWindow::dwRSA(double msg, double p, double q)
{
    // generate public as first, private as second key
    std::pair<double,double> keys = RSAKeys(p, q);

    int n = p*q;
    int d = keys.second;

    return RSADecryption(msg, n, d);
}

double MainWindow::RSAEncryption(double msg, double n, double e)
{
    // Encryption c = (msg ^ e) % n
    double c = pow(msg, e);
    c = fmod(c, n);
    return c;
}

double MainWindow::RSADecryption(double msg, double n, double d)
{
    // Decryption m = (c ^ d) % n
    double m = pow(msg, d);
    m = fmod(m, n);
    return m;
}

std::pair<double, double> MainWindow::RSAKeys(double p, double q)
{
    // Finding public key; e stands for encrypt.
    double e = 2;
    double phi = (p-1)*(q-1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }

    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient

    int d = e;
    while((int)(d*e)%((int)phi) != 1)
    {
        d++;
    }

    return std::make_pair(e, d);
}

int MainWindow::gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}





// RC4 Methods

QString MainWindow::ewRC4(QString msg, QString key)
{
    std::vector<int> k;

    // initialize key
    std::string stdCppKey = key.toStdString();
    for(int i=0; i<stdCppKey.length(); ++i)
        k.push_back(int(stdCppKey[i] - '0'));

    std::vector<int> s(256);
    std::vector<int> t(256);

    // initialize vector S to [0:255]
    for(int i=0; i<256; ++i)
        s[i] = i;

    // initialize vector T from key K
    for(int i=0; i<256; ++i)
        t[i] = k[i%k.size()];

    // initial Permutation Of S
    int j = 0;
    for(int i=0; i<256; ++i)
    {
        j = (j + s[i] + t[i])%256;
        std::swap(s[i], s[j]);
    }

    // prepare msg
    std::vector< std::bitset<8> > msg_bytes = bytesOfMessage(msg.toStdString());


    // generate a key for each byte of input
    // e.g input: 5 bytes, generates output: 5 bytes
    std::vector< std::bitset<8> > keys = keysGenerator((int)msg_bytes.size(), s);

    return RC4Encryption(msg_bytes, keys);

}

QString MainWindow::dwRC4(QString msg, QString key)
{
    return ewRC4(msg, key);
}

QString MainWindow::RC4Encryption(std::vector< std::bitset<8> > msg_bytes, std::vector< std::bitset<8> > keys)
{
    std::string result = "";
    for (int i = 0; i < msg_bytes.size(); ++i)
    {
        std::bitset<8> temp = std::bitset<8>(msg_bytes[i] ^ keys[i]);
        result += temp.to_string();
    }

    // Debugging output
    std::cout << "> Debugging Statements" << std::endl;

    std::cout << "I/P: " ;
    for(int t=0; t<msg_bytes.size(); ++t)
        std::cout << msg_bytes[t];
    std::cout << std::endl;

    std::cout << "Key: ";
    for(int t=0; t<keys.size(); ++t)
        std::cout << keys[t].to_string();
    std::cout << std::endl;
    std::cout << "O/P: " << result << std::endl;

    return QString::fromStdString(result);
}

std::vector< std::bitset<8> > MainWindow::keysGenerator(int msg_length, std::vector<int> s)
{
    std::vector< std::bitset<8> > keys(msg_length);

    int i=0, j=0, k=0;
    for (int lc = 0; lc < msg_length; ++lc)
    {
        i = (i+1)%256;
        j = (j+s[i])%256;
        std::swap(s[i], s[j]);
        k = s[(s[i]+s[j])%256];
        keys[lc] = std::bitset<8>(k);
    }

    return keys;
}

std::vector< std::bitset<8> > MainWindow::bytesOfMessage(std::string msg)
{
    std::vector< std::bitset<8> > msg_bytes;

    for(int i=0; i<(msg.length()/8); ++i)
    {
        std::string msg_byte = "";
        for(int j=0; j<8; ++j)
        {
            int idx = j + i*8;
            msg_byte += msg[idx];
        }
        msg_bytes.push_back(std::bitset<8>(msg_byte));
    }

    return msg_bytes;
}


void MainWindow::on_Ajouter_4_clicked()
{
    int ID_P=ui->lineEdit_id->text().toInt();
    QString PRENOM_P=ui->lineEdit_prenom->text();
    QString NOM_P=ui->lineEdit_nom->text();
    int NUMTEL=ui->lineEdit_numtel->text().toInt();
    int AGE=ui->lineEdit_age->text().toInt();

    employe E(ID_P,PRENOM_P,NOM_P,NUMTEL,AGE);
    bool test=E.ajouter();
    if(test)
    {
        ui->tabAffiche->setModel(E.afficher());

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué§\n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supp_4_clicked()
{
    employe E1;
        int id=ui->lineEdit_supp_4->text().toInt();
        bool test=E1.supprimer(id);
        if(test)
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("Suppression effectué§\n"
                                                "Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Supprission non effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Generation en pdf effectué§\n"
                                        "Click Cancel to exit."),QMessageBox::Cancel);

    QString id=ui->lineEdit_id->text();
        QString nom=ui->lineEdit_nom->text();
        QString prenom=ui->lineEdit_prenom->text();
         QString numtel =ui->lineEdit_numtel->text();
         QString age =ui->lineEdit_age->text();

        QPdfWriter pdf("C:/Users/MSI/Downloads/integration radio.pdf");
         QPainter painter(&pdf);


        int i = 4000;

             painter.setPen(Qt::blue);
             painter.setFont(QFont("Century Gothic",35,QFont::Bold));
             painter.drawText(2000,1500,"LISTE DES EMPLOYEES");
             painter.setPen(Qt::black);
             painter.drawRect(0,2700,9600,500);
             painter.setFont(QFont("Calibri",14,QFont::Bold));
             painter.drawText(200,3000,"ID_P");
             painter.drawText(1800,3000,"NOM_P");
             painter.drawText(3100,3000,"PRENOM_P");
             painter.drawText(4900,3000,"NUMERO TEL");
             painter.drawText(6800,3000,"AGE");




             QSqlQuery query;

             query.prepare("select * from EMPLOYES");
             query.exec();
             while (query.next())
             {
                    painter.setFont(QFont("Calibri",13));
                 painter.drawText(200,i,query.value(1).toString());
                 painter.drawText(1800,i,query.value(0).toString());
                 painter.drawText(3200,i,query.value(2).toString());
                 painter.drawText(4900,i,query.value(3).toString());
                 painter.drawText(6900,i,query.value(4).toString());


                i = i + 500;
             }

}


void MainWindow::on_spot_2_clicked()
{
    ui->setupUi(this);
    ui->tabEmploye->setModel(E.afficher());
}

void MainWindow::on_pushButton_S_2_clicked()
{

    ui->stackedWidget->setCurrentIndex(2);

}



void MainWindow::on_menu_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_update_4_clicked()
{
    QDesktopServices::openUrl(QUrl("https://wa.me/+21628551902", QUrl::TolerantMode));

}


void MainWindow::on_pushButton_clicked()
{
    QString data = T.read_from_arduino();
    qDebug()<<data;
    int result = data.split( "," )[0].toInt();
    if (result == 0 )
        ui->fireLabel->setText("FIRE");
    else
        ui->fireLabel->setText("NO FIRE");
}

void MainWindow::on_pushButton_4_clicked()
{
        T.write_to_arduino("s");
}

void MainWindow::on_pushButton_S_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_ajouter_2_clicked()
{
    QString id=ui->le_id_e->text();
      int id1=ui->le_id_e->text().toInt();
            QString nom=ui->le_nom_e_3->text();
            QString type=ui->le_type_e->text();
            QString marque=ui->le_marque_e->text();
            int etat=ui->le_etat_e->text().toInt();
            Equipement eq(id1,etat,nom,type,marque);
            bool test=eq.ajouter();
            QMessageBox msgBox;
            if((test)&&(id!="")&&(id!="0"))
            {msgBox.setText("ajout avec succes");
            ui->tab_equipement->setModel(eq.afficher());
            }
            else
                msgBox.setText("Echec de l'ajout");
            ui->tab_equipement->setModel(eq.afficher());

            msgBox.exec();
}

void MainWindow::on_supprimer_2_clicked()
{
    QString id=ui->le_id_supp->text();
      int id1=ui->le_id_supp->text().toInt();
        bool test=eq.supprimer(id1);
        if((test)&&(id!="")&&(id!="0"))
        {
            ui->tab_equipement->setModel(eq.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                    QObject::tr("suppression succes.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else

        {        ui->tab_equipement->setModel(eq.afficher());

            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                            QObject::tr("Echec de suppression .\n"
                                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void MainWindow::on_chercher_2_clicked()
{
    ui->tab_equipement->setModel(eq.afficher());


        QString rech = ui->rech_eq->text();



                         etmp.recherche(ui->tab_equipement,rech);



                         if (ui->rech_eq->text().isEmpty())



                         {



                             ui->tab_equipement->setModel(etmp.afficher());



                         }

}

void MainWindow::on_modifier_2_clicked()
{
    QString id1=ui->le_id_mod->text();
        int id=ui->le_id_mod->text().toInt();
        QString nom=ui->le_nom_mod->text();
        QString type=ui->le_type_mod->text();
        QString marque=ui->le_marque_mod->text();
        int etat=ui->le_etat_mod->text().toInt();
        Equipement eq(id,etat,nom,type,marque);
        bool test=eq.modifier(id,etat);
        QMessageBox msgBox;
        if((test)&&(id1!="")&&(id1!="0"))
        {        ui->tab_equipement->setModel(eq.afficher());

            QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Modification effectué\n"
                                              "Click cancel to exit"), QMessageBox::Cancel);

        }
        else
        {        ui->tab_equipement->setModel(eq.afficher());

            QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                            QObject::tr("Modification non effectué\n"
                                        "Click cancel to exit"), QMessageBox::Cancel);}
}

void MainWindow::on_label_stat2_2_linkActivated(const QString &link)
{

}

void MainWindow::on_radioButton_clicked()
{
    ui->tab_equipement->setModel(eq.afficher());

       ui->tab_equipement->setModel(etmp.trienom());
}

void MainWindow::on_menu_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_statsmed_2_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                       model->setQuery("select * from EQUIPMENTS where MARQUE = 'samsung'");
                       float dispo1=model->rowCount();

                       model->setQuery("select * from EQUIPMENTS where MARQUE = 'oppo'");
                       float dispo=model->rowCount();

                       model->setQuery("select * from EQUIPMENTS where MARQUE = 'appel'");
                       float dispo3=model->rowCount();

                       float total=dispo1+dispo+dispo3;
                           QString a=QString("samsung " +QString::number((dispo1*100)/total,'f',2)+"%" );
                           QString b=QString("oppo  " +QString::number((dispo*100)/total,'f',2)+"%" );
                           QString c=QString("appel  " +QString::number((dispo3*100)/total,'f',2)+"%" );
                           QPieSeries *series = new QPieSeries();
                           series->append(a,dispo1);
                           series->append(b,dispo);
                           series->append(c,dispo3);
                       if (dispo1!=0)
                       {QPieSlice *slice = series->slices().at(0);
                           slice->setLabelVisible();
                           slice->setPen(QPen());}
                       if ( dispo!=0)
                       {
                           QPieSlice *slice1 = series->slices().at(1);
                           slice1->setLabelVisible();
                           slice1->setPen(QPen());
                       }
                       if (dispo3!=0)
                       {QPieSlice *slice = series->slices().at(2);
                           slice->setLabelVisible();
                           slice->setPen(QPen());}

                       QChart *chart = new QChart();


                       chart->addSeries(series);
                       chart->setTitle("Nombre: "+ QString::number(total));



                       QChartView *chartView = new QChartView(chart);
                       chartView->setRenderHint(QPainter::Antialiasing);
                       chartView->resize(1300,800);
                       chartView->show();
}

void MainWindow::on_qrcodegen_2_clicked()
{
    ui->t11->setModel(tmp.Afficher1());

}

void MainWindow::on_envoyer_mail_2_clicked()
{
    ui->t12->setModel(etmp.suivie());

}

void MainWindow::on_PDF_2_clicked()
{
    etmp.telechargerPDF();







                   QMessageBox::information(nullptr,QObject::tr("OK"),



                              QObject::tr("Téléchargement terminé"), QMessageBox::Cancel);

}
