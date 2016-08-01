#include "graficadora.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graficadora w;

    //QObject::connect(w, SIGNAL(hablo(QString)),
    //                 w,SLOT(escucha(QString)));
    //w.graficar();

    w.show();

    return a.exec();
}
