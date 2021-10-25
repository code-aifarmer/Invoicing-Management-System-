#ifndef COORDINATE_CHART_H
#define COORDINATE_CHART_H

#include <QMainWindow>

namespace Ui {
class coordinate_chart;
}

class coordinate_chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit coordinate_chart(QWidget *parent = nullptr);
    ~coordinate_chart();

private:
    Ui::coordinate_chart *ui;
};

#endif // COORDINATE_CHART_H
