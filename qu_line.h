#ifndef QU_LINE_H
#define QU_LINE_H

#include <QMainWindow>

namespace Ui {
class qu_line;
}

class qu_line : public QMainWindow
{
    Q_OBJECT

public:
    explicit qu_line(QWidget *parent = nullptr);
    ~qu_line();

private:
    Ui::qu_line *ui;
};

#endif // QU_LINE_H
