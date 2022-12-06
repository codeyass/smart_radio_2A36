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
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "dialog.h"
#include "secdialog.h"
#include "emission.h"
#include "employe.h"
#include "arduino.h"
#include <QUrl>
#include <QSystemTrayIcon>
#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
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
#include <QMainWindow>
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <QUrl>
#include <QSystemTrayIcon>

#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include <QMainWindow>
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <QUrl>
#include <QSystemTrayIcon>
#include<QWidget>

#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>

#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include<QVBoxLayout>
#include<QMenu>
#include<QAction>

#include <equipement.h>
#include <historique.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Position {
    int x;
    int y;
};


class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class QVBoxLayout;
class QMenu;
class QAction;

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

void on_browse_clicked();

// ******************** Emission ***********************

void on_pushButton_S_E_clicked();
void on_menu_6_clicked();

void on_pushButton_ajout_clicked();

void on_modifEm_clicked();

void on_pb_supprimer_clicked();

void on_pushButton_10_clicked();

void on_pushButton_11_clicked();

void on_pushButton_5_clicked();

bool controlId(int id);

bool controlDuree(int test);

bool controlVide(QString test);

void on_cb_id_modif_activated(const QString &arg1);

void on_pushButton_13_clicked();

void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);
void on_stat_clicked();

void on_rechercher_button_clicked();
void on_radioButton_croissant_clicked();

void on_radioButton_dcroissant_clicked();

void on_pushButton_encrypt_clicked();

 void on_pb_envoyer_clicked();
     void on_pushButton_decrypt_clicked();
     void on_actionReset_Fields_triggered();
     void on_actionClear_Plain_Text_triggered();
     void on_actionClear_Encrypted_Text_triggered();
     void on_actionExit_triggered();
     void on_actionAbout_Qt_triggered();
     void on_comboBox_currentTextChanged(const QString &arg1);

void on_btn_imp_clicked();


void on_lineEdit_CC_key_cursorPositionChanged(int arg1, int arg2);

void on_comboBox_activated(const QString &arg1);

// Employee

void on_Ajouter_4_clicked();

void on_pushButton_supp_4_clicked();

void on_spot_2_clicked();

void on_pushButton_3_clicked();

//void on_pushButton_update_4_clicked();

void on_pushButton_S_2_clicked();

void on_menu_4_clicked();

void on_pushButton_update_4_clicked();


void on_pushButton_clicked();

void on_pushButton_4_clicked();

void on_pushButton_S_5_clicked();

void on_ajouter_2_clicked();

void on_supprimer_2_clicked();

void on_chercher_2_clicked();

void on_modifier_2_clicked();

void on_label_stat2_2_linkActivated(const QString &link);

void on_pushButton_update_5_clicked();

void on_radioButton_clicked();

void on_statsmed_2_clicked();

void on_PDF_2_clicked();

void on_menu_8_clicked();

void on_qrcodegen_2_clicked();

void on_envoyer_mail_2_clicked();

private:
    Ui::MainWindow *ui;
     Sponsors S1;
     employe E;
     QTableView* view;
     QSqlTableModel* model;
     QByteArray data;
     Arduino T;

     INVITES I;
     QStringList files;

     //amen
     Equipement eq;
         Equipement etmp;
         historique tmp;


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
// chaimaaa
         Emission C;
         bool dateTimeEditS_hadfocus = false;
         bool dateTimeEditE_hadfocus = false;

         QString ewCaesarCipher(QString plainText, int key);
             QString dwCaesarCipher(QString encryptedText, int key);

             QString ewPlayfair(QString plainText, QString secret);
             QString dwPlayfair(QString encryptedText, QString secret);

             char pfMatrix[5][5];
           bool inSameRow(Position p1, Position p2);
          bool inSameColumn(Position p1, Position p2);
             void normalizePFString(std::string &str);
             void normalizePFSecret(std::string &secret);
             void populatePFMatrix(std::string secret);
             std::string encryptPFString(std::string plainStdText);
             std::string decryptPFString(std::string encryptedStdText);
            Position findPositionByChar(char ch);
             char findCharByPosition(Position p);

             QString ewDES(QString plainText, std::string key);
             QString dwDES(QString encryptedText, std::string key);
             std::vector<std::string> keyPreparation(std::string key);
             QString DESEncryption(std::string dataBlock, std::vector< std::string > keys);
             std::string apply_xor(std::string str1, std::string str2);
             std::string apply_func_F(std::string str1, std::string str2);
             std::string apply_func_E(std::string str);

             QString ewIDES(QString plainText, std::string key);
             QString dwIDES(QString encryptedText, std::string key);
             std::vector< std::string > textToBinaryAscii(std::string str);
             std::string binaryAsciiToText(std::string str);
             std::string charToBinaryAscii(char ch);
             char binaryAsciiToChar(std::string binaryAscii);

             double ewRSA(double msg, double p, double q);
             double dwRSA(double msg, double p, double q);
             double RSAEncryption(double msg, double n, double e);
             double RSADecryption(double msg, double n, double d);
             std::pair<double, double> RSAKeys(double p, double q);
             int gcd(int a, int h);

             QString ewRC4(QString msg, QString key);
             QString dwRC4(QString msg, QString key);
             QString RC4Encryption(std::vector< std::bitset<8> > msg_bytes, std::vector< std::bitset<8> > keys);
             std::vector< std::bitset<8> > keysGenerator(int msg_length, std::vector<int> s);
             std::vector< std::bitset<8> > bytesOfMessage(std::string msg);

             QCamera *mCamera;
             QCameraViewfinder *mCameraViewfinder;
             QCameraImageCapture *mCameraImageCapture;
             QVBoxLayout *mLayout;
             QMenu *mOpcionesMenu;
             QAction *mEncenderAction;
             QAction *mApagarAction;
             QAction *mCapturarAction;

};
#endif // MAINWINDOW_H

