#ifndef REGISTER_H
#define REGISTER_H

#include <QMainWindow>
#include "QButtonGroup"
#include "login.h"
namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    //Login back_login;
    ~Register();
    QButtonGroup *groupButton1;
    QButtonGroup *groupButton2;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_back_clicked();

private:
    Ui::Register *ui;

};

#endif // REGISTER_H
