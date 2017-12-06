#ifndef TSTDATALINK_H
#define TSTDATALINK_H

#include <QObject>
#include <QTest>
#include "datalink.h"
#include "iologibriinterface.h"
class TstDataLink : public QObject {
    Q_OBJECT

private slots:
    void tstNew()
    {
        DataLink link;

        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().length(), 0);
    }

    void tstLinkInputInterface()
    {
        DataLink link;
        IOLogibriInterface* in = new IOLogibriInterface(INT_DATA_TYPE,4);
        link.linkInput(in);

        QCOMPARE(link.getInputLogibriInterface(), in);
        QCOMPARE(link.getOutputLogibriInterfaces().length(), 0);
    }
    void tstLinkoutputInterface()
    {
        DataLink link;
        IOLogibriInterface* out = new IOLogibriInterface(INT_DATA_TYPE,4);
        link.linkOutput(out);

        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().count(), 1);
        QCOMPARE(link.getOutputLogibriInterfaces().at(0), out);
    }

    void tstRemoveLinkInputInterface()
    {
        DataLink link;
        IOLogibriInterface* in = new IOLogibriInterface(INT_DATA_TYPE,4);
        link.linkInput(in);
        link.removeInputIOLI();
        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().length(), 0);
    }
    void tstRemoveLinkoutputInterface()
    {
        DataLink link;
        IOLogibriInterface* out = new IOLogibriInterface(INT_DATA_TYPE,4);
        link.linkOutput(out);
        link.removeOutputIOLI(out);
        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().count(), 0);
    }

    void tstGetDataInfo()
    {
        DataLink link;
        IOLogibriInterface* in = new IOLogibriInterface(INT_DATA_TYPE,4);
        int* data = new int();
        *data = 10;
        in->setPushingData(data);
        link.linkInput(in);

        QCOMPARE(link.getDataLength(), 4);
        QCOMPARE(link.getDataType(), INT_DATA_TYPE);
        QCOMPARE(link.getPushingData(), data);
        QCOMPARE(*(int*)link.getPushingData(), 10);
    }
};


#endif // TSTDATALINK_H
