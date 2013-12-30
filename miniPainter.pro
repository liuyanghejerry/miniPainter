#-------------------------------------------------
#
# Project created by QtCreator 2013-10-20T16:23:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = miniPainter
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    minicanvas.cpp \
    abstractbrush.cpp \
    basicbrush.cpp \
    waterbased.cpp \
    maskbased.cpp \
    binarybrush.cpp \
    brushfeature.cpp \
    sketchbrush.cpp

HEADERS  += mainwindow.h \
    minicanvas.h \
    abstractbrush.h \
    basicbrush.h \
    waterbased.h \
    brushsettings.h \
    maskbased.h \
    binarybrush.h \
    brushfeature.h \
    sketchbrush.h

FORMS    += mainwindow.ui
