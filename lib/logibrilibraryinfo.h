#ifndef LOGIBRILIBRARYINFO_H
#define LOGIBRILIBRARYINFO_H
#include "logibri.h"

typedef Logibri* (LogibryFactory)();

struct LogibriInfo {
    QString name;
    LogibryFactory factory;
};

struct LibraryInfo {
    QString name;
    QString version;
    LogibriInfo* logibriInfoList;
    int logibriInfoListCount;
};

typedef LibraryInfo* (LibraryInfoLoader)();

#endif // LOGIBRILIBRARYINFO_H
