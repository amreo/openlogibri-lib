#include "iologibriinterface.h"

IOLogibriInterface::IOLogibriInterface(QObject *parent) : QObject(parent)
{
    this->dataLength = 0;
    this->dataType = VOID_DATA_TYPE;
    this->pushingData = nullptr;
}

IOLogibriInterface::IOLogibriInterface(const char *dataType, int dataLength, QObject *parent) : QObject(parent)
{
    this->dataType = dataType;
    this->dataLength = dataLength;
    this->pushingData = nullptr;
}

const char *IOLogibriInterface::getDataType() const
{
    return dataType;
}

int IOLogibriInterface::getDataLength() const
{
    return dataLength;
}

void IOLogibriInterface::setDataLength(int value)
{
    dataLength = value;
}

void *IOLogibriInterface::getPushingData() const
{
    return pushingData;
}

void IOLogibriInterface::setPushingData(void *value)
{
    pushingData = value;
}
