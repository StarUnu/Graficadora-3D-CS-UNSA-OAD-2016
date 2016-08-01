#ifndef GENERADOR_PTOS_H
#define GENERADOR_PTOS_H

#include "Desarrollo.h"
#include "DEFINI.h"
#include <string>
#include <vector>
using namespace std;
//typedef vector<vector<FICHA>> matriz;
typedef vector<vector<pto_f1>> matriz_float;
/** \brief Estoy heredando Desarrollo para aprovechar dos de sus
 *  funciones que son el Traductor y el Evaluador.
 */
class Generador_Ptos: public Desarrollo
{
    public:
        /** Inicializo los datos mienbros de la clase no inicializo de Desarrollo
         *  pues no tiene paramentro en su constructor y este es predeterminado.
         * \param La funcion que es fun.
         * \param  Desde que numero a otro numero genera los puntos (min_num,max_num)
         */
        Generador_Ptos(const string funcion,const pto_f1 max_num,
                       const pto_f1 min_num, const pto_f1 num_avance);
        virtual ~Generador_Ptos();
        /** \brief Mediante traductor y Evaluador de Desarrollo lo evalua para cada numero
         *          que lo coresponde.
         */
        void Obtener_ptos(matriz_float & ptos_result, pto_f1 &zmin, pto_f1 &zmax );

        /** \brief Verifca si esta de acuerdo a las reglas para ser resuelto
          *
          */
        bool sp_resolver();
    protected://recuerda

    private:
        pto_f1 max_num;
        pto_f1 min_num;
        pto_f1 num_avance;
        string funcion;//f(x,y)=x+y+5

};

#endif // GENERADOR_PTOS_H
