#ifndef FIND_PASSWORD_H
#define FIND_PASSWORD_H

#include <QMainWindow>

namespace Ui {
class find_password;
}

class find_password : public QMainWindow
{
    Q_OBJECT

public:
    explicit find_password(QWidget *parent = nullptr);
    ~find_password();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::find_password *ui;
};

#endif // FIND_PASSWORD_H
