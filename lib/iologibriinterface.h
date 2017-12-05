#ifndef IOLOGIBRIINTERFACE_H
#define IOLOGIBRIINTERFACE_H

#include <QObject>
#include <QtTest/QTest>
#include "common.h"
/**
 * @brief The IOLogibriInterface class is a object that manage a Logibri Data interface. It can be used as a input as a output interface.
 * @authors amreo.
 */
class IOLogibriInterface : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Create a new VOID IOLogibriInterface object.
     */
    IOLogibriInterface(QObject *parent = nullptr);
    /**
     * @brief Create a new IOLogibriInterface with the specified datatype.
     * @param dataType is the interface data type.
     * @param dataLength is the length of the data that flow through the interface.
     */
    IOLogibriInterface(const char* dataType, int dataLength, QObject *parent = nullptr);

    /**
     * @brief Return the interface data type.
     * @return the data type.
     */
    const char *getDataType() const;

    /**
     * @brief Return the length of the data that flow through the interface
     * @return the data length.
     */
    int getDataLength() const;
    /**
     * @brief Set the length of the data.
     * @param value The length to be setted.
     */
    void setDataLength(int value);

    /**
     * @brief Get the pushing data to the DataLink
     * @return The pushing data to the Datalink
     */
    void *getPushingData() const;
    /**
     * @brief Set the pushing data to the DataLimk
     * @param value The pointer to the data
     */
    void setPushingData(void *value);

private:
    char const* dataType;
    int dataLength;
    void* pushingData;

signals:

public slots:
};

#endif // IOLOGIBRIINTERFACE_H
