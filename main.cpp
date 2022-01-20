#include "httpclient.h"
#include <QApplication>

/*
    - Eingabefeld für URL/Adresse
    - OK-Button zum Absenden
    - Ausgabefeld für HTTP-Response
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    httpclient w;
    w.show();

    return a.exec();
}
