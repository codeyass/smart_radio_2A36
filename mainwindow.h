#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "emission.h"
#include <QMessageBox>
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
    void on_pushButton_ajout_clicked();

    void on_pushButton_2_clicked();

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

private:
    Ui::MainWindow *ui;
    Emission C;
};
#endif // MAINWINDOW_H
