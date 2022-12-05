#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include "arduino.h"

namespace Ui {
class Secdialog;
}

class Secdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Secdialog(QWidget *parent = nullptr);
    ~Secdialog();

private slots:


    void on_continuer_clicked();

private:
    Ui::Secdialog *ui;
     QByteArray datas;
     Arduino A1;
};

#endif // SECDIALOG_H
