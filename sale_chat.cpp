#include "sale_chat.h"
#include "ui_sale_chat.h"
#include "QDebug"
#include "database.h"
#include "login.h"
#include "saleuser_first_page.h"
#include "speech.h"
sale_chat::sale_chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sale_chat)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    ui->pushButton_2->setText("按住说话");
    database *userDb = database::getdatabase();
    QVector<int> info1 = userDb->judge_sale_or_user(self_sale_name);
    QList<QString> info2 = userDb->get_friends_message(self_sale_name);
    for(int i=0;i<info1.size();i++)
    {

        qDebug()<<"ttttttttttttt";



        QString message = info2[i];
        qDebug()<<info2[i]<<"000";
       if(info1[i]==0)
       {
           ui->textEdit->textCursor().insertText("您：");
           ui->textEdit->textCursor().insertText(info2[i]+"\n\n");
       }
       else if(info1[i]==1)
       {
           ui->textEdit->textCursor().insertText("经销商：");
           ui->textEdit->textCursor().insertText(info2[i]+"\n\n");
       }



    }

}

sale_chat::~sale_chat()
{
    delete ui;
}

void sale_chat::on_pushButton_3_clicked()
{
    ui->textEdit->textCursor().insertText("我："+ui->lineEdit->text()+"\n\n");
    database *userDb = database::getdatabase();
    if(!userDb->support_write_into_messagebox(ui->lineEdit->text(),self_sale_name))
    {
        qDebug()<<"聊天记录保存失败！";
    }
    else
    {
        qDebug()<<"聊天记录保存成功！";
    }
    ui->lineEdit->clear();
}


void sale_chat::on_pushButton_clicked()
{
    //(new saleuser_first_page)->show();
    this->hide();
}


void sale_chat::on_pushButton_2_pressed()
{
    ui->pushButton_2->setText("松开识别");
    //开始录音
    Audio=new audio;
    Audio->startAudio("D:\\1.pcm");
}


void sale_chat::on_pushButton_2_released()
{
    Audio->stopAudio();
    //停止录音

    ui->pushButton_2->setText("开始识别");
    //开始识别
    Speach m_speech;
    QString text=m_speech.speechIdentify("D:\\1.pcm");
    ui->lineEdit->setText(text);
    ui->pushButton_2->setText("按住说话");
}

