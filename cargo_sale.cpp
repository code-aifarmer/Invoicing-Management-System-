#include "cargo_sale.h"
#include "ui_cargo_sale.h"
#include "QMessageBox"
#include "goods_manage.h"
#include "database.h"
cargo_sale::cargo_sale(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cargo_sale)
{
    ui->setupUi(this);
}

cargo_sale::~cargo_sale()
{
    delete ui;
}

void cargo_sale::on_pushButton_clicked()
{
    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::about(NULL,"提示","请补全信息!");
        return;
    }
    if(ui->lineEdit->text().toInt()<0)
    {
        QMessageBox::about(NULL,"提示","出售数量不能为负！");
    }

    database* db = database::getdatabase();
    int gid = db->get_cargo_GidsByName(select_name);
    int stock = db->get_cargo_StockByGid(gid);
    int count = ui->lineEdit->text().toInt();
    if(stock < count) {
       QMessageBox::about(NULL,"提示","出售数量不能大于库存数量！");
       return;
    }
    stock -= count;

   bool succeed = db->modifyStockByGid(gid, stock);
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
   // one_page =0;


}

