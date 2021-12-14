#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include<QtNetwork>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
//#include "audio.h"
//#include "speech.h"
namespace Ui {
class chat;
}

class chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
    //audio* Audio;


public slots:
     void Tuling_replyFinish(QNetworkReply* reply);
private slots:
     void on_pushButton_3_clicked();

     //void on_pushButton_2_clicked();
     //void on_pushButton_2_pressed();
     //void on_pushButton_2_released();
     //void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_clicked();

private:
    Ui::chat *ui;
};

#endif // CHAT_H
