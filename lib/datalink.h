#ifndef DATALINK_H
#define DATALINK_H

#include <QObject>
#include <QList>
#include "iologibriinterface.h"

/**
 * @brief The DataLink class is a class that manage a one-way connection from a input ioli to multiple output iolis
 */
class DataLink : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Create a new DataLink with no input and output ioli
     */
    explicit DataLink(QObject *parent = nullptr);

    /**
     * @brief Return the data type of the link
     * @return The data type of the link
     */
    const char *getDataType() const;
    /**
     * @brief Return the length of the data on the link
     * @return The length of the data on the link
     */
    int getDataLength() const;
    /**
     * @brief Return the data on the link that are being pushed by the input ioli
     * @return The data being pushed by the input ioli
     */
    void *getPushingData() const;

    /**
     * @brief Connect a output ioli to the input of the datalink
     * @param ioli to be connected to the datalink
     */
    void linkInput(IOLogibriInterface* ioli);
    /**
     * @brief Connect a input ioli to the output of the datalink
     * @param ioli to be connected to the datalink
     */
    void linkOutput(IOLogibriInterface* ioli);
    /**
     * @brief Remove the connection between the output ioli and the input of the datalink
     * @param ioli to be disconnected from the datalink
     */
    void removeInputIOLI();
    /**
     * @brief Remove the connection between the input ioli and the output of the datalink
     * @param ioli to be disconnected from the datalink
     */
    void removeOutputIOLI(IOLogibriInterface* ioli);
    /**
     * @brief Return a pointer to the ioli connected to the input of the datalink
     * @return A pointer to the ioli connected to the input of the datalink
     */
    IOLogibriInterface* getInputLogibriInterface();
    /**
     * @brief Return the list of the ioli's pointer connected to the output of the datalink
     * @return The list of the ioli's pointer connected to the output of the datalink
     */
    QList<IOLogibriInterface* > getOutputLogibriInterfaces();

private:
    IOLogibriInterface* input;
    QList<IOLogibriInterface*> outputs;

signals:

public slots:

};

#endif // DATALINK_H
