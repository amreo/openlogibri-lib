#include <QTest>
#include "tstiologibriinterface.h"
#include "tstdatalink.h"
#include "tstlogibri.h"
int main(int argc, char* argv[])
{
    int status = 0;
    {
        TstIOLogibriInterface tst;
        status |= QTest::qExec(&tst, argc, argv);
    }
    {
        TstDataLink tst;
        status |= QTest::qExec(&tst, argc, argv);
    }
    {
        TstLogibri tst;
        status |= QTest::qExec(&tst, argc, argv);
    }

    return status;
}
