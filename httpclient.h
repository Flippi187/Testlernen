#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "ui_httpclient.h"

class httpclient : public QMainWindow, private Ui::httpclient
{
    Q_OBJECT

public:
    explicit httpclient(QWidget *parent = nullptr);
private slots:
    void on_g_absenden_clicked();
};

#endif // HTTPCLIENT_H
