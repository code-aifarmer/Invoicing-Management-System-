#include "supply_system.h"
#include "ui_supply_system.h"
#include "saleuser_first_page.h"
#include "input_cargo.h"
#include "database.h"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QSqlQueryModel"
#include "update_cargo.h"
#include "QMessageBox"
#include "QDebug"
#include "goods_manage.h"
#include "cargo_sale.h"
#include "QAbstractItemModel"
#include<QAxObject>
#include "QFile"
#include "QFileDialog"
#include "qtableview.h"
#include "QStandardPaths"
#include "QDate"
#include "QCheckBox"
#include "QDesktopServices"
#include "QMouseEvent"
#include "QDesktopWidget"
#include "QPushButton"
#include "QMouseEvent"
supply_system::supply_system(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::supply_system)
{
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
     this->showMaximized();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    //int columnNum = userDb->get_now_number(name);
    //model->setColumnCount(columnNum);

    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "cargo_manage";
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
    model1->setHeaderData(2,Qt::Horizontal,"商品进货价格");
    model1->setHeaderData(3,Qt::Horizontal,"商品销售价格");
    model1->setHeaderData(4,Qt::Horizontal,"商品库存");
    model1->setHeaderData(5,Qt::Horizontal,"采购日期");

//    model1->setHeaderData(8,Qt::Horizontal,"买家姓名");
//    model1->setHeaderData(9,Qt::Horizontal,"买家地址");
//    model1->setHeaderData(10,Qt::Horizontal,"订购日期");
//    model1->setHeaderData(11,Qt::Horizontal,"买家电话");
     this->ui->tableView->setColumnWidth(0, 150);    //设置列的宽度
     this->ui->tableView->setColumnWidth(1, 150);
    this->ui->tableView->setColumnWidth(2, 150);
     this->ui->tableView->setColumnWidth(3, 150);
     this->ui->tableView->setColumnWidth(4, 150);
     this->ui->tableView->setColumnWidth(5, 150);





    this->showMaximized();
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();
    //resize(b,a);

    qDebug()<<ui->splitter->width()<<" "<<ui->splitter->height();
    leftIcon = QIcon(":/new/prefix1/left.png");
    rightIcon = QIcon(":/new/prefix1/right.png");
    pushButtonn = new QPushButton(this);
    pushButtonn->setFocusPolicy(Qt::NoFocus);
    pushButtonn->hide();
    pushButtonn->setFixedSize(26, 84);
    pushButtonn->setIconSize(pushButtonn->size());
    pushButtonn->setStyleSheet("border:none;");
    pushButtonn->setIcon(rightIcon);
     connect(ui->splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(slotSplitterMoved(int,int)));
    // pushButton->move(contentFrame->width() - pushButton->width()-2, (contentFrame->height() - pushButton->height())/2);
    pushButtonn->move( b-50,a/2-100);
    qDebug()<<this->maximumWidth()/2-100<<" "<<this->maximumHeight()/2-130;
    qDebug()<<ui->splitter->width()<<" "<<ui->splitter->height();
    connect(pushButtonn,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));
    //ui->pushButton_3->move(200,200);
    //connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));

    //contentFrame->setMouseTracking(true);
    ui->splitter->setMouseTracking(true);
    //contentFrame->installEventFilter(this);
   ui->splitter->installEventFilter(this);
   pushButtonn->show();
   left_or_right = 1;

}

supply_system::~supply_system()
{
    delete ui;
}

void supply_system::on_pushButton_clicked()
{
       (new saleuser_first_page)->show();
       this->hide();
}


void supply_system::on_pushButton_9_clicked()
{
    this->hide();
    (new supply_system)->show();
}


void supply_system::on_pushButton_5_clicked()
{
    (new input_cargo)->show();
    this->hide();
}
void supply_system::text_find()
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
void supply_system::on_pushButton_2_clicked()
{
    text_find();
}

void supply_system::on_pushButton_3_clicked()
{



    QAbstractItemModel *modessl = ui->tableView->model();
    //qDebug()<<ui->tableView->currentIndex().row();
    if(ui->tableView->currentIndex().row() == -1)
    {
        QMessageBox::about(NULL,"提示","请选择需要修改的商品！");
        return;
    }
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),0);
    QVariant datatemp = modessl->data(indextemp);
    int gid = datatemp.toInt();
    update_cargo_gid = gid;
    (new update_cargo)->show();
}


void supply_system::on_pushButton_4_clicked()
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
    qDebug()<<ui->tableView->currentIndex().row()<<"00000000000000000000";
    QMessageBox::StandardButton box;
    box = QMessageBox::question(this, "提示", "是否确定删除?", QMessageBox::Yes|QMessageBox::No);
    if(box==QMessageBox::No)
       return;

    QItemSelectionModel *selections = ui->tableView->selectionModel();
    if(selections->selectedIndexes().empty())
    {
        QMessageBox::about(NULL,"提示","请选中要删除的商品！");
        return;
    }
    QModelIndexList selected = selections->selectedIndexes();
    qDebug()<<selections->selectedIndexes()<<"111111111111111111111111111";
    qDebug()<<selected.at(0).data(0);//<<selected.at(1).data(0);
    //selected;
   // for(int i =0;i<5;i++)
   // qDebug()<<selected[8].data();
    qDebug()<<selected.size();
    for(int i = 0; i<selected.size();i=i+8)
    {
        //gid为 selected[i].data()
       database *userDb = database::getdatabase();
       bool succeed = userDb->delete_cargo_ByGid(selected[i].data().toInt());
       if(!succeed) {
               QMessageBox::about(NULL,"提示","删除失败!");

       }
    }
    ////////////////////////////

  /*

    QVariant datatemp = modessl->data(indextemp);
    int gid = datatemp.toInt();
     database *userDb = database::getdatabase();
    bool succeed = userDb->deleteGoodsByGid(gid);
    if(!succeed) {
            QMessageBox::about(NULL,"提示","删除失败!");

    }
    */
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "cargo_manage";
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
    model1->setHeaderData(2,Qt::Horizontal,"商品进货价格");
    model1->setHeaderData(3,Qt::Horizontal,"商品销售价格");
    model1->setHeaderData(4,Qt::Horizontal,"商品库存");
    model1->setHeaderData(5,Qt::Horizontal,"采购日期");

//    model1->setHeaderData(8,Qt::Horizontal,"买家姓名");
//    model1->setHeaderData(9,Qt::Horizontal,"买家地址");
//    model1->setHeaderData(10,Qt::Horizontal,"订购日期");
//    model1->setHeaderData(11,Qt::Horizontal,"买家电话");
     this->ui->tableView->setColumnWidth(0, 150);    //设置列的宽度
     this->ui->tableView->setColumnWidth(1, 150);
    this->ui->tableView->setColumnWidth(2, 150);
     this->ui->tableView->setColumnWidth(3, 150);
     this->ui->tableView->setColumnWidth(4, 150);
     this->ui->tableView->setColumnWidth(5, 150);


}


void supply_system::on_pushButton_6_clicked()
{
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),1);
    QVariant datatemp = modessl->data(indextemp);
    QString num_of_name = datatemp.toString();
    qDebug()<<num_of_name;
    database* db = database::getdatabase();
    int sum = db->ask_cargo_num(num_of_name);
    QString s= QString::number(sum);
    qDebug()<<sum;
    if(ui->tableView->currentIndex().row() == -1)
    {
        QMessageBox::about(NULL,"提示","请选择需要统计的商品");
        return;
    }
    QMessageBox::about(this,"提示","该商品共有"+s+"件");
    //qDebug()<<ui->tableView->currentIndex().row();
}


void supply_system::on_pushButton_7_clicked()
{
    //database *userDb = database::getdatabase();


    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),1);
    QVariant datatemp = modessl->data(indextemp);
    if(ui->tableView->currentIndex().row() == -1)
    {
        QMessageBox::about(NULL,"提示","请选择想要出售的商品!");
        return;
    }
    QString num_of_name = datatemp.toString();
    select_name = num_of_name;
    qDebug()<<num_of_name;
    database* db = database::getdatabase();
    sum_sale = db->ask_cargo_num(num_of_name);
    QModelIndex indextemp1 = modessl->index(ui->tableView->currentIndex().row(),0);
    QVariant datatemp1 = modessl->data(indextemp1);
    select_gid = datatemp1.toInt();
    //add_goods* ag = new add_goods();
    //ag->show();
   // ag->setGoods(this);
    //this->hide();

(new cargo_sale)->show();
}


void supply_system::on_pushButton_8_clicked()
{
    Table2ExcelByHtml(ui->tableView,"商品明细");
}
void supply_system::Table2ExcelByHtml(QTableView *table,QString title)
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
void supply_system::resizeEvent(QResizeEvent *event)
{
    //ui->splitter->setGeometry(0, 0, width(), height());
    //move((QApplication::desktop()->width() - width())/2,  (QApplication::desktop()->height() - height())/2);
    QWidget::resizeEvent(event);
}

bool supply_system::eventFilter(QObject *obj, QEvent *event)
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

void supply_system::setBtnPos()
{
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();
    pushButtonn->move(ui->splitter->width()-pushButtonn->width()-2, (ui->splitter->height()-pushButtonn->height())/2);
    //pushButton->move(0, 0);
}
void supply_system::setBtnPos1()
{
    //pushButton->move();
}
void supply_system::setBtnIcon()
{
    if (ui->splitter->width() != 0&&left_or_right==0) {
        qDebug()<<ui->splitter->width();
        pushButtonn->setIcon(leftIcon);
    }
    else {
        pushButtonn->setIcon(rightIcon);
    }
}

void supply_system::slotClickedBtn()
{
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();
    QList <int> sizeList;
    sizeList.clear();
    if (ui->splitter->width()!=0&&left_or_right==1) {
        sizeList.append(0);
        sizeList.append(2000);
        qDebug()<<ui->splitter->width();left_or_right=0;
    }
    else {

        sizeList.append(105);
        sizeList.append(105);
        qDebug()<<"0000000000000000000000000";
        left_or_right=1;
    }
    ui->splitter->setSizes(sizeList);
    //ui->splitter->getRange(1,1)
    setBtnIcon();
    setBtnPos();

    //pushButton->hide();
    qDebug()<<ui->splitter->width();
}

void supply_system::slotSplitterMoved(int pos, int index)
{
    Q_UNUSED(pos)
    Q_UNUSED(index)
    setBtnIcon();
    setBtnPos();
}

void supply_system::mousePressEvent ( QMouseEvent * event)
{
    bPressFlag = true;
    dragPosition = event->pos();
    QWidget::mousePressEvent(event);
}

void supply_system::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - dragPosition);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void supply_system::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}

