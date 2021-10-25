#include "friend_list.h"
#include "ui_friend_list.h"
#include "QStringListModel"
#include "database.h"
#include "QDebug"
#include "friends_chat.h"
#include "QMessageBox"
friend_list::friend_list(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::friend_list)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
   QStringList theStrList;

     database *userDb = database::getdatabase();
     //QStringList list;
    QList<QString> info = userDb->get_friends_info();
    qDebug()<<"qqqqqqqqqqq";
    QList<QString>::iterator it;
    qDebug()<<"wwwwwwwwwwwwww";
    for(int i=0;i<info.size();i++)
    {

        qDebug()<<"ttttttttttttt";


       // qDebug()<<info[i];
        QString name = info[i];
        qDebug()<<name<<"000";
        //it++;

       // qDebug()<<name;
        theStrList<<"供货商用户名："+name+"\n";

    }






    theModel=new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::SelectedClicked);

}

friend_list::~friend_list()
{
    delete ui;
}

void friend_list::on_pushButton_2_clicked()
{
    this->hide();
}


void friend_list::on_listView_doubleClicked(const QModelIndex &index)
{

    qDebug()<<ui->listView->currentIndex().data().toString();
    QString s = "\n";
    QString s1 = "供货商用户名：";
    qDebug()<<"ui->listView->currentIndex().data().toString()";
    QString res = ui->listView->currentIndex().data().toString().mid(7,ui->listView->currentIndex().data().toString().size()-s.size()-s1.size());
    qDebug()<<res;
    friends_name = res;
    qDebug()<<friends_name<<"!!!!!!!!!!!!!!";
    (new friends_chat)->show();
    this->hide();


}
QString friend_list::get_name()
{
    qDebug()<<ui->listView->currentIndex().data().toString();
    QString s = "\n";
    QString s1 = "供货商用户名：";
    QString res = ui->listView->currentIndex().data().toString().mid(7,ui->listView->currentIndex().data().toString().size()-s.size()-s1.size());
    return res;
}

void friend_list::on_pushButton_clicked()
{
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "确认删除该供货商?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
     database *userDb = database::getdatabase();
     QString name = get_name();
     if(userDb->del_support(name))
     {
         qDebug()<<"del success!";
     }
     else
     {
         qDebug()<<"error!";
     }
     this->hide();
     (new friend_list)->show();


}

