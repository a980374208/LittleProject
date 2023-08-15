/********************************************************************************
** Form generated from reading UI file 'CreateNewLink.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWLINK_H
#define UI_CREATENEWLINK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateNewLink
{
public:
    QGroupBox *generalGroup;
    QLabel *label;
    QLineEdit *linkNameLine;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *linkTypeCom;
    QComboBox *linkFunCom;
    QListWidget *protoListW;
    QLabel *label_4;
    QLabel *conStausLab;
    QCheckBox *autoConcheck;
    QPushButton *cancleButton;
    QPushButton *okButton;
    QGroupBox *proSetGroup;
    QPushButton *closeButton;
    QLabel *label_5;

    void setupUi(QDialog *CreateNewLink)
    {
        if (CreateNewLink->objectName().isEmpty())
            CreateNewLink->setObjectName(QString::fromUtf8("CreateNewLink"));
        CreateNewLink->resize(741, 603);
        CreateNewLink->setStyleSheet(QString::fromUtf8("*{\n"
"  color:black;\n"
"   font-family:\"Microsoft YaHei\";\n"
"}\n"
"QLineEdit#linkNameLine\n"
"{\n"
"border:1px solid blue;\n"
"background: transparent\n"
"}\n"
"QRadioButton::indicator\n"
"{\n"
"width:28px;\n"
"height:28px;\n"
"}\n"
"QRadioButton::indicator::unchecked\n"
"{\n"
"background: transparent;\n"
"border:1px white;\n"
"\n"
"}\n"
"QRadioButton::indicator::checked\n"
"{\n"
"border-image: url(:/new/image/FastCombatImage/TeamConfigImage/multiSelect.png);\n"
"}\n"
"/*\350\256\276\347\275\256QListWidget\350\203\214\346\231\257\344\270\216item\346\240\267\345\274\217*/\n"
"QListWidget#protoListW\n"
"{\n"
"background-image: url(:/LinkMImage/listWBgk.png);\n"
"/*border-left:3px solid white;\n"
"border-bottom:3px solid white;*/\n"
"}\n"
"QListWidget::item\n"
"{\n"
"background: transparent;\n"
"}\n"
"QListWidget::item::hover\n"
"{\n"
"background-color: rgb(85, 85, 255);\n"
"}\n"
"QListWidget::item::selected\n"
"{\n"
"background-color: rgb(85, 170, 255);\n"
"}\n"
"/*\346\260\264\345\271\263\347\272\257\350\211"
                        "\262\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar:horizontal {/*\346\250\252\345\220\221\350\203\214\346\231\257\350\211\262*/\n"
"      border: 1px solid grey;\n"
"      background: transparent;\n"
"      height: 10px;\n"
"      margin: 0px 0px 0 0px;\n"
"  }\n"
"QScrollBar::handle:horizontal {/*\345\260\217\346\273\221\345\235\227\350\203\214\346\231\257\350\211\262*/\n"
"      background: rgb(85, 85, 255);\n"
"      min-width: 5px;\n"
"	border-radius:2px\n"
"}\n"
"/*\346\260\264\345\271\263\347\272\257\350\211\262\346\273\232\345\212\250\346\235\241*/\n"
" QScrollBar:vertical {/*\346\250\252\345\220\221\350\203\214\346\231\257\350\211\262*/\n"
"      border: 1px solid grey;\n"
"      background: transparent;\n"
"      height: 10px;\n"
"      margin: 0px 0px 0 0px;\n"
"  }\n"
"QScrollBar::handle:vertical {/*\345\260\217\346\273\221\345\235\227\350\203\214\346\231\257\350\211\262*/\n"
"      background: rgb(85, 85, 255);\n"
"      min-width: 5px;\n"
"}\n"
"/*\344\270\244\346\256\265\346\273\232\345\212"
                        "\250\346\235\241*/\n"
"QScrollBar::add-page,QScrollBar::sub-page{\n"
"   background: transparent;}\n"
"QScrollBar::add-line,QScrollBar::sub-line{\n"
"   background: transparent;}\n"
"\n"
"/*\344\270\213\346\213\211\346\241\206\350\203\214\346\231\257\350\211\262\351\200\211\346\213\251*/\n"
"QComboBox#linkTypeCom,#linkFunCom\n"
"{\n"
"background-color: rgb(85, 85, 255);\n"
"border:1px solid white;\n"
"border-radius:3px;\n"
"}\n"
"QComboBox#linkTypeCom QAbstractItemView\n"
"{\n"
"background-color: rgb(85, 170, 255);\n"
"selection-background-color:green;\n"
"\n"
"}\n"
"QComboBox#linkFunCom QAbstractItemView\n"
"{\n"
"background-color: rgb(85, 170, 255);\n"
"selection-background-color:green;\n"
"\n"
"}"));
        generalGroup = new QGroupBox(CreateNewLink);
        generalGroup->setObjectName(QString::fromUtf8("generalGroup"));
        generalGroup->setGeometry(QRect(20, 30, 681, 231));
        label = new QLabel(generalGroup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 40, 71, 21));
        linkNameLine = new QLineEdit(generalGroup);
        linkNameLine->setObjectName(QString::fromUtf8("linkNameLine"));
        linkNameLine->setGeometry(QRect(130, 40, 171, 21));
        label_2 = new QLabel(generalGroup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 80, 71, 21));
        label_3 = new QLabel(generalGroup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 130, 71, 21));
        linkTypeCom = new QComboBox(generalGroup);
        linkTypeCom->addItem(QString());
        linkTypeCom->addItem(QString());
        linkTypeCom->addItem(QString());
        linkTypeCom->addItem(QString());
        linkTypeCom->addItem(QString());
        linkTypeCom->setObjectName(QString::fromUtf8("linkTypeCom"));
        linkTypeCom->setGeometry(QRect(130, 80, 171, 22));
        linkFunCom = new QComboBox(generalGroup);
        linkFunCom->addItem(QString());
        linkFunCom->addItem(QString());
        linkFunCom->addItem(QString());
        linkFunCom->setObjectName(QString::fromUtf8("linkFunCom"));
        linkFunCom->setGeometry(QRect(130, 130, 171, 22));
        protoListW = new QListWidget(generalGroup);
        new QListWidgetItem(protoListW);
        new QListWidgetItem(protoListW);
        protoListW->setObjectName(QString::fromUtf8("protoListW"));
        protoListW->setGeometry(QRect(410, 30, 256, 192));
        protoListW->setLineWidth(0);
        protoListW->setAutoScrollMargin(0);
        label_4 = new QLabel(generalGroup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 170, 71, 21));
        conStausLab = new QLabel(generalGroup);
        conStausLab->setObjectName(QString::fromUtf8("conStausLab"));
        conStausLab->setGeometry(QRect(130, 170, 161, 21));
        autoConcheck = new QCheckBox(generalGroup);
        autoConcheck->setObjectName(QString::fromUtf8("autoConcheck"));
        autoConcheck->setGeometry(QRect(30, 200, 161, 18));
        autoConcheck->setChecked(true);
        cancleButton = new QPushButton(CreateNewLink);
        cancleButton->setObjectName(QString::fromUtf8("cancleButton"));
        cancleButton->setGeometry(QRect(610, 530, 90, 30));
        okButton = new QPushButton(CreateNewLink);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(490, 530, 90, 30));
        proSetGroup = new QGroupBox(CreateNewLink);
        proSetGroup->setObjectName(QString::fromUtf8("proSetGroup"));
        proSetGroup->setGeometry(QRect(20, 280, 700, 200));
        closeButton = new QPushButton(CreateNewLink);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(700, 10, 14, 14));
        closeButton->setMinimumSize(QSize(14, 14));
        closeButton->setMaximumSize(QSize(14, 14));
        label_5 = new QLabel(CreateNewLink);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 10, 91, 16));

        retranslateUi(CreateNewLink);

        QMetaObject::connectSlotsByName(CreateNewLink);
    } // setupUi

    void retranslateUi(QDialog *CreateNewLink)
    {
        CreateNewLink->setWindowTitle(QCoreApplication::translate("CreateNewLink", "Dialog", nullptr));
        generalGroup->setTitle(QCoreApplication::translate("CreateNewLink", "General", nullptr));
        label->setText(QCoreApplication::translate("CreateNewLink", "\350\277\236\346\216\245\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("CreateNewLink", "\350\277\236\346\216\245\347\261\273\345\236\213\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("CreateNewLink", "\350\277\236\346\216\245\345\212\237\350\203\275\357\274\232", nullptr));
        linkTypeCom->setItemText(0, QCoreApplication::translate("CreateNewLink", "Serial", nullptr));
        linkTypeCom->setItemText(1, QCoreApplication::translate("CreateNewLink", "TCP", nullptr));
        linkTypeCom->setItemText(2, QCoreApplication::translate("CreateNewLink", "UDP\347\273\204\346\222\255", nullptr));
        linkTypeCom->setItemText(3, QCoreApplication::translate("CreateNewLink", "UDP\345\215\225\346\222\255", nullptr));
        linkTypeCom->setItemText(4, QCoreApplication::translate("CreateNewLink", "UDP\345\271\277\346\222\255", nullptr));

        linkFunCom->setItemText(0, QCoreApplication::translate("CreateNewLink", "\344\273\205\347\224\250\344\272\216\345\217\221\351\200\201", nullptr));
        linkFunCom->setItemText(1, QCoreApplication::translate("CreateNewLink", "\344\273\205\347\224\250\344\272\216\346\216\245\346\224\266", nullptr));
        linkFunCom->setItemText(2, QCoreApplication::translate("CreateNewLink", "\345\215\263\345\217\221\351\200\201\345\217\210\346\216\245\345\217\227", nullptr));


        const bool __sortingEnabled = protoListW->isSortingEnabled();
        protoListW->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = protoListW->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("CreateNewLink", "Link1", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = protoListW->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("CreateNewLink", "Link2", nullptr));
        protoListW->setSortingEnabled(__sortingEnabled);

        label_4->setText(QCoreApplication::translate("CreateNewLink", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        conStausLab->setText(QCoreApplication::translate("CreateNewLink", "TextLabel", nullptr));
        autoConcheck->setText(QCoreApplication::translate("CreateNewLink", "\345\210\233\345\273\272\350\277\236\346\216\245\345\220\216\350\207\252\345\212\250\350\277\236\346\216\245", nullptr));
        cancleButton->setText(QCoreApplication::translate("CreateNewLink", "\345\217\226\346\266\210", nullptr));
        okButton->setText(QCoreApplication::translate("CreateNewLink", "\347\241\256\345\256\232", nullptr));
        proSetGroup->setTitle(QCoreApplication::translate("CreateNewLink", "\344\270\262\345\217\243-\344\273\205\347\224\250\344\272\216\345\217\221\351\200\201-\351\205\215\347\275\256", nullptr));
        closeButton->setText(QString());
        label_5->setText(QCoreApplication::translate("CreateNewLink", "createNewLink", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNewLink: public Ui_CreateNewLink {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWLINK_H
