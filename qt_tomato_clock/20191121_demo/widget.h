#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <string>
#include <QString>
#include <QFile>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QSoundEffect>

const int BREAKT=300;
const int WORKT=1500;
const int TIME=1800;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
public:
    void tturn(int x);
private:
    Ui::Widget *ui;
    int msec=0;//毫秒
    int sec=0;//秒
    int rsec=0;
    int rmin=0;//分钟
    int rhour=0;//小时
    int res=0;//当前剩余时间
    bool isbreak;//当前是什么模式
    int num=0;//当前时间
    QString str="NONE tomatoes now";
    QTimer *ttimer=new  QTimer;
    QSoundEffect effect;
};

#endif // WIDGET_H
