#ifndef SIMPLELIBRARYINFOLOADER_H
#define SIMPLELIBRARYINFOLOADER_H
#include "logibrilibraryinfo.h"
#include "simplesumlogibri.h"

inline Logibri* createSimpleSumLogibri() {
    return new SimpleSumLogibri();
}

inline LibraryInfo* getLibraryInfo() {
    LibraryInfo* info = new LibraryInfo();
    info->name = "org.example.simplelibrary";
    info->version = "1.0.0";
    info->logibriInfoList = new LogibriInfo[1];
    info->logibriInfoListCount = 1;
    info->logibriInfoList[0].name = "org.example.simplelibrary.simplesum";
    info->logibriInfoList[0].factory = createSimpleSumLogibri;

    return info;
}

#endif // SIMPLELIBRARYINFOLOADER_H
