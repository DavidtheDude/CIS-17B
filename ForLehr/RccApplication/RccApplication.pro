#-------------------------------------------------
#
# Project created by QtCreator 2014-11-16T02:38:32
#
#-------------------------------------------------

QT       += core gui sql
QT       +=xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RccApplication
TEMPLATE = app


SOURCES += main.cpp\
        loginpage.cpp \
    sha1.cpp \
    settings.cpp \
    io.cpp \
    database.cpp \
    createaccount.cpp \
    user.cpp \
    globals.cpp \
    homescreen.cpp \
    homescreenpages.cpp \
    subforum.cpp \
    thread.cpp \
    respond.cpp

HEADERS  += loginpage.h \
    sha1.h \
    setting.h \
    io.h \
    database.h \
    createaccount.h \
    user.h \
    globals.h \
    homescreen.h \
    homescreenpages.h \
    subforum.h \
    thread.h \
    respond.h

FORMS    += loginpage.ui \
    createaccount.ui \
    NewsPage.ui \
    Forums.ui \
    schedule.ui \
    schoolInfo.ui \
    Appointments.ui \
    busSchedule.ui \
    about.ui \
    clubs.ui \
    Map.ui \
    subforum.ui \
    thread.ui \
    respond.ui

RESOURCES += \
    Images.qrc \
    xml.qrc

QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

OTHER_FILES += \
    article2.txt \
    article3.txt
