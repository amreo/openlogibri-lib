#include "logibrilibrary.h"
#include <QLibrary>
#include <QtDebug>
LogibriLibrary::LogibriLibrary(QObject *parent) : QObject(parent)
{

}

void LogibriLibrary::addLogibriInfo(LogibriInfo *info, int debugLevel)
{
    if (debugLevel == 1)
        qInfo() << "Added logibri to library: " << info->name;
    logibriInfoList.insert(info->name, info);
}

void LogibriLibrary::addLogibriInfoFromLibraryInfo(LibraryInfo *library, int debugLevel)
{
    if (debugLevel == 1)
        qInfo() << "Adding some logibri from library: " << library->name << " " << library->version;
    for (int i=0; i<library->logibriInfoListCount; i++)
        addLogibriInfo(&library->logibriInfoList[i]);
}

void LogibriLibrary::addLogibriInfoFromLibrary(QString filename, int debugLevel)
{
    if (QLibrary::isLibrary(filename))
    {
        QLibrary lib(filename);
        lib.load();
        if (lib.isLoaded())
        {
            LibraryInfoLoader* loader = (LibraryInfoLoader*) lib.resolve("getLibraryInfo");
            if (loader)
            {
                LibraryInfo* info = loader();
                addLogibriInfoFromLibraryInfo(info, debugLevel);
            }
            else
            {
                qWarning() << "Failed to resolve the symbol getLibraryInfo of the library " << filename << ", error:" << lib.errorString();
            }
        }
        else
        {
            qWarning() << "Failed to load the library " << filename << ", error:" << lib.errorString();
        }
    }
    else
    {
        qWarning() << filename << " is not a library";
    }
}

void LogibriLibrary::removeLogibriInfo(QString name)
{
    logibriInfoList.remove(name);
}

LogibriInfo *LogibriLibrary::getLogibriInfo(QString name)
{
    return logibriInfoList[name];
}

QList<LogibriInfo *> LogibriLibrary::getLogibriInfoList()
{
    return logibriInfoList.values();
}

Logibri* LogibriLibrary::createLogibri(QString name)
{
    if (!logibriInfoList.contains(name))
        return nullptr;
    return logibriInfoList[name]->factory();
}
