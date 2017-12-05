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
    IOLogibriInterface(const char* dataType, int dataLength, QObject *parent = nullptr);

    const char *getDataType() const;
    int getDataLength() const;
    void *getPushingData() const;



private:
    char const* dataType;
    int dataLength;
    void* pushingData;

private:
    IOLogibriInterface* input;
    QList<IOLogibriInterface*> outputs;

signals:

public slots:

};

#endif // DATALINK_H
