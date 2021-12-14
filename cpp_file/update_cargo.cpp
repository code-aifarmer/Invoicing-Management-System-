#include "update_cargo.h"
#include "ui_update_cargo.h"
#include "QMessageBox"
#include "database.h"
#include "QDebug"
#include "login.h"
update_cargo::update_cargo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::update_cargo)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    database *db = database::getdatabase();
    cargo = db->getCargoByGid(update_cargo_gid);
    ui->name->setText(cargo->getName());
    ui->purchase_price->setText(QString::number(cargo->getPurchase_price()));
    ui->sale_price->setText(QString::number(cargo->getSale_price()));
    ui->stock->setText(QString::number(cargo->getStock()));
    ui->purchase_date->setText(cargo->getPurchase_date());
    cargo->setGid(update_cargo_gid);
    cargo->setSaller(self_sale_name);
    qDebug() << cargo->toString();
}

update_cargo::~update_cargo()
{
    delete ui;
}

void update_cargo::on_pushButton_clicked()
{
    if(ui->name->toPlainText().isEmpty()||ui->purchase_date->toPlainText().isEmpty()||ui->purchase_price->toPlainText().isEmpty()||ui->sale_price->toPlainText().isEmpty()||ui->stock->toPlainText().isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息!");
        return;
    }
    database* db = database::getdatabase();
    cargo->setName(ui->name->toPlainText());
    cargo->setPurchase_price(ui->purchase_price->toPlainText().toDouble());
    cargo->setSale_price(ui->sale_price->toPlainText().toDouble());
    cargo->setStock(ui->stock->toPlainText().toInt());
    cargo->setPurchase_date(ui->purchase_date->toPlainText());

    bool succeed = db->update_cargo_info(cargo);
    if(!succeed) {
        //TODO
        qDebug() << "error in updating date";
    } else {
        //TODO
        qDebug() << "update succeed";
    }
    this->hide();
}

