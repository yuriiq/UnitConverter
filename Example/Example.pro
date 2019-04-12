#-------------------------------------------------
#
# Project created by QtCreator 2018-03-08T11:06:20
#
#-------------------------------------------------

QT       += qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Application
TEMPLATE = app

FORMS += \
    mainwindow.ui

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

INCLUDEPATH += ../UnitConverterWidget
LIBS += -L./../UnitConverterWidget -lUnitConverterWidget
