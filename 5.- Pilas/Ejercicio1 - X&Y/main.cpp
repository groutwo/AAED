#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Pila.h"
using namespace std;

bool esPalindromo(string);

int main()
{
    string cadena1 ("asqw&wqsa");
    string cadena2 ("asqw&wesa");

    cout<<"Tam cad1: "<<cadena1.size()<<endl;
    cout<<"Tam cad2: "<<cadena2.size()<<endl;

    /*system("pause");
    system("cls");*/
    if(esPalindromo(cadena1))
        cout<<"La cadena1 si cumple la propiedad"<<endl;
    else
        cout<<"La cadena1 no cumple la propiedad"<<endl;

    /*system("pause");
    system("cls");*/
    cout<<"-----------------------------------------------------------------"<<endl;

    if(esPalindromo(cadena2))
        cout<<"La cadena2 si cumple la propiedad"<<endl;
    else
        cout<<"La cadena2 no cumple la propiedad"<<endl;

    system("pause");
    system("cls");
}

bool esPalindromo(string cadena)
{
    cout<<"Tam cad: "<<cadena.size()<<endl;
    cout<<"El elemento del medio es: "<<cadena.at(cadena.size()/2)<<endl<<endl;
    if(!cadena.size()%2)
    {
        cout<<"Como \"cadena.size()%2\" = "<<cadena.size()%2<<endl;
        cout<<"El resultado es falso"<<endl;
        return false;
    }

    if(cadena.at(cadena.size()/2)!='&')
    {
        cout<<"Como \"cadena.at(cadena.size()/2)\" = "<<cadena.at(cadena.size()/2)<<"!=&"<<endl;
        cout<<"El resultado es falso"<<endl;
        return false;
    }

    Pila<char> P;
    unsigned i=0;
    while(cadena.at(i)!='&')
    {
        cout<<"Como cadena.at("<<i<<") = "<<cadena.at(i)<<
            " introducimos dicho valor en la pila"<<endl;
        P.push(cadena.at(i));
        i++;
    }
    i++;
    cout<<endl;
    cout<<"Luego tenemos que, la pila resultante es: "<<endl;
    muestraPila(P);
    while(i<cadena.size())
    {
        cout<<"Como cadena.at("<<i<<")= "<<cadena.at(i)<<endl;
        cout<<"Y P.tope()=        "<<P.tope()<<endl;
        if(cadena.at(i)!=P.tope())
        {
            cout<<"Al ser distintos, salimos con false"<<endl;
            return false;
        }
        cout<<"Al ser iguales, pasamos al siguiente elemento\n"<<endl;
        P.pop();
        i++;
    }
    if(P.vacia())
    {
        cout<<"Como la pila esta vacia, salimos con true"<<endl;
        return true;
    }
    cout<<"No deberia de llegar aqui"<<endl;
    return false;
}
