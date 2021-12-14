#ifndef OPENINGANIMATION_H
#define OPENINGANIMATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class OpeningAnimation; }
QT_END_NAMESPACE

class OpeningAnimation : public QMainWindow
{
    Q_OBJECT

public:
    OpeningAnimation(QWidget *parent = nullptr);
    ~OpeningAnimation();

    void setStyle();//设置开场动画

private:
    Ui::OpeningAnimation *ui;
};
#endif // OPENINGANIMATION_H
