#include "login.h"
#include "QRect"
#include <QApplication>
#include "QScreen"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "QFile"
#include "goods_manage.h"
#include "check_network.h"
#include "QtConcurrent"
#include "QTcpSocket"
#include "QFuture"
#include "openinganimation.h"
//#include <QtAndroidExtras>

//goods_manage* goods_manage::goods = new goods_manage();

QString yanzheng;
QString rmail;
int update_gid;
//QString index1;
int sum_sale;
QString select_name;
QSqlDatabase db;
QStringList* tracking;
int select_gid;
int single_num;
QString track_single;
int one_page;
QString current_buyer_name;
bool left_or_right;
bool left_or_right2;
QString friends_name;
QString self_sale_name;
int update_cargo_gid;
int fun();
static bool IPLive(QString ip, int port, int timeout = 1000) {
        QTcpSocket tcpClient;
        tcpClient.abort();
        tcpClient.connectToHost(ip, port);
        //100毫秒没有连接上则判断不在线
        return tcpClient.waitForConnected(timeout);
    }
//判断是否通外网
static bool IsWebOk() {

        return IPLive("121.37.168.139", 1433);
    }
int fun()
{
    while(1){
    if(!IsWebOk())
    {
        //qDebug()<<"HELLO!!!!!!!!!!!!!!!!!!!!!!S";
        //QMessageBox::critical(0, QObject::tr("网络问题"),"请检查网络！");
        return 0;
    }
    else
    {
        return 1;
    }
    }
    //while(1)qDebug()<<"HELLO!!!!!!!!!!!!!!!!!!!!!!S";
}
int main(int argc, char *argv[])
{
    //checkPermission();

    QApplication a(argc, argv);
    OpeningAnimation q;
    //q.show();
   // check_network *son_thread;
    //son_thread = new check_network;
   // son_thread->start();
    QtConcurrent::run(fun);
    QFuture<int> future = QtConcurrent::run(fun);
    int result = future.result();
    qDebug()<<result<<"00000000000000000";
    if(result ==0)
    {
        QMessageBox::critical(0, QObject::tr("网络问题"),"请检查网络！");
        return 0;
    }
    QApplication::addLibraryPath("./plugins");
    tracking = new QStringList();
    single_num = 0;
    one_page =0;

    Login w;
    q.hide();
    w.show();
    //son_thread->wait();
    return a.exec();
}

