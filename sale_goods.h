#ifndef SALE_GOODS_H
#define SALE_GOODS_H

#include <QMainWindow>

namespace Ui {
class sale_goods;
}

class sale_goods : public QMainWindow
{
    Q_OBJECT

public:
    explicit sale_goods(QWidget *parent = nullptr);
    ~sale_goods();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


public slots:
    void on_comboBox_currentIndexChanged();

private:
    Ui::sale_goods *ui;
};

#endif // SALE_GOODS_H
