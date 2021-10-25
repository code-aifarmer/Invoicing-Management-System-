#include "poiyline_chart.h"
#include "ui_poiyline_chart.h"
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
#include "sale_manage.h"
poiyline_chart::poiyline_chart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::poiyline_chart)
{
    ui->setupUi(this);
    //this->showMaximized();
    QIcon icon(":/new/prefix1/logo.png");
    setWindowIcon(icon);
    setWindowTitle(QStringLiteral("进销货平台"));
    database* userdb = database::getdatabase();
   // userdb->getSalesPerMonthByName(track_single);
    /* QBarSeries *series = new QBarSeries();


    QBarSet* set[TRACKING_MAX_NUM];
    for(int i = 0; i < tracking->count(); i++) {
        set[i] = new QBarSet(tracking->at(i));
        *set[i] << userdb->getGoods_numByGoods_name(tracking->at(i));
        series->append(set[i]);
    }
    */

    /*
     * LineChart Example
     */
    //添加一个QLineSeries实例
    QLineSeries *lineseries = new QLineSeries();
    //QPointF
    QVector<int>* a= userdb->getSalesPerMonthByName(track_single);
    //添加数据（点），有两种方式
    for(int i =1;i<=12;i++)
    {
       lineseries->append(i, a->at(i-1));
    }
   /* lineseries->append(1, a->at(0));  //参数分别为横纵坐标
    lineseries->append(2, a->at(0));
    lineseries->append(3, a->at(0));
    lineseries->append(4, a->at(0));
    lineseries->append(5, 4);
    lineseries->append(6, 4);
    lineseries->append(7, 4);
    lineseries->append(8, 4);
    lineseries->append(9, 4);
    lineseries->append(10, 4);
    lineseries->append(11, 4);
    lineseries->append(12, 4);

*/

    //*lineseries << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);
    //添加一个QChart实例，为了展示数据
    QChart *chart = new QChart();
    chart->legend()->hide();  //隐藏图例
    chart->addSeries(lineseries);
    chart->createDefaultAxes();
    chart->setTitle("商品销量走势折线图");
    //添加一个QChartView图例
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  //呈现方式
    //显示
    this->setCentralWidget(chartView);
    this->setCentralWidget(chartView);
    this->resize(400, 300);
    chart->setAnimationOptions(QChart::SeriesAnimations);//设置动画模式
    this->show();
    this->showMaximized();
}

poiyline_chart::~poiyline_chart()
{
    delete ui;
}
