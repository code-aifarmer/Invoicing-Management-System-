#include "check_network.h"
#include "QTcpSocket"
#include "QMessageBox"
check_network::check_network(QObject *parent) : QThread(parent)
{

}
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
void check_network::run()
{


   if(!IsWebOk())
   {
        QMessageBox::critical(0, QObject::tr("网络问题"),"请检查网络！");
   }

}
