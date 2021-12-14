#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();


private slots:
    void on_pushButton_6_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_register_2_clicked();

    void on_login_button_clicked();

    void on_radioButton_clicked();

    //void on_pushButton_3_clicked();

    void on_forget_password_clicked();

private:
    Ui::Login *ui;


};
extern QString self_sale_name;
#endif // LOGIN_H
