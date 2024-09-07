#ifndef SUPPLIER_MANAGE_H
#define SUPPLIER_MANAGE_H

#include <QMainWindow>

namespace Ui {
class supplier_manage;
}

class supplier_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit supplier_manage(QWidget *parent = nullptr);
    ~supplier_manage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::supplier_manage *ui;
};

#endif // SUPPLIER_MANAGE_H
