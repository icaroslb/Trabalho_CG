#-------------------------------------------------
#
# Project created by QtCreator 2018-11-08T13:13:30
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raycasting
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


SOURCES += \
        src/main.cpp \
        src/mainwindow.cpp \
    src/glwidget.cpp \
    src/objeto.cpp \
    src/vetor.cpp \
    src/vertice.cpp \
    src/face.cpp \
    src/esfera.cpp \
    src/parser.cpp \

HEADERS += \
        headers/mainwindow.h \
    headers/glwidget.h \
    headers/objeto.h \
    headers/forma.h \
    headers/vertice.h \
    headers/vetor.h \
    headers/face.h \
    headers/esfera.h \
    headers/parser.h

FORMS += \
        mainwindow.ui
