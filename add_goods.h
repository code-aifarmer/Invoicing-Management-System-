#ifndef ADD_GOODS_H
#define ADD_GOODS_H

#include <QMainWindow>
#include "goods_manage.h"
namespace Ui {
class add_goods;
}

class add_goods : public QMainWindow
{
    Q_OBJECT

public:
    explicit add_goods(QWidget *parent = nullptr);
    ~add_goods();
    //goods_manage w;


    goods_manage *getGoods() const;
    void setGoods(goods_manage *newGoods);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::add_goods *ui;
    goods_manage* goods;
};

#endif // ADD_GOODS_H
