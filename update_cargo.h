#ifndef UPDATE_CARGO_H
#define UPDATE_CARGO_H

#include <QMainWindow>
#include "entity.h"

namespace Ui {
class update_cargo;
}

class update_cargo : public QMainWindow
{
    Q_OBJECT

public:
    explicit update_cargo(QWidget *parent = nullptr);
    ~update_cargo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::update_cargo *ui;
    Cargo* cargo;
};
extern  int update_cargo_gid;
#endif // UPDATE_CARGO_H
