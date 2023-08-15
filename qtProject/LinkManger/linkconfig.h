#ifndef LINKCONFIG_H
#define LINKCONFIG_H

#include <QHostAddress>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QCoreApplication>
#include <QSerialPort>
typedef uint16_t PortType;
class ILink;

enum LinkStatus/* : int*/ ///值越小优先级越高
{
    LinkStatusError = -1,
    ConnectSuccess,      ///< 连接成功
    DisConSuccess ,      ///< 断开连接成功
    LinkError     ,      ///< 连接错误
    ConnectFailure,     ///<  连接失败
    DisConFailure ,     ///<  断开连接失败
    UnkonowStatus       ///<  未知状态
};

enum LinkType {
    LinkTypeError = -1,
    LinkTypeSerial,     ///< Serial Link
    LinkTypeUdp,        ///< UDP Link
    LinkTypeTcp,        ///< TCP Link
    LinkTypeMultiCastUdp,
    LinkTypeBroadCastUdp,
    //LinkTypeBluetooth,  ///< Bluetooth Link
    LinkTypeLast        // Last type value (type >= TypeLast == invalid)
};

enum LinkFunction {
    LinkFunctionError = -1,
    LinkFunSendRece,        ///< Send&Receive Link
    LinkFunSend,            ///< Send Link
    LinkFunReceive,         ///< Receive Link
    LinkFunLast             // Last type value (type >= TypeLast == invalid)
};

struct BaseConfig{
    BaseConfig();
    QString               linkID;
    QString               linkName;
    bool                  bUpdate;
    bool                  bAutoLink;
    LinkType              connectType;
    int                   protoType;
    LinkStatus            linkStatus;
    QList<QString>        lstProtoName;
    LinkFunction          linkFunction;
    QString               linkInfo;

    QHostAddress          localIP = QHostAddress("0,0,0,0");
    PortType              localPort = 0;
    QHostAddress          targetIP = QHostAddress("-1,-1,-1,-1");
    PortType              targetPort = 0;

    QSerialPort::BaudRate boundRate;
    QString               serialPort = "-1";

    ILink*      pLink;
    ~BaseConfig();
};

class LinkConfig:public QObject
{
    Q_OBJECT
public:
    static LinkConfig *instance();

    ~LinkConfig();

    void makeConfig();

    void readConfig();

    void readShouldModifyLinkID();

    void readLinkConfig(QJsonObject &obj,BaseConfig &config);

    void appendLinkConfig(BaseConfig* config);

    QString  orgnaizationProtoName(const QStringList& lst);

    QSerialPort::BaudRate  switchStringToBaudRate(const int &intRate);

    uint16_t getMaxCacheSize() const;

    void startWatcher();

    void stopWatcher();

    void removeLinkConfigs(const QList<BaseConfig*> &lstConfig);
    void removeLinkConfig( BaseConfig* config,const QString& ProtoName);
    void removeLinkConfig( const QString& strLinkID);
    void removeFileLinkConfig(const QString& strLinkID);

    void modifyFileLinkConfig(const QString& strLinkID);

    void saveConfig(const BaseConfig* config);
public:
    QList<BaseConfig*> getLstConfig() const;

    QMap<QString, BaseConfig *> getMapConfig() const;

signals:
    void sig_CreateNewLink(BaseConfig* config);

private:
    LinkConfig(QObject *parent = nullptr);
    static QScopedPointer<LinkConfig> m_instance;

    QMap<QString,BaseConfig*> m_mapConfig;

    quint16 m_maxCacheSize;
    QFileSystemWatcher m_fileWatcher;
    QString m_configFilePath;

};

#endif // LINKCONFIG_H
