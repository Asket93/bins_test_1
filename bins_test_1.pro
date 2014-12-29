#-------------------------------------------------
#
# Project created by QtCreator 2014-11-16T22:27:32
#
#-------------------------------------------------

QT       += core gui
QT       += concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bins_test_1
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    specialthread.cpp

HEADERS  += window.h \
    specialthread.h

FORMS    += window.ui

RESOURCES += \
    img.qrc

OTHER_FILES +=
