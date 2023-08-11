#ifndef CREATESERIAL_H
#define CREATESERIAL_H

#include <QWidget>
#include "linkconfig.h"
namespace Ui {
class CreateSerial;
}

class CreateSerial : public QWidget
{
    Q_OBJECT

public:
    explicit CreateSerial(QWidget *parent = nullptr);
    ~CreateSerial();
    void            setSerialEnable      (bool isEnable);
    void getSerialInf(BaseConfig   *config);

private:
    Ui::CreateSerial *ui;

};

#endif // CREATESERIAL_H
