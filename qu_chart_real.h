#ifndef QU_CHART_REAL_H
#define QU_CHART_REAL_H

#include <QMainWindow>

namespace Ui {
class qu_chart_real;
}

class qu_chart_real : public QMainWindow
{
    Q_OBJECT

public:
    explicit qu_chart_real(QWidget *parent = nullptr);
    ~qu_chart_real();

private:
    Ui::qu_chart_real *ui;
};

#endif // QU_CHART_REAL_H
