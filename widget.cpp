#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbCoke->setEnabled(false);
    ui->pbTea->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
    pdCheck();
}
void Widget::pdCheck(){

    if(money < 100){
        ui->pbCoffee->setEnabled(false);
    }else{
        ui->pbCoffee->setEnabled(true);
    }

    if(money < 150){
        ui->pbTea->setEnabled(false);
    }else{
        ui->pbTea->setEnabled(true);
    }

    if(money < 200){
        ui->pbCoke->setEnabled(false);
    }else{
        ui->pbCoke->setEnabled(true);
    }
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    resetMoney(money);
    QMessageBox msg;
    msg.information(nullptr, "See U Lat3r!", message);
    changeMoney(money * -1);
}

void Widget::resetMoney(int n){

    int count500=0, count100=0, count50=0, count10=0;

    int m = n / 100;
    if(m >= 5){
        count500 = m/5;
        count100 = m%5;
    }else{
        count100 = m;
    }

    n = n % 100;
    if(n >= 50){
        count50 = 1;
        n -= 50;
    }
    count10 = n/10;

    message.sprintf("500 won : %d\n100 won : %d\n50 won : %d\n10 won : %d",count500, count100, count50, count10);
}







