#include "supplier_manage.h"
#include "ui_supplier_manage.h"
#include "first_page.h"
supplier_manage::supplier_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::supplier_manage)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
     this->showMaximized();
}

supplier_manage::~supplier_manage()
{
    delete ui;
}

void supplier_manage::on_pushButton_clicked()
{
    (new first_page)->show();
    this->hide();
}

