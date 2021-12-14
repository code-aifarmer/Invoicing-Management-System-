#ifndef POIYLINE_CHART_H
#define POIYLINE_CHART_H
#include <QMainWindow>

namespace Ui {
class poiyline_chart;
}

class poiyline_chart : public QMainWindow
{
    Q_OBJECT

public:
    explicit poiyline_chart(QWidget *parent = nullptr);
    ~poiyline_chart();

private:
    Ui::poiyline_chart *ui;
};

#endif // POIYLINE_CHART_H
