#ifndef IOLOGIBRIINTERFACE_H
#define IOLOGIBRIINTERFACE_H

#include <QObject>
#include <QtTest/QTest>
#include "common.h"
class IOLogibriInterface : public QObject
{
    Q_OBJECT
public:
    IOLogibriInterface(QObject *parent = nullptr);
    IOLogibriInterface(const char* dataType, int dataLength, QObject *parent = nullptr);

    const char *getDataType() const;

    int getDataLength() const;
    void setDataLength(int value);

    void *getPushingData() const;
    void setPushingData(void *value);

private:
    char const* dataType;
    int dataLength;
    void* pushingData;

signals:

public slots:
};

#endif // IOLOGIBRIINTERFACE_H
