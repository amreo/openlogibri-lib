#ifndef SIMPLESUMLOGIBRI_H
#define SIMPLESUMLOGIBRI_H

#include <QObject>
#include "logibri.h"

class SimpleSumLogibri : public Logibri
{
public:
    SimpleSumLogibri(QString name = "Undefined", QObject* parent = nullptr);

    // Logibri interface
public:
    void linkOutput(QString outputInterfaceName, DataLink *dl);

public slots:
    int run(int debugLevel);

    // Logibri interface
public:
    QString getClassName() const;
};

#endif // SIMPLESUMLOGIBRI_H
