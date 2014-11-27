#-------------------------------------------------
#
# Project created by QtCreator 2014-10-11T19:25:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settings.cpp \
    battlearea.cpp

HEADERS  += mainwindow.h \
    settings.h \
    battlearea.h

FORMS    += mainwindow.ui \
    settings.ui \
    battlearea.ui

OTHER_FILES += \
    config.txt

RESOURCES += \
    images.qrc

CONFIG += release

