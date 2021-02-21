#ifndef MINUTEUR_H
#define MINUTEUR_H

#include <QMainWindow>
#include <QStyle>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class Minuteur; }
QT_END_NAMESPACE

class Minuteur : public QMainWindow
{
    Q_OBJECT
    static const int TIMER_INTERVAL = 1000;

public:
    Minuteur(QWidget *parent = nullptr);
    ~Minuteur();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonPlusOne_clicked();
    void updateTime();

private:
    Ui::Minuteur *ui;
    QTimer timer;
    QTime time;
    QString remainingTimeStr();
    void pauseCountDown();
    void startCountDown(QTime startTime);
    void updateTimeLabel();
    void stopTimer();
    void notifyEnd();
};
#endif // MINUTEUR_H
