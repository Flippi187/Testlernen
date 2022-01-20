#include "httpclient.h"
#include <QDebug>

httpclient::httpclient(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    m_socket = new QTcpSocket();

    connect(m_socket, &QTcpSocket::connected, this, &httpclient::tcp_connect);
    connect(m_socket, &QTcpSocket::readyRead, this, &httpclient::tcp_receive);
}

void httpclient::on_g_absenden_clicked()
{
   g_output->clear();

   QString serverAddress = g_address->text();
   m_socket->connectToHost(serverAddress, m_port);
   if(!m_socket->waitForConnected(5000))
   {
       g_output->setTextColor(QColor::fromRgb(255, 0, 0));
       g_output->setText("Connection timed out!");
       g_output->setTextColor(QColor::fromRgb(0, 0, 0));
       m_socket->disconnectFromHost();
   }
}

void httpclient::tcp_connect()
{
    m_socket->write(QString("GET / HTTP/1.1\r\nHost:" + m_hostname + "\r\n\r\n").toLocal8Bit());
}

void httpclient::tcp_receive()
{
    g_output->setText(m_socket->readAll());
    m_socket->disconnectFromHost();

}
