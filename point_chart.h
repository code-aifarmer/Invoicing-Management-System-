#ifndef POINT_CHART_H
#define POINT_CHART_H

#include <QMainWindow>

namespace Ui {
class point_chart;
}

class point_chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit point_chart(QWidget *parent = nullptr);
    ~point_chart();

private:
    Ui::point_chart *ui;
};

#endif // POINT_CHART_H
