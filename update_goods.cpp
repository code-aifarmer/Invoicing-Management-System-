#include "update_goods.h"
#include "ui_update_goods.h"
#include "database.h"
#include "QDebug"
#include <QSqlError>
#include "goods_manage.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <exception>
#include "QMessageBox"
update_goods::update_goods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::update_goods)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    database* db = database::getdatabase();
    QStringList* data = db->getGoodsByGid(update_gid);
    int i = 1;

    ui->name->textCursor().insertText(data->at(i++));
    ui->purchase_price->textCursor().insertText(data->at(i++));
    ui->sale_price->textCursor().insertText(data->at(i++));
    ui->stock->textCursor().insertText(data->at(i++));
    ui->purchase_date->textCursor().insertText(data->at(i++));
    ui->purchaser->textCursor().insertText(data->at(i++));
    ui->phone->textCursor().insertText(data->at(i++));
    ui->name->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->purchase_price->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->sale_price->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->stock->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->purchase_date->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->purchaser->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->phone->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");


}

update_goods::~update_goods()
{
    delete ui;
}

void update_goods::on_pushButton_clicked()
{
    if(ui->name->toPlainText().isEmpty()||ui->phone->toPlainText().isEmpty()||ui->purchase_date->toPlainText().isEmpty()||ui->purchase_price->toPlainText().isEmpty()||ui->purchaser->toPlainText().isEmpty()||ui->sale_price->toPlainText().isEmpty()||ui->stock->toPlainText().isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息!");
        return;
    }
    Goods* goods = new Goods(
            update_gid,
            ui->name->toPlainText(),
            ui->purchase_price->toPlainText().toDouble(),
            ui->sale_price->toPlainText().toDouble(),
            ui->stock->toPlainText().toInt(),
            ui->purchase_date->toPlainText(),
            ui->purchaser->toPlainText(),
            ui->phone->toPlainText()
    );
    database* db = database::getdatabase();

    bool succeed = db->update_info(goods);
    if(!succeed) {
        //TODO
        qDebug() << "error in updating date";
    } else {
        //TODO
        qDebug() << "update succeed";
    }
    this->hide();
    one_page = 0;
   // goods_manage().renew();
    //(new goods_manage)->show();
}


void update_goods::on_pushButton_2_clicked()
{
    (new goods_manage)->show();
    this->hide();
}

