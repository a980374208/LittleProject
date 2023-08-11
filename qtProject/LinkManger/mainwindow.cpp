#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model\linktreemodel.h"
#include "Model\treeitemdelegate.h"

#include <QReadLocker>

#include <UI/AllLinkWidget.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pAllLinkWidget(nullptr)
{
    ui->setupUi(this);
    m_linkManger = LinkManager::instance();
    m_pModel = new LinkTreeModel;
    m_pDelegate = new TreeItemDelegate(ui->treeView);

    m_pModel->setModelData(LinkConfig::instance()->getMapConfig());

    ui->treeView->header()->setVisible(false);
    ui->treeView->setModel(m_pModel);
    ui->treeView->setItemDelegate(m_pDelegate);
    ui->treeView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeView->update();
}

MainWindow::~MainWindow()
{
    if(m_pAllLinkWidget){
        m_pAllLinkWidget->deleteLater();
    }
    delete ui;
}

void MainWindow::on_newBtn_clicked()
{
    if(!m_newLinkWidget){
        m_newLinkWidget = new CreateNewLink(this);
        m_newLinkWidget->show();
        connect(m_newLinkWidget,&CreateNewLink::destroyed,this,[&](){
            m_newLinkWidget = nullptr;
        });
        connect(m_newLinkWidget,&CreateNewLink::sig_updateModel,this,[&](){
            m_pModel->setModelData(LinkConfig::instance()->getMapConfig());
        });
    }else{
        m_newLinkWidget->show();
        m_newLinkWidget->raise();
        m_newLinkWidget->activateWindow();
    }
}

void MainWindow::on_delBtn_clicked()
{
    if(m_pAllLinkWidget){
        m_pAllLinkWidget->show();
        m_pAllLinkWidget->raise();
        m_pAllLinkWidget->activateWindow();
        return;
    }
    m_pAllLinkWidget = new  AllLinkWidget;
    connect(m_pAllLinkWidget,&AllLinkWidget::destroyed,this,[&](){
        m_pAllLinkWidget->deleteLater();
        m_pAllLinkWidget = nullptr;
    });
    connect(m_pAllLinkWidget,&AllLinkWidget::sig_delSuccess,this,[&](){
        m_pModel->setModelData(LinkConfig::instance()->getMapConfig());
    });
    m_pAllLinkWidget->showAllLinkListWid(LinkManager::instance()->getLstLink());
    m_pAllLinkWidget->show();
}

void MainWindow::on_closeButton_clicked()
{
    m_pDelegate->closeDetailDialog();
    this->close();
}
