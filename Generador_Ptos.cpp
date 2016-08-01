#include "Generador_Ptos.h"

Generador_Ptos::Generador_Ptos(const string funcion, const pto_f1 max_num,const pto_f1 min_num, const pto_f1 num_avance)
{
    this -> funcion=funcion;
    this -> max_num=max_num;
    this -> min_num=min_num;
    this -> num_avance =num_avance;
}

Generador_Ptos::~Generador_Ptos()
{
    //dtor
}
string aumenta_ce(string funcion,fj_int large_funcion)
{
    string new_funcion="";//falta los casos que dan error
    ///////////cuando es (( al comienzo
    if(funcion[0]=='(' && funcion[1]=='(')
        new_funcion=new_funcion+'0'+'+';
    ///////////cuando es )) al comienzo
    if(funcion[large_funcion-2]==')' && funcion[large_funcion-1]==')')
        new_funcion=new_funcion+'0'+'+';
    //////////////cuando es sin
    if(funcion[0]=='s' && funcion[1]=='i' && funcion[2]=='n')
        new_funcion=new_funcion+'0'+'+';

    //////////////si es -2el primer elemento
    fj_int cont3=0;
    while(funcion[cont3]=='(')
        cont3++;
    if(funcion[cont3]=='-')
        new_funcion=new_funcion+'0';
    for(fj_int cont=0;cont<large_funcion;cont++)
    {
        if(funcion[cont]=='x' || funcion[cont]=='y')

            new_funcion=new_funcion+'0'+funcion[cont];
        else{
            if(funcion[cont]!=' ')
                new_funcion=new_funcion+funcion[cont];
        }
    }
    return new_funcion;
}

bool Generador_Ptos::sp_resolver()
{
    if(num_avance==0){
        return 0;
    }
    fj_int large_funcion=funcion.size();
    fj_char signos [5]={'-','+','*','/','^'};
    fj_int cantidad_s=5;
    ///////////////si en el comienzo hay al ultimo hay un signo
    for(fj_int j=0;j<cantidad_s;j++)
        if(funcion[large_funcion-1]==signos[j])
            return false;
    /////////////si hay dos signos seguidos
    fj_int canti_signos=0;
    fj_int num_signos_va=0;
    for(fj_int cont=0;cont<large_funcion;cont++)
    {
        num_signos_va=0;
        for(fj_int cont2=0;cont2<cantidad_s;cont2++)
        {
            if(signos[cont2]==funcion[cont])
                num_signos_va++;
        }

        for(fj_int cont2=0;cont2<cantidad_s;cont2++)
        {
            if(signos[cont2]==funcion[cont+1])
                num_signos_va++;
        }
        canti_signos++;
        if(num_signos_va==2)
            return false;
    }
    /////////////que las variables ingresadas sean x y y
    fj_int cantisinx_y=0;
    for(fj_int cont=0;cont<large_funcion;cont++)
    {
        if(funcion[cont]!='x' || funcion[cont]!='y')
            cantisinx_y++;
    }
    if(canti_signos!=cantisinx_y)
        return false;

    cout<<"Claro que si todo se puede resolver";

    ///////////si hay una x y y se le aumenta un 0
    this->funcion=aumenta_ce(funcion,large_funcion);
    return true;
}
void replace_strings(string & despejo_y,fj_char cmp_c,string remplaso,string & nuevo)
{
    for(int cont=0;cont<despejo_y.size();cont++)
    {
        if(despejo_y[cont] == cmp_c)
        {
            nuevo=nuevo +remplaso;
        }
        else
        {
         nuevo=nuevo+despejo_y[cont];
        }
    }
}

void Generador_Ptos :: Obtener_ptos(matriz_float & ptos_result, pto_f1 &zmin, pto_f1 &zmax)
{
    int x=0;
    vector <pto_f1> Pto;
    //fj_int large =list_puntos(max_num,min_num,po_numeros);
    bandera is_cero=0;
    //bandera is_cero2=0;
    cout<<"min_num"<<min_num<<"  max_num"<<max_num<<endl;
   // string cmpnum_avance=static_cast<ostringstream* >(&(ostringstream() <<(-1*num_avance)))->str();
    for(pto_f1 xmin=min_num; xmin<max_num;xmin+=num_avance)
    {
        /*if(is_cero2)
        {
            is_cero2=0;
            min_num=0.0;
        }*/
        string num_str1=static_cast<ostringstream* >(&(ostringstream() << xmin))->str();

        for(pto_f1 ymin=min_num; ymin<max_num; ymin+=num_avance)
        {
            Pto.clear();

            string num_str2=static_cast<ostringstream* >(&(ostringstream() << ymin))->str();
            fj_char carac='x';
            string nuevo="";
            replace_strings(funcion,carac,num_str1,nuevo);
            carac='y';
            string nuevo_f="";
            replace_strings(nuevo,carac,num_str2,nuevo_f);
            matriz completa1;
            completa1.clear();
            fj_int large = Traductor(completa1,nuevo_f);
            pto_f1 resu=Evaluador
                    (large,completa1);
            Pto.push_back(xmin);
            Pto.push_back(ymin);
            Pto.push_back(resu);
            ptos_result.push_back(Pto);
            if(xmin==min_num && ymin==min_num)
            {
                zmax=resu;
                zmin=resu;
            }
            if(resu>zmax)
               zmax=resu;
            if(resu<zmin)
               zmin=resu;

            cout<<"x"<<xmin<<"y"<<ymin<<"TP";
        }
        cout<<"total"<<min_num<<endl;
    }
    if(zmax==zmin){
        zmax=zmax+2;
        zmin=zmin-2;
    }

    for (auto primer :ptos_result)
    {
        for(auto segundo:primer)
        {
            cout<<segundo<<"|";
        }
        cout<<endl<<" ";
    }
    //aunque seria un desgasto por motivos de rapides es lo que voy a hacer
}
