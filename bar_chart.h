#ifndef BAR_CHART_H
#define BAR_CHART_H

#include <QMainWindow>

namespace Ui {
class bar_chart;
}

class bar_chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit bar_chart(QWidget *parent = nullptr);
    ~bar_chart();

private:
    Ui::bar_chart *ui;
};

#endif // BAR_CHART_H
