#ifndef DATALINK_H
#define DATALINK_H

#include <QObject>

class DataLink : public QObject
{
    Q_OBJECT
public:
    explicit DataLink(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DATALINK_H