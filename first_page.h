#ifndef FIRST_PAGE_H
#define FIRST_PAGE_H

#include <QMainWindow>

namespace Ui {
class first_page;
}

class first_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit first_page(QWidget *parent = nullptr);
    ~first_page();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::first_page *ui;
};

#endif // FIRST_PAGE_H
