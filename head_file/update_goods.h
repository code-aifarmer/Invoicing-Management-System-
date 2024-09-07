#ifndef UPDATE_GOODS_H
#define UPDATE_GOODS_H

#include <QMainWindow>

namespace Ui {
class update_goods;
}

class update_goods : public QMainWindow
{
    Q_OBJECT

public:
    explicit update_goods(QWidget *parent = nullptr);
    ~update_goods();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::update_goods *ui;

};
extern  int update_gid;
#endif // UPDATE_GOODS_H
