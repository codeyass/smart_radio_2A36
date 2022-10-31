#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "INVITES.h"
#include <QMainWindow>

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
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_modifier_clicked();

    void on_quitter_ajout_clicked();

    void on_quitter_supp_clicked();

    void on_quitter_modif_clicked();

private:
    Ui::MainWindow *ui;
    INVITES I;
};
#endif // MAINWINDOW_H