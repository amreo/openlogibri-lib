#ifndef TSTLOGIBRILIBRARY_H
#define TSTLOGIBRILIBRARY_H

#include <QObject>
#include <QTest>
#include "logibrilibraryinfo.h"
#include "simplelibraryinfoloader.h"
#include "logibri.h"

class TstLogibriLibrary : public QObject {
    Q_OBJECT

private slots:
    void tstLogibryFactory()
    {
        LibraryInfo* info = getLibraryInfo();
        QCOMPARE(info->name, "org.example.simplelibrary");
        QCOMPARE(info->version, "1.0.0");
        QCOMPARE(info->logibriInfoListCount, 1);
        LogibriInfo* li =  &info->logibriInfoList[0];
        QCOMPARE(li->name, "org.example.simplelibrary.simplesum");
        Logibri* a = li->factory();
        QCOMPARE(a->getClassName(), "org.example.simplelibrary.simplesum");
    }
};



#endif // TSTLOGIBRILIBRARY_H
