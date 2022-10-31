#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

#include <QString>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/MSI/Desktop/Radio/IMG/smart_radio.png");
   ui->label_pic->setPixmap(pix.scaled(400,300,Qt::KeepAspectRatio));
   ////////////////////////
   //QPixmap pix1("C:/Users/MSI/Desktop/smartRadio/img/login.jpg");
  //ui->log->setPixmap(pix1.scaled(100,100,Qt::KeepAspectRatio));





}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_password->text();

    if(username=="test" && password=="test")
    {


        QMessageBox::information(this,"Login","Username and Password are correct");
        hide();
        dialog = new Dialog(this);
        dialog->show();
        hide();

    }

    else


        QMessageBox::warning(this,"Login","Username and Password are not correct");

}
