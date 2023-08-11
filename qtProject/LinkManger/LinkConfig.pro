#-------------------------------------------------
#
# Project created by QtCreator 2023-06-13T16:03:47
#
#-------------------------------------------------

QT += core gui
QT += serialport network
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataAnalysisAndProcessing
TEMPLATE = app
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += c++11


MOC_DIR=$${PWD}\Tmp\MOC
UI_DIR=$${PWD}\Tmp\UI
OBJECTS_DIR=$${PWD}\Tmp\OBJ
RCC_DIR=$${PWD}\Tmp\RCC

SOURCES += \
        UI/AllLinkWidget.cpp \
        UI/detaildialog.cpp \
        UI\CreateNewLink.cpp \
        UI\CreateOtherLinks.cpp \
        UI\CreateSerial.cpp \
        UI\CreateUDPMul.cpp \
        Link\ilink.cpp \
        Link\broadcastudplink.cpp \
        Link\multicastudplink.cpp \
        Link\seriaportlink.cpp \
        Link\tcplink.cpp \
        Link\udplink.cpp \
        Model\linktreemodel.cpp \
        Model\treeitem.cpp \
        Model\treeitemdelegate.cpp \
        consumerproductthread.cpp \
        linkconfig.cpp \
        linkmanager.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        UI/AllLinkWidget.h \
        UI/detaildialog.h \
        UI\CreateNewLink.h \
        UI\CreateOtherLinks.h \
        UI\CreateSerial.h \
        UI\CreateUDPMul.h \
        Link\ilink.h \
        Link\broadcastudplink.h \
        Link\multicastudplink.h \
        Link\seriaportlink.h \
        Link\tcplink.h \
        Link\udplink.h \
        Model\linktreemodel.h \
        Model\treeitem.h \
        Model\treeitemdelegate.h \
        consumerproductthread.h \
        linkconfig.h \
        linkmanager.h \
        mainwindow.h

FORMS += \
        UI/AllLinkWidget.ui \
        UI/detaildialog.ui \
        UI\CreateNewLink.ui \
        UI\CreateOtherLinks.ui \
        UI\CreateSerial.ui \
        UI\CreateUDPMul.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

