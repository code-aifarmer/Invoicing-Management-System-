#include "bar_chart.h"
#include "ui_bar_chart.h"
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts>

#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>
#include "sale_manage.h"
#include "database.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>
#include <QMap>



bar_chart::bar_chart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bar_chart)
{
    ui->setupUi(this);

    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    database* userdb = database::getdatabase();
 /*
    //int index_list =0;
    QDateTime current_date_time =QDateTime::currentDateTime();
    int year = current_date_time.toString("yyyy").toInt();
    QSqlDatabase db = QSqlDatabase::database("smart-home-db");
    QSqlQuery query(db);
        //TODO
    for(int i = 10; i <= 12; i++) {
        QStringList* list = new QStringList();

        QString sqlStr = QString("select distinct goods_name from order_history where order_date like '%1.%2%'").arg(year).arg((i < 10 ? "0" : "") + QString::number(i));
        qDebug()<<sqlStr;
        query.prepare(sqlStr);
        if(!query.exec())
        {
            qDebug() <<"error in bar_chart::bar_chart(QWidget*)";
            return;


        }

        while(query.next()){
            qDebug()<<query.lastError();
            list->append(query.value("goods_name").toString());
            qDebug()<<query.value("goods_name").toString();
            //db.close();
            //return true;
        }

        //获取数据库查询结果，并以字符串形式存储在list中

        if(!query.exec()){
            qDebug() << "Fail return goods id" << db.lastError().text();
            return ;
        }

        //qDebug()<<query.lastError()<<query.next();







        /////////////////////////////////////////
        QVector<Pair*>* vector = new QVector<Pair*>();
        for(int j = 0; j < list->count(); j++) {
            query.prepare("select sum(goods_num) sum from order_history where goods_name = ?");
            query.addBindValue(list->at(j));
            if(!query.exec()) {
                qDebug() <<"2nd error in bar_chart::bar_chart(QWidget*)";
            }
            //QMap<QString, int>* map = new QMap<QString, int>();
            //map->insert(list->at(j), userdb->getGoods_numByGoods_name(list->at(i)));
            if(query.next()){
                qDebug()<<query.lastError();
                int sum = query.value("sum").toInt();
                vector->append(new Pair(list->at(j), sum));
            }

        }
        //sort vector


        ///////////////////////////////



        delete list;

    }


*/

/*

        QBarSet *set0 = new QBarSet("a");
        QBarSet *set1 = new QBarSet("b");
        QBarSet *set2 = new QBarSet("c");
        QBarSet *set3 = new QBarSet("d");
        QBarSet *set4 = new QBarSet("e");
        QBarSet *set5 = new QBarSet("f");
        QBarSet *set6 = new QBarSet("g");
        QBarSet *set7 = new QBarSet("h");
        //共设置八样销量最高的商品进行统计，需要将每月销售的商品按照销量排序，取前八


        *set7 << 1;
        *set0 << 1 << 2 << 3 << 4 << 5 << 6 << 2 << 3 << 4 << 8 << 9 << 5 ;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7 << 2 << 3 << 4 << 8 << 9 << 5 ;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5 << 2 << 3 << 4 << 8 << 9 << 5 ;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5 << 2 << 3 << 4 << 8 << 9 << 5 ;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2 << 2 << 3 << 4 << 8 << 9 << 5 ;
        *set5 << 1 << 2 << 3 << 4 << 5 << 6<< 2 << 3 << 4 << 8 << 9 << 5 ;
        *set6 << 1 << 2 << 3 << 4 << 5 << 6 << 2 << 3 << 4 << 8 << 9 << 5 ;
        *set7 << 2 << 3 << 4 << 5 << 6 << 2 << 3 << 4 << 8 << 9 << 5 ;
        //set0即为第一种商品，set1为第二种商品，以此类推。
        // 后面"<<"中的十二个数据setn商品在每个月中的销售表现（利润）。


        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);
        series->append(set5);
        series->append(set6);
        series->append(set7);



        categories << "一月" << "二月" << "三月" << "四月" << "五月" << "六月"<<"七月"<<"八月"<<"九月"<<"十月"<<"十一月"<<"十二月";
        */
    QBarSeries *series = new QBarSeries();


    QBarSet* set[TRACKING_MAX_NUM];
    for(int i = 0; i < tracking->count(); i++) {
        set[i] = new QBarSet(tracking->at(i));
        *set[i] << userdb->getGoods_numByGoods_name(tracking->at(i));
        series->append(set[i]);
    }

    series->setLabelsPosition(QAbstractBarSeries::LabelsInsideEnd);
    series->setLabelsVisible(true);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("柱状图分析");
    chart->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories;

        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->setCentralWidget(chartView);
        this->resize(400, 300);
        chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画模式
        this->show();
        this->showMaximized();
}

bar_chart::~bar_chart()
{
    delete ui;
}
