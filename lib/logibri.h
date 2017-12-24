#ifndef LOGIBRI_H
#define LOGIBRI_H

#include <QObject>
#include <QHash>
#include "outputlogibriinterface.h"
/**
 * @brief The Logibri class is a class that contain information about a single logibri
 */
class Logibri : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Create a new Logibri object with specified parent and object
     * @param name Name of the object
     */
    explicit Logibri(QString name = "Undefined", QObject *parent = nullptr);

    /**
     * @brief Return the input interfaces of this logibri
     * @return The input interfaces of this logibri
     */
    QHash<QString, InputLogibriInterface*> getInputLogibriInterface() const;
    /**
     * @brief Return the output interfaces of this logibri
     * @return The output interfaces of this logibri
     */
    QHash<QString, OutputLogibriInterface*> getOutputLogibriInterface() const;
    /**
     * @brief Connect the datalink to the input interface specified by name
     * @param inputInterfaceName The name of the input interface
     * @param dl DataLink to be connected
     */
    virtual void linkInput(QString inputInterfaceName, DataLink* dl);
    /**
     * @brief Connect the output interface specified by name to the datalink
     * @param outputInterfaceName The name of the input interface
     * @param dl DataLink to be connected
     */
    virtual void linkOutput(QString outputInterfaceName, DataLink* dl) = 0;
    /**
     * @brief Remoove the connection between the datalink and the input interface specified by name
     * @param inputInterfaceName The name of the input interface
     */
    virtual void unlinkInput(QString inputInterfaceName);
    /**
     * @brief Remoove the connection between the datalink and the output interface specified by name
     * @param outputInterfaceName The name of the output interface
     */
    virtual void unlinkOutput(QString outputInterfaceName);

public slots:
    /**
     * @brief Execute the logibri
     * @param debug True if print to the stdout information about the execution
     * @return 0 if the executrion is completed successfull, otherwise a negative numero
     */
    virtual int run(int debugLevel = 1) = 0;

protected:
    QHash<QString, InputLogibriInterface*> inputInterfaces;
    QHash<QString, OutputLogibriInterface*> outputInterfaces;
};

#endif // LOGIBRI_H
