#include "coordinate_chart.h"
#include "ui_coordinate_chart.h"

coordinate_chart::coordinate_chart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::coordinate_chart)
{
    ui->setupUi(this);
}

coordinate_chart::~coordinate_chart()
{
    delete ui;
}
