#ifndef MINUTEUR_H
#define MINUTEUR_H

#include <QMainWindow>
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
    void on_pushButton_clicked();
    void updateCountDown();

private:
    Ui::Minuteur *ui;
    QTimer timer;
    QTime time;
    QString remainingTimeStr();
    void startCountDown(QTime startTime);
    void updateTimeLabel();
};
#endif // MINUTEUR_H
