#ifndef TSTLOGIBRI_H
#define TSTLOGIBRI_H

#include <QObject>
#include <QTest>
#include "datalink.h"
#include "common.h"
#include "logibri.h"
#include "simplesumlogibri.h"

class TstLogibri : public QObject {
    Q_OBJECT

private slots:
    void tstNew()
    {
        SimpleSumLogibri* logibri = new SimpleSumLogibri();
        QCOMPARE(logibri->objectName(), "Undefined");
    }
    void tstNew2()
    {
        SimpleSumLogibri* logibri = new SimpleSumLogibri("LogibriTest1");
        QCOMPARE(logibri->objectName(), "LogibriTest1");
    }

    void tstLinkInput()
    {
        SimpleSumLogibri* logibri = new SimpleSumLogibri();
        DataLink* dl = new DataLink();
        logibri->linkInput("a", dl);
        QCOMPARE(logibri->getInputLogibriInterface().count(), 1);
        QCOMPARE(logibri->getOutputLogibriInterface().count(), 0);
        QCOMPARE(logibri->getInputLogibriInterface()["a"]->getDataLink(), dl);
        QCOMPARE(dl->getOutputLogibriInterfaces().count(), 1);
        QCOMPARE(dl->getOutputLogibriInterfaces()[0], logibri->getInputLogibriInterface()["a"]);
    }

    void tstLinkOutput()
    {
        SimpleSumLogibri* logibri = new SimpleSumLogibri();
        DataLink* dl = new DataLink();
        logibri->linkOutput("a", dl);
        QCOMPARE(logibri->getOutputLogibriInterface().count(), 1);
        QCOMPARE(logibri->getInputLogibriInterface().count(), 0);
        QCOMPARE(logibri->getOutputLogibriInterface()["a"]->getDataLink(), dl);
        QCOMPARE(dl->getInputLogibriInterface(), logibri->getOutputLogibriInterface()["a"]);
    }

    void tstUnlinkInput()
    {
        SimpleSumLogibri* logibri = new SimpleSumLogibri();
        DataLink* dl = new DataLink();
        logibri->linkInput("a", dl);
        logibri->unlinkInput("a");
        QCOMPARE(logibri->getInputLogibriInterface().count(), 0);
        QCOMPARE(logibri->getOutputLogibriInterface().count(), 0);
        QCOMPARE(dl->getOutputLogibriInterfaces().count(), 0);
    }
    void tstUnlinkOutput()
    {
        SimpleSumLogibri* logibri = new SimpleSumLogibri();
        DataLink* dl = new DataLink();
        logibri->linkOutput("a", dl);
        logibri->unlinkOutput("a");
        QCOMPARE(logibri->getInputLogibriInterface().count(), 0);
        QCOMPARE(logibri->getOutputLogibriInterface().count(), 0);
        QCOMPARE(dl->getInputLogibriInterface(), nullptr);
    }

    void tstRun()
    {
        //Simple software
        //[OLO inA: 10] --> |ILI: a  SimpleSum    OLO: c|-->[ILI outC: expected 30]
        //[OLO inB: 20] --> |ILI: b                     |
        OutputLogibriInterface* inA = new OutputLogibriInterface(INT_DATA_TYPE, 4);
        OutputLogibriInterface* inB = new OutputLogibriInterface(INT_DATA_TYPE, 4);
        int* ptrA = new int(); *ptrA = 10;
        int* ptrB = new int(); *ptrB = 20;
        inA->setPushingData(ptrA);
        inB->setPushingData(ptrB);
        InputLogibriInterface* outC = new InputLogibriInterface();
        SimpleSumLogibri* sumLogibri = new SimpleSumLogibri();
        DataLink* dlAa = new DataLink();
        DataLink* dlBb = new DataLink();
        DataLink* dlcC = new DataLink();
        dlAa->linkInput(inA);
        dlBb->linkInput(inB);
        dlcC->linkOutput(outC);
        sumLogibri->linkInput("a", dlAa);
        sumLogibri->linkInput("b", dlBb);
        sumLogibri->linkOutput("c", dlcC);

        //Run
        sumLogibri->run(1);
        //Check the result
        QCOMPARE(*(int*)outC->getPushingData(), 30);

        //Change value
        *ptrA = 30;
        //Run
        sumLogibri->run(1);
        //Check the result
        QCOMPARE(*(int*)outC->getPushingData(), 50);


    }
};



#endif // TSTLOGIBRI_H
