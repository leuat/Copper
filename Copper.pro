#-------------------------------------------------
#
# Project created by QtCreator 2019-04-17T22:24:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Copper
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
    QMAKE_CXXFLAGS += -fopenmp
    QMAKE_CXXFLAGS +=  -Wno-unused-variable -Wno-unused-parameter -Wno-sign-compare -Wno-comment -Wno-parentheses -Wno-delete-non-virtual-dtor -Wno-missing-noreturn
    LIBS += -fopenmp
#    QMAKE_CXXFLAGS +=  -Ofast

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    source/base/copperdata.cpp \
    source/base/copperdatafactory.cpp \
    source/forms/formcopperdataviewer.cpp \
    source/base/copperbrowser.cpp

HEADERS += \
        mainwindow.h \
    source/base/copperdata.h \
    source/base/copperdatafactory.h \
    source/forms/formcopperdataviewer.h \
    source/base/copperbrowser.h

FORMS += \
        mainwindow.ui \
    source/forms/formcopperdataviewer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
