#-------------------------------------------------
#
# Project created by QtCreator 2012-03-16T23:17:53
#
#-------------------------------------------------

QT       += core gui

TARGET = Daedalus
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classes/maindocument.cpp \
    classes/documenttreemodel.cpp

HEADERS  += mainwindow.h \
    classes/maindocument.h \
    classes/documenttreemodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    graphics.qrc
