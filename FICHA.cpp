/**
  *@file FICHA.h
  *@version 1.0
  *@date 02/05/2016
  *@autores Hermanos Tamos
  *@title Funciones nodos llamados fichas
  *@brief Funciones Elementales
  */
#include "FICHA.h"
/**
 * @brief constructor cuando la ficha es un número
 * @param number1 para dar este valor a number(dato mienbro)
 */
FICHA::FICHA(double number1)
{
    this -> number = number1;
    this -> operador = 0;
    this -> kind =1;
    this -> evaluado = false;
    this -> acumulate = number1;
}
/**
 * @brief Constructor cuando la ficha es un operador es decir cuando es char
 * @param operador1 para dar este valor a operador(dato miembro).
 */
FICHA::FICHA(char operador1)
{
    this -> operador = operador1;
    this -> kind =2;
    this ->evaluado = false;
    this -> acumulate =0;
}

FICHA::~FICHA()
{
    //dtor
}
/**
 * @breif Obtiene acumulate
 * @return Retorna el acumulate(dato mienbro)
 */
double  FICHA::getAcumula()
{
    return acumulate;
}
/**
 * @breif Obtiene es evaluado
 * @return Retorna un booleno que me dice si esta evaluado.
 */
bool FICHA :: isEvaluado()
{
    return evaluado;
}
/**
 * @breif Si la ficha fuese un numero entonces me devolveria ese valor.
 * @return Retorna un double que es number de la ficha.
 */
double FICHA:: getNumero()
{
    return number;
}
/**
 * @breif Si la ficha fuese tipo operador entonces me devolveria este valor.
 * @return Retorna el operador.
 */
char FICHA::getOperador()
{
    return operador;
}
/**
 * @breif  Se pregunta si la ficha  es operador o si es numero.
 * @return Retorna 1 si es numero y 2 si es operador.
 */
int FICHA:: getTipo()
{
    return kind;
}

/**
 * @breif Chanca en el valor acumulate el acumulado
 */
void FICHA::setAcumula(double acumulado)
{
    this->acumulate = acumulado;
}
/**
  @breif Chanca en el valor evaluado al evaluado
  */
void FICHA::setEvaluado(bool evaluado)
{
    this->evaluado = evaluado;
}


