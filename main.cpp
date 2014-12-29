#include "window.h"
#include "specialthread.h"
#include <QApplication>

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

    one.setTestClass(&text1);
    //two.setTestClass(&text2);
    //three.setTestClass(&text3);

    one.start();
    //two.start();
    //three.start();
    return a.exec();
}
