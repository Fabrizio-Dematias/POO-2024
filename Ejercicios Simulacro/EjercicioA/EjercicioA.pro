QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = LoginApp
TEMPLATE = app

SOURCES += main.cpp \
    login.cpp

HEADERS  += \
    login.h
