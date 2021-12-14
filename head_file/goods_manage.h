#ifndef GOODS_MANAGE_H
#define GOODS_MANAGE_H

#include <QMainWindow>
#include "QStandardItemModel"
#include "QSqlQuery"
#include <QCoreApplication>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include "QDebug"
#include "QTableView"
#include "QMessageBox"
#include "QAbstractItemModel"
#include "QSplitter"
namespace Ui {
class goods_manage;
}

class goods_manage : public QMainWindow
{
    Q_OBJECT

public:
    explicit goods_manage(QWidget *parent = nullptr);
    QStandardItemModel *model1 = new QStandardItemModel();
    void text_find();
    //void on_tableView_customContextMenuRequested(QPoint pos);
   // void update_info();
    //void del_info();
    //int selected_current_row;
    //QMenu *popMenu;
     //void slotContextMenu(QPoint pos);
     //QMenu *tableviewMenue;
     //QAction *appendAction;
     //QAction *deleteAction;
     //QAction *prependAction;
     //QAction *translationAction;
    bool static save(QString filePath,QStringList headers,QList<QStringList> data,QString comment="");
    //将QTableView保存为excel
    bool static saveFromTable(QString filePath,QTableView *tableView,QString comment="");
    bool static insert(QSqlQuery& query, QString sheetName, QStringList slist);
    void setBtnPos();
    void setBtnPos1();
    void setBtnIcon();
    ~goods_manage();
    void reflush();
    void renew();


private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    //void slotContextMenu(QPoint pos);
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void slotClickedBtn();
    void slotSplitterMoved(int pos, int index);
    void on_pushButton_9_clicked();

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
public:
    Ui::goods_manage *ui;
    //    static goods_manage* goods;
    goods_manage *getGoods() const;
    void setGoods(goods_manage *newGoods);
    void handle_hide();
    void Table2ExcelByHtml(QTableView *table,QString title);
};
//extern QString index1;
extern int sum_sale;
extern QString select_name;
extern int select_gid;
extern int one_page;
extern bool left_or_right;
extern int fun();
#endif // GOODS_MANAGE_H
