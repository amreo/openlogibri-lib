#ifndef LOGIBRILIBRARY_H
#define LOGIBRILIBRARY_H

#include <QObject>
#include <QHash>
#include "logibrilibraryinfo.h"

class LogibriLibrary : public QObject
{
    Q_OBJECT
public:
    explicit LogibriLibrary(QObject *parent = nullptr);

    void addLogibriInfo(LogibriInfo* info, int debugLevel = 0);
    void addLogibriInfoFromLibraryInfo(LibraryInfo* library, int debugLevel = 0);
    void addLogibriInfoFromLibrary(QString filename, int debugLevel = 0);
    void removeLogibriInfo(QString name);

    LogibriInfo* getLogibriInfo(QString name);
    QList<LogibriInfo*> getLogibriInfoList();

    Logibri* createLogibri(QString name);
signals:

public slots:

private:
    QHash<QString, LogibriInfo*> logibriInfoList;
};

#endif // LOGIBRILIBRARY_H
