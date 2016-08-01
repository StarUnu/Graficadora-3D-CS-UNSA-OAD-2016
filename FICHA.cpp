#include "FICHA.h"
/*FICHA :: FICHA()
{
 this-> number =1;
}*/
FICHA::FICHA(pto_f1 number1)
{
    this -> number = number1;
    this -> operador = 0;
    this -> kind =1;
    this -> evaluado = false;
}

FICHA::FICHA(vauop operador1)
{
    this -> operador = operador1;
    this -> kind =2;
    this ->evaluado = false;
}
FICHA::FICHA()
{
    this->kind=3;
}

FICHA::~FICHA()
{
    //dtor
}

bool FICHA :: isEvaluado()
{
    return evaluado;
}

pto_f1 FICHA:: getNumero()
{
    return number;
}

char FICHA::getOperador()
{
    return operador;
}

fj_int FICHA:: getTipo()
{
    return kind;
}

void FICHA :: push_Tipo(fj_int cmb)
{
    this -> kind=cmb;
}
void FICHA :: push_operador(vauop oper)
{
 operador=oper;
}
void FICHA :: push_numero(pto_f1 numero)
{
    number=numero;
}

void FICHA::push_Evaluado()
{
    this->evaluado = 1;
}
void FICHA::push_Evaluado_false()
{
    this->evaluado= 0;
}
//void FICHA :: catchNumero(){
  //  N
