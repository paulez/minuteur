#include "minuteur.h"
#include "./ui_minuteur.h"

Minuteur::Minuteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minuteur)
{
    ui->setupUi(this);
}

Minuteur::~Minuteur()
{
    delete ui;
}

void Minuteur::startCountDown(QTime userStartTime)
{
    time = userStartTime;
    updateTimeLabel();
    timer.start(TIMER_INTERVAL);
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateCountDown()));
}


void Minuteur::on_pushButton_clicked()
{
    startCountDown(ui->timeEdit->time());
}

QString Minuteur::remainingTimeStr(){
    return time.toString();
}

void Minuteur::updateTimeLabel() {
    ui->timeLabel->setText(time.toString());
}

void Minuteur::updateCountDown(){
    time = time.addMSecs(-TIMER_INTERVAL);
    updateTimeLabel();
}
