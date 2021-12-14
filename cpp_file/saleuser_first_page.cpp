#include "saleuser_first_page.h"
#include "ui_saleuser_first_page.h"
#include "first_page.h"
#include "login.h"
#include "QGraphicsDropShadowEffect"
#include "chat.h"
#include "chat2.h"
#include "supply_system.h"
#include "sale_chat.h"
saleuser_first_page::saleuser_first_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::saleuser_first_page)
{
    ui->setupUi(this);
    this->showMaximized();
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow1 = new QGraphicsDropShadowEffect(this);
    QGraphicsDropShadowEffect *shadow2 = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(5, 7);//阴影的偏移量
    shadow->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow->setBlurRadius(8); // 阴影圆角的大小

    shadow1->setOffset(5, 7);//阴影的偏移量
    shadow1->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow1->setBlurRadius(8); // 阴影圆角的大小

    shadow2->setOffset(5, 7);//阴影的偏移量
    shadow2->setColor(QColor(43, 43, 43));//阴影的颜色
    shadow2->setBlurRadius(8); // 阴影圆角的大小

    ui->pushButton_2->setGraphicsEffect(shadow);
    ui->pushButton->setGraphicsEffect(shadow1);
    ui->pushButton_4->setGraphicsEffect(shadow2);


    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
}

saleuser_first_page::~saleuser_first_page()
{
    delete ui;
}

void saleuser_first_page::on_pushButton_3_clicked()
{
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "确认退出登录?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;
    (new Login)->show();
    this->hide();
}//返回


void saleuser_first_page::on_pushButton_4_clicked()
{
    (new chat2)->show();

}


void saleuser_first_page::on_pushButton_2_clicked()
{
    (new supply_system)->show();
    this->hide();
}


void saleuser_first_page::on_pushButton_clicked()
{
    (new sale_chat)->show();
    //this->hide();
}

