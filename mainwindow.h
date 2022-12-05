#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sponsors.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QSqlTableModel>
#include "invites.h"
#include "arduino.h"
#include "arduino_invite.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "dialog.h"
#include "secdialog.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:


// ************* Sponsor **********************

    void on_Ajouter_3_clicked();

    void on_pushButton_supp_3_clicked();

    void on_pushButton_update_3_clicked();

    void on_Chercher_2_clicked();

    void on_pushButton_2_clicked();

    void on_TRI_2_clicked();

    void on_menu_clicked();

    void on_pushButton_login_clicked();

void on_pushButton_S_clicked();

void on_menu_2_clicked();

void on_commandLinkButton_clicked();

void on_photo_2_clicked();

void on_spot_clicked();

void on_pushButton_stat_clicked();

void on_pushButton_S_4_clicked();

void on_menu_3_clicked();

void update_label();


//**********************  Invitee *********************************************

void on_ajouter_clicked();

void on_supprimer_clicked();

void on_modifier_clicked();

void on_PDF_clicked();

void on_chercher_clicked();

void on_button_tri_clicked();
void on_statsmed_clicked();

void on_qrcodegen_clicked();

void on_envoyer_mail_clicked();
void sendMail();
void mailSent(QString);

void update_label_I();

private:
    Ui::MainWindow *ui;
     Sponsors S1;
     QTableView* view;
     QSqlTableModel* model;

     INVITES I;
     QStringList files;

// arduino yassmine
         QByteArray dataS;
         Arduino A1;
         Dialog d;
         Secdialog sec;

// arduino nousseiba et chaima

         QByteArray dataI; // variable contenant les données reçues
         Arduino A;
         QString c="";
         int t=0;

};
#endif // MAINWINDOW_H

