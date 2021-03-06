#include "chat.h"
#include "ui_chat.h"
#include <QDesktopServices>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
//#include "audio.h"
#include "saleuser_first_page.h"
chat::chat(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chat)
{

    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    //ui->pushButton_2->setText("按住说话");
}

chat::~chat()
{
    delete ui;
}

void chat::on_pushButton_3_clicked()
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

void chat::Tuling_replyFinish(QNetworkReply *reply)
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

}


void chat::on_pushButton_4_clicked()
{
    qDebug()<<"12345";
}


void chat::on_pushButton_clicked()
{
    qDebug()<<"!!!!!!!!!!!!!!!!!";
    (new saleuser_first_page)->show();
    this->hide();
}

