#ifndef FICHA_H
#define FICHA_H


class FICHA
{
    public:
        FICHA(char operador1);
        FICHA(double number1);
        //las siguientes funciones son para obtener los
        //privados en esta clase
        double getAcumula();
        bool isEvaluado();
        double getNumero();
        double getOperador();
        int getTipo();
        //los set se chanca en sús respectivos variables
        void setAcumula(double acumulado);
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
