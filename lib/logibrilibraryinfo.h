#ifndef LOGIBRILIBRARYINFO_H
#define LOGIBRILIBRARYINFO_H
#include "logibri.h"

typedef Logibri* (LogibryFactory)();

struct LogibriInfo {
    QString name;
    LogibryFactory* factory;
};

struct LibraryInfo {
    QString name;
    QString version;
    LogibriInfo* logibriInfoList;
    int logibriInfoListCount;
};

typedef LibraryInfo* (LibraryInfoLoader)();

#ifdef Q_OS_WIN
#define EXPORT_ENTRY_POINT __declspec(dllexport)
#else
#define EXPORT_ENTRY_POINT extern "C"
#endif

#endif // LOGIBRILIBRARYINFO_H
