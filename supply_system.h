#ifndef SUPPLY_SYSTEM_H
#define SUPPLY_SYSTEM_H

#include <QMainWindow>
#include "QTableView"
#include "QMessageBox"
#include "QAbstractItemModel"
#include "QSplitter"
namespace Ui {
class supply_system;
}

class supply_system : public QMainWindow
{
    Q_OBJECT

public:
    explicit supply_system(QWidget *parent = nullptr);
    ~supply_system();
    supply_system *getcargo() const;
    void setcargo(supply_system *cargo);
    void Table2ExcelByHtml(QTableView *table,QString title);
    void text_find();
    void setBtnPos();
    void setBtnPos1();
    void setBtnIcon();

private:
    QPoint dragPosition;
    bool bPressFlag;
    //QSplitter *splitter;
    //QFrame *contentFrame;
    //QFrame *listFrame;
    QPushButton *pushButtonn;
    //QPushButton *pushButton1;
    QIcon leftIcon;
    QIcon rightIcon;
protected:
    void mousePressEvent ( QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
private slots:
    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();
    void slotSplitterMoved(int pos, int index);
     void slotClickedBtn();

private:
    Ui::supply_system *ui;
};

#endif // SUPPLY_SYSTEM_H
