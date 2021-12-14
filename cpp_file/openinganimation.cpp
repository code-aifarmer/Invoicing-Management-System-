#include "openinganimation.h"
#include "ui_openinganimation.h"
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>
#include "QDateTime"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "QDebug"
#include "goods_manage.h"
#include "ui_goods_manage.h"
#include "database.h"
OpeningAnimation::OpeningAnimation(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OpeningAnimation)
{
    ui->setupUi(this);
    this->setStyle();//调用开场动画
}

void OpeningAnimation::setStyle(){
    //开场动画
    QSplashScreen splash1(QPixmap(QString(":/new/prefix1/welcome.png")));
    splash1.show();
    QEventLoop eventloop1;
    long startTime = QDateTime::currentMSecsSinceEpoch();
    database::getdatabase();
    long endTime = QDateTime::currentMSecsSinceEpoch();

//    qDebug() << "共用时" << (endTime - startTime) << "毫秒";
    QTimer::singleShot(4000,&eventloop1,SLOT(quit()));
    eventloop1.exec();
/*
    QSplashScreen splash2(QPixmap(QString(":/res/uuu2.png")));
    splash2.show();
    QEventLoop eventloop2;
    QTimer::singleShot(40,&eventloop2,SLOT(quit()));
    eventloop2.exec();

    QSplashScreen splash3(QPixmap(QString(":/res/uuu3.png")));
    splash3.show();
    QEventLoop eventloop3;
    QTimer::singleShot(40,&eventloop3,SLOT(quit()));
    eventloop3.exec();

    QSplashScreen splash4(QPixmap(QString(":/res/uuu4.png")));
    splash4.show();
    QEventLoop eventloop4;
    QTimer::singleShot(40,&eventloop4,SLOT(quit()));
    eventloop4.exec();

    QSplashScreen splash5(QPixmap(QString(":/res/uuu5.png")));
    splash5.show();
    QEventLoop eventloop5;
    QTimer::singleShot(40,&eventloop5,SLOT(quit()));
    eventloop5.exec();

    QSplashScreen splash6(QPixmap(QString(":/res/uuu6.png")));
    splash6.show();
    QEventLoop eventloop6;
    QTimer::singleShot(40,&eventloop6,SLOT(quit()));
    eventloop6.exec();

    QSplashScreen splash7(QPixmap(QString(":/res/uuu7.png")));
    splash7.show();
    QEventLoop eventloop7;
    QTimer::singleShot(40,&eventloop7,SLOT(quit()));
    eventloop7.exec();

    QSplashScreen splash8(QPixmap(QString(":/res/uuu8.png")));
    splash8.show();
    QEventLoop eventloop8;
    QTimer::singleShot(100,&eventloop8,SLOT(quit()));
    eventloop8.exec();
    */
}

OpeningAnimation::~OpeningAnimation()
{
    delete ui;
}
