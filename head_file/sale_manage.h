#ifndef SALE_MANAGE_H
#define SALE_MANAGE_H

#include <QMainWindow>
#include "QTableView"
#include "QPushButton"
namespace Ui {
class sale_manage;
}

class sale_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit sale_manage(QWidget *parent = nullptr);
    void text_find();
    ~sale_manage();
    void Table2ExcelByHtml(QTableView *table,QString title);
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

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();
    void slotClickedBtn();
    void slotSplitterMoved(int pos, int index);

private:
    Ui::sale_manage *ui;

};
extern QStringList* tracking;
extern int single_num;
extern QString track_single;
extern QString current_buyer_name;
extern bool left_or_right2;
#endif // SALE_MANAGE_H
