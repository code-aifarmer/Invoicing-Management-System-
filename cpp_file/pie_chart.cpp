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

}

pie_chart::~pie_chart()
{
    delete ui;
}
