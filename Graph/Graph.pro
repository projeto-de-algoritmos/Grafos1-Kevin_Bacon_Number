TEMPLATE = app
TARGET = Graph
INCLUDEPATH += .

QT = core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

SOURCES += \
        main.cpp \
        window.cpp \
    dados.cpp \
    grafo.cpp

HEADERS += \
        window.h \
    pessoa.h \
    dados.h \
    grafo.h
