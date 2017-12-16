#ifndef TSTDATALINK_H
#define TSTDATALINK_H

#include <QObject>
#include <QTest>
#include "datalink.h"
#include "inputlogibriinterface.h"
#include "common.h"
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
        OutputLogibriInterface* in = new OutputLogibriInterface(INT_DATA_TYPE);
        in->setDataLength(4);

        link.linkInput(in);

        QCOMPARE(link.getInputLogibriInterface(), in);
        QCOMPARE(link.getOutputLogibriInterfaces().length(), 0);
    }
    void tstLinkoutputInterface()
    {
        DataLink link;
        InputLogibriInterface* out = new InputLogibriInterface();
        link.linkOutput(out);

        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().count(), 1);
        QCOMPARE(link.getOutputLogibriInterfaces().at(0), out);
    }

    void tstRemoveLinkInputInterface()
    {
        DataLink link;
        OutputLogibriInterface* in = new OutputLogibriInterface(INT_DATA_TYPE);
        link.linkInput(in);
        link.removeInputOLI();
        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().length(), 0);
    }
    void tstRemoveLinkoutputInterface()
    {
        DataLink link;
        InputLogibriInterface* out = new InputLogibriInterface();
        link.linkOutput(out);
        link.removeOutputILI(out);
        QCOMPARE(link.getInputLogibriInterface(), nullptr);
        QCOMPARE(link.getOutputLogibriInterfaces().count(), 0);
    }

    void tstGetDataInfo()
    {
        DataLink link;
        OutputLogibriInterface* in = new OutputLogibriInterface(INT_DATA_TYPE);
        in->setDataLength(4);
        int* data = new int();
        *data = 10;
        in->setPushingData(data);
        link.linkInput(in);

        QCOMPARE(link.getDataLength(), 4);
        QCOMPARE(link.getDataType(), INT_DATA_TYPE);
        QCOMPARE(link.getPushingData(), data);
        QCOMPARE(*(int*)link.getPushingData(), 10);
    }

    void tstGetNullDataInfo()
    {
        DataLink link;

        QCOMPARE(link.getDataLength(), 0);
        QCOMPARE(link.getDataType(), nullptr);
        QCOMPARE(link.getPushingData(), nullptr);
    }
};


#endif // TSTDATALINK_H
