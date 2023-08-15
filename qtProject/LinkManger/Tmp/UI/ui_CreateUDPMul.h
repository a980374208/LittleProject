/********************************************************************************
** Form generated from reading UI file 'CreateUDPMul.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUDPMUL_H
#define UI_CREATEUDPMUL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateUDPMul
{
public:
    QLabel *localPortLab;
    QLineEdit *localIPLine;
    QLineEdit *tarIPLine;
    QLineEdit *tarPortLine;
    QLabel *tarIPLab;
    QLabel *tarPortLab;
    QLabel *localIPLab;
    QLineEdit *localPortLine;

    void setupUi(QWidget *CreateUDPMul)
    {
        if (CreateUDPMul->objectName().isEmpty())
            CreateUDPMul->setObjectName(QString::fromUtf8("CreateUDPMul"));
        CreateUDPMul->resize(600, 100);
        localPortLab = new QLabel(CreateUDPMul);
        localPortLab->setObjectName(QString::fromUtf8("localPortLab"));
        localPortLab->setGeometry(QRect(320, 20, 71, 21));
        localIPLine = new QLineEdit(CreateUDPMul);
        localIPLine->setObjectName(QString::fromUtf8("localIPLine"));
        localIPLine->setGeometry(QRect(110, 20, 171, 21));
        tarIPLine = new QLineEdit(CreateUDPMul);
        tarIPLine->setObjectName(QString::fromUtf8("tarIPLine"));
        tarIPLine->setGeometry(QRect(110, 60, 171, 21));
        tarPortLine = new QLineEdit(CreateUDPMul);
        tarPortLine->setObjectName(QString::fromUtf8("tarPortLine"));
        tarPortLine->setGeometry(QRect(420, 60, 171, 21));
        tarIPLab = new QLabel(CreateUDPMul);
        tarIPLab->setObjectName(QString::fromUtf8("tarIPLab"));
        tarIPLab->setGeometry(QRect(10, 60, 71, 21));
        tarPortLab = new QLabel(CreateUDPMul);
        tarPortLab->setObjectName(QString::fromUtf8("tarPortLab"));
        tarPortLab->setGeometry(QRect(320, 60, 71, 21));
        localIPLab = new QLabel(CreateUDPMul);
        localIPLab->setObjectName(QString::fromUtf8("localIPLab"));
        localIPLab->setGeometry(QRect(10, 20, 71, 21));
        localPortLine = new QLineEdit(CreateUDPMul);
        localPortLine->setObjectName(QString::fromUtf8("localPortLine"));
        localPortLine->setGeometry(QRect(420, 20, 171, 21));

        retranslateUi(CreateUDPMul);

        QMetaObject::connectSlotsByName(CreateUDPMul);
    } // setupUi

    void retranslateUi(QWidget *CreateUDPMul)
    {
        CreateUDPMul->setWindowTitle(QCoreApplication::translate("CreateUDPMul", "Form", nullptr));
        localPortLab->setText(QCoreApplication::translate("CreateUDPMul", "\346\234\254\345\234\260\347\253\257\345\217\243:", nullptr));
        tarIPLab->setText(QCoreApplication::translate("CreateUDPMul", "\347\233\256\346\240\207IP:", nullptr));
        tarPortLab->setText(QCoreApplication::translate("CreateUDPMul", "\347\233\256\346\240\207\347\253\257\345\217\243:", nullptr));
        localIPLab->setText(QCoreApplication::translate("CreateUDPMul", "\346\234\254\345\234\260IP:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateUDPMul: public Ui_CreateUDPMul {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUDPMUL_H
