#include "friends_chat.h"
#include "ui_friends_chat.h"
#include "friend_list.h"
#include "QDebug"
#include "database.h"
#include "audio.h"
#include "speech.h"
friends_chat::friends_chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::friends_chat)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    ui->pushButton_3->setText("按住说话");
    database *userDb = database::getdatabase();
    //QString name = friend_list().get_name();
    //qDebug()<<name<<"54645655622";
    qDebug()<<friends_name;
    ui->label->setText("您正在与"+friends_name+"聊天");
    qDebug()<<"11111111111111111111111111111";

    QVector<int> info1 = userDb->judge_sale_or_user(friends_name);
    QList<QString> info2 = userDb->get_friends_message(friends_name);
    for(int i=0;i<info1.size();i++)
    {

        qDebug()<<"ttttttttttttt";



        QString message = info2[i];
        qDebug()<<info2[i]<<"000";
       if(info1[i]==0)
       {
           ui->textEdit->textCursor().insertText(friends_name+":");
           ui->textEdit->textCursor().insertText(info2[i]+"\n\n");
       }
       else if(info1[i]==1)
       {
           ui->textEdit->textCursor().insertText("您：");
           ui->textEdit->textCursor().insertText(info2[i]+"\n\n");
       }



    }







}

friends_chat::~friends_chat()
{
    delete ui;
}
void friends_chat::set()
{

}
void friends_chat::on_pushButton_clicked()
{
    (new friend_list)->show();
    this->hide();
    qDebug()<<friends_name<<"@@@@@@@@@@";
}


void friends_chat::on_pushButton_2_clicked()
{
    ui->textEdit->textCursor().insertText("我："+ui->lineEdit->text()+"\n\n");
    database *userDb = database::getdatabase();
    if(!userDb->write_into_messagebox(ui->lineEdit->text(),friends_name))
    {
        qDebug()<<"聊天记录保存失败！";
    }
    else
    {
        qDebug()<<"聊天记录保存成功！";
    }
    ui->lineEdit->clear();
}//发送消息


void friends_chat::on_pushButton_3_pressed()
{
    ui->pushButton_3->setText("松开识别");
    //开始录音
    Audio=new audio;
    Audio->startAudio("D:\\1.pcm");
}


void friends_chat::on_pushButton_3_released()
{
    Audio->stopAudio();
    //停止录音

    ui->pushButton_3->setText("开始识别");
    //开始识别
    Speach m_speech;
    QString text=m_speech.speechIdentify("D:\\1.pcm");
    ui->lineEdit->setText(text);
    ui->pushButton_3->setText("按住说话");
}

