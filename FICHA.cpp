#include "FICHA.h"

FICHA::FICHA(double number1)
{
    this -> number = number1;
    this -> operador = 0;
    this -> kind =1;
    this -> evaluado = false;
    this -> acumulate = number1;
}
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
double  FICHA::getAcumula()
{
    return acumulate;
}

bool FICHA :: isEvaluado()
{
    return evaluado;
}

double FICHA:: getNumero()
{
    return number;
}

double  FICHA::getOperador()
{
    return operador;
}

int FICHA:: getTipo()
{
    return kind;
}

void FICHA::setAcumula(double acumulado)
{
    this->acumulate = acumulado;
}

void FICHA::setEvaluado(bool evaluado)
{
    this->evaluado = evaluado;
}


