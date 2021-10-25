#include "login.h"
#include "QRect"
#include <QApplication>
#include "QScreen"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "QFile"
#include "goods_manage.h"

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
/*
bool checkPermission() {
    QtAndroid::PermissionResult r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
    if(r == QtAndroid::PermissionResult::Denied) {
        QtAndroid::requestPermissionsSync( QStringList() << "android.permission.WRITE_EXTERNAL_STORAGE" );
        r = QtAndroid::checkPermission("android.permission.WRITE_EXTERNAL_STORAGE");
        if(r == QtAndroid::PermissionResult::Denied) {
             return false;
        }
   }
   return true;
}
*/
int main(int argc, char *argv[])
{
    //checkPermission();
    QApplication a(argc, argv);
    QApplication::addLibraryPath("./plugins");
    tracking = new QStringList();
    single_num = 0;
    one_page =0;
    //QRect screen =QGuiApplication::primaryScreen()->geometry();
    //int screenW = screen.width();
    //int screenH = screen.height();

/*
   db = QSqlDatabase::addDatabase("QSQLITE");
        QFile file("/storage/emulated/0/data/qtDb.db");
        if(!file.exists()||file.size()==0){
            QFile::copy("assets:/bbb/qtDb.db", "/storage/emulated/0/data/qtDb.db");
            file.setPermissions(QFile::ReadUser  | QFile::WriteUser);//设置权限
        }
        db.setDatabaseName("/storage/emulated/0/data/qtDb.db");
        db.open();
*/
    Login w;
    //w.setFixedSize(screenW,screenH);
    w.show();
    return a.exec();
}
