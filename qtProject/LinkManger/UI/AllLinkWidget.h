#ifndef ALLLINKWIDGET_H
#define ALLLINKWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QList>
#include <QDialog>

#include <Link/ilink.h>


namespace Ui {
class AllLinkWidget;
}

class AllLinkWidget : public QDialog
{
    Q_OBJECT

public:
     using AddProtocolLinkCallBack = std::function<void(const QList<int>&,const QString&)>;
     using DelLinksCallBack        = std::function<void(const QList<int>&)>;
    enum class ActionType
    {
        AddProtocolLink,
        DelLinks,
        UnknowType
    };
    explicit AllLinkWidget   (QWidget *parent = nullptr);
    void showAllLinkListWid  (QVector<ILink*> allLink);
    void setActionType       (ActionType type,const QString& protoVersion = "");
    ~AllLinkWidget();
private slots:
    void on_okBtn_clicked();

    void on_cancleBtn_clicked();

    void on_ButtonClose_clicked();

signals:
    void sig_delSuccess();
private:
    void    _initListWidget             ();
    void    _initListWidgetItem         (QListWidgetItem* item);
private:
    Ui::AllLinkWidget *ui;
//    ActionType mActionType;
    QString    mCurProtocol;
//    AddProtocolLinkCallBack mAddLinkFun;
//    DelLinksCallBack        mDelLinksCallBack;
};

#endif // ALLLINKWIDGET_H
