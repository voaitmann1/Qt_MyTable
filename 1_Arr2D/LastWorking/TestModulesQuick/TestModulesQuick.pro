QT += core
QT -= gui

CONFIG += c++11

TARGET = TestModulesQuick
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    mylib.cpp \
    tests1.cpp \
    fluttermodels.cpp \
    mymathlib.cpp \
    array1d_size2d_elem2d_1.cpp \
    array2dlib.cpp \
    matrixcomplex.cpp

HEADERS += \
    mylib.h \
    tests1.h \
    fluttermodels.h \
    mymathlib.h \
    array1d_size2d_elem2d_1.h \
    array2dlib.h \
    matrixcomplex.h
