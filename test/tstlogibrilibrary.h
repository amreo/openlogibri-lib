#ifndef TSTLOGIBRILIBRARY_H
#define TSTLOGIBRILIBRARY_H

#include <QObject>
#include <QTest>
#include "logibrilibraryinfo.h"
#include "logibri.h"
#include "logibrilibrary.h"
#include "simplelibraryinfoloader.h"
class TstLogibriLibrary : public QObject {
    Q_OBJECT

private slots:
    void tstLogibriFactory()
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

    void tstLogibriLibraryGetListWithEmptyList()
    {
        LogibriLibrary lib;
        QCOMPARE(lib.getLogibriInfoList().size(), 0);
    }
    void tstLogibriLibraryGetNotFoundLogibri()
    {
        LogibriLibrary lib;
        QCOMPARE(lib.getLogibriInfo("aaa.bbb.ccc"), nullptr);
    }

    void tstLogibriLibraryAddLogibriInfo() {
        LogibriLibrary lib;
        LogibriInfo* info = new LogibriInfo();
        info->name = "org.example.simplelibrary.simplesum";
        info->factory = createSimpleSumLogibri;
        lib.addLogibriInfo(info);

        QCOMPARE(lib.getLogibriInfoList().count(), 1);
        QCOMPARE(lib.getLogibriInfo(info->name)->name, info->name);
        QVERIFY(lib.getLogibriInfo(info->name)->factory == info->factory);
        QCOMPARE(lib.getLogibriInfo(info->name)->factory()->getClassName(), info->name);
    }

    void tstLogibriLibraryAddLibraryInfo() {
        LogibriLibrary lib;
        lib.addLogibriInfoFromLibraryInfo(getLibraryInfo());

        QCOMPARE(lib.getLogibriInfoList().count(), 1);
        QCOMPARE(lib.getLogibriInfo("org.example.simplelibrary.simplesum")->name, "org.example.simplelibrary.simplesum");
        QCOMPARE(lib.getLogibriInfo("org.example.simplelibrary.simplesum")->factory()->getClassName(), "org.example.simplelibrary.simplesum");
    }

    void tstLogibriLibraryRemoveLogibri() {
        LogibriLibrary lib;
        lib.addLogibriInfoFromLibraryInfo(getLibraryInfo());
        lib.removeLogibriInfo("org.example.simplelibrary.simplesum");

        QCOMPARE(lib.getLogibriInfoList().count(), 0);
    }

    void tstLogibriLibraryRemoveNotFoundLogibri() {
        LogibriLibrary lib;
        lib.removeLogibriInfo("org.example.simplelibrary.simplesum");

        QCOMPARE(lib.getLogibriInfoList().count(), 0);
    }

//    void tstLogibriLibraryLoadItself() {
//        LogibriLibrary lib;
//        lib.addLogibriInfoFromLibrary("../bin/liblogibri-base.so.1.0.0", 1);
//    }
};



#endif // TSTLOGIBRILIBRARY_H
