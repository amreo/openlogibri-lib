#include "outputlogibriinterface.h"

OutputLogibriInterface::OutputLogibriInterface(const char *dataType,int dataLength, QObject *parent) : InputLogibriInterface(parent)
{
    this->dataType = dataType;
    this->dataLength = dataLength;
    dataType = nullptr;
    pushingData = nullptr;
}

void OutputLogibriInterface::setDataLength(int value)
{
    dataLength = value;
}

void OutputLogibriInterface::setPushingData(void *value)
{
    pushingData = value;
}

const char *OutputLogibriInterface::getDataType() const
{
    return dataType;
}

int OutputLogibriInterface::getDataLength() const
{
    return dataLength;
}

void *OutputLogibriInterface::getPushingData() const
{
    return pushingData;
}
