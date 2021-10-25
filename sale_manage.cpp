#include "sale_manage.h"
#include "ui_sale_manage.h"
#include "first_page.h"
#include "database.h"
#include "QSqlError"
#include <QSqlDatabase>
#include "QDebug"
#include "QStandardItemModel"
#include <QButtonGroup>
#include "QSqlQuery"
#include <QCoreApplication>
#include <QSqlQueryModel>
#include <QMenu>
#include <QAction>
#include "Qmessagebox.h"
//#include "QAbstractTableModel"
#include<QAxObject>
#include "QDesktopServices"
#include "goods_manage.h"
#include "QFile"
#include "QFileDialog"
#include "notebook.h"
#include "QDesktopWidget"
#include "QMouseEvent"
sale_manage::sale_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sale_manage)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "goods_order";
    QString sql_to_tableview;
    QSqlQueryModel *model1;
    model1 = new QSqlQueryModel(this);
    sql_to_tableview += "select * from ";
    sql_to_tableview += name;
    model1->setQuery(sql_to_tableview,db);
    ui->tableView->setModel(model1);
    //将sqlite中的数据导入到tableview
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    model1->setHeaderData(0,Qt::Horizontal,"商品编号");
    model1->setHeaderData(1,Qt::Horizontal,"商品名称");
    model1->setHeaderData(2,Qt::Horizontal,"进货价格");
    model1->setHeaderData(3,Qt::Horizontal,"销售价格");
    model1->setHeaderData(4,Qt::Horizontal,"库存");
    model1->setHeaderData(5,Qt::Horizontal,"进货日期");
    model1->setHeaderData(6,Qt::Horizontal,"进货商");
     model1->setHeaderData(7,Qt::Horizontal,"进货商电话");
      //model1->setHeaderData(6,Qt::Horizontal,"买家姓名");
       //model1->setHeaderData(6,Qt::Horizontal,"买家地址");
        //model1->setHeaderData(6,Qt::Horizontal,"买家购买日期");
        // model1->setHeaderData(6,Qt::Horizontal,"买家电话");
          model1->setHeaderData(8,Qt::Horizontal,"订单编号");
          model1->setHeaderData(9,Qt::Horizontal,"商品名称");
          model1->setHeaderData(10,Qt::Horizontal,"销售数量");
          model1->setHeaderData(11,Qt::Horizontal,"买家姓名");
          model1->setHeaderData(12,Qt::Horizontal,"买家地址");
          model1->setHeaderData(13,Qt::Horizontal,"买家电话");
          model1->setHeaderData(14,Qt::Horizontal,"订购日期");
          model1->setHeaderData(15,Qt::Horizontal,"商品编号");
          model1->setHeaderData(16,Qt::Horizontal,"该单所获利润");
     this->ui->tableView->setColumnWidth(0, 175);    //设置列的宽度
     this->ui->tableView->setColumnWidth(1, 175);
     this->ui->tableView->setColumnWidth(2, 175);
     this->ui->tableView->setColumnWidth(3, 175);
     this->ui->tableView->setColumnWidth(4, 175);
     this->ui->tableView->setColumnWidth(5, 175);
     this->ui->tableView->setColumnWidth(6, 175);
              this->ui->tableView->setColumnWidth(7, 175);
              this->ui->tableView->setColumnWidth(8, 175);
              this->ui->tableView->setColumnWidth(9, 175);
              this->ui->tableView->setColumnWidth(10, 175);
              this->ui->tableView->setColumnWidth(11, 175);
              this->ui->tableView->setColumnWidth(12, 175);
              this->ui->tableView->setColumnWidth(13, 175);
              this->ui->tableView->setColumnWidth(14, 175);
              this->ui->tableView->setColumnWidth(15, 175);
          this->ui->tableView->setColumnWidth(16, 175);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


    this->showMaximized();
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();
    //resize(b,a);

    qDebug()<<ui->splitter2->width()<<" "<<ui->splitter2->height();
    leftIcon = QIcon(":/new/prefix1/left.png");
    rightIcon = QIcon(":/new/prefix1/right.png");
    pushButtonn = new QPushButton(this);
    pushButtonn->setFocusPolicy(Qt::NoFocus);
    pushButtonn->hide();
    pushButtonn->setFixedSize(26, 84);
    pushButtonn->setIconSize(pushButtonn->size());
    pushButtonn->setStyleSheet("border:none;");
    pushButtonn->setIcon(rightIcon);
     connect(ui->splitter2, SIGNAL(splitterMoved(int,int)), this, SLOT(slotSplitterMoved(int,int)));
    // pushButton->move(contentFrame->width() - pushButton->width()-2, (contentFrame->height() - pushButton->height())/2);
    pushButtonn->move( b-50,a/2-100);
    qDebug()<<this->maximumWidth()/2-100<<" "<<this->maximumHeight()/2-130;
    qDebug()<<ui->splitter2->width()<<" "<<ui->splitter2->height();
    connect(pushButtonn,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));
    //ui->pushButton_3->move(200,200);
    //connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));

    //contentFrame->setMouseTracking(true);
    ui->splitter2->setMouseTracking(true);
    //contentFrame->installEventFilter(this);
   ui->splitter2->installEventFilter(this);
   pushButtonn->show();
   left_or_right2 = 1;

}
void sale_manage::resizeEvent(QResizeEvent *event)
{
    //ui->splitter->setGeometry(0, 0, width(), height());
    //move((QApplication::desktop()->width() - width())/2,  (QApplication::desktop()->height() - height())/2);
    QWidget::resizeEvent(event);
}

bool sale_manage::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseMove) {
        QMouseEvent *mouseMove = static_cast<QMouseEvent*>(event);
        QRect rect = pushButtonn->frameGeometry();
        if (rect.contains(mouseMove->pos())) {
            pushButtonn->show();
            //pushButton1->show();
        }
        else {
            pushButtonn->hide();
            //pushButton1->hide();
        }
    }
    return QWidget::eventFilter(obj, event);
}

void sale_manage::setBtnPos()
{
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();

    pushButtonn->move(ui->splitter2->width()-pushButtonn->width()-2, (ui->splitter2->height()-pushButtonn->height())/2);
    //pushButton->move(0, 0);
}
void sale_manage::setBtnPos1()
{
    //pushButton->move();
}
void sale_manage::setBtnIcon()
{

    if (ui->splitter2->width() != 0&&left_or_right2==0) {
        qDebug()<<ui->splitter2->width();
        pushButtonn->setIcon(leftIcon);
    }
    else {
        pushButtonn->setIcon(rightIcon);
    }
}

void sale_manage::slotClickedBtn()
{
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();
    QList <int> sizeList;
    sizeList.clear();
    if (ui->splitter2->width()!=0&&left_or_right2==1) {
        sizeList.append(0);
        sizeList.append(2000);
        qDebug()<<ui->splitter2->width();left_or_right2=0;
    }
    else {

        sizeList.append(100);
        sizeList.append(100);
        qDebug()<<"0000000000000000000000000";
        left_or_right2=1;
    }
    ui->splitter2->setSizes(sizeList);
    //ui->splitter->getRange(1,1)
    setBtnIcon();
    setBtnPos();

    //pushButton->hide();
    qDebug()<<ui->splitter2->width();
}

void sale_manage::slotSplitterMoved(int pos, int index)
{
    Q_UNUSED(pos)
    Q_UNUSED(index)
    setBtnIcon();
    setBtnPos();
}

void sale_manage::mousePressEvent ( QMouseEvent * event)
{
    bPressFlag = true;
    dragPosition = event->pos();
    QWidget::mousePressEvent(event);
}

void sale_manage::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - dragPosition);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void sale_manage::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}

sale_manage::~sale_manage()
{
    delete ui;
}
void sale_manage::text_find()
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
void sale_manage::on_pushButton_clicked()
{
    (new first_page)->show();
    this->hide();

}


void sale_manage::on_pushButton_2_clicked()
{
    text_find();
}

//加入多元统计
void sale_manage::on_pushButton_3_clicked()
{
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),1);
    QVariant datatemp = modessl->data(indextemp);
    QString name = datatemp.toString();
    if(tracking->count() >= TRACKING_MAX_NUM) {
        QMessageBox::about(NULL,"提示","同时追踪的商品数量已达上限！");
    }
    if(!tracking->contains(name)){
        tracking->append(name);
        QMessageBox::about(NULL,"提示","已经成功加入统计！");
    }
    else {
        QMessageBox::about(NULL,"提示","请勿添加重复商品！");
    }
}

//一键清除统计
void sale_manage::on_pushButton_4_clicked()
{
    tracking->clear();
    single_num = 0;
    track_single ="";
}

//单元统计
void sale_manage::on_pushButton_5_clicked()
{
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),1);
    QVariant datatemp = modessl->data(indextemp);
    QString name = datatemp.toString();
    qDebug()<<name;
    track_single = name;
    qDebug()<<track_single;
  //  if(single_num > 1) {
    //    QMessageBox::about(NULL,"提示","单元统计只能选择一个进行追踪！");
    //    single_num = 0;
   // }
    QMessageBox::about(NULL,"提示","已经成功加入统计！");
}


void sale_manage::on_pushButton_6_clicked()
{
    //select sum(profit) sum from goods_order;
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    query.prepare("select sum(profit) sum from goods_order");
    if(!query.exec()) {
        //TODO
        qDebug()<<query.lastError();
        db.close();

    }
    if(query.next())
    {
        QString s = query.value("sum").toString();
        QMessageBox::about(NULL,"提示","您的总利润为"+s);
        db.close();
    }


}


void sale_manage::on_pushButton_7_clicked()
{
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),0);
    qDebug()<<ui->tableView->currentIndex().row();
    if(ui->tableView->currentIndex().row()== -1)
    {
        QMessageBox::about(NULL,"提示","请选择删除的商品!");
        return;
    }
    ////////////////////

    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "是否确定删除?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;

    QItemSelectionModel *selections = ui->tableView->selectionModel();
    QModelIndexList selected = selections->selectedIndexes();
    qDebug()<<selected.at(0).data(0);//<<selected.at(1).data(0);
    //selected;
   // for(int i =0;i<5;i++)
   // qDebug()<<selected[8].data();
    qDebug()<<selected.size();
    for(int i = 8; i<selected.size();i=i+17)
    {
        //gid为 selected[i].data()
       database *userDb = database::getdatabase();
       bool succeed = userDb->delete_sale_history(selected[i].data().toInt());
       if(!succeed) {
               QMessageBox::about(NULL,"提示","删除失败!");

       }
    }

    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "goods_order";
    QString sql_to_tableview;
    QSqlQueryModel *model1;
    model1 = new QSqlQueryModel(this);
    sql_to_tableview += "select * from ";
    sql_to_tableview += name;
    model1->setQuery(sql_to_tableview,db);
    ui->tableView->setModel(model1);
    //将sqlite中的数据导入到tableview


    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    model1->setHeaderData(0,Qt::Horizontal,"商品编号");
    model1->setHeaderData(1,Qt::Horizontal,"商品名称");
    model1->setHeaderData(2,Qt::Horizontal,"进货价格");
    model1->setHeaderData(3,Qt::Horizontal,"销售价格");
    model1->setHeaderData(4,Qt::Horizontal,"库存");
    model1->setHeaderData(5,Qt::Horizontal,"进货日期");
    model1->setHeaderData(6,Qt::Horizontal,"进货商");
     model1->setHeaderData(7,Qt::Horizontal,"进货商电话");
      //model1->setHeaderData(6,Qt::Horizontal,"买家姓名");
       //model1->setHeaderData(6,Qt::Horizontal,"买家地址");
        //model1->setHeaderData(6,Qt::Horizontal,"买家购买日期");
        // model1->setHeaderData(6,Qt::Horizontal,"买家电话");
          model1->setHeaderData(8,Qt::Horizontal,"订单编号");
          model1->setHeaderData(9,Qt::Horizontal,"商品名称");
          model1->setHeaderData(10,Qt::Horizontal,"销售数量");
          model1->setHeaderData(11,Qt::Horizontal,"买家姓名");
          model1->setHeaderData(12,Qt::Horizontal,"买家地址");
          model1->setHeaderData(13,Qt::Horizontal,"买家电话");
          model1->setHeaderData(14,Qt::Horizontal,"订购日期");
          model1->setHeaderData(15,Qt::Horizontal,"该单所获利润");
     this->ui->tableView->setColumnWidth(0, 175);    //设置列的宽度
     this->ui->tableView->setColumnWidth(1, 175);
     this->ui->tableView->setColumnWidth(2, 175);
     this->ui->tableView->setColumnWidth(3, 175);
     this->ui->tableView->setColumnWidth(4, 175);
     this->ui->tableView->setColumnWidth(5, 175);
     this->ui->tableView->setColumnWidth(6, 175);
              this->ui->tableView->setColumnWidth(7, 175);
              this->ui->tableView->setColumnWidth(8, 175);
              this->ui->tableView->setColumnWidth(9, 175);
              this->ui->tableView->setColumnWidth(10, 175);
              this->ui->tableView->setColumnWidth(11, 175);
              this->ui->tableView->setColumnWidth(12, 175);
              this->ui->tableView->setColumnWidth(13, 175);
              this->ui->tableView->setColumnWidth(14, 175);
              this->ui->tableView->setColumnWidth(15, 175);

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);


/*
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),8);
    QVariant datatemp = modessl->data(indextemp);
    int choose = datatemp.toInt();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
    QString sql_str = QString("delete from order_history where oid = %1").arg(choose);
    qDebug()<<sql_str;
    //query.prepare("delete from goods_order where gid = ?");
    //query.addBindValue(choose);
    query.exec(sql_str);
    qDebug()<<query.lastError();
*/

}
void sale_manage::Table2ExcelByHtml(QTableView *table,QString title)
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

void sale_manage::on_pushButton_8_clicked()
{
    Table2ExcelByHtml(ui->tableView,"销售记录明细");
}


void sale_manage::on_pushButton_9_clicked()
{
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),11);
    QVariant datatemp = modessl->data(indextemp);
    current_buyer_name = datatemp.toString();
    (new notebook)->show();
    this->hide();

}

