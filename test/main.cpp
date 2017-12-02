#include <QTest>
#include <tstiologibriinterface.h>
int main(int argc, char* argv[])
{
    int status = 0;

    {
        TstIOLogibriInterface tst;
        status |= QTest::qExec(&tst, argc, argv);
    }

    return status;
}
