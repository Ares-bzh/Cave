#-------------------------------------------------
#
# Project created by QtCreator 2016-09-12T17:32:55
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cave
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Rack.cpp \
    Bottle.cpp \
    BottleList.cpp \
    GraphicsView.cpp

HEADERS  += MainWindow.h \
    Rack.h \
    Bottle.h \
    BottleList.h \
    GraphicsView.h

FORMS    += MainWindow.ui
