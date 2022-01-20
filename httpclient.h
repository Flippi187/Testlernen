#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include "ui_httpclient.h"

class httpclient : public QMainWindow, private Ui::httpclient
{
    Q_OBJECT

public:
    explicit httpclient(QWidget *parent = nullptr);
};

#endif // HTTPCLIENT_H
