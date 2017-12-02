#include <QTest>
#include "tstlogicoperators.h"
int main(int argc, char* argv[])
{
    int status = 0;
    {
        TstLogicOperators tst;
        status |= QTest::qExec(&tst, argc, argv);
    }
    return status;
}
