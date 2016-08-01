#include "graficadora.h"
#include "ui_graficadora.h"

Graficadora::Graficadora(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graficadora)
{
    ui->setupUi(this);
    QAction *grafica, *elimina;
    grafica=new QAction("graficar",this);
    elimina=new QAction("eliminar",this);
    //connect(eliminar,SIGNAL(triggered()),this, SLOT(on_eliminar_clicked()));
    //connect(grafica, SIGNAL(triggered()), this, SLOT(on_graficar_clicked()));
    //ui->listaExpresiones->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->listaExpresiones->addAction(grafica);
    //ui->listaExpresiones->addAction(elimna);
}

Graficadora::~Graficadora()
{
    delete ui;
    matrizstl.~vector();
    surface.~QSurface();
}

void Graficadora::graficar()
{
    matrizstl.clear();
    //surface.deleteLater();
    //surface.setFlags(surface.flags() ^ Qt::FramelessWindowHint);
    QSurfaceDataArray *data = new QSurfaceDataArray;
    Generador_Ptos t(expresion.toStdString(),xMax, xMin, tamanio_celda);
    if(t.sp_resolver())
    {
        //pto_f1 zmin=0;
        t.Obtener_ptos(matrizstl, zmin, zmax);

        fj_int indice=0;
        for (pto_f1 i = 0 ; i < (xMax-xMin)/tamanio_celda; i+=tamanio_celda) {
            qDebug()<<i<<"  fila";
            QSurfaceDataRow *nuevafila = new QSurfaceDataRow(xMax-xMin);
            for (pto_f1 j = 0; j < (xMax-xMin)/tamanio_celda; j+=tamanio_celda) {
                (*nuevafila)[j].setPosition(QVector3D( matrizstl[indice][0],
                                matrizstl[indice][2],matrizstl[indice][1] ));
                qDebug()<<j<<"  columna "<<indice <<"  indice        " <<
                            matrizstl[indice][0]<<"   X "<<
                            matrizstl[indice][1]<<"   Y "<<
                            matrizstl[indice][2]<<"   Z ";
                indice++;

            }
            *data << nuevafila;
        }
        QSurface3DSeries *series = new QSurface3DSeries;
        series->dataProxy()->resetArray(data);
        surface.addSeries(series);
        surface.show();

        surface.setHeight(500);
        surface.setWidth(600);
        surface.axisX()->setRange(xMin-2,xMax+2);
        surface.axisY()->setRange(zmin,zmax);
        surface.axisZ()->setRange(xMin-2,xMax+2);
        //qDebug()<<zmin<<"  "<< zmax;
        surface.show();
    }
     //ap.exec();
}

void Graficadora::on_eliminar_clicked(){
    delete ui->listaExpresiones->currentItem();
}

void Graficadora::on_graficar_clicked(){
    if(ui->listaExpresiones->currentItem())
    {
    expresion=ui->listaExpresiones->currentItem()->text();
    graficar();
    }
    else{
        return;
    }

}

void Graficadora::on_add_clicked(){
    if(ui->expresion->text().isEmpty())
        return;
    QString expresiontexto;
    expresiontexto=ui->expresion->text();
    ui->listaExpresiones->addItem(expresiontexto);
}

void Graficadora::on_cerrarGrafica_clicked(){
    surface.close();
    surface.destroyed();
}

void Graficadora::on_expresion_returnPressed(){
    if(ui->expresion->text().isEmpty())
        return;
    QString expresiontexto;
    expresiontexto=ui->expresion->text();
    ui->listaExpresiones->addItem(expresiontexto);
}
