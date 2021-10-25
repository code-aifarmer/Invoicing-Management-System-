#include "find_password.h"
#include "ui_find_password.h"
#include "login.h"
#include "widget.h"
#include "database.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
find_password::find_password(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::find_password)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    ui->username->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->mail->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->set_password->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
     ui->confirm_code->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->username->setPlaceholderText( "帐号" );
    ui->mail->setPlaceholderText( "邮箱" );
    ui->confirm_code->setPlaceholderText( "请输入验证码" );
    ui->set_password->setPlaceholderText( "请输入新密码" );
}

find_password::~find_password()
{
    delete ui;
}

void find_password::on_pushButton_3_clicked()
{
    (new Login)->show();
    this->hide();
}


void find_password::on_pushButton_2_clicked()
{
    database *userDb = database::getdatabase();
    //if(userDb->findpassword(ui->username->text(),ui->mail->text())){
        //在数据库中查询到了就跳转到主页
        if(ui->confirm_code->text()=="")
        {
            QMessageBox::about(NULL,"提示","验证码不能为空!");
            return;
        }
        if(ui->confirm_code->text()!=yanzheng)
        {
            QMessageBox::about(NULL,"提示","验证码有误");
        }
        if(userDb->findpassword(ui->username->text(),ui->mail->text()) && ui->confirm_code->text() ==yanzheng ){
            QMessageBox::information(NULL,"提示","success");
            userDb->update_password(ui->username->text(),ui->set_password->text());
        }
        //在数据库中查询不到即弹出信息错误窗口
        else{
            QMessageBox::information(NULL,"提示","账号与邮箱不匹配");
            return;
        }
}


void find_password::on_pushButton_clicked()
{
    rmail=ui->mail->text();
    Widget *s=new Widget();
}

