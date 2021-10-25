#include "pie_chart.h"
#include "ui_pie_chart.h"
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts>
#include "database.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>
#include "goods_manage.h"
#include "sale_manage.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QDateTime>
#include <QMap>
pie_chart::pie_chart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pie_chart)
{
    ui->setupUi(this);
    //this->showMaximized();
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    database* userdb = database::getdatabase();
    /*
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
    chart->setTitle("Simple barchart example");
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
        this->show();
 */
    QPieSeries *series = new QPieSeries();
    QPieSlice* set[TRACKING_MAX_NUM];
    QPieSlice *slice  = new QPieSlice();
    for(int i = 0; i < tracking->count(); i++) {
        series->append(tracking->at(i),userdb->getGoods_numByGoods_name(tracking->at(i)));
       slice = series->slices().at(i);
       slice->setExploded();
       slice->setLabelVisible();
    }
   // QPieSlice *slice1 = series->slices().at(0);
    //slice1->setExploded();
    //slice1->setLabelVisible();

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("销量分析");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
    this->resize(400, 300);
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画模式
    this->show();
    this->showMaximized();
/*
        series->append("a", 1);
        series->append("b", 2);
        series->append("c", 3);
        series->append("d", 4);
        series->append("e", 5);
        series->append("f", 6);
        series->append("g", 7);
        series->append("h", 8);
        //append(饼块名,饼块大小)
        QPieSlice *slice = series->slices().at(0);
        slice->setExploded();
        slice->setLabelVisible();
        //slice->setPen(QPen(Qt::darkGreen, 2));
        //slice->setBrush(Qt::green);
        QPieSlice *slice1 = series->slices().at(1);
        slice1->setExploded();
        slice1->setLabelVisible();
        QPieSlice *slice2 = series->slices().at(2);
        slice2->setExploded();
        slice2->setLabelVisible();
        QPieSlice *slice3 = series->slices().at(3);
        slice3->setExploded();
        slice3->setLabelVisible();
        QPieSlice *slice4 = series->slices().at(4);
        slice4->setExploded();
        slice4->setLabelVisible();
        QPieSlice *slice5 = series->slices().at(5);
        slice5->setExploded();
        slice5->setLabelVisible();
        QPieSlice *slice6 = series->slices().at(6);
        slice6->setExploded();
        slice6->setLabelVisible();
        QPieSlice *slice7 = series->slices().at(7);
        slice7->setExploded();
        slice7->setLabelVisible();
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("title");
        chart->legend()->hide();

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->setCentralWidget(chartView);
        this->resize(400, 300);
        this->show();
        */
}

pie_chart::~pie_chart()
{
    delete ui;
}
