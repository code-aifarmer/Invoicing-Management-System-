#ifndef SALE_CHAT_H
#define SALE_CHAT_H

#include <QMainWindow>
#include "audio.h"
namespace Ui {
class sale_chat;
}

class sale_chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit sale_chat(QWidget *parent = nullptr);
    ~sale_chat();
    QString tuling_get_ans;
    QString voice_get_ans;
    QString UI_ANS_String;
    audio* Audio;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();

private:
    Ui::sale_chat *ui;
};

#endif // SALE_CHAT_H
