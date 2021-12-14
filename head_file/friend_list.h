#ifndef FRIEND_LIST_H
#define FRIEND_LIST_H

#include <QMainWindow>
#include "QStringListModel"
//#include "friends_chat.h"
namespace Ui {
class friend_list;
}

class friend_list : public QMainWindow
{
    Q_OBJECT

public:
    explicit friend_list(QWidget *parent = nullptr);
    ~friend_list();
    QString get_name();
    //friends_chat p;


public slots:
    void on_pushButton_2_clicked();

    void on_listView_doubleClicked(const QModelIndex &index);

private slots:
    void on_pushButton_clicked();

private:
    Ui::friend_list *ui;
    QStringListModel *theModel;
};
extern QString friends_name;
#endif // FRIEND_LIST_H
