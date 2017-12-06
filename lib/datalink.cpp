#include "datalink.h"

DataLink::DataLink(QObject *parent) : QObject(parent)
{
    this->input = nullptr;
}

const char *DataLink::getDataType() const
{
    if (this->input == nullptr)
        return nullptr;
    else
        return this->input->getDataType();
}

int DataLink::getDataLength() const
{
    if (this->input == nullptr)
        return 0;
    else
        return this->input->getDataLength();

}

void *DataLink::getPushingData() const
{
    if (this->input == nullptr)
        return nullptr;
    else
        return this->input->getPushingData();

}

void DataLink::linkInput(IOLogibriInterface *ioli)
{
    this->input = ioli;
}

void DataLink::linkOutput(IOLogibriInterface *ioli)
{
    if (!this->outputs.contains(ioli))
        outputs.append(ioli);
}

void DataLink::removeInputIOLI()
{
    this->input = nullptr;
}

void DataLink::removeOutputIOLI(IOLogibriInterface *ioli)
{
    if (this->outputs.contains(ioli))
        this->outputs.removeOne(ioli);
}

IOLogibriInterface* DataLink::getInputLogibriInterface()
{
    return this->input;
}

QList<IOLogibriInterface* > DataLink::getOutputLogibriInterfaces()
{
    return this->outputs;
}
