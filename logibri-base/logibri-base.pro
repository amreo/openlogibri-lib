#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T12:53:50
#
#-------------------------------------------------

QT       -= gui
TARGET = logibri-base
TEMPLATE = lib
CONFIG += c++11

DEFINES += LOGIBRI_BASE_LIBRARY

DESTDIR = ../bin
MOC_DIR = ../build/moc
RCC_DIR = ../build/rcc
UI_DIR = ../build/ui

CONFIG += c++11

unix:OBJECTS_DIR = ../build/o/unix
win32:OBJECTS_DIR = ../build/o/win32
macx:OBJECTS_DIR = ../build/o/mac

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../bin/release/ -lopenlogibri
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../bin/debug/ -lopenlogibri
else:unix: LIBS += -L$$OUT_PWD/../bin/ -lopenlogibri

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

HEADERS += \
    logibrilogicoperator.h

SOURCES += \
    logibrilogicoperator.cpp
