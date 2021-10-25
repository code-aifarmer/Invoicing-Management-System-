#ifndef INPUT_CARGO_H
#define INPUT_CARGO_H

#include <QMainWindow>

namespace Ui {
class input_cargo;
}

class input_cargo : public QMainWindow
{
    Q_OBJECT

public:
    explicit input_cargo(QWidget *parent = nullptr);
    ~input_cargo();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::input_cargo *ui;
};

#endif // INPUT_CARGO_H
