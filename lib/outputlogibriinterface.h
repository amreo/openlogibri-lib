#ifndef OUTPUTLOGIBRIINTERFACE_H
#define OUTPUTLOGIBRIINTERFACE_H

#include <QObject>
#include "inputlogibriinterface.h"

/**
 * @brief The OutputLogibriInterface class is a class that manage a output interface of the logibris.
 */
class OutputLogibriInterface : public InputLogibriInterface
{
    Q_OBJECT
public:
    /**
     * @brief Create a new OutputLogibriInterface with the specified datatype and data length.
     * @param dataType is the interface data type.
     * @param dataLength it the length of data that pass throught the interface.
     */
    OutputLogibriInterface(char const* dataType = nullptr, int dataLength = 0, QObject *parent = nullptr);

    /**
     * @brief Set the length of the data.
     * @param value the length to be setted.
     */
    void setDataLength(int value);

  /**
   * @brief Set the pushing data to the DataLimk.
   * @param value The pointer to the data.
   */
  void setPushingData(void *value);

    // InputLogibriInterface interface
public:
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
     * @brief Return the pushing data to the DataLink
     * @return The pushing data to the Datalink
     */
    void *getPushingData() const;

private:
    char const* dataType;
    int dataLength;
    void* pushingData;
};

#endif // OUTPUTLOGIBRIINTERFACE_H
