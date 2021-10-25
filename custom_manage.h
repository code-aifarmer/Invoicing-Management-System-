#ifndef CUSTOM_MANAGE_H
#define CUSTOM_MANAGE_H

#include <QMainWindow>

namespace Ui {
class custom_manage;
}

class custom_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit custom_manage(QWidget *parent = nullptr);
    ~custom_manage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::custom_manage *ui;
};

#endif // CUSTOM_MANAGE_H
