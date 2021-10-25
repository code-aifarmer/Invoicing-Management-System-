#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>
#include "QTableView"
namespace Ui {
class notebook;
}

class notebook : public QMainWindow
{
    Q_OBJECT

public:
    explicit notebook(QWidget *parent = nullptr);
    ~notebook();
    void text_find();
    void Table2ExcelByHtml(QTableView *table,QString title);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::notebook *ui;
};

#endif // NOTEBOOK_H
