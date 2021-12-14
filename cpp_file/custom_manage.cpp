#include "custom_manage.h"
#include "ui_custom_manage.h"
#include "first_page.h"
custom_manage::custom_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::custom_manage)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
}

custom_manage::~custom_manage()
{
    delete ui;
}

void custom_manage::on_pushButton_clicked()
{
    (new first_page)->show();
    this->hide();
}

