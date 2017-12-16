#ifndef INPUTLOGIBRIINTERFACE_H
#define INPUTLOGIBRIINTERFACE_H
#include <QObject>
class DataLink;

/**
 * @brief The InputLogibriInterface class ia a class that manage a input interface of the logibris.
 */
class InputLogibriInterface : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Create a new InputLogibriInterface object.
     */
    InputLogibriInterface(QObject *parent = nullptr);

    /**
     * @brief Return the data type of the interface.
     * @return the data type.
     */
    virtual const char *getDataType() const;
    /**
     * @brief Return the length of the data that pass through the interface.
     * @return the data length.
     */
    virtual int getDataLength() const;
    /**
     * @brief Return the pushing data to the DataLink
     * @return The pushing data to the Datalink
     */
    virtual void *getPushingData() const;

    /**
     * @brief Set the DataLink connected to this LogibriInterface
     */
    void setDataLink(DataLink* dl);
    /**
     * @brief Return the DataLink connected to this LogibriInterface
     * @return The DataLink connected to this LogibriInterface
     */
    DataLink* getDataLink() const;

private:
    DataLink* dataLink;

};

#endif // INPUTLOGIBRIINTERFACE_H
