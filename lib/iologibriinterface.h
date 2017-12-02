#ifndef IOLOGIBRIINTERFACE_H
#define IOLOGIBRIINTERFACE_H

#include <QObject>

class IOLogibriInterface : public QObject
{
    Q_OBJECT
public:
    explicit IOLogibriInterface(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IOLOGIBRIINTERFACE_H