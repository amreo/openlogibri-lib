#include "logibri.h"
#include "datalink.h"
Logibri::Logibri(QString name, QObject *parent) : QObject(parent)
{
    setObjectName(name);
}

QHash<QString, InputLogibriInterface*> Logibri::getInputLogibriInterface() const
{
    return inputInterfaces;
}

QHash<QString, OutputLogibriInterface*> Logibri::getOutputLogibriInterface() const
{
    return outputInterfaces;
}

void Logibri::linkInput(QString inputInterfaceName, DataLink* dl)
{
    if (inputInterfaces.contains(inputInterfaceName))
        dl->linkOutput(inputInterfaces[inputInterfaceName]);
    else
    {
        InputLogibriInterface* newILI = new InputLogibriInterface(this);
        newILI->setObjectName(inputInterfaceName);
        dl->linkOutput(newILI);
        inputInterfaces[inputInterfaceName] = newILI;
    }
}

void Logibri::unlinkInput(QString inputInterfaceName)
{
    if (inputInterfaces.contains(inputInterfaceName))
    {
        inputInterfaces[inputInterfaceName]->getDataLink()->removeOutputILI(inputInterfaces[inputInterfaceName]);
        delete inputInterfaces[inputInterfaceName];
        inputInterfaces.remove(inputInterfaceName);
    }
}

void Logibri::unlinkOutput(QString outputInterfaceName)
{
    if (outputInterfaces.contains(outputInterfaceName))
    {
        outputInterfaces[outputInterfaceName]->getDataLink()->removeInputOLI();
        delete outputInterfaces[outputInterfaceName];
        outputInterfaces.remove(outputInterfaceName);
    }
}
