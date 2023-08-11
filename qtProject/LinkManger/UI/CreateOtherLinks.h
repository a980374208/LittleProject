#ifndef CREATEOTHERLINKS_H
#define CREATEOTHERLINKS_H

#include <QWidget>
#include "linkconfig.h"
namespace Ui {
class CreateOtherLinks;
}

class CreateOtherLinks : public QWidget
{
    Q_OBJECT

public:
    explicit CreateOtherLinks(QWidget *parent = nullptr);
    ~CreateOtherLinks();

    void        setLocalEnable      (bool isEnable);
    void        setTargetEnable     (bool isEnable);
    void        setConfig        (const BaseConfig& linkIpPort);
    void        getConfig        (BaseConfig *linkData);
private:
    void        _setLocalStyle      (bool isEnable);
    void        _setTargetStyle     (bool isEnable);
private:
    Ui::CreateOtherLinks *ui;
};

#endif // CREATEOTHERLINKS_H
