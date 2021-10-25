#include "chat2.h"
#include "ui_chat2.h"
#include <QDesktopServices>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
#include "audio.h"
#include "saleuser_first_page.h"

chat2::chat2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat2)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    ui->pushButton_2->setText("按住说话");
}

chat2::~chat2()
{
    delete ui;
}

void chat2::on_pushButton_3_clicked()
{
    qDebug()<<"000000000000000000";
    ui->textEdit->textCursor().insertText("我："+ui->lineEdit->text()+"\n\n");
    QString Url="http://api.qingyunke.com/api.php?key=free&appid=0&msg="+ui->lineEdit->text();
    ui->lineEdit->clear();
       QUrl url;
       url.setUrl(Url);
       QNetworkRequest request(url);
       QNetworkAccessManager *manager=new QNetworkAccessManager(this);
       connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(Tuling_replyFinish(QNetworkReply*)));
       manager->get(request);
}
void chat2::Tuling_replyFinish(QNetworkReply *reply)
{

    QString data=reply->readAll();
    QJsonParseError json_error;
    QJsonDocument json=QJsonDocument::fromJson(data.toUtf8(),&json_error);
    //判断有没有错
    if(json_error.error==QJsonParseError::NoError)
    {
        if(json.isObject())
        {
            QJsonObject jsonObj=json.object();
            if(jsonObj.contains("content"))
            {
                //qDebug()<<"成功获取text";
                QJsonValue text_value=jsonObj.take("content");
                if(text_value.isString())
                {
                    tuling_get_ans=text_value.toVariant().toString();
                    tuling_get_ans.replace("br","\n");
                    //qDebug()<<"!!!返回的ans:"<<tuling_get_ans;
                }
            }
        }
    }
    reply->deleteLater();
    ui->textEdit->textCursor().insertText("客服："+tuling_get_ans+"\n\n");
    //QString content = ui.contentTextEdit->append(message+"\n");
}


void chat2::on_pushButton_2_pressed()
{
    ui->pushButton_2->setText("松开识别");
    //开始录音
    Audio=new audio;
    Audio->startAudio("D:\\1.pcm");

}


void chat2::on_pushButton_2_released()
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


void chat2::on_pushButton_clicked()
{
    //(new saleuser_first_page)->show();
    this->hide();
}

