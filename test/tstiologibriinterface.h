#ifndef TSTIOLOGIBRIINTERFACE_H
#define TSTIOLOGIBRIINTERFACE_H

#include <QObject>
#include <QTest>
#include "iologibriinterface.h"
class TstIOLogibriInterface : public QObject {
    Q_OBJECT

private slots:
    void tstNew()
    {
        IOLogibriInterface ioli;

        QCOMPARE(ioli.getDataLength(), 0);
        QCOMPARE(ioli.getPushingData(), nullptr);
        QCOMPARE(ioli.getDataType(), VOID_DATA_TYPE);
    }

    void tstNewInt32()
    {
        IOLogibriInterface ioli(INT_DATA_TYPE, 4);

        QCOMPARE(ioli.getDataLength(), 4);
        QCOMPARE(ioli.getPushingData(), nullptr);
        QCOMPARE(ioli.getDataType(), INT_DATA_TYPE);
    }

    void tstPushValue()
    {
        IOLogibriInterface ioli(INT_DATA_TYPE, 4);
        int* data = new int();
        *data = 10;
        QCOMPARE(ioli.getDataLength(), 4);

        QCOMPARE(ioli.getPushingData(), nullptr);
        QCOMPARE(ioli.getDataType(), INT_DATA_TYPE);
        ioli.setPushingData(data);
        QCOMPARE(ioli.getPushingData(), data);
        QCOMPARE(*(int *)ioli.getPushingData(),  *data);
    }


};

#endif // TSTIOLOGIBRIINTERFACE_H
