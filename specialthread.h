#ifndef SPECIALTHREAD_H
#define SPECIALTHREAD_H

#include <QThread>

class TestClass : public QObject
{
    Q_OBJECT
public:
    TestClass(int);
private:
    int num;
public slots:
    void run();
signals:
    void finished();
};

class SpecialThread : public QThread
{
public:
    SpecialThread();
    void setTestClass(TestClass*);
private:
    TestClass* pTestObject;
public:
    void run();
};
#endif // SPECIALTHREAD_H
