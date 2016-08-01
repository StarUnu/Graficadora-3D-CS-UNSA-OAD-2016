#ifndef GRAFICADORA_H
#define GRAFICADORA_H

#include <QWidget>
#include <QtDataVisualization>
#include "Generador_Ptos.h"
#include "DEFINI.h"
#include <qDebug>

using namespace QtDataVisualization;

namespace Ui {
class Graficadora;
}

class Graficadora : public QWidget
{
    Q_OBJECT


public:
    explicit Graficadora(QWidget *parent = 0);
    ~Graficadora();
    void graficar();

private slots:
    void on_graficar_clicked();

    void on_eliminar_clicked();

    void on_add_clicked();

    void on_cerrarGrafica_clicked();

    void on_expresion_returnPressed();

private:
    Ui::Graficadora *ui;

    QString expresion="";
    gInt xMin=-5;
    gInt xMax=5;
    pto_f1 zmin;
    pto_f1 zmax;
    //gInt yMin=0;
    //gInt yMax=0;
    pto_f1 tamanio_celda=1;
    matriz_float matrizstl;
    Q3DSurface surface;
};

#endif // GRAFICADORA_H
