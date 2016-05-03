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

class FICHA
{
    public:
/**
 * @brief constructor cuando la ficha es un número
 * @param number1 para dar este valor a number(dato mienbro)
 */    
        FICHA(char operador1);
/**
 * @brief Constructor cuando la ficha es un operador es decir cuando es char
 * @param operador1 para dar este valor a operador(dato miembro).
 */
        FICHA(double number1);
        //las siguientes funciones son para obtener los
        //privados en esta clase
/**
 * @breif Obtiene acumulate
 * @return Retorna el acumulate(dato mienbro)
 */
        double getAcumula();
        
/**
 * @breif Obtiene es evaluado
 * @return Retorna un booleno que me dice si esta evaluado.
 */
        bool isEvaluado();
/**
 * @breif Si la ficha fuese un numero entonces me devolveria ese valor.
 * @return Retorna un double que es number de la ficha.
 */
        double getNumero();
/**
 * @breif Si la ficha fuese tipo operador entonces me devolveria este valor.
 * @return Retorna el operador.
 */
        double getOperador();
        
/**
 * @breif  Se pregunta si la ficha  es operador o si es numero.
 * @return Retorna 1 si es numero y 2 si es operador.
 */
        int getTipo();
        //los set se chanca en sús respectivos variables
/**
 * @breif Chanca en el valor acumulate el acumulado
 */
        void setAcumula(double acumulado);
/**
  @breif Chanca en el valor evaluado al evaluado
  */
        void setEvaluado(bool evaluado);
        virtual ~FICHA();
    protected:
    private:
        int kind;//clase
        char operador;
        bool evaluado;//si ya fue evaluado  o no
        double number;
        double acumulate; //acumulado
};

#endif // FICHA_H
