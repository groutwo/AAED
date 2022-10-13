#include <iostream>
#include "polinom.h"
#include "E_S_polinomio.h"
#include "ARIT_polinomio.h"
using namespace std;

int main()
{

    cout<<"Sea el polinomio p1: "<<endl;
    polinomio p1 = leePolinomio();
    cout<<"Sea el polinomio p2: "<<endl;
    polinomio p2 = leePolinomio();

    cout<<"El primer polinomio es"<<endl;
    muestraPolinomio(p1);
    cout<<"El segundo polinomio es"<<endl;
    muestraPolinomio(p2);

    cout<<"La suma de los anteriores es: ";
    muestraPolinomio(p1+p2);

    cout<<"La resta de los anteriores es: ";
    muestraPolinomio(p1-p2);

    cout<<"El producto de los anteriores es: ";
    muestraPolinomio(p1*p2);

    cout<<"La derivada del primero es: ";
    muestraPolinomio(derivada(p1));
    cout<<"La derivada del segundo es: ";
    muestraPolinomio(derivada(p2));

    cout<<"Ejercicio 2: "<<endl;

    cout<<"Aplicando operadores con asignacion: "<<endl;
    cout<<"La suma es : ";
    p1+=p2;
    muestraPolinomio(p1);
    cout<<"La resta es: ";
    p1-=p2;
    muestraPolinomio(p1);
    cout<<"El producto es: ";
    p1*=p2;
    muestraPolinomio(p1);
    cout<<"La division es: ";
//    p1/=p2
    muestraPolinomio(p1);

    cout<<"Dame un numero distinto de 0: ";
    float n;
    cin>>n;
/*
    cout<<"La suma del numero con el primer polinomio es: ";
    muestraPolinomio(p1+n);

    cout<<"La resta del numero con el primer polinomio es: ";
    muestraPolinomio(p1-n);

    cout<<"El producto del numero con el primer polinomio es: ";
    muestraPolinomio(p1*n);

    cout<<"La division del numero con el primer polinomio es: ";
    muestraPolinomio(p1/n);
*/
    cout<<"El resultado de p1!=p2 es: ";
    cout<<(p1!=p2);

    cout<<"El resultado de p1<=p2 es: ";
    cout<<(p1<=p2);

    cout<<"El resultado de p1>p2 es: ";
    cout<<(p1>p2);

    cout<<"El resultado de p1>=p2 es: ";
    cout<<(p1>=p2);

    return 0;
}

