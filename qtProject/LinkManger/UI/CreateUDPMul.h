#ifndef CREATEUDPMUL_H
#define CREATEUDPMUL_H

#include <QWidget>
#include <QLineEdit>
#include "linkconfig.h"

namespace Ui {
class CreateUDPMul;
}

class CreateUDPMul : public QWidget
{
    Q_OBJECT

public:
    explicit CreateUDPMul(QWidget *parent = nullptr);
    ~CreateUDPMul();

    void        setLocalEnable      (bool isEnable);
    void        setTargetEnable     (bool isEnable);
    void        setConfig        (const BaseConfig& config);
    void   getConfig        (BaseConfig* config);
private:
    void        _setLocalStyle   (bool isEnable);
    void        _setTargetStyle  (bool isEnable);
private:
    Ui::CreateUDPMul *ui;

};

#endif // CREATEUDPMUL_H
