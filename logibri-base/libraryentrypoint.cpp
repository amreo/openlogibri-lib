#include "logibrilibraryinfo.h"

EXPORT_ENTRY_POINT LibraryInfo* getLibraryInfo() {
    //STUB
    LibraryInfo* info = new LibraryInfo();
    info->name = "loc.logibri.logibri-base";
    info->version = "0.0.0";
    info->logibriInfoListCount = 0;
    return info;
}
