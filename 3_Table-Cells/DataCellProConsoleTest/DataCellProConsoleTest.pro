QT += core
QT -= gui

CONFIG += c++11

TARGET = DataCellProConsoleTest
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    datacell.cpp \
    mymathlib.cpp \
    numberparse.cpp \
    tableinfo.cpp \
    mystringlib.cpp \
    array1dlib.cpp \
    array2dlib.cpp \
    array2dsize.cpp \
    mylib.cpp

HEADERS += \
    datacell.h \
    mymathlib.h \
    numberparse.h \
    tableinfo.h \
    mystringlib.h \
    array1dlib.h \
    array2dlib.h \
    array2dsize.h \
    mylib.h
