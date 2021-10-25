#ifndef CHAT2_H
#define CHAT2_H

#include <QMainWindow>
#include<QtNetwork>
#include <QUrl>
#include  <QtNetwork>
#include  <QNetworkAccessManager>
#include "audio.h"
#include "speech.h"
namespace Ui {
class chat2;
}

class chat2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit chat2(QWidget *parent = nullptr);
    ~chat2();
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
    audio* Audio;
public slots:
     void Tuling_replyFinish(QNetworkReply* reply);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

    void on_pushButton_clicked();

private:
    Ui::chat2 *ui;
};

#endif // CHAT2_H
