#ifndef CARGO_SALE_H
#define CARGO_SALE_H

#include <QMainWindow>

namespace Ui {
class cargo_sale;
}

class cargo_sale : public QMainWindow
{
    Q_OBJECT

public:
    explicit cargo_sale(QWidget *parent = nullptr);
    ~cargo_sale();

private slots:
    void on_pushButton_clicked();

private:
    Ui::cargo_sale *ui;
};

#endif // CARGO_SALE_H
