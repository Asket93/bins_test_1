#include "specialthread.h"

SpecialThread::SpecialThread()
{
    pTestObject=0;
}

void SpecialThread::setTestClass(TestClass *pTO)
{
    pTestObject=pTO;
}

void SpecialThread::run()
{
    if (pTestObject)
    {
        pTestObject->run();
    }
}
