#include "audio_input.h"
#include "ui_audio_input.h"

audio_input::audio_input(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::audio_input)
{
    ui->setupUi(this);
}

audio_input::~audio_input()
{
    delete ui;
}
