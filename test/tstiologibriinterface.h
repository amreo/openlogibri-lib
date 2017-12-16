#ifndef TSTIOLOGIBRIINTERFACE_H
#define TSTIOLOGIBRIINTERFACE_H

#include <QObject>
#include <QTest>
#include "outputlogibriinterface.h"
#include "inputlogibriinterface.h"
#include "datalink.h"
#include "common.h"
class TstIOLogibriInterface : public QObject {
    Q_OBJECT

private slots:
    void tstNew()
    {
        OutputLogibriInterface ioli;

        QCOMPARE(ioli.getDataLength(), 0);
        QCOMPARE(ioli.getPushingData(), nullptr);
        QCOMPARE(ioli.getDataType(), nullptr);
        QCOMPARE(ioli.getDataLink(), nullptr);
    }

    void tstNewInt32()
    {
        OutputLogibriInterface ioli(INT_DATA_TYPE);
        ioli.setDataLength(4);
        QCOMPARE(ioli.getDataLength(), 4);
        QCOMPARE(ioli.getPushingData(), nullptr);
        QCOMPARE(ioli.getDataType(), INT_DATA_TYPE);
        QCOMPARE(ioli.getDataLink(), nullptr);
    }

    void tstPushValue()
    {
        OutputLogibriInterface ioli(INT_DATA_TYPE);
        ioli.setDataLength(4);
        int* data = new int();
        *data = 10;
        QCOMPARE(ioli.getDataLength(), 4);

        QCOMPARE(ioli.getPushingData(), nullptr);
        QCOMPARE(ioli.getDataType(), INT_DATA_TYPE);
        ioli.setPushingData(data);
        QCOMPARE(ioli.getPushingData(), data);
        QCOMPARE(*(int *)ioli.getPushingData(),  *data);
    }

    void tstSetDataLink()
    {
        OutputLogibriInterface ioli;
        DataLink* dl = new DataLink();
        QCOMPARE(ioli.getDataLink(), nullptr);
        ioli.setDataLink(dl);
        QCOMPARE(ioli.getDataLink(), dl);
    }

    void tstPullData()
    {
        OutputLogibriInterface* out = new OutputLogibriInterface(INT_DATA_TYPE);
        out->setDataLength(4);
        InputLogibriInterface* in= new InputLogibriInterface();
        DataLink* link = new DataLink();
        int* data = new int();
        *data = 10;
        link->linkInput(out);
        link->linkOutput(in);

        QCOMPARE(in->getDataLength(), 4);
        QCOMPARE(in->getDataType(), INT_DATA_TYPE);
        QCOMPARE(in->getPushingData(), nullptr);

        out->setPushingData(data);

        QCOMPARE(in->getDataLength(), 4);
        QCOMPARE(in->getDataType(), INT_DATA_TYPE);
        QCOMPARE(in->getPushingData(), data);
    }

    void tstPullDataNoDataLink()
    {
        InputLogibriInterface* in= new InputLogibriInterface();

        QCOMPARE(in->getDataLength(), 0);
        QCOMPARE(in->getDataType(), nullptr);
        QCOMPARE(in->getPushingData(), nullptr);

    }

};

#endif // TSTIOLOGIBRIINTERFACE_H
