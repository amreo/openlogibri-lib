#-------------------------------------------------
#
# Project created by QtCreator 2015-08-20T14:21:17
#
#-------------------------------------------------

QT       += testlib

TARGET = test-logibri-base
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../bin/release/ -lopenlogibri -llogibri-base
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../bin/debug/ -lopenlogibri -llogibri-base
else:unix: LIBS += -L$$OUT_PWD/../bin/ -lopenlogibri -llogibri-base

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
INCLUDEPATH += $$PWD/../logibri-base
DEPENDPATH += $$PWD/../logibri-base

