/**
  *@file FICHA.h
  *@version 1.0
  *@date 02/05/2016
  *@autores Hermanos Tamos
  *@title Funciones nodos llamados fichas
  *@brief Funciones Elementales
  */
#ifndef FICHA_H
#define FICHA_H

#include <iostream>
#include "DEFINI.h"

using namespace std;
class FICHA
{
    public:
/**
 * @brief Constructor cuando la ficha es un operador es decir cuando es char.
 * @param variyope para dar este valor al operador o a la variable.
 */
        FICHA(vauop variyope);

/**
 * @brief constructor cuando la ficha es un número
 * @param number1 para dar este valor a number(dato mienbro)
 */
        FICHA(pto_f1 number1);
        //las siguientes funciones son para obtener los
        //privados en esta clase
        FICHA();
/**
 * @brief Obtiene si ya esta evaluada la Ficha
 * @return Retorna evaluado(dato mienbro)
 */
      bool isEvaluado();
/** \brief Le chanca al valor de evaluado que por defecto es false a true
 */
    void push_Evaluado();
/**
 * @brief Si la ficha fuese un numero entonces me devolveria ese valor.
 * @return Retorna un double que es number de la ficha.
 */
        pto_f1 getNumero();
//	void catchNumero(double numero);

/**
 * @brief Si la ficha fuese tipo operador entonces me devolveria este valor.
 * @return Retorna el operador.
t */
        vauop getOperador();

/**
 * @brief  Se pregunta si la ficha  es operador o si es numero.
 * @return Retorna 1 si es numero y 2 si es operador.
 */
        fj_int getTipo();
        //los set se chanca en sús respectivos variables
/**
 * @brief  Cambia el Tipo de Ficha
 * @param  Resive un int
 */
        void push_Tipo(fj_int cmb);
/**
 * @brief Chanca en el valor operador.
 * @param Resive un char
 */
    void push_operador(vauop oper);
/**
  @brief Chanca en el valor number el numero recibido
  @param Es el valor nuevo para number
*/
    void push_numero(pto_f1 numero);
    void push_Evaluado_false();
    virtual ~FICHA();
    protected:
    private:
        fj_int kind;//clase
        fj_char operador;
        bandera evaluado;//si ya fue evaluado  o no
        pto_f1 number;
};

#endif // FICHA_H
