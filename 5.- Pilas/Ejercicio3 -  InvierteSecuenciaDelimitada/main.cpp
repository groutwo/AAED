#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Pila.h"

using namespace std;
int main()
{
    int tam,a,b,i;
    cout<<"Introduzca la longitud de la pila: ";
    cin>>tam;
    Pila<int> P(tam);//original
    for(int j=0;j<tam;j++){
        cout<<"Introduzca elemento "<< j+1<<" de la pila:";
        cin>>i;
        P.push(i);
    }
    cout<<"Introduce los elementos 'a' y 'b':";
    cin>>a;
    cin>>b;

    Pila <int> Paux(P.tam());
    while(!P.vacia())Paux.push(P.tope()),P.pop();

    P=Paux;
    muestraPila(P);
    P=invierte(P,a,b);
    muestraPila(P);
}

