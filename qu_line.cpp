#include "qu_line.h"
#include "ui_qu_line.h"
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
qu_line::qu_line(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::qu_line)
{
    ui->setupUi(this);
    //this->showMaximized();
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    QLineSeries *series0 = new QLineSeries();
        QLineSeries *series1 = new QLineSeries();
        *series0 << QPointF(1, 5) << QPointF(3, 7) << QPointF(7, 6) << QPointF(9, 7) << QPointF(12, 6)
                 << QPointF(16, 7) << QPointF(18, 5);
        *series1 << QPointF(1, 3) << QPointF(3, 4) << QPointF(7, 3) << QPointF(8, 2) << QPointF(12, 3)
                 << QPointF(16, 4) << QPointF(18, 3);

        QAreaSeries *series = new QAreaSeries(series0, series1);
        series->setName("Batman");
        QPen pen(0x059605);
        pen.setWidth(3);
        series->setPen(pen);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("面积图分析");
        chart->createDefaultAxes();
        chart->axisX()->setRange(0, 20);
        chart->axisY()->setRange(0, 10);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->setCentralWidget(chartView);
        this->setCentralWidget(chartView);
        this->resize(400, 300);
        this->show();
        this->showMaximized();
}

qu_line::~qu_line()
{
    delete ui;
}
