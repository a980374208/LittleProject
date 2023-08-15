/********************************************************************************
** Form generated from reading UI file 'CreateOtherLinks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEOTHERLINKS_H
#define UI_CREATEOTHERLINKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateOtherLinks
{
public:
    QLineEdit *localPortLine;
    QLabel *localIPLab;
    QLabel *localPortLab;
    QLabel *tarIPLab;
    QComboBox *localIPCom;
    QLabel *tarPortLab;
    QLineEdit *tarPortLine;
    QLineEdit *tarIPLine;

    void setupUi(QWidget *CreateOtherLinks)
    {
        if (CreateOtherLinks->objectName().isEmpty())
            CreateOtherLinks->setObjectName(QString::fromUtf8("CreateOtherLinks"));
        CreateOtherLinks->resize(600, 100);
        localPortLine = new QLineEdit(CreateOtherLinks);
        localPortLine->setObjectName(QString::fromUtf8("localPortLine"));
        localPortLine->setGeometry(QRect(420, 20, 171, 21));
        localIPLab = new QLabel(CreateOtherLinks);
        localIPLab->setObjectName(QString::fromUtf8("localIPLab"));
        localIPLab->setGeometry(QRect(10, 20, 71, 21));
        localPortLab = new QLabel(CreateOtherLinks);
        localPortLab->setObjectName(QString::fromUtf8("localPortLab"));
        localPortLab->setGeometry(QRect(320, 20, 71, 21));
        tarIPLab = new QLabel(CreateOtherLinks);
        tarIPLab->setObjectName(QString::fromUtf8("tarIPLab"));
        tarIPLab->setGeometry(QRect(10, 60, 71, 21));
        localIPCom = new QComboBox(CreateOtherLinks);
        localIPCom->setObjectName(QString::fromUtf8("localIPCom"));
        localIPCom->setGeometry(QRect(110, 20, 171, 22));
        tarPortLab = new QLabel(CreateOtherLinks);
        tarPortLab->setObjectName(QString::fromUtf8("tarPortLab"));
        tarPortLab->setGeometry(QRect(320, 60, 71, 21));
        tarPortLine = new QLineEdit(CreateOtherLinks);
        tarPortLine->setObjectName(QString::fromUtf8("tarPortLine"));
        tarPortLine->setGeometry(QRect(420, 60, 171, 21));
        tarIPLine = new QLineEdit(CreateOtherLinks);
        tarIPLine->setObjectName(QString::fromUtf8("tarIPLine"));
        tarIPLine->setGeometry(QRect(110, 60, 171, 21));

        retranslateUi(CreateOtherLinks);

        QMetaObject::connectSlotsByName(CreateOtherLinks);
    } // setupUi

    void retranslateUi(QWidget *CreateOtherLinks)
    {
        CreateOtherLinks->setWindowTitle(QCoreApplication::translate("CreateOtherLinks", "Form", nullptr));
        localIPLab->setText(QCoreApplication::translate("CreateOtherLinks", "\346\234\254\345\234\260IP:", nullptr));
        localPortLab->setText(QCoreApplication::translate("CreateOtherLinks", "\346\234\254\345\234\260\347\253\257\345\217\243:", nullptr));
        tarIPLab->setText(QCoreApplication::translate("CreateOtherLinks", "\347\233\256\346\240\207IP:", nullptr));
        tarPortLab->setText(QCoreApplication::translate("CreateOtherLinks", "\347\233\256\346\240\207\347\253\257\345\217\243:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateOtherLinks: public Ui_CreateOtherLinks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEOTHERLINKS_H
