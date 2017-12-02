#include <QTest>
#include "tstlogibri.h"
int main(int argc, char* argv[])
{
    int status = 0;
    {
        TstLogibri tst;
        status |= QTest::qExec(&tst, argc, argv);
    }
    return status;
}
