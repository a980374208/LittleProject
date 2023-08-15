/********************************************************************************
** Form generated from reading UI file 'CreateSerial.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESERIAL_H
#define UI_CREATESERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateSerial
{
public:
    QComboBox *serialCom;
    QLabel *localIPLab;
    QLabel *localPortLab;
    QComboBox *rateCom;

    void setupUi(QWidget *CreateSerial)
    {
        if (CreateSerial->objectName().isEmpty())
            CreateSerial->setObjectName(QString::fromUtf8("CreateSerial"));
        CreateSerial->resize(600, 100);
        CreateSerial->setStyleSheet(QString::fromUtf8("QComboBox#serialCom,#rateCom\n"
"{\n"
"background-color: rgb(85, 85, 255);\n"
"border:1px solid white;\n"
"border-radius:3px;\n"
"}\n"
"QComboBox#serialCom QAbstractItemView\n"
"{\n"
"background-color: rgb(85, 170, 255);\n"
"selection-background-color:green;\n"
"\n"
"}\n"
"QComboBox#rateCom QAbstractItemView\n"
"{\n"
"background-color: rgb(85, 170, 255);\n"
"selection-background-color:green;\n"
"\n"
"}"));
        serialCom = new QComboBox(CreateSerial);
        serialCom->setObjectName(QString::fromUtf8("serialCom"));
        serialCom->setGeometry(QRect(130, 30, 171, 22));
        localIPLab = new QLabel(CreateSerial);
        localIPLab->setObjectName(QString::fromUtf8("localIPLab"));
        localIPLab->setGeometry(QRect(30, 30, 71, 21));
        localPortLab = new QLabel(CreateSerial);
        localPortLab->setObjectName(QString::fromUtf8("localPortLab"));
        localPortLab->setGeometry(QRect(340, 30, 71, 21));
        rateCom = new QComboBox(CreateSerial);
        rateCom->addItem(QString());
        rateCom->addItem(QString());
        rateCom->addItem(QString());
        rateCom->addItem(QString());
        rateCom->addItem(QString());
        rateCom->addItem(QString());
        rateCom->addItem(QString());
        rateCom->setObjectName(QString::fromUtf8("rateCom"));
        rateCom->setGeometry(QRect(400, 30, 171, 22));

        retranslateUi(CreateSerial);

        QMetaObject::connectSlotsByName(CreateSerial);
    } // setupUi

    void retranslateUi(QWidget *CreateSerial)
    {
        CreateSerial->setWindowTitle(QCoreApplication::translate("CreateSerial", "Form", nullptr));
        localIPLab->setText(QCoreApplication::translate("CreateSerial", "COM\345\217\243\357\274\232", nullptr));
        localPortLab->setText(QCoreApplication::translate("CreateSerial", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        rateCom->setItemText(0, QCoreApplication::translate("CreateSerial", "1200", nullptr));
        rateCom->setItemText(1, QCoreApplication::translate("CreateSerial", "2400", nullptr));
        rateCom->setItemText(2, QCoreApplication::translate("CreateSerial", "9600", nullptr));
        rateCom->setItemText(3, QCoreApplication::translate("CreateSerial", "19200", nullptr));
        rateCom->setItemText(4, QCoreApplication::translate("CreateSerial", "38400", nullptr));
        rateCom->setItemText(5, QCoreApplication::translate("CreateSerial", "57600", nullptr));
        rateCom->setItemText(6, QCoreApplication::translate("CreateSerial", "115200", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CreateSerial: public Ui_CreateSerial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESERIAL_H
