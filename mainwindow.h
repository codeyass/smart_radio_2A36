#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sponsors.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QSqlTableModel>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//try


private slots:




    void on_Ajouter_3_clicked();



    void on_pushButton_supp_3_clicked();

   // void on_pushButton_a_clicked();

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

private:
    Ui::MainWindow *ui;
     Sponsors S1;
     QTableView* view;
     QSqlTableModel* model;

};
#endif // MAINWINDOW_H

