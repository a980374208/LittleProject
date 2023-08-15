/********************************************************************************
** Form generated from reading UI file 'AllLinkWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLLINKWIDGET_H
#define UI_ALLLINKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AllLinkWidget
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *ButtonClose;
    QListWidget *allLinkListW;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *cancleBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *AllLinkWidget)
    {
        if (AllLinkWidget->objectName().isEmpty())
            AllLinkWidget->setObjectName(QString::fromUtf8("AllLinkWidget"));
        AllLinkWidget->resize(470, 677);
        AllLinkWidget->setStyleSheet(QString::fromUtf8("*{\n"
"  color:white;\n"
"    font-family:\"Microsoft YaHei\";\n"
"}\n"
"QWidget#AllLinkWidget\n"
"{\n"
"background-image: url(:/LinkMImage/allLinkBG.png);\n"
"}\n"
"/*\350\256\276\347\275\256QListWidget\350\203\214\346\231\257\344\270\216item\346\240\267\345\274\217*/\n"
"QListWidget#allLinkListW\n"
"{\n"
"border-image: url(:/LinkMImage/listWBgk.png);\n"
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
"QPushButton#okBtn,#cancleBtn\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamConfigImage/btnMidDefault.png);\n"
"\n"
"}\n"
"QPushButton#cancleBtn :hover\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamConfigImage/btmMidHover.png);\n"
"\n"
"}\n"
"QPushButton#cancleBtn:pressed\n"
""
                        "{\n"
"background: transparent;\n"
"	border-image: url(:/new/image/FastCombatImage/TeamConfigImage/btnMidSelect.png);\n"
"}\n"
"QPushButton#okBtn :hover\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamConfigImage/btmMidHover.png);\n"
"}\n"
"QPushButton#okBtn:pressed\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamConfigImage/btnMidSelect.png);\n"
"}\n"
"\n"
"QPushButton#ButtonClose\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamChange/closeDefau.png);\n"
"}\n"
"QPushButton#ButtonClose :hover\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamChange/closeHover.png);\n"
"}\n"
"QPushButton#ButtonClose:pressed\n"
"{\n"
"background: transparent;\n"
"border-image: url(:/new/image/FastCombatImage/TeamChange/closePress.png);\n"
"}\n"
"/*\344\270\213\346\213\211\346\241\206\350\203\214\346\231\257\350\211\262\351\200\211\346\213\251*/\n"
"QComboBox#protoComBox\n"
""
                        "{\n"
"background-color: rgb(85, 85, 255);\n"
"border:1px solid white;\n"
"border-radius:3px;\n"
"}\n"
"QComboBox#protoComBox QAbstractItemView\n"
"{\n"
"background-color: rgb(85, 170, 255);\n"
"selection-background-color:green;\n"
"\n"
"}\n"
"/*\346\260\264\345\271\263\347\272\257\350\211\262\346\273\232\345\212\250\346\235\241*/\n"
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
"/*\345\236\202\347\233\264\347\272\257\350\211\262\346\273\232\345\212\250\346\235\241*/\n"
" QScrollBar:vertical {/*\346\250\252\345\220\221\350\203\214\346\231\257\350\211\262*/\n"
"      border: 1px solid grey;\n"
"      background: transparent;\n"
"   "
                        "   height: 10px;\n"
"      margin: 0px 0px 0 0px;\n"
"  }\n"
"QScrollBar::handle:vertical {/*\345\260\217\346\273\221\345\235\227\350\203\214\346\231\257\350\211\262*/\n"
"      background: rgb(85, 85, 255);\n"
"      min-width: 5px;\n"
"}\n"
"/*\344\270\244\346\256\265\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar::add-page,QScrollBar::sub-page{\n"
"   background: transparent;}\n"
"QScrollBar::add-line,QScrollBar::sub-line{\n"
"   background: transparent;}\n"
""));
        gridLayout = new QGridLayout(AllLinkWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(AllLinkWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        ButtonClose = new QPushButton(AllLinkWidget);
        ButtonClose->setObjectName(QString::fromUtf8("ButtonClose"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ButtonClose->sizePolicy().hasHeightForWidth());
        ButtonClose->setSizePolicy(sizePolicy);
        ButtonClose->setMinimumSize(QSize(25, 25));
        ButtonClose->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(ButtonClose);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        allLinkListW = new QListWidget(AllLinkWidget);
        allLinkListW->setObjectName(QString::fromUtf8("allLinkListW"));

        gridLayout->addWidget(allLinkListW, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okBtn = new QPushButton(AllLinkWidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMinimumSize(QSize(90, 30));

        horizontalLayout_2->addWidget(okBtn);

        horizontalSpacer_2 = new QSpacerItem(79, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        cancleBtn = new QPushButton(AllLinkWidget);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));
        cancleBtn->setMinimumSize(QSize(90, 30));

        horizontalLayout_2->addWidget(cancleBtn);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        retranslateUi(AllLinkWidget);

        QMetaObject::connectSlotsByName(AllLinkWidget);
    } // setupUi

    void retranslateUi(QWidget *AllLinkWidget)
    {
        AllLinkWidget->setWindowTitle(QCoreApplication::translate("AllLinkWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("AllLinkWidget", "\346\211\200\346\234\211\350\277\236\346\216\245", nullptr));
        ButtonClose->setText(QString());
        okBtn->setText(QCoreApplication::translate("AllLinkWidget", "\345\210\240\351\231\244\351\200\211\344\270\255", nullptr));
        cancleBtn->setText(QCoreApplication::translate("AllLinkWidget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AllLinkWidget: public Ui_AllLinkWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLLINKWIDGET_H
