#include "inputlogibriinterface.h"
#include "datalink.h"

InputLogibriInterface::InputLogibriInterface(QObject *parent) : QObject(parent)
{
    dataLink = nullptr;
}

const char *InputLogibriInterface::getDataType() const
{
    if (dataLink == nullptr)
        return nullptr;
    else
        return dataLink->getDataType();
}

int InputLogibriInterface::getDataLength() const
{
    if (dataLink == nullptr)
        return 0;
    else
        return dataLink->getDataLength();
}

void *InputLogibriInterface::getPushingData() const
{
    if (dataLink == nullptr)
        return nullptr;
    else
        return dataLink->getPushingData();
}

void InputLogibriInterface::setDataLink(DataLink *dl)
{
    dataLink = dl;
}

DataLink *InputLogibriInterface::getDataLink() const
{
    return dataLink;
}
