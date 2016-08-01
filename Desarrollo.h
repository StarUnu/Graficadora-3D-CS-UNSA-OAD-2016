#ifndef DESARROLLO_H
#define DESARROLLO_H

#include <cmath>
#include <regex>
#include "FICHA.h"
#include <iostream>
#include <string>
#include "DEFINI.h"
#include <vector>
//no hay necesidad de herencia acá
typedef vector<vector<FICHA>> matriz;

class Desarrollo
{
    public:
/**
 * @brief Inicializa al dato mienbro de desarrollo numeros .con numeros
 */
        Desarrollo();
        virtual ~Desarrollo();
/**
 * @brief convierte todo el string en objetos de Ficha
 * @return El tamaño de mi vector que es la cadena de caracteres aumentando un #[a-z]*
 *         Ademas de una matriz de Ficha.Tal que subarrays de Fichas contendra lo que esta en los parentesis
 */
        fj_int Traductor(matriz & completa, string numeros);

/**matriz completa
 * @brief Separa la matriz obtenida en Traductor en un vector de Numeros y Operandos
 *        Lo resuelve la +,-,*,/,^ ,al resta solo lo suma por ejemplo:
 *        2-3-4 --> 2 + (-3) + (-4)
 * @param Acepta un int esto sera el indicador e que subvector esta en en la matriz de vectores
 *         Esto ayudara a crearse un  recursion
 * @return El resultado de la operacion que esta en punto flotante.
 */
        pto_f1 Evaluador(fj_int tamano,matriz completa);
    protected:
    private:
        //falta imprir lo que estoy guardstring numerosando...
        //acá falta dos declaraciones para hacer de acuerdo al algoritmo de mi hermamno recuerda
        // mi algoritmo noseria para todos los casos se tendria que incorparar más y más ..pero aun asi le he incluido algo
        // que me parece genial no lo voy hacer con rwcursividad sino con bucles
        vauop contpa='a';//el conteo de los parentesis
        bandera bandera_fl =0;
        bandera cero =0 ;
        pto_f1  result=0.0 ;
        pto_f1  result2=0;
        fj_int number=1;
};

#endif // DESARROLLO_H
