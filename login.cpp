#include "login.h"
#include "ui_login.h"
#include "register.h"
#include "database.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "QMessageBox"
#include "first_page.h"
#include "find_password.h"
#include "saleuser_first_page.h"
#include "QDebug"
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->showMaximized();
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    //setWindowFlags(Qt::FramelessWindowHint);

    //const QString m_SheetStyle = "min-width: 16px; min-height: 16px;max-width:16px; max-height: 16px;border-radius: 8px;  border:1px solid black;";
    //ui->avatar->setStyleSheet(m_SheetStyle);
    ui->login->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->password->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->login->setPlaceholderText( "帐号" );
    ui->password->setPlaceholderText( "密码" );
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_6_clicked()
{
       this->close();
}


//关闭窗口

//登录

void Login::on_pushButton_2_clicked()
{

    showMinimized();

}


void Login::on_register_2_clicked()
{
    (new Register)->show();
    this->hide();
}


void Login::on_login_button_clicked()
{

    if(!ui->radioButton_2->isChecked()){
    QString username = ui->login->text();
       //获取密码输入框的数据
       QString password = ui->password->text();

       database *userDb = database::getdatabase();
       if(userDb->queryusername(username)){
           //在数据库中查询到了就跳转到主页
           if(userDb->querypassword(username,password)){
               first_page *major = new first_page;
               major->show();//跳转到major页面
               qDebug()<<"1111111111111111111";
               this->close(); //关闭登陆页面
           }
           //在数据库中查询不到即弹出信息错误窗口
           else{
               QMessageBox::information(NULL,"登录","用户名或密码错误",QMessageBox::Ok);
               qDebug()<<"77777777777777777777777777";
               return;
           }
       }
       else{
           QMessageBox::information(NULL,"登录","用户名或密码错误！",QMessageBox::Ok);
           qDebug()<<"333333333333333333";
           //return;
       }
    }
    else
    {
        QString username = ui->login->text();
           //获取密码输入框的数据
           self_sale_name = ui->login->text();
           QString password = ui->password->text();

           database *userDb = database::getdatabase();
           if(userDb->queryusername_Saleuser(username)){
               //在数据库中查询到了就跳转到主页
               if(userDb->querypassword_Saleuser(username,password)){
                   //first_page *major = new first_page;
                   //major->show();//跳转到major页面
                   (new saleuser_first_page)->show();
                   qDebug()<<"1111111111111111111";
                   this->close(); //关闭登陆页面
               }
               //在数据库中查询不到即弹出信息错误窗口
               else{
                   QMessageBox::information(NULL,"登录","用户名或密码错误",QMessageBox::Ok);
                   qDebug()<<"22222222222222222222";
                   return;
               }
           }
           else{
               QMessageBox::information(NULL,"登录","用户名或密码错误！",QMessageBox::Ok);
               qDebug()<<"333333333333333333";
               //return;
           }
    }

}


void Login::on_pushButton_clicked()
{
    this->close();
}


void Login::on_radioButton_clicked()
{

}




void Login::on_forget_password_clicked()
{
    (new find_password)->show();
    this->hide();
}

