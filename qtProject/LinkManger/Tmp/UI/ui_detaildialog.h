/********************************************************************************
** Form generated from reading UI file 'detaildialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILDIALOG_H
#define UI_DETAILDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DetailDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *lab_ConnectInfo;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *check_AutoConn;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_Connect;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_Disconnect;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *ButtonClose;

    void setupUi(QDialog *DetailDialog)
    {
        if (DetailDialog->objectName().isEmpty())
            DetailDialog->setObjectName(QString::fromUtf8("DetailDialog"));
        DetailDialog->resize(400, 129);
        gridLayout = new QGridLayout(DetailDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 0, 0, -1);
        lab_ConnectInfo = new QLabel(DetailDialog);
        lab_ConnectInfo->setObjectName(QString::fromUtf8("lab_ConnectInfo"));

        gridLayout->addWidget(lab_ConnectInfo, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        check_AutoConn = new QCheckBox(DetailDialog);
        check_AutoConn->setObjectName(QString::fromUtf8("check_AutoConn"));

        horizontalLayout_2->addWidget(check_AutoConn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btn_Connect = new QPushButton(DetailDialog);
        btn_Connect->setObjectName(QString::fromUtf8("btn_Connect"));

        horizontalLayout_3->addWidget(btn_Connect);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btn_Disconnect = new QPushButton(DetailDialog);
        btn_Disconnect->setObjectName(QString::fromUtf8("btn_Disconnect"));

        horizontalLayout_3->addWidget(btn_Disconnect);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        label = new QLabel(DetailDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(40, 20));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        ButtonClose = new QPushButton(DetailDialog);
        ButtonClose->setObjectName(QString::fromUtf8("ButtonClose"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonClose->sizePolicy().hasHeightForWidth());
        ButtonClose->setSizePolicy(sizePolicy);
        ButtonClose->setMinimumSize(QSize(25, 25));
        ButtonClose->setMaximumSize(QSize(25, 25));

        gridLayout->addWidget(ButtonClose, 0, 4, 1, 1);


        retranslateUi(DetailDialog);

        QMetaObject::connectSlotsByName(DetailDialog);
    } // setupUi

    void retranslateUi(QDialog *DetailDialog)
    {
        DetailDialog->setWindowTitle(QCoreApplication::translate("DetailDialog", "Dialog", nullptr));
        lab_ConnectInfo->setText(QCoreApplication::translate("DetailDialog", "TextLabel", nullptr));
        check_AutoConn->setText(QCoreApplication::translate("DetailDialog", "\350\207\252\345\212\250\350\277\236\346\216\245", nullptr));
        btn_Connect->setText(QCoreApplication::translate("DetailDialog", "\350\277\236\346\216\245", nullptr));
        btn_Disconnect->setText(QCoreApplication::translate("DetailDialog", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("DetailDialog", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        ButtonClose->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DetailDialog: public Ui_DetailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILDIALOG_H
