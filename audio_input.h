#ifndef AUDIO_INPUT_H
#define AUDIO_INPUT_H

#include <QMainWindow>

namespace Ui {
class audio_input;
}

class audio_input : public QMainWindow
{
    Q_OBJECT

public:
    explicit audio_input(QWidget *parent = nullptr);
    ~audio_input();

private:
    Ui::audio_input *ui;
};

#endif // AUDIO_INPUT_H
