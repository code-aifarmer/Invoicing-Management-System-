#include "profit.h"
#include "ui_profit.h"

profit::profit(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profit)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
}

profit::~profit()
{
    delete ui;
}
