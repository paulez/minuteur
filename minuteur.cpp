/**
MIT License

Copyright (c) 2021 Paul Ezvan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "minuteur.h"
#include "./ui_minuteur.h"

/**
 * @brief Minuteur::Minuteur
 * Simple kitchen timer.
 * @param parent
 */
Minuteur::Minuteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Minuteur)
{
    ui->setupUi(this);
    ui->pushButtonStart->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

Minuteur::~Minuteur()
{
    delete ui;
}

/**
 * @brief Minuteur::startCountDown
 * Start the timer
 * @param userStartTime Timer time selected by the user
 */
void Minuteur::startCountDown(QTime userStartTime)
{
    time = userStartTime;
    updateTimeLabel();
    timer.start(TIMER_INTERVAL);
}

/**
 * @brief Minuteur::on_pushButton_clicked
 * Start the timer
 */
void Minuteur::on_pushButtonStart_clicked()
{
    startCountDown(ui->timeEdit->time());
}

/**
 * @brief Minuteur::remainingTimeStr
 * Format remaining time
 * @return
 */
QString Minuteur::remainingTimeStr()
{
    return time.toString();
}

/**
 * @brief Minuteur::updateTimeLabel
 * Update time display. To be run when the timer expires.
 */
void Minuteur::updateTimeLabel()
{
    ui->timeLabel->setText(time.toString());
}

/**
 * @brief Minuteur::updateTime
 * Update timer after timer has expired.
 * Triggers notification when the remaining time is 0.
 */
void Minuteur::updateTime()
{
    time = time.addMSecs(-TIMER_INTERVAL);
    if (time == QTime(0,0))
    {
        stopTimer();
        notifyEnd();
    }
    updateTimeLabel();
}

/**
 * @brief Minuteur::stopTimer
 * Stop the timer.
 */
void Minuteur::stopTimer()
{
    timer.stop();
}

/**
 * @brief Minuteur::notifyEnd
 * Notify user that the timer is over
 */
void Minuteur::notifyEnd()
{
    system("notify-send --urgency=critical 'Minuteur' 'Minuteur is over!'");
}

void Minuteur::on_pushButtonPlusOne_clicked()
{
    if (timer.isActive())
    {
        time = time.addSecs(60);
        updateTimeLabel();
    } else {
        ui->timeEdit->setTime(ui->timeEdit->time().addSecs(60));
    }
 }
