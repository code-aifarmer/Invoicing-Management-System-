#ifndef PIE_CHART_H
#define PIE_CHART_H

#include <QMainWindow>

namespace Ui {
class pie_chart;
}

class pie_chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit pie_chart(QWidget *parent = nullptr);
    ~pie_chart();

private:
    Ui::pie_chart *ui;
};

#endif // PIE_CHART_H
