#ifndef DATALINK_H
#define DATALINK_H

#include <QObject>
#include <QList>
#include "iologibriinterface.h"

class DataLink : public QObject
{
    Q_OBJECT
public:
    explicit DataLink(QObject *parent = nullptr);

    const char *getDataType() const;
    int getDataLength() const;
    void *getPushingData() const;

    void linkInput(IOLogibriInterface* ioli);
    void linkOutput(IOLogibriInterface* ioli);
    void removeInputIOLI();
    void removeOutputIOLI(IOLogibriInterface* ioli);
    IOLogibriInterface* getInputLogibriInterface();
    QList<IOLogibriInterface* > getOutputLogibriInterfaces();

private:
    IOLogibriInterface* input;
    QList<IOLogibriInterface*> outputs;

signals:

public slots:

};

#endif // DATALINK_H
