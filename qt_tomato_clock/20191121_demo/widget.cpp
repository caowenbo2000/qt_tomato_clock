#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{

        effect.setSource(QUrl::fromLocalFile("C:\\Users\\caowenbo\\Desktop\\12228.wav"));
        //循环播放
        //effect.setLoopCount(QSoundEffect::Infinite);
        //设置音量，0-1
        effect.setVolume(1);
        effect.play();
    ui->setupUi(this);
    //QLabel *label = new QLabel(this);
    //label_sec->setText("this"+QString::number(sec));
    ui->label_sec->setText("<h1>PLEASE START</h1>");
    ui->label_sec->setStyleSheet("background-color:GREEN;");
    ui->label_sec->setAlignment(Qt::AlignCenter);
    ui->label_did->setAlignment(Qt::AlignCenter);
    ui->label_did->setStyleSheet("background-color:PINK;");
    ui->label_did->setText(QString("<h1>%1<h1>").arg(str));
    connect(ttimer,&QTimer::timeout,
            [=]() mutable
    {
        sec++;
        if(sec==WORKT)
        {
            effect.play();
        }
        if(sec==TIME)
        {
            if(num==0) str="TOTAL tomatos:";
            num++;
            sec-=TIME;
            str+='#';
            ui->label_did->setText(QString("<h1>%1<h1>").arg(str));
            effect.play();
        }
        if(sec>=WORKT)//判断是休息时间还是工作时间：休息时间
        {
            res=TIME-sec;
            isbreak=1;
        }
        else //工作时间
        {
            res=WORKT-sec;
            isbreak=0;
        }
        tturn(res);
        if(isbreak==0) ui->label_sec->setText(QString("<h1>WORK time is %1:%2</h1>").arg(rmin).arg(rsec));
        else ui->label_sec->setText(QString("<h1>BREAK time is %1:%2</h1>").arg(rmin).arg(rsec));
    }
            );
    ui->pushButton->setText("停止");
    ui->pushButton_2->setText("开始");
    connect(ui->pushButton,&QPushButton::clicked,
            [=]() mutable
    {
        ttimer->stop();
        sec=0;
       ui->label_sec->setText("<h1>PLEASE START</h1>");
    }
            );
    connect(ui->pushButton_2,&QPushButton::clicked,
            [=]() mutable
    {
        ttimer->start(1000);
    }
    );
}

Widget::~Widget()
{
    delete ui;
}

void Widget::tturn(int x)
{
    rmin=x/60;
    rsec=x%60;
}
