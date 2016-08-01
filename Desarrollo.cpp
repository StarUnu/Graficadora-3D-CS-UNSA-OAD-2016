
#include "Desarrollo.h"
#include <math.h>
Desarrollo::Desarrollo()
{
}

Desarrollo::~Desarrollo()
{
    //dtor
}
//mejoraria con punteros ohh
//funcion para no repetir mucho codigo
//entrada un puntero de un vector de FICHA
//entrada sea un caracter o number por esto utilizo  polimorfismo de funciones
void push_Ficha(vector<FICHA> * arreglo, vauop vauop1)//vayop quiere decir que puede entrar un operando o una variable
{
    FICHA  imput_l(vauop1);
    (* arreglo).push_back(imput_l);
}

void push_Ficha(vector<FICHA> * arreglo,  pto_f1 number)
{
    FICHA  imput_l(number);
    (* arreglo).push_back(imput_l);
}
void print_array(matriz array_1)
{
    fj_int large=(array_1).size();//aca arreglar
    for(fj_int n=0;n<large;n++)
    {
        fj_int large_sub=(array_1[n]).size();
        for(fj_int m=0;m<large_sub;m++)
        {
            if((array_1[n][m]).getTipo()==1)
                cout<<"T1 "<<array_1[n][m].getNumero();
            else
                cout<<"T2 "<<array_1[n][m].getOperador();
        }
        cout<<endl;
    }
}

void eliminar(vector<FICHA> & Operandos,fj_char operador)
{
    for(fj_int i=0,j=0;j<Operandos.size();i++,j++)
    {
        if( (Operandos[i]).getOperador()== operador)
           {
              j+=1;
           }
        Operandos[i]=Operandos[j];
    }
    Operandos.pop_back();
}

void Canti_p(string numeros,matriz & posibles_arrays)
{
    int cont=0;
    vector<FICHA>list_Ficha;
    for(char x : numeros)
    {
        if(x=='(')
        {
         posibles_arrays.push_back(list_Ficha);
        }
    }
}

fj_int Desarrollo ::Traductor(matriz & completa,string numeros)
{
    fj_int aparte22;
    bandera juntos_parent=0;
    bandera parent=0;
    bandera menorque0=0;
    bandera comprueba_1p=1;
    fj_int num_array=0;//este numero sera aumentado para recorrer todos los
    //posibles subarreglos
    vector <FICHA> * ptro_arrefi ;
    vector<FICHA> Lista;
    matriz Posibles_A;
    ptro_arrefi=&Lista;
    Canti_p(numeros,Posibles_A);
    fj_int cont_p=0;
    if(numeros[numeros.size()-1]!= ')')
        numeros=numeros +',';
    else
        numeros=numeros +',';
    string copi_x =" ";
    regex e ("[[:d:]]");
    fj_int conteo=0;
for(char x:numeros){
    parent=0;
    copi_x= static_cast<ostringstream* >(&(ostringstream() << x)) ->str();
if(regex_match(copi_x,e)){
    result =result*10+(int(x)-48);
    number=number*10;
    cero=1;
   }
else{
 if(x=='.')
 { result2=result;
   result=0;number=1;
   bandera_fl=1;}
 else {
    if(x=='('  ){
        if(comprueba_1p)
        {
            comprueba_1p=0;
            aparte22=cont_p;
        }
        x =contpa;
        push_Ficha(ptro_arrefi,x);//añodo más para despues no me complique en la tabla hash
        ptro_arrefi =&Posibles_A[num_array];
        x= contpa;
        contpa=int(contpa) + 1;//estrategia vea bien
        num_array++;
        cont_p++;
    }
    if(x ==')'){
        cont_p-=1;
        parent=1;
        }
    if(bandera_fl ==1){
        result2 = result2 + (result /number);
        bandera_fl=0;
        if(menorque0==1)
        {   push_Ficha(ptro_arrefi,(result2)*(-1));//con esto digo que el idintificador seria un #01 y lo mismo para lo otro}
           menorque0=0;
        }
        else
            push_Ficha(ptro_arrefi,result2);
        if(parent!=1)
        push_Ficha(ptro_arrefi,x);
        result=0;
        number=1;cero=0;
    }
    else{
        if(result!=0 || cero == 1 ) {
            if(numeros[conteo]==')' && numeros[conteo+1]==')' )
                juntos_parent=1;
            if(menorque0==1)
              {push_Ficha(ptro_arrefi,(result)*(-1));//con esto digo que el idintificador seria un #01 y lo mismo para lo otro}
               menorque0=0;
              }
            else
                push_Ficha(ptro_arrefi,result);
            cero=0;
            result=0;
            }//ningun numeo debe ser igual a cero
        if(parent==0 & numeros[conteo]!='-')
         push_Ficha(ptro_arrefi,x);
        if(numeros[conteo]=='-')
            {menorque0=1;
            if(conteo!=0)
            push_Ficha(ptro_arrefi,'+');
            }
    }
    if(parent==1){//tambien puede haber un negativo
        completa.push_back(*ptro_arrefi);
        if(cont_p==aparte22)
        {
        comprueba_1p=1;
        ptro_arrefi=&Lista;
        cont_p=num_array;
        }
        else
        {  if (juntos_parent==1)
            {
                juntos_parent=0;
                ptro_arrefi=&Posibles_A[cont_p];
            }
            else
                ptro_arrefi=&Posibles_A[cont_p-1];
        }
       }
    }
       }
       conteo++;
     }
Lista.pop_back();//por que aumente en numeros una coma para que itere
completa.push_back(Lista);
fj_int tam_com = completa.size()-1;
return tam_com;
}

int jerarquia(vauop operando , vauop list_operandos [],fj_int cantidad)
{
    for(int i =0;i<cantidad ;i++)
    {
        if(operando == list_operandos[i])
            return i;
    }
}
pto_f1 suma(bool true_1 ,pto_f1 param ,pto_f1 param2)
{
    return param+param2;
}


pto_f1 multiplicar(bool true_1 ,pto_f1 param ,pto_f1 param2)
{
    return param*param2;
}

pto_f1 division(bool true_1 ,pto_f1 param ,pto_f1 param2)
{
    return param /param2;
}

pto_f1 potencia(bool true_1 ,pto_f1 param ,pto_f1 param2)
{
    return pow(param,param2);
}

pto_f1 restar(bool true_1,pto_f1 param ,pto_f1 param2)
{
    return (param-param2);
}

pto_f1 seno(bool true_1,pto_f1 param)
{
    return sin(param);
}

pto_f1 coseno(bool true_1,pto_f1 param)
{
    return cos(param);
}

bool es_operador(fj_char  prioridad [],char cmp)
{
    for(fj_int x=0;x<strlen(prioridad);x++)
    {
        if(prioridad[x]==cmp)
        {
          return false;//si hay
        }
    }
    return true;
}
pto_f1 Desarrollo ::Evaluador(fj_int posicion_c,matriz completa)
{//me falta hacer esto
    //matriz tabla_hash (10);
    vector <FICHA> Numeros;
    vector <FICHA> Operandos;
    fj_char prioridad [] ={'-','+','*','/','^'};
    fj_int lar_prio=5;
    bandera es_resta=0;
    fj_int subtamano=completa.size();
    fj_int eliminar_sin [100]={};
    fj_int cont_eliminar=0;
    bandera tenia_sin=0;
    //seria todos menos la ultima recuerda
    //despues tocar esto para manipularlo
    /////////uno especial para sin
    fj_int sub_subtamano=(completa[posicion_c]).size();
     for(fj_int cont1=0,cont2=1;cont1<sub_subtamano;cont1+=1,cont2+=1){
        if(completa[posicion_c][cont1].getOperador() =='s' &&
           completa[posicion_c][cont2].getOperador() =='i' &&
           completa[posicion_c][cont2+1].getOperador() =='n' )
        {
            for(fj_int cont3=0;cont3<subtamano;cont3++)
            {
                //cont2+2 este sera el siguiente letra que contendra todo el parentesis
                if(completa[posicion_c][cont2+2].getOperador()==completa[cont3][0].getOperador()
                    )
                {
                   fj_int kind=1;
                   pto_f1 resultado_Eva=sin(Evaluador(cont3,completa));

                   completa[posicion_c][cont1].push_numero(resultado_Eva);//esta parte del codigo es cuando hay parentesis
                   completa[posicion_c][cont1].push_Tipo(kind);
                   completa[posicion_c][cont1].push_Evaluado_false();
                   completa[posicion_c][cont2].push_Evaluado();
                   completa[posicion_c][cont2+1].push_Evaluado();
                   completa[posicion_c][cont2+2].push_Evaluado();
                   completa[posicion_c][cont1].push_Evaluado_false();
                   eliminar_sin[cont_eliminar]=cont2;
                   eliminar_sin[cont_eliminar+1]=cont2+1;
                   eliminar_sin[cont_eliminar+2]=cont2+2;
                   //return resultado_Eva;
                   cont_eliminar+=3;
                   cont1=cont1+4;
                   cont2=cont2+4;
                   tenia_sin=1;

                   break;
                }
            }

        }
     //////////////////////////////recursividad
        if( completa[posicion_c][cont1].getTipo()==completa[posicion_c][cont2].getTipo())
        {
            if(es_operador(prioridad,completa[posicion_c][cont2].getOperador()))
                {
                 for (fj_int j=0;j<subtamano;j++)
                  {
                    if(completa[posicion_c][cont2].getOperador() == completa[j][0].getOperador() )
                    {

                       fj_int kind=1;
                       completa[posicion_c][cont2].push_numero( Evaluador(j,completa) );//esta parte del codigo es cuando hay parentesis
                       completa[posicion_c][cont2].push_Tipo(kind);
                       break;}
                  }
                }
            else
            {

             for (fj_int j=0;j<subtamano;j++)
              {
                if(completa[posicion_c][cont1].getOperador() == completa[j][0].getOperador() )
                {
                   fj_int kind=1;
                   //pto_f1 evalua3=Evaluador(j,completa);
                   completa[posicion_c][cont1].push_numero( Evaluador(j,completa) );//esta parte del codigo es cuando hay parentesis
                   completa[posicion_c][cont1].push_Tipo(kind);
                   break;}
              }
            }
        }
     }

     if(tenia_sin)
     {
         //completa[posicion_c].erase(completa[posicion_c].begin()+3);
          for(fj_int j=cont_eliminar-1;j>-1;j--)
         {
            completa[posicion_c].erase(completa[posicion_c].begin()+eliminar_sin[j]);
         }
         tenia_sin=0;
     }

    //Separa en Numeros y Operandos
    sub_subtamano=completa[posicion_c].size();
    for(fj_int cont1=0,cont2=1;cont1<sub_subtamano;cont1+=1,cont2+=1)
    {
            if((completa[posicion_c][cont1]).getTipo()==1)//es un numero¿?
            {
                Numeros.push_back(completa[posicion_c][cont1]);
            }

            if ((completa[posicion_c][cont2]).getTipo() ==2 &&
                (completa[posicion_c][cont2]).isEvaluado()==0 )//es un char ?
            {
                Operandos.push_back(completa[posicion_c][cont2]);
                //despues_p=despues_p+str(completa[posicion_c][cont2]);
                fj_int sub_large=Operandos.size()-1;
                fj_int ultimo_op=jerarquia( (Operandos[sub_large].getOperador()),prioridad,lar_prio);
                for(fj_int j=0;j<sub_large;j++)
                {
                    fj_int elemento=jerarquia( (Operandos[j].getOperador()),prioridad,lar_prio);
                    if(elemento>ultimo_op)
                    {//Operandos.erase(Operandos.begin()+j);
                     Numeros.push_back(Operandos[j]);
                     eliminar(Operandos,Operandos[j].getOperador());
                    }
                }
            }
    }

    for(fj_int p=0;p<Operandos.size();p++)//desde el ultimo hasta el inicio lo copea de operadores
        {Numeros.push_back(Operandos[Operandos.size()-1-p]);
        }
    pto_f1 op_resultado=0;
    fj_int cantidad=0;
    for(auto m:Numeros)//contabiliza la cantidad de operadores
    {
        if(m.getTipo()==2)
           {    cantidad++;
           }
    }
    while(cantidad>0)
    {
        fj_int eliminar_a[100]={};
        fj_int cont5=0;
        for(fj_int cont=0,cont2=1,cont3=2;cont<Numeros.size();cont++,cont2++,cont3++)
        {
            if(Numeros[cont].getTipo()==1 && ~(Numeros[cont].isEvaluado()) && Numeros[cont2].getTipo()==1
              && ~(Numeros[cont2].isEvaluado()) && ~(Numeros[cont3].isEvaluado()) && Numeros[cont3].getTipo()==2)
            {
                if(Numeros[cont3].getOperador()=='+')
                op_resultado= suma(2==3,Numeros[cont].getNumero(),Numeros[cont2].getNumero());
                if(Numeros[cont3].getOperador()=='/')
                op_resultado=division(true,Numeros[cont].getNumero(),Numeros[cont2].getNumero());
                if(Numeros[cont3].getOperador()=='^')
                op_resultado=potencia(true,Numeros[cont].getNumero(),Numeros[cont2].getNumero());
                if(Numeros[cont3].getOperador()=='*')
                op_resultado=multiplicar(true,Numeros[cont].getNumero(),Numeros[cont2].getNumero());
                if(Numeros[cont3].getOperador()=='-')
                op_resultado=restar(true,Numeros[cont].getNumero(),Numeros[cont2].getNumero());

                FICHA objeto(op_resultado);
                Numeros[cont]=objeto;

                //eliminar_a[cont5]=cont;
                eliminar_a[cont5]=cont3;
                eliminar_a[cont5+1]=cont2;
                cont5+=2;
                Numeros[cont].push_Evaluado();
                Numeros[cont2].push_Evaluado();
                Numeros[cont3].push_Evaluado();
                cantidad=cantidad-1;
                if(cantidad==0)  break;
            }
            fj_int number;
        }
        cont5=cont5;
        fj_int menos=2;
       for(fj_int n=0,m=1;m<cont5;n+=2,m+=2)
        {
            if(cont5%2==0 && n>1)
            {
                eliminar_a[n]=eliminar_a[n]-menos;
                eliminar_a[m]=eliminar_a[m]-menos;
                menos+=2;
            }
            Numeros.erase(Numeros.begin()+ eliminar_a[n]);
            Numeros.erase(Numeros.begin()+ eliminar_a[m]);
        }
    }

    Operandos.~vector();
    return Numeros[0].getNumero();

}
