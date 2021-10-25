#include "goods_manage.h"
#include "ui_goods_manage.h"
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
#include "update_goods.h"
#include "add_goods.h"
#include "sale_goods.h"
#include "QMessageBox"
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
#pragma execution_character_set("utf-8")
//将数据保存为excel

goods_manage::goods_manage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::goods_manage)
{







     //database *userDb = database::getdatabase();
    ui->setupUi(this);
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    //int columnNum = userDb->get_now_number(name);
    //model->setColumnCount(columnNum);

    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "goods_manage";
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
    model1->setHeaderData(6,Qt::Horizontal,"进货商");
    model1->setHeaderData(7,Qt::Horizontal,"进货商电话");
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
    this->ui->tableView->setColumnWidth(6, 150);
     this->ui->tableView->setColumnWidth(7, 150);
//    this->ui->tableView->setColumnWidth(8, 150);
//    this->ui->tableView->setColumnWidth(9, 150);
//    this->ui->tableView->setColumnWidth(10, 150);
//    this->ui->tableView->setColumnWidth(11, 150);


  /*  //右键菜单
    ui->tableView->verticalHeader()->setVisible(false);   //隐藏列表头
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //选择整行
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); //只选择一行
    ui->tableView->horizontalHeader()->setStretchLastSection(true); //最后一列填满表
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu); //可弹出右键菜单
    QMenu *popMenu; //菜单
    popMenu = new QMenu(ui->tableView);
    QAction *actionUpdateInfo = new QAction();
    QAction *actionDelInfo = new QAction();
    actionUpdateInfo ->setText(QString("修改"));
    actionDelInfo ->setText(QString("删除"));
    popMenu->addAction(actionUpdateInfo);
    popMenu->addAction(actionDelInfo);
    connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));

*/

    //ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
  /* ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    popMenu = new QMenu(ui->tableView);
    QAction *actionUpdateInfo = new QAction();
    QAction *actionDelInfo = new QAction();
    actionUpdateInfo ->setText(QString("修改"));
    actionDelInfo ->setText(QString("删除"));
    popMenu->addAction(actionUpdateInfo);
    popMenu->addAction(actionDelInfo);
    connect(actionUpdateInfo,&QAction::triggered,this,&goods_manage::update_info);
    connect(actionDelInfo,&QAction::triggered,this,&goods_manage::del_info);
    //connect(ui->tableView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotContextMenu(QPoint)));
    connect(ui->tableView,SIGNAL(customContextMenuRequested(const QPoint &pos)),this,SLOT(createContextMenu(const QPoint &pos)));
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    */
        //660 460
        //resize();
      /*  int a=QApplication::desktop ()->height();
        //qDebug()<<a;
        int b=QApplication::desktop ()->width();
        resize(b-10,a-65);
        splitter = new QSplitter(Qt::Horizontal, this);
        splitter->setHandleWidth(1);
        splitter->setStyleSheet("QSplitter::handle{background:#FFFFFF}");
        contentFrame = new QFrame(splitter);
        //contentFrame->setStyleSheet("background:#000000");
       // contentFrame->resize(0, height());
        //contentFrame->setMinimumWidth(405)
        contentFrame->setMaximumHeight(0);
        contentFrame->setMaximumWidth(200);
        listFrame = new QFrame(splitter);
        //listFrame->setStyleSheet("rgba(255, 255, 255,0)");
        listFrame->setStyleSheet("background:#000000");
        listFrame->resize(660 - 475, 100);
        listFrame->setMaximumWidth(660 - 405);
        //listFrame->setMaximumHeight(100);
        //listFrame->seta
        connect(splitter, SIGNAL(splitterMoved(int,int)), this, SLOT(slotSplitterMoved(int,int)));

        leftIcon = QIcon(":/new/prefix1/left.png");
        rightIcon = QIcon(":/new/prefix1/right.png");

        pushButton = new QPushButton(this);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->hide();
        pushButton->setFixedSize(26, 84);
        pushButton->setIconSize(pushButton->size());
        pushButton->setStyleSheet("border:none;");
        pushButton->setIcon(rightIcon);
        pushButton->move(b - pushButton->width()-2, (a - pushButton->height())/2);
        connect(pushButton,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));
        pushButton1 = new QPushButton(this);
        pushButton1->setIconSize(pushButton->size());
        pushButton1->move(0,0);
        connect(pushButton1,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));

        ui->pushButton_3->move(200,200);
        connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(slotClickedBtn()));
        contentFrame->setMouseTracking(true);
        listFrame->setMouseTracking(true);
        contentFrame->installEventFilter(this);
        listFrame->installEventFilter(this);



*/  //setBtnPos();
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
/*
void goods_manage::slotContextMenu(QPoint pos)
{    auto index = ui->tableView->indexAt(pos);
     selected_current_row = index.row();
     qDebug() << index.isValid();
      if (index.isValid())
      {
          popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
      }
}
*/
/*void goods_manage::update_info()
{
    QString index = (model1->index(selected_current_row,0)).data().toString();
    //qDebug()<<index;
    index1=index;

}
void goods_manage::del_info()
{

}
void goods_manage::slotContextMenu(QPoint pos)
{
    //QMenu *popMenu;

   auto index = ui->tableView->indexAt(pos);
   selected_current_row = index.row();
   qDebug() << index.isValid();
    if (index.isValid())
    {
        popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
    }
}
*/

void goods_manage::resizeEvent(QResizeEvent *event)
{
    //ui->splitter->setGeometry(0, 0, width(), height());
    //move((QApplication::desktop()->width() - width())/2,  (QApplication::desktop()->height() - height())/2);
    QWidget::resizeEvent(event);
}

bool goods_manage::eventFilter(QObject *obj, QEvent *event)
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

void goods_manage::setBtnPos()
{
    int a=QApplication::desktop ()->height();
    //qDebug()<<a;
    int b=QApplication::desktop ()->width();
    pushButtonn->move(ui->splitter->width()-pushButtonn->width()-2, (ui->splitter->height()-pushButtonn->height())/2);
    //pushButton->move(0, 0);
}
void goods_manage::setBtnPos1()
{
    //pushButton->move();
}
void goods_manage::setBtnIcon()
{
    if (ui->splitter->width() != 0&&left_or_right==0) {
        qDebug()<<ui->splitter->width();
        pushButtonn->setIcon(leftIcon);
    }
    else {
        pushButtonn->setIcon(rightIcon);
    }
}

void goods_manage::slotClickedBtn()
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

void goods_manage::slotSplitterMoved(int pos, int index)
{
    Q_UNUSED(pos)
    Q_UNUSED(index)
    setBtnIcon();
    setBtnPos();
}

void goods_manage::mousePressEvent ( QMouseEvent * event)
{
    bPressFlag = true;
    dragPosition = event->pos();
    QWidget::mousePressEvent(event);
}

void goods_manage::mouseMoveEvent(QMouseEvent *event)
{
    if (bPressFlag) {
        QPoint relaPos(QCursor::pos() - dragPosition);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(event);
}

void goods_manage::mouseReleaseEvent(QMouseEvent *event)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(event);
}

void goods_manage::reflush()
{
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query = QSqlQuery(db);
    QString name;name = "goods_manage";
    QString sql_to_tableview;
    QSqlQueryModel *model1;
    model1 = new QSqlQueryModel(this);
    model1->clear();
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
    model1->setHeaderData(6,Qt::Horizontal,"进货商");
    model1->setHeaderData(7,Qt::Horizontal,"进货商电话");
     this->ui->tableView->setColumnWidth(0, 150);    //设置列的宽度
     this->ui->tableView->setColumnWidth(1, 150);
    this->ui->tableView->setColumnWidth(2, 150);
     this->ui->tableView->setColumnWidth(3, 150);
     this->ui->tableView->setColumnWidth(4, 150);
     this->ui->tableView->setColumnWidth(5, 150);
    this->ui->tableView->setColumnWidth(6, 150);
     this->ui->tableView->setColumnWidth(7, 150);


}

goods_manage::~goods_manage()
{
    delete ui;
}

void goods_manage::on_pushButton_clicked()
{
    (new first_page)->show();
    this->hide();
}
void goods_manage::text_find()
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


void goods_manage::on_pushButton_2_clicked()
{
    text_find();
}


void goods_manage::on_pushButton_4_clicked()
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
       bool succeed = userDb->deleteGoodsByGid(selected[i].data().toInt());
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
    QString name;name = "goods_manage";
    QString sql_to_tableview;
    QSqlQueryModel *model1;
    model1 = new QSqlQueryModel(this);
    sql_to_tableview += "select * from ";
    sql_to_tableview += name;
    model1->setQuery(sql_to_tableview,db);
    ui->tableView->setModel(model1);
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
     this->ui->tableView->setColumnWidth(0, 150);    //设置列的宽度
     this->ui->tableView->setColumnWidth(1, 150);
     this->ui->tableView->setColumnWidth(2, 150);
     this->ui->tableView->setColumnWidth(3, 150);
     this->ui->tableView->setColumnWidth(4, 150);
     this->ui->tableView->setColumnWidth(5, 150);
     this->ui->tableView->setColumnWidth(6, 150);
     this->ui->tableView->setColumnWidth(7, 150);
    this->ui->tableView->setColumnWidth(8, 150);
    this->ui->tableView->setColumnWidth(9, 150);
    this->ui->tableView->setColumnWidth(10, 150);
    this->ui->tableView->setColumnWidth(11, 150);



}


void goods_manage::on_pushButton_3_clicked()
{
    if(one_page == 0){
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
    update_gid = gid;
    (new update_goods)->show();
    //this->hide();

    }
}
void goods_manage::renew()
{
    this->hide();
    (new goods_manage)->show();
}

void goods_manage::on_pushButton_5_clicked()
{
    if(one_page == 0){
    (new add_goods)->show();

    this->hide();

    }
}


void goods_manage::on_pushButton_6_clicked()
{
    QAbstractItemModel *modessl = ui->tableView->model();
    QModelIndex indextemp = modessl->index(ui->tableView->currentIndex().row(),1);
    QVariant datatemp = modessl->data(indextemp);
    QString num_of_name = datatemp.toString();
    qDebug()<<num_of_name;
    database* db = database::getdatabase();
    int sum = db->ask_num(num_of_name);
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


void goods_manage::on_pushButton_7_clicked()
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
    sum_sale = db->ask_num(num_of_name);
    QModelIndex indextemp1 = modessl->index(ui->tableView->currentIndex().row(),0);
    QVariant datatemp1 = modessl->data(indextemp1);
    select_gid = datatemp1.toInt();
    //add_goods* ag = new add_goods();
    //ag->show();
   // ag->setGoods(this);
    //this->hide();

(new sale_goods)->show();
}

void goods_manage::handle_hide() {
    this->hide();
}

//第一个参数是页面上的表格，第二个是导出文件的表头数据
 void goods_manage::Table2ExcelByHtml(QTableView *table,QString title)
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

void goods_manage::on_pushButton_8_clicked()
{
    Table2ExcelByHtml(ui->tableView,"商品明细");
}


void goods_manage::on_pushButton_9_clicked()
{
    this->hide();
    (new goods_manage)->show();
}

