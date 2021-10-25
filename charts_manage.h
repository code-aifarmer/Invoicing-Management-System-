#ifndef CHARTS_MANAGE_H
#define CHARTS_MANAGE_H

#include <QMainWindow>

namespace Ui {
class charts_manage;
}

class charts_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit charts_manage(QWidget *parent = nullptr);
    ~charts_manage();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::charts_manage *ui;
};

#endif // CHARTS_MANAGE_H
