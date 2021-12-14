#include "charts_manage.h"
#include "ui_charts_manage.h"
#include "poiyline_chart.h"
#include "first_page.h"
#include "qu_line.h"
#include "point_chart.h"
#include "bar_chart.h"
#include "pie_chart.h"
#include "qu_chart_real.h"
#include <QGraphicsDropShadowEffect>
#include "goods_manage.h"
#include "charts_manage.h"
#include "sale_manage.h"
#include "QMessageBox"
charts_manage::charts_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::charts_manage)
{
    ui->setupUi(this);this->showMaximized();
     //this->showMaximized();
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow4 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow5 = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(5, 7);//阴影的偏移量
    shadow->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow->setBlurRadius(8); // 阴影圆角的大小

    shadow1->setOffset(5, 7);//阴影的偏移量
    shadow1->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow1->setBlurRadius(8); // 阴影圆角的大小

    shadow2->setOffset(5, 7);//阴影的偏移量
    shadow2->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow2->setBlurRadius(8); // 阴影圆角的大小

    shadow3->setOffset(5, 7);//阴影的偏移量
    shadow3->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow3->setBlurRadius(8); // 阴影圆角的大小

    shadow4->setOffset(5, 7);//阴影的偏移量
    shadow4->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow4->setBlurRadius(8); // 阴影圆角的大小

    shadow5->setOffset(5, 7);//阴影的偏移量
    shadow5->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow5->setBlurRadius(8); // 阴影圆角的大小

    ui->pushButton->setGraphicsEffect(shadow);
    ui->pushButton_2->setGraphicsEffect(shadow1);
    ui->pushButton_3->setGraphicsEffect(shadow2);
    ui->pushButton_4->setGraphicsEffect(shadow3);
    ui->pushButton_5->setGraphicsEffect(shadow4);
    ui->pushButton_6->setGraphicsEffect(shadow5);



    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
}

charts_manage::~charts_manage()
{
    delete ui;
}

void charts_manage::on_pushButton_3_clicked()//折线图
{
    if(track_single == "")
    {
        QMessageBox::about(NULL,"提示","请先将商品加入单元统计！");
        return;
    }
    (new poiyline_chart)->show();
}


void charts_manage::on_pushButton_7_clicked()
{
    (new first_page)->show();
    this->hide();
}


void charts_manage::on_pushButton_5_clicked()//曲线图
{

    if(track_single == "")
    {
        QMessageBox::about(NULL,"提示","请先将商品加入单元统计！");
        return;
    }
    (new qu_chart_real)->show();
    //this->hide();
    //this->hide();
}


void charts_manage::on_pushButton_6_clicked()//散点图
{
    (new point_chart)->show();
    //this->hide();
}


void charts_manage::on_pushButton_2_clicked()//柱状图
{
    if(tracking->isEmpty())
    {
        QMessageBox::about(NULL,"提示","请先将商品加入多元统计！");
        return;
    }
    (new bar_chart)->show();
}


void charts_manage::on_pushButton_4_clicked()//饼图
{
    if(tracking->isEmpty())
    {
        QMessageBox::about(NULL,"提示","请先将商品加入多元统计！");
        return;
    }
    (new pie_chart)->show();
    //this->hide();
}


void charts_manage::on_pushButton_clicked()//面积图
{
    (new qu_line)->show();
}

