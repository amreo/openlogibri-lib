#include "simplesumlogibri.h"
#include "common.h"
#include "datalink.h"
#include <QDebug>
SimpleSumLogibri::SimpleSumLogibri(QString name, QObject* parent) :  Logibri(name, parent)
{

}

void SimpleSumLogibri::linkOutput(QString outputInterfaceName, DataLink *dl)
{
    if (outputInterfaces.contains(outputInterfaceName))
        outputInterfaces[outputInterfaceName]->getDataLink()->linkInput(outputInterfaces[outputInterfaceName]);
    else
    {
        OutputLogibriInterface* newOLI = new OutputLogibriInterface(INT_DATA_TYPE, 4, this);
        newOLI->setObjectName(outputInterfaceName);
        dl->linkInput(newOLI);
        outputInterfaces[outputInterfaceName] = newOLI;
    }
}

int SimpleSumLogibri::run(int debugLevel)
{
    //pull a and b
    int a;
    int b;
    int c;
    if (inputInterfaces.contains("a"))
    {
        if (inputInterfaces["a"]->getPushingData() == nullptr)
        {
            qWarning() << this->objectName() << ": There are no pushing data for a.";
            a = 0;
        } else if (inputInterfaces["a"]->getDataType() != INT_DATA_TYPE) {
            qWarning() << this->objectName() << ": The input data type for a is not a int.";
            a = 0;
        } else if (inputInterfaces["a"]->getDataLength() > 4) {
            qWarning() << this->objectName() << ": The input data length for a is not 4.";
            a = 0;
        } else {
            a = *(int *)inputInterfaces["a"]->getPushingData();
        }
    } else {
        qWarning() << this->objectName() << ": There are no InputLogibriInterface for a.";
        a = 0;
    }


    if (inputInterfaces.contains("b"))
    {
        if (inputInterfaces["b"]->getPushingData() == nullptr)
        {
            qWarning() << this->objectName() << ": There are no pushing data to b.";
            b = 0;
        } else if (inputInterfaces["b"]->getDataType() != INT_DATA_TYPE) {
            qWarning() << this->objectName() << ": The input data type for b is not a int.";
            b = 0;
        } else if (inputInterfaces["b"]->getDataLength() > 4) {
            qWarning() << this->objectName() << ": The input data length for b is not 4.";
            b = 0;
        } else {
            b = *(int *)inputInterfaces["b"]->getPushingData();
        }
    } else {
        qWarning() << this->objectName() << ": There are no InputLogibriInterface for b.";
        b = 0;
    }

    //Run the operation
    c=a+b;

    //Debug print
    if (debugLevel == 1)
        qDebug() <<  this->objectName() << ": a=" << a << " b=" << b << " c=" << c;

    //Set the results, if there are relative interfaces
    if (outputInterfaces.contains("c"))
    {
        if (outputInterfaces["c"]->getPushingData() != nullptr)
        {
            *(int *)outputInterfaces["c"]->getPushingData() = c;
        } else {
            int* cPtr = new int();
            *cPtr = c;
            outputInterfaces["c"]->setPushingData((void*)cPtr);
        }
    }

    return 0;
}
