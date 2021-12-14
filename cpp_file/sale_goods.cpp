#include "sale_goods.h"
#include "ui_sale_goods.h"
#include "QDateTime"
#include "goods_manage.h"
#include "QMessageBox"
#include "ui_goods_manage.h"
#include "database.h"
#include "QDebug"
#include "QSqlQuery"
#include <QCoreApplication>
#include <QSqlQueryModel>
#include "add_goods.h"
sale_goods::sale_goods(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sale_goods)
{

    ui->setupUi(this);
    database* db = database::getdatabase();
    QStringList strList1 = db->selectAllFromOrder();
   // strList <<"1111"<<"2222"<<"3333";
    ui->comboBox->addItems(strList1);

        //关联信号和槽
    QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_comboBox_currentIndexChanged()));
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm:ss");
    ui->goods_num->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->buyer_name->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->buyer_address->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->order_date->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->buyer_phone->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    //ui->purchaser->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    //ui->phone->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px");
    ui->goods_num->setPlaceholderText( "请输入出售数量" );
    ui->buyer_name->setPlaceholderText( "请输入买家姓名" );
    ui->buyer_address->setPlaceholderText( "请输入买家地址" );
    //ui->order_date->setPlaceholderText( "请输入进货数量" );
    //ui->purchase_date->setPlaceholderText( current_date);
    ui->order_date->setText(current_date);
    ui->order_date->setFocusPolicy(Qt::NoFocus);
    ui->buyer_phone->setPlaceholderText( "请输入买家电话" );
    //ui->phone->setPlaceholderText( "请输入进货商电话" );
}

sale_goods::~sale_goods()
{
    delete ui;
}

void sale_goods::on_pushButton_clicked()
{
    (new goods_manage)->show();
    this->hide();
}


void sale_goods::on_pushButton_2_clicked()
{
    if(ui->buyer_address->text().isEmpty()||ui->buyer_name->text().isEmpty()||ui->buyer_phone->text().isEmpty()||ui->goods_num->text().isEmpty()||ui->order_date->text().isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息!");
        return;
    }
    if(ui->goods_num->text().toInt()<0)
    {
        QMessageBox::about(NULL,"提示","出售数量不能为负！");
    }
   // int temp = QString::number(ui->goods_num->text())
    int left;
    if((left = ui->goods_num->text().toInt()) > sum_sale)
    {
        QMessageBox::about(NULL,"提示","出售数量不能大于库存总量!");
        qDebug()<<ui->goods_num->text().toInt() << sum_sale;
        return;
    }
    //QString goodname = goods_manage().ui->
    database* db = database::getdatabase();
    QStringList* gids = db->getGidsByName(select_name);
    for(int i = 0; left > 0 && i <= gids->count(); i++) {
        int stock = db->getStockByGid(gids->at(i).toInt());
        qDebug() << stock << left;
        if(stock <= left) { //如果库存小于剩余需求量，将数据库中指定gid的商品库存置为0
            db->subStockByGid(gids->at(i).toInt(), 0);
        } else { //如果库存数量大于剩余需求量，则将指定gid的商品库存减去当前需求量
            db->subStockByGid(gids->at(i).toInt(), stock - left);
        }
        left -= stock;
    }
    //todo
    Order* order = new Order(
       select_name,
       ui->goods_num->text().toInt(),
       ui->buyer_name->text(),
       ui->buyer_address->text(),
       ui->buyer_phone->text(),
       ui->order_date->text(),
       select_gid
   );
   bool succeed = db->insertIntoOrder(order);
   if(!succeed) {
       //TODO
       qDebug() << "failed insert into order_history";
       QMessageBox::about(NULL,"提示","出售失败！");
   }
   else
   {
       QMessageBox::about(NULL,"提示","出售成功!");
   }
    this->hide();
    one_page =0;
    QSqlDatabase db1 = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db1);
    QString name;name = "goods_manage";
    QString sql_to_tableview;
    QSqlQueryModel *model1;
    model1 = new QSqlQueryModel(this);
    sql_to_tableview += "select * from ";
    sql_to_tableview += name;
    model1->setQuery(sql_to_tableview,db1);
    goods_manage().ui->tableView->setModel(model1);
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

}
void sale_goods::on_comboBox_currentIndexChanged()
{
    database* db = database::getdatabase();

    ui->buyer_name->setText(ui->comboBox->currentText());
    ui->buyer_address->setText(db->getAddressByBuyer(ui->buyer_name->text()));
    ui->buyer_phone->setText(db->getPhoneByBuyer(ui->buyer_name->text()));

}
