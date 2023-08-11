#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "linkmanager.h"
#include "UI/CreateNewLink.h"

namespace Ui {
class MainWindow;
}

class LinkTreeModel;
class TreeItemDelegate;
class AllLinkWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_newBtn_clicked();

    void on_delBtn_clicked();

    void on_closeButton_clicked();

private:
    Ui::MainWindow *ui;
    LinkManager* m_linkManger;
    CreateNewLink *m_newLinkWidget = nullptr;
    LinkTreeModel *m_pModel;
    TreeItemDelegate* m_pDelegate;
    AllLinkWidget* m_pAllLinkWidget;
};

#endif // MAINWINDOW_H
