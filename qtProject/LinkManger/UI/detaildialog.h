#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include <QDialog>
#include "linkconfig.h"

namespace Ui {
class DetailDialog;
}

class DetailDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DetailDialog(QWidget *parent = nullptr);
    ~DetailDialog();

    void setConfig(BaseConfig* config);

    void init();

private:
    void setLightAndLinkStatus(LinkStatus status, const QString &extraDes);

private slots:
    void on_btn_Connect_clicked();

    void on_btn_Disconnect_clicked();

    void on_ButtonClose_clicked();

signals:
    void sig_ConnectTypeChanged();

private:
    Ui::DetailDialog *ui;
    BaseConfig* m_pConfig;
};

#endif // DETAILDIALOG_H
