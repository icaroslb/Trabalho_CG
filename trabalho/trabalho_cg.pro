#-------------------------------------------------
#
# Project created by QtCreator 2018-12-03T19:09:59
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trabalho_cg
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        view/mainwindow.cpp \
    controler/raycast.cpp \
    matematica/vetor.cpp \
    view/glwidget.cpp \
    view/configuracoes.cpp \
    matematica/matriz.cpp \
    objetos/forma.cpp \
    objetos/material.cpp \
    objetos/luz.cpp \
    objetos/esfera.cpp

HEADERS += \
        view/mainwindow.h \
    controler/raycast.h \
    objetos/objetos.h \
    matematica/vetor.h \
    view/glwidget.h \
    view/configuracoes.h \
    matematica/matriz.h \
    objetos/forma.h \
    objetos/material.h \
    objetos/luz.h \
    objetos/esfera.h

FORMS += \
        mainwindow.ui \
    configuracoes.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
