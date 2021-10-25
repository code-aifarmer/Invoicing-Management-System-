#ifndef SALEUSER_FIRST_PAGE_H
#define SALEUSER_FIRST_PAGE_H

#include <QMainWindow>

namespace Ui {
class saleuser_first_page;
}

class saleuser_first_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit saleuser_first_page(QWidget *parent = nullptr);
    ~saleuser_first_page();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::saleuser_first_page *ui;
};

#endif // SALEUSER_FIRST_PAGE_H
