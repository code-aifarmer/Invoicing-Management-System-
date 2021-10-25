#include "register.h"
#include "ui_register.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "widget.h"
#include "login.h"
#include "database.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include "QButtonGroup"
Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
   // ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    setWindowFlags(Qt::FramelessWindowHint);

    ui->Input_name->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->set_password->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->confirm_password->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->Input_email->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->confirm->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    //ui->pushButton_2->setStyleSheet("border-radius:10px");
    ui->Input_name->setPlaceholderText( "请设置您的账号" );
    ui->set_password->setPlaceholderText( "请设置您的密码" );
    ui->confirm_password->setPlaceholderText( "请再次输入您的密码" );
    ui->Input_email->setPlaceholderText( "请输入您的qq邮箱" );
    ui->confirm->setPlaceholderText( "请输入验证码" );
    //connect(mainwindow,SIGNAL(signal_ipdisconnect()),this,SLOT(slot_ipdisconnect()));


    groupButton1=new QButtonGroup(this);
    groupButton1->addButton(ui->radioButton,0);
    //groupButton2=new QButtonGroup(this);
    groupButton1->addButton(ui->radioButton_2,1);
    groupButton1->setExclusive(true);

}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    rmail=ui->Input_email->text();
    Widget *s=new Widget();
}


void Register::on_pushButton_3_clicked()
{
    (new Login)->show();
    this->hide();
}


void Register::on_pushButton_2_clicked()
{

    if(ui->radioButton->isChecked())
    {
    QString username,password,email;
    if(ui->set_password->text()==""){
        QMessageBox::about(NULL,"提示","密码不能为空");
    }
    QString judge_same_password1 = ui->set_password->text();
    QString judge_same_password2 = ui->confirm_password->text();
    if(judge_same_password1!=judge_same_password2)
    {
        QMessageBox::about(NULL,"提示","两次输入的密码不一致");
        return;
    }
    if(ui->Input_name->text()=="")
    {
        QMessageBox::about(NULL,"提示","账号不能为空");
    }
    else
    {
         username = ui->Input_name->text();
    }
    if(judge_same_password1 == judge_same_password2)
    {
         password = ui->confirm_password->text();
    }
    if(ui->Input_email->text() == "")
    {
        QMessageBox::about(NULL,"提示","邮箱不能为空");
    }
    else
    {
         email = ui->Input_email->text();
    }
    if(ui->confirm->text()!="pass")//仅供调试期间使用，正式运行删掉ui->confirm->text()!="pass"
    if(ui->confirm->text() != yanzheng || ui->confirm->text()=="")
    {
        QMessageBox::about(NULL,"提示","验证码有误");
        return;
    }
    //控制台输出测试部分
        qDebug() << "username : " << username;
        qDebug() << "password : " << password;
        qDebug() << "email    : " << email;

    //
        database *userDb = database::getdatabase();

    //判断用户名在数据库中是否存在，违规弹出注册失败弹窗
        if(userDb->queryusername(username)){
            QMessageBox::information(NULL,"注册","用户名已被注册",QMessageBox::Ok);
            return;
        }



    //判断手机号在数据库中是否存在，违规弹出注册失败弹窗
        if(userDb->queryemail(email)){
            QMessageBox::information(NULL,"注册","邮箱号只能绑定一个账号，注册失败",QMessageBox::Ok);
            return;
        }
    //打开数据库
        bool ok = userDb->addRegiserUser(username,password,email);
        if(!ok)
        {
            //qDebug()<<password;
            QMessageBox::information(NULL,"注册","注册失败",QMessageBox::Ok);
        }
        else{
            QMessageBox::information(NULL,"注册","注册成功",QMessageBox::Ok);

        }
}
    else if(ui->radioButton_2->isChecked())
    {
        QString username,password,email;
        if(ui->set_password->text()==""){
            QMessageBox::about(NULL,"提示","密码不能为空");
        }
        QString judge_same_password1 = ui->set_password->text();
        QString judge_same_password2 = ui->confirm_password->text();
        if(judge_same_password1!=judge_same_password2)
        {
            QMessageBox::about(NULL,"提示","两次输入的密码不一致");
            return;
        }
        if(ui->Input_name->text()=="")
        {
            QMessageBox::about(NULL,"提示","账号不能为空");
        }
        else
        {
             username = ui->Input_name->text();
        }
        if(judge_same_password1 == judge_same_password2)
        {
             password = ui->confirm_password->text();
        }
        if(ui->Input_email->text() == "")
        {
            QMessageBox::about(NULL,"提示","邮箱不能为空");
        }
        else
        {
             email = ui->Input_email->text();
        }
        if(ui->confirm->text()!="pass")//仅供调试期间使用，正式运行删掉ui->confirm->text()!="pass"
        if(ui->confirm->text() != yanzheng || ui->confirm->text()=="")
        {
            QMessageBox::about(NULL,"提示","验证码有误");
            return;
        }
        //控制台输出测试部分
            qDebug() << "username : " << username;
            qDebug() << "password : " << password;
            qDebug() << "email    : " << email;

        //
            database *userDb = database::getdatabase();

        //判断用户名在数据库中是否存在，违规弹出注册失败弹窗
            if(userDb->queryusername_Saleuser(username)){
                QMessageBox::information(NULL,"注册","用户名已被注册",QMessageBox::Ok);
                qDebug()<<"?????????????";
                return;
            }
            if(!userDb->create_messagebox(username))
            {
                qDebug()<<"聊天记录存储失败！！";
                QMessageBox::about(NULL,"提示","ERROR!");
                return;
            }
        //判断手机号在数据库中是否存在，违规弹出注册失败弹窗
            if(userDb->queryemail_Saleuser(email)){
                QMessageBox::information(NULL,"注册","邮箱号只能绑定一个账号，注册失败",QMessageBox::Ok);
                return;
            }
        //打开数据库
            //bool ok = userDb->addRegiserUser(username,password,email);
            bool ok = userDb->addRegiserUser_Saleuser(username,password,email);
            if(ok)
            {
                //qDebug()<<password;
                qDebug()<<username<<" "<<password<<" "<<email;

                QMessageBox::information(NULL,"注册","注册失败",QMessageBox::Ok);
            }
            else{
                QMessageBox::information(NULL,"注册","注册成功",QMessageBox::Ok);
            }
    }

}


void Register::on_back_clicked()
{
    (new Login)->show();
    this->hide();
}

