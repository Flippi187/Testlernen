#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "ui_httpclient.h"
#include <QAbstractSocket>
#include <QTcpSocket>

class httpclient : public QMainWindow, private Ui::httpclient
{
    Q_OBJECT

public:
    explicit httpclient(QWidget *parent = nullptr);
private slots:
    void on_g_absenden_clicked();
    void tcp_connect();
    void tcp_receive();
private:
    QTcpSocket* m_socket = nullptr;
    const unsigned short m_port = 80;
    QString m_hostname;
};

#endif // HTTPCLIENT_H
