#include "linkconfig.h"

#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>
#include <QMutex>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include "Link/ilink.h"
#include "io.h"


LinkConfig::LinkConfig(QObject *parent):QObject (parent)
{
    m_configFilePath = QCoreApplication::applicationDirPath()+"/linkConfig.json";
    if(_access(m_configFilePath.toStdString().c_str(),0) == -1){
        makeConfig();
        qDebug()<<"aaaa";
    }
    readConfig();
    startWatcher();
    connect(&m_fileWatcher,&QFileSystemWatcher::fileChanged,this,[&](){

    });
}

QMap<QString, BaseConfig *> LinkConfig::getMapConfig() const
{
    return m_mapConfig;
}


QScopedPointer<LinkConfig> LinkConfig::m_instance;
LinkConfig *LinkConfig::instance()
{
    if(m_instance.isNull()){
        QMutex mutex;
        QMutexLocker locker(&mutex);
        if(m_instance.isNull()){
            m_instance.reset(new LinkConfig);
        }
    }
    return m_instance.data();
}

LinkConfig::~LinkConfig()
{
    qDeleteAll(m_mapConfig);
}

void LinkConfig::makeConfig()
{
    QFile loadFile(m_configFilePath);

    if (!loadFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return ;
    }
}

void LinkConfig::readConfig()
{
    QFile loadFile(m_configFilePath);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return ;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray jsonArray = loadDoc.array();
    for(int i = 0;i<jsonArray.size();++i){
        BaseConfig *baseConfig = new BaseConfig;
        QJsonObject objTmp = jsonArray.at(i).toObject();
        readLinkConfig(objTmp,*baseConfig);
        m_mapConfig.insert(baseConfig->linkID,baseConfig);
    }
}

void LinkConfig::readShouldModifyLinkID()
{
    QFile loadFile(m_configFilePath);

    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return ;
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray jsonArray = loadDoc.array();
    BaseConfig *baseConfig;
    QVector<BaseConfig*> lstConfig;
    for(auto item:jsonArray){
        if(item.toObject().value("bAutoLink").toBool() ){
            baseConfig= new BaseConfig;
            QJsonObject objTmp = item.toObject();
            readLinkConfig(objTmp,*baseConfig);
            lstConfig.append(baseConfig);
        }
    }
    for(auto item:lstConfig){
        removeLinkConfig(item->linkID);
        emit sig_CreateNewLink(item);
    }
}

void LinkConfig::readLinkConfig(QJsonObject &obj,BaseConfig &config)
{
    config.bAutoLink = obj.value("bAutoLink").toBool();
    config.bUpdate = obj.value("bUpdate").toBool();
    config.localIP =QHostAddress(obj.value("localIP").toString());
    config.localPort = static_cast<PortType>(obj.value("localPort").toInt());
    config.connectType = static_cast<LinkType>(obj.value("connectType").toInt());
    config.protoType = obj.value("protoType").toInt();
    config.targetIP = QHostAddress(obj.value("targetIP").toString());
    config.targetPort = static_cast<PortType>(obj.value("targetPort").toInt());
    config.lstProtoName = obj.value("protoName").toString().split(";");
    config.boundRate = switchStringToBaudRate(obj.value("boundRate").toInt());
    config.linkID = obj.value("linkId").toString();
    config.linkFunction = static_cast<LinkFunction>(obj.value("linkFunction").toInt());
    config.serialPort = obj.value("serialPort").toString();
    config.linkName =  obj.value("linkName").toString();
}

void LinkConfig::appendLinkConfig(BaseConfig* config)
{
    m_mapConfig.insert(config->linkID,config);
    startWatcher();
    saveConfig(config);
    stopWatcher();
}

QString LinkConfig::orgnaizationProtoName(const QStringList &lst)
{
    QString str;
    for (int i = 0;i<lst.size();++i) {
        str += lst.at(i)+";";
    }
    str = str.left(str.size()-1);
    return str;
}

QSerialPort::BaudRate LinkConfig::switchStringToBaudRate(const int &intRate)
{
    QSerialPort::BaudRate baudRate;
    switch (intRate) {
    case 1200:
        baudRate = QSerialPort::Baud1200;
        break;
    case 2400:
        baudRate = QSerialPort::Baud2400;
        break;
    case 4800:
        baudRate = QSerialPort::Baud4800;
        break;
    case 9600:
        baudRate = QSerialPort::Baud9600;
        break;
    case 19200:
        baudRate = QSerialPort::Baud19200;
        break;
    case 38400:
        baudRate = QSerialPort::Baud38400;
        break;
    case 57600:
        baudRate = QSerialPort::Baud57600;
        break;
    case 115200:
        baudRate = QSerialPort::Baud115200;
        break;
    default:
        baudRate = QSerialPort::UnknownBaud;
        break;
    };
    return baudRate;
}


uint16_t LinkConfig::getMaxCacheSize() const
{
    return m_maxCacheSize;
}

void LinkConfig::startWatcher()
{
    m_fileWatcher.addPath(m_configFilePath);
}

void LinkConfig::stopWatcher()
{
    m_fileWatcher.removePath(m_configFilePath);
}

void LinkConfig::removeLinkConfigs(const QList<BaseConfig*> &lstConfig)
{
    for(auto config:lstConfig){
        delete  m_mapConfig.take(config->linkID);;
    }
}

void LinkConfig::removeLinkConfig(BaseConfig *config,const QString& ProtoName)
{
    if(!ProtoName.isEmpty()&&m_mapConfig[config->linkID]->lstProtoName.size()>1){
        m_mapConfig[config->linkID]->lstProtoName.removeOne(ProtoName);
        modifyFileLinkConfig(config->linkID);
        return;
    }
    m_mapConfig.remove(config->linkID);
    removeFileLinkConfig(config->linkID);
    delete config;
}

void LinkConfig::removeLinkConfig(const QString &strLinkID)
{
    if(m_mapConfig.contains(strLinkID)){
        delete m_mapConfig.take(strLinkID);
    }
}

void LinkConfig::removeFileLinkConfig(const QString &strLinkID)
{
    QFile loadFile(m_configFilePath);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return ;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray jsonArray = loadDoc.array();
    QJsonObject objTmp;
    int removePos = -1;
    for(int i =0 ;i<jsonArray.size();++i){
       objTmp = jsonArray.at(i).toObject();
       if(objTmp.value("linkId").toString() == strLinkID){
           removePos = i;
           break;
       }
    }
    if(removePos != -1){
        jsonArray.removeAt(removePos);
    }else{
        return;
    }
    loadDoc.setArray(jsonArray);
    QFile saveFile(m_configFilePath);
    if (!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Couldn't open save file.");
        return;
    }
    saveFile.write(loadDoc.toJson());
    saveFile.close();
}

void LinkConfig::modifyFileLinkConfig(const QString &strLinkID)
{
    QFile loadFile(m_configFilePath);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return ;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray jsonArray = loadDoc.array();
    QJsonObject objTmp;
    for(int i =0 ;i<jsonArray.size();++i){
       objTmp = jsonArray.at(i).toObject();
       if(objTmp.value("linkId").toString() == strLinkID){
           objTmp["protoName"] = orgnaizationProtoName( m_mapConfig[strLinkID]->lstProtoName);
           jsonArray[i]=objTmp;
       }
    }
    loadDoc.setArray(jsonArray);
    QFile saveFile(m_configFilePath);
    if (!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Couldn't open save file.");
        return;
    }
    saveFile.write(loadDoc.toJson());
    saveFile.close();
}

void LinkConfig::saveConfig(const BaseConfig *config)
{
    QFile loadFile(m_configFilePath);
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
        return ;
    }
    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonArray jsonArray = loadDoc.array();
    QJsonObject obj;
    obj.insert("bAutoLink",config->bAutoLink);
    obj.insert("bUpdate",config->bUpdate);
    obj.insert("localIP",config->localIP.toString());
    obj.insert("localPort",config->localPort);
    obj.insert("connectType",config->connectType);
    obj.insert("protoType",config->protoType);
    obj.insert("targetIP",config->targetIP.toString());
    obj.insert("targetPort",config->targetPort);
    obj.insert("protoName",orgnaizationProtoName(config->lstProtoName));
    obj.insert("boundRate",config->boundRate);
    obj.insert("linkId",config->linkID);
    obj.insert("linkFunction",config->linkFunction);
    obj.insert("serialPort",config->serialPort );
    obj.insert("linkName",config->linkName );
    //  obj.insert("linkStatus",config->linkStatus);
    //    QJsonArray jsArr;
    //    for(int i=0;i<m_lstConfig.size();++i){
    //        BaseConfig config = m_lstConfig.at(i);

    //        jsArr.append(obj);
    //    }
    jsonArray.append(obj);
    loadDoc.setArray(jsonArray);
    QFile saveFile(m_configFilePath);
    if (!saveFile.open(QIODevice::WriteOnly)){
        qWarning("Couldn't open save file.");
        return;
    }
    saveFile.write(loadDoc.toJson());
    saveFile.close();
}

BaseConfig::BaseConfig():
    linkID("-1"),
    linkName("name"),
    bUpdate(false),
    bAutoLink(false),
    connectType(LinkTypeError),
    protoType(),
    linkStatus(LinkStatusError),
    lstProtoName({"-"}),
    linkFunction(LinkFunctionError),
    linkInfo(""),
    localIP("127.0.0.1"),
    localPort(1),
    targetIP("127.0.0.1"),
    targetPort(0),
    //boundRate("0"),
    serialPort("-1"),
    pLink(nullptr)
{

}

BaseConfig::~BaseConfig()
{
    pLink->deleteLater();
}
