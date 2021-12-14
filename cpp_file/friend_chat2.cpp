#include "friend_chat2.h"
#include "ui_friend_chat2.h"

friend_chat2::friend_chat2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::friend_chat2)
{
    ui->setupUi(this);
}

friend_chat2::~friend_chat2()
{
    delete ui;
}
