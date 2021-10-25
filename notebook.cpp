#include "notebook.h"
#include "ui_notebook.h"
#include "first_page.h"
#include <QSqlDatabase>
#include "QDebug"
#include "QStandardItemModel"
#include <QButtonGroup>
#include "database.h"
#include "QSqlQuery"
#include <QCoreApplication>
#include <QSqlQueryModel>
#include <QMenu>
#include <QAction>
#include "QSqlError"
#include "Qmessagebox.h"
#include "sale_manage.h"
#include<QAxObject>
#include "QFile"
#include "QFileDialog"
#include "QStandardPaths"
#include "QDate"
#include "QCheckBox"
#include "QDesktopServices"
notebook::notebook(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::notebook)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    this->showMaximized();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "order_history";
    QString sql_to_tableview;
    QSqlQueryModel *model1;
    model1 = new QSqlQueryModel(this);
    QString a = current_buyer_name;
    sql_to_tableview += "select oid,goods_name,goods_num,buyer,address1,phone,order_date from order_history where buyer = " + current_buyer_name;
    qDebug()<<sql_to_tableview;
    //sql_to_tableview += name;
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    model1->setQuery(sql_to_tableview,db);
    ui->tableView->setModel(model1);
    //将sqlite中的数据导入到tableview



    model1->setHeaderData(0,Qt::Horizontal,"订单编号");
    model1->setHeaderData(1,Qt::Horizontal,"商品名称");
    model1->setHeaderData(2,Qt::Horizontal,"销售数量");
    model1->setHeaderData(3,Qt::Horizontal,"购买者");
    model1->setHeaderData(4,Qt::Horizontal,"买家地址");
    model1->setHeaderData(5,Qt::Horizontal,"买家联系方式");
    model1->setHeaderData(6,Qt::Horizontal,"订单日期");
    this->ui->tableView->setColumnWidth(0, 200);    //设置列的宽度
    this->ui->tableView->setColumnWidth(1, 200);
   this->ui->tableView->setColumnWidth(2, 200);
    this->ui->tableView->setColumnWidth(3, 200);
    this->ui->tableView->setColumnWidth(4, 200);
    this->ui->tableView->setColumnWidth(5, 200);
   this->ui->tableView->setColumnWidth(6, 200);
}

notebook::~notebook()
{
    delete ui;
}

void notebook::on_pushButton_clicked()
{
    (new sale_manage)->show();
    this->hide();
}

void notebook::text_find()
{
       // ui->mmenu->setCurrentIndex(0);
        //ui->tableView->setCurrentIndex(0)
       if(ui->textEdit->toPlainText()=="")
       {
           for(int i=0;i<ui->tableView->model()->rowCount();i++)
               ui->tableView->setRowHidden(i,false);
       }
       else
       {
           //获取文本框内容
           QString str=ui->textEdit->toPlainText();
           str.remove(QRegExp("\\s"));
           for(int i=0;i<ui->tableView->model()->rowCount();i++)
           {
               ui->tableView->setRowHidden(i,true);
               QString r="";
               //提取商品信息
               QAbstractItemModel *model=ui->tableView->model();
               QModelIndex index;
               for(int j=0;j<ui->tableView->model()->columnCount();j++)
               {
                   index=model->index(i,j);
                   r+=model->data(index).toString();
               }
               r.remove(QRegExp("\\s"));
               if(r.contains(str,Qt::CaseSensitive))
                   ui->tableView->setRowHidden(i,false);
           }
       }

}

void notebook::on_pushButton_6_clicked()
{
    text_find();
}

void notebook::Table2ExcelByHtml(QTableView *table,QString title)
{
    QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
    if (fileName!="")
    {
        QAxObject *excel = new QAxObject;
        if (excel->setControl("Excel.Application")) //连接Excel控件
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

            int i,j;
            //QTablewidget 获取数据的列数
            int colcount=ui->tableView->model()->columnCount();
             //QTablewidget 获取数据的行数
            int rowscount=ui->tableView->model()->rowCount();



            QAxObject *cell,*col;
            //标题行
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);
            cell->dynamicCall("SetValue(const QString&)", title);
            cell->querySubObject("Font")->setProperty("Size", 18);
            //调整行高
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);
            //合并标题行
            QString cellTitle;
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter
            //列标题
            for(i=0;i<colcount;i++)
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", table->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                //QTableWidget 获取表格头部文字信息
               //11111111111111111 columnName=ui->tableView->horizontalHeaderItem(i)->text();
                //QTableView 获取表格头部文字信息
                 columnName=ui->tableView->model()->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);//xlCenter
                cell->setProperty("VerticalAlignment", -4108);//xlCenter
            }

           //数据区




          // QTableView 获取表格数据部分
             for(i=0;i<rowscount;i++) //行数
               {
                    for (j=0;j<colcount;j++)   //列数
                   {
                        QModelIndex index = ui->tableView->model()->index(i, j);
                       QString strdata=ui->tableView->model()->data(index).toString();
                        worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", strdata);
                    }
                }


            //画框线
            QString lrange;
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(rowscount + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));
            //调整数据区行高
            QString rowsName;
            rowsName.append("2:");
            rowsName.append(QString::number(rowscount + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");//关闭工作簿
            excel->dynamicCall("Quit()");//关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }
        }
        else
        {
            QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
        }
    }
}
void notebook::on_pushButton_5_clicked()
{
    Table2ExcelByHtml(ui->tableView,"交易清单---"+current_buyer_name);
}

