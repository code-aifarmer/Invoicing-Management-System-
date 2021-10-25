#include "qu_chart_real.h"
#include "ui_qu_chart_real.h"
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
#include "database.h"
#include "sale_manage.h"
#include "goods_manage.h"
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QHBoxLayout>
#include <QValueAxis>
qu_chart_real::qu_chart_real(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qu_chart_real)
{
    ui->setupUi(this);
    //this->showMaximized();
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    QSplineSeries *series = new QSplineSeries();
        series->setName("spline");
        database* db = database::getdatabase();
        QVector<int>* num = db->getSalesPerMonthByName(track_single);
        qDebug() << num->count() << (*num);
        for(int i = 0; i < 12; i++) {
            series->append(i + 1, num->at(i));
        }

        QChart *chart = new QChart();
        QChartView *chartview;
        chartview = new QChartView(chart);
        chart->legend()->hide();
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        chart->addSeries(series);
        chart->setTitle("商品销量走势曲线图");
        chart->createDefaultAxes();
        //chart->axisY()->setRange(0, 550);
        chartview->setRenderHint(QPainter::Antialiasing);
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->setCentralWidget(chartView);
        this->setCentralWidget(chartView);
        this->resize(400, 300);
        chartview->setRenderHint(QPainter::Antialiasing);
        chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画模式
        this->show();
        this->showMaximized();
}

qu_chart_real::~qu_chart_real()
{
    delete ui;
}
