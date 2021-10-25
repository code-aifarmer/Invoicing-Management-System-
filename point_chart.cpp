#include "point_chart.h"
#include "ui_point_chart.h"
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
point_chart::point_chart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::point_chart)
{
    ui->setupUi(this);
    //this->showMaximized();
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    QScatterSeries *series0 = new QScatterSeries();
        series0->setName("scatter1");
        series0->setMarkerShape(QScatterSeries::MarkerShapeCircle);
        series0->setMarkerSize(5.0);

        QScatterSeries *series1 = new QScatterSeries();
        series1->setName("scatter2");
        series1->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
        series1->setMarkerSize(10.0);

        QScatterSeries *series2 = new QScatterSeries();
        series2->setName("scatter3");
        series2->setMarkerShape(QScatterSeries::MarkerShapeRectangle);
        series2->setMarkerSize(15.0);

        series0->append(0, 6);
        series0->append(2, 4);
        series0->append(3, 8);
        series0->append(7, 4);
        series0->append(10, 5);
        *series1 << QPointF(1, 1) << QPointF(3, 3) << QPointF(7, 6) << QPointF(8, 3) << QPointF(10, 2);
        *series2 << QPointF(1, 5) << QPointF(4, 6) << QPointF(6, 3) << QPointF(9, 5);

        QChart *chart = new QChart();
        chart->addSeries(series0);
        chart->addSeries(series1);
        chart->addSeries(series2);
        chart->setTitle("散点图分析");
        chart->createDefaultAxes();
        chart->setDropShadowEnabled(false);

        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);

        this->setCentralWidget(chartView);
        this->resize(400, 300);
        this->show();
        this->showMaximized();
}

point_chart::~point_chart()
{
    delete ui;
}
