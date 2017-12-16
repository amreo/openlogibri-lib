#ifndef DATALINK_H
#define DATALINK_H

#include <QObject>
#include <QList>
#include "outputlogibriinterface.h"

/**
 * @brief The DataLink class is a class that manage a one-way connection from a OutputLogibriInterface to multiple InputLogibriInterface
 */
class DataLink : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Create a new DataLink without a input and output connection
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
     * @brief Return the data on the link that are being pushed by the input OutputLogibriInterface
     * @return The data being pushed by the input OutputLogibriInterface
     */
    void *getPushingData() const;

    /**
     * @brief Connect a output OutputLogbiriInterface to the input of the datalink
     * @param oli to be connected to the datalink
     */
    void linkInput(OutputLogibriInterface* oli);
    /**
     * @brief Connect a input InputLogibriInterface to the output of the datalink
     * @param ili to be connected to the datalink
     */
    void linkOutput(InputLogibriInterface* ili);
    /**
     * @brief Remove the connection between the output InputLogibriInterface and the input of the datalink
     */
    void removeInputOLI();
    /**
     * @brief Remove the connection between the InputLogibriInterface and the output of the datalink
     * @param ili to be disconnected from the datalink
     */
    void removeOutputILI(InputLogibriInterface* ili);
    /**
     * @brief Return a pointer to the OutputLogibriInterface connected to the input of the datalink
     * @return A pointer to the oli connected to the input of the datalink
     */
    OutputLogibriInterface* getInputLogibriInterface();
    /**
     * @brief Return the list of the InputLogibriInterface's pointers connected to the output of the datalink
     * @return The list of the ili's pointer connected to the output of the datalink
     */
    QList<InputLogibriInterface* > getOutputLogibriInterfaces();

private:
    OutputLogibriInterface* input;
    QList<InputLogibriInterface*> outputs;
};

#endif // DATALINK_H
