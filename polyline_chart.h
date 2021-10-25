#ifndef POLYLINE_CHART_H
#define POLYLINE_CHART_H

#include <QMainWindow>

namespace Ui {
class polyline_chart;
}

class polyline_chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit polyline_chart(QWidget *parent = nullptr);
    ~polyline_chart();

private:
    Ui::polyline_chart *ui;
};

#endif // POLYLINE_CHART_H
