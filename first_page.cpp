#include "first_page.h"
#include "ui_first_page.h"
#include "login.h"
#include "goods_manage.h"
#include "sale_manage.h"
#include "custom_manage.h"
#include "supplier_manage.h"
#include "charts_manage.h"
#include "QMessageBox"
#include <QGraphicsDropShadowEffect>
#include "notebook.h"
#include "friend_list.h"
first_page::first_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::first_page)
{
    ui->setupUi(this);
    this->showMaximized();
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow3 = new QGraphicsDropShadowEffect(this);
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

    ui->pushButton_3->setGraphicsEffect(shadow);
    ui->pushButton_6->setGraphicsEffect(shadow1);
    ui->pushButton_7->setGraphicsEffect(shadow2);
    ui->pushButton_2->setGraphicsEffect(shadow3);

    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
}

first_page::~first_page()
{
    delete ui;
}

void first_page::on_pushButton_clicked()
{


    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "确认退出登录?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
    (new Login)->show();
    this->hide();
}


void first_page::on_pushButton_7_clicked()
{
    //(goods_manage::goods).show();
    (new goods_manage)->show();
    this->hide();
}


void first_page::on_pushButton_6_clicked()
{
    (new sale_manage)->show();
    this->hide();
}


void first_page::on_pushButton_4_clicked()
{
    (new custom_manage)->show();
    this->hide();
}


void first_page::on_pushButton_5_clicked()
{
    (new supplier_manage)->show();
    this->hide();
}


void first_page::on_pushButton_3_clicked()
{
    (new charts_manage)->show();
    this->hide();
}


void first_page::on_pushButton_2_clicked()
{
    (new friend_list)->show();
    //this->hide();
}

