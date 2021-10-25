#include "input_cargo.h"
#include "ui_input_cargo.h"
#include "supply_system.h"
#include "QMessageBox"
#include "database.h"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "login.h"
#include "QDateTime"
input_cargo::input_cargo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::input_cargo)
{
    ui->setupUi(this);
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->name->setPlaceholderText( "请输入商品名称" );
    ui->purchase_prise->setPlaceholderText( "输入入库价格" );
    ui->sale_prise->setPlaceholderText( "输入销售价格" );
    ui->stock->setPlaceholderText( "请输入入库的数量" );
    ui->purchase_date->setText(current_date);

}

input_cargo::~input_cargo()
{
    delete ui;
}

void input_cargo::on_pushButton_2_clicked()
{
    (new supply_system)->show();
    this->hide();
}


void input_cargo::on_pushButton_clicked()
{
    if(ui->name->text().isEmpty()||ui->purchase_prise->text().isEmpty()||ui->sale_prise->text().isEmpty()||ui->stock->text().isEmpty()||ui->purchase_date->text().isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息！");
        return;
    }
     database *userDb = database::getdatabase();
     userDb->add_cargo(ui->name->text().trimmed(),ui->purchase_prise->text(),ui->sale_prise->text(),ui->stock->text(),ui->purchase_date->text(), self_sale_name);
 //    userDb->add_to_salemanage(ui->name->text(),ui->purchase_prise->text(),ui->sale_prise->text(),ui->stock->text(), select_gid);

    // one_page = 0;
     //111goods_manage::goods.reflush();
     //(new goods_manage)->reflush();
     //this->goods->reflush();
     //goods_manage* gm = new goods_manage(this->goods);
     //delete goods;
     //gm->show();
     QSqlDatabase db = QSqlDatabase::database("smart-home-db");
     QSqlQuery query = QSqlQuery(db);
     QString name;name = "cargo_manage";
     QString sql_to_tableview;
     QSqlQueryModel *model1;
     model1 = new QSqlQueryModel(this);
     sql_to_tableview += "select * from ";
     sql_to_tableview += name;
      model1->setQuery(sql_to_tableview,db);
    /*goods_manage().ui->tableView->setModel(model1);
     model1->setHeaderData(0,Qt::Horizontal,"商品编号");
     model1->setHeaderData(1,Qt::Horizontal,"商品名称");
     model1->setHeaderData(2,Qt::Horizontal,"商品进货价格");
     model1->setHeaderData(3,Qt::Horizontal,"商品销售价格");
     model1->setHeaderData(4,Qt::Horizontal,"商品库存");
     model1->setHeaderData(5,Qt::Horizontal,"采购日期");
     model1->setHeaderData(6,Qt::Horizontal,"进货商");
     model1->setHeaderData(7,Qt::Horizontal,"进货商电话");
     model1->setHeaderData(8,Qt::Horizontal,"买家姓名");
     model1->setHeaderData(9,Qt::Horizontal,"买家地址");
     model1->setHeaderData(10,Qt::Horizontal,"订购日期");
     model1->setHeaderData(11,Qt::Horizontal,"买家电话");
      goods_manage().ui->tableView->setColumnWidth(0, 150);    //设置列的宽度
      goods_manage().ui->tableView->setColumnWidth(1, 150);
      goods_manage().ui->tableView->setColumnWidth(2, 150);
      goods_manage().ui->tableView->setColumnWidth(3, 150);
      goods_manage().ui->tableView->setColumnWidth(4, 150);
      goods_manage().ui->tableView->setColumnWidth(5, 150);
      goods_manage().ui->tableView->setColumnWidth(6, 150);
      goods_manage().ui->tableView->setColumnWidth(7, 150);
     goods_manage().ui->tableView->setColumnWidth(8, 150);
     goods_manage().ui->tableView->setColumnWidth(9, 150);
     goods_manage().ui->tableView->setColumnWidth(10, 150);
     goods_manage().ui->tableView->setColumnWidth(11, 150);
     */
     QMessageBox::about(NULL,"提示","导入成功！");
     this->hide();
     (new supply_system)->show();

}

