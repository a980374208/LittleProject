#ifndef SERIAPORTLINK_H
#define SERIAPORTLINK_H

#include <QObject>
#include <QSerialPort>
#include "ilink.h"

class SeriaPortLink : public ILink
{
    Q_OBJECT
public:
    explicit SeriaPortLink(BaseConfig *baseConfig,QObject *parent = nullptr);

    ~SeriaPortLink() override;

    bool _connectLink() override;

    void _disconnectLink() override;

    void initSerialPort(QSerialPort::BaudRate baudRate);

    QByteArray readAll()override;

signals:

public slots:

private:

    QSerialPort*           m_Serial = nullptr;
};

#endif // SERIAPORTLINK_H
