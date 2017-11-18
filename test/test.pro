#-------------------------------------------------
#
# Project created by QtCreator 2015-08-20T14:21:17
#
#-------------------------------------------------

QT       += testlib

TARGET = test
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../bin/release/ -lopenlogibri
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../bin/debug/ -lopenlogibri
else:unix: LIBS += -L$$OUT_PWD/../bin/ -lopenlogibri

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

