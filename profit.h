#ifndef PROFIT_H
#define PROFIT_H

#include <QMainWindow>

namespace Ui {
class profit;
}

class profit : public QMainWindow
{
    Q_OBJECT

public:
    explicit profit(QWidget *parent = nullptr);
    ~profit();

private:
    Ui::profit *ui;
};

#endif // PROFIT_H
