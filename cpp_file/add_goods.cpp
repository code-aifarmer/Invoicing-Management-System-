#include "add_goods.h"
#include "ui_add_goods.h"
#include "database.h"
#include "goods_manage.h"
#include "QDateTime"
#include "QMessageBox"
#include "database.h"
#include "QSqlQuery"
#include <QCoreApplication>
#include <QSqlQueryModel>
#include "ui_goods_manage.h"
add_goods::add_goods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_goods)
{

    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->name->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->purchase_prise->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->sale_prise->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->stock->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->purchase_date->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->purchaser->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->phone->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->name->setPlaceholderText( "请输入商品名称" );
    ui->purchase_prise->setPlaceholderText( "请输入进货价格" );
    ui->sale_prise->setPlaceholderText( "请输入销售价格" );
    ui->stock->setPlaceholderText( "请输入进货数量" );
    //ui->purchase_date->setPlaceholderText( current_date);
    ui->purchase_date->setText(current_date);
    ui->purchase_date->setFocusPolicy(Qt::NoFocus);
    ui->purchaser->setPlaceholderText( "请输入进货商" );
    ui->phone->setPlaceholderText( "请输入进货商电话" );
}

add_goods::~add_goods()
{
    delete ui;
}

//导入
void add_goods::on_pushButton_clicked()
{
    if(ui->name->text().isEmpty()||ui->purchase_prise->text().isEmpty()||ui->sale_prise->text().isEmpty()||ui->stock->text().isEmpty()||ui->purchase_date->text().isEmpty()||ui->purchaser->text().isEmpty()||ui->phone->text().isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息！");
        return;
    }
     database *userDb = database::getdatabase();
     userDb->add_good(ui->name->text().trimmed(),ui->purchase_prise->text(),ui->sale_prise->text(),ui->stock->text(),ui->purchase_date->text(),ui->purchaser->text(),ui->phone->text());

     one_page = 0;
     QSqlDatabase db = QSqlDatabase::database("smart-home-db");
     QSqlQuery query = QSqlQuery(db);
     QString name;name = "goods_manage";
     QString sql_to_tableview;
     QSqlQueryModel *model1;
     model1 = new QSqlQueryModel(this);
     sql_to_tableview += "select * from ";
     sql_to_tableview += name;
      model1->setQuery(sql_to_tableview,db);
     QMessageBox::about(NULL,"提示","导入成功！");
     this->hide();
     (new goods_manage)->show();


}


void add_goods::on_pushButton_2_clicked()
{
    (new goods_manage)->show();
    this->hide();
}

goods_manage *add_goods::getGoods() const
{
    return goods;
}

void add_goods::setGoods(goods_manage *newGoods)
{
    goods = newGoods;
}

