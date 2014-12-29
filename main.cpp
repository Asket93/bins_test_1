#include <QApplication>
#include <QThread>
#include <QtConcurrentRun>
#include "window.h"
#include "specialthread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window w;
    // w.setWindowFlags(Qt::CustomizeWindowHint);
    w.show();
    //запускаем поток
    SpecialThread one;
    SpecialThread two;
    SpecialThread three;

    TestClass text1(1);
    TestClass text2(2);
    TestClass text3(3);

    QObject::connect(&one,SIGNAL(started()),&text1,SLOT(run()));
    QObject::connect(&text1,SIGNAL(finished()),&one,SLOT(terminate()));

    QObject::connect(&two,SIGNAL(started()),&text2,SLOT(run()));
    QObject::connect(&text2,SIGNAL(finished()),&two,SLOT(terminate()));

    text1.moveToThread(&one);
    text2.moveToThread(&two);

    //QtConcurrent::run(&text1,&TestClass::run);
    //QtConcurrent::run(&text2,&TestClass::run);
    //one.setTestClass(&text1);
    //two.setTestClass(&text2);
    //three.setTestClass(&text3);
    //one.start();
    //two.start();
    //two.QThread::usleep(1000);
    //one.terminate();
    one.start();
    two.start();
    //three.start();
    return a.exec();
}
