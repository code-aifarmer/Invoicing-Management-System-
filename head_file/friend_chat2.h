#ifndef FRIEND_CHAT2_H
#define FRIEND_CHAT2_H

#include <QMainWindow>

namespace Ui {
class friend_chat2;
}

class friend_chat2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit friend_chat2(QWidget *parent = nullptr);
    ~friend_chat2();

private:
    Ui::friend_chat2 *ui;
};

#endif // FRIEND_CHAT2_H
