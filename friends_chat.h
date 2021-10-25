#ifndef FRIENDS_CHAT_H
#define FRIENDS_CHAT_H

#include <QMainWindow>
#include "friend_list.h"
#include "audio.h"
namespace Ui {
class friends_chat;
}

class friends_chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit friends_chat(QWidget *parent = nullptr);
    ~friends_chat();
    void set();
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
    audio* Audio;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

private:
    Ui::friends_chat *ui;
};

#endif // FRIENDS_CHAT_H
