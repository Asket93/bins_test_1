#include "specialthread.h"
#include "window.h"
#include "ui_window.h"

#include <QThread>
#include <QtConcurrentRun>
#include <QPixmap>
#include <QPainter>
#include <QByteArray>
#include <QFile>
#include <QDebug>
#include <QString>

int p=0, y=0, r=0;

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/new/prefix1/pic3"));
    ui->label_r->setPixmap(QPixmap(":/new/prefix1/pic5"));
    ui->label_y->setPixmap(QPixmap(":/new/prefix1/pic4"));
}

Window::~Window()
{
    delete ui;
}

void Window::rotate_fly(int angle, QPixmap img, int tipe) // передаем значение угла и ссылку на изображение
                                                          // 1 -pitch, 2 -roll, 3 -yaw
{
    QPixmap rotate(img.size());
    rotate.fill(Qt::transparent);

    QPainter p(&rotate);
    p.setRenderHint(QPainter::Antialiasing); // улучшайзеры
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width()/2, rotate.size().height()/2);
    p.rotate(angle);
    p.translate(-rotate.size().width()/2, -rotate.size().height()/2);

    p.drawPixmap(0,0,img);
    p.end();
    img=rotate;
    switch (tipe) {
    case 1:
        ui->label->setPixmap(rotate);
        break;
    case 2:
        ui->label_r->setPixmap(rotate);
        break;
    case 3:
        ui->label_y->setPixmap(rotate);
        break;
    }
}
//если нужно читать из файла
void Window::read_pitch()
{
    QPixmap fly(":/new/prefix1/pic3");
    QFile pitch("/home/misha/pitch.txt");

    QString data_s;
    if (!pitch.open(QIODevice::ReadOnly))
        qDebug() << QString("error"); // Выводим данные в консоль
    data_s=pitch.readLine();
    pitch.close();
    double d_p=data_s.toDouble();
        //qDebug() << data_s; // Выводим данные в консоль
    p=abs(d_p);
    rotate_fly(p, fly, 1);

    ui->val_pitch_lable->setNum(d_p);
}
void Window::read_yaw()
{
    QPixmap fly(":/new/prefix1/pic4");
    QFile pitch("/home/misha/yaw.txt");

    QString data_s;
    if (!pitch.open(QIODevice::ReadOnly))
        qDebug() << QString("error"); // Выводим данные в консоль
    data_s=pitch.readLine();
    pitch.close();
    double d_p=data_s.toDouble();
        //qDebug() << data_s; // Выводим данные в консоль
    p=abs(d_p);
    rotate_fly(p, fly, 3);

    ui->val_yaw_lable->setNum(d_p);
}
void Window::read_roll()
{
    QPixmap fly(":/new/prefix1/pic5");
    QFile pitch("/home/misha/roll.txt");

    QString data_s;
    if (!pitch.open(QIODevice::ReadOnly))
        qDebug() << QString("error"); // Выводим данные в консоль
    data_s=pitch.readLine();
    pitch.close();
    double d_p=data_s.toDouble();
        //qDebug() << data_s; // Выводим данные в консоль
    p=abs(d_p);
    rotate_fly(p, fly, 2);

    ui->val_roll_lable->setNum(d_p);
}

void Window::on_pushButton_2_clicked()
{
    QApplication::exit();
}
// Тест. Создание потока
TestClass::TestClass(int i)
{
    num=i;
}

void TestClass::run()
{
    for (int i=0; i<5000; i++)
    {
        qDebug()<<"from"<<num;
    }
    emit finished();
}

void Window::on_pushButton_clicked()
{
    read_pitch();
    read_roll();
    read_yaw();
}

void Window::on_dial_valueChanged(int value)
{
    QPixmap fly(":/new/prefix1/pic3");
    rotate_fly(value, fly, 1);

    ui->val_pitch_lable->setNum(value);
}
