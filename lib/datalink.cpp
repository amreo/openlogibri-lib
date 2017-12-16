#include "datalink.h"
DataLink::DataLink(QObject *parent) : QObject(parent)
{
    this->input = nullptr;
}

const char *DataLink::getDataType() const
{
    if (input == nullptr)
        return nullptr;
    else
        return input->getDataType();
}

int DataLink::getDataLength() const
{
    if (input == nullptr)
        return 0;
    else
        return input->getDataLength();

}

void *DataLink::getPushingData() const
{
    if (input == nullptr)
        return nullptr;
    else
        return input->getPushingData();

}

void DataLink::linkInput(OutputLogibriInterface *oli)
{
    this->input = oli;
    if (oli != nullptr)
        oli->setDataLink(this);
}

void DataLink::linkOutput(InputLogibriInterface *ili)
{
    if (!this->outputs.contains(ili))
        outputs.append(ili);
    if (ili != nullptr)
        ili->setDataLink(this);
}

void DataLink::removeInputOLI()
{
    this->input = nullptr;
}
void DataLink::removeOutputILI(InputLogibriInterface *ili)
{
    if (this->outputs.contains(ili))
        this->outputs.removeOne(ili);
}

OutputLogibriInterface *DataLink::getInputLogibriInterface()
{
    return this->input;
}

QList<InputLogibriInterface *> DataLink::getOutputLogibriInterfaces()
{
    return this->outputs;
}
