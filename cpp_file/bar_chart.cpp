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
