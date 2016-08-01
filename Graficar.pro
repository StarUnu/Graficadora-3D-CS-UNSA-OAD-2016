#-------------------------------------------------
#
# Project created by QtCreator 2016-07-31T08:59:05
#
#-------------------------------------------------

QT       += core gui
QT += datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Graficar
TEMPLATE = app


SOURCES += main.cpp\
    Desarrollo.cpp \
    FICHA.cpp \
    Generador_Ptos.cpp \
    graficadora.cpp

HEADERS  += graficadora.h \
    DEFINI.h \
    Desarrollo.h \
    FICHA.h \
    Generador_Ptos.h

FORMS    += graficadora.ui
