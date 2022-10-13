#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Pila.h"
#include "Cola.h"
using namespace std;
int main()
{
    int tam,a,b,i;
    cout<<"Introduzca la longitud de la cola: ";
    cin>>tam;
    Cola<int> C(tam);//original
    for(int j=0;j<tam;j++){
        cout<<"Introduzca elemento "<< j+1<<" de la pila:";
        cin>>i;
        C.push(i);
    }
    cout<<"Introduce los elementos 'a' y 'b':";
    cin>>a;
    cin>>b;

    cout<<"La cola original es: "<<endl; muestraCola(C);

    C=invierte(C,a,b);

    cout<<"La cola invertida es: "<<endl; muestraCola(C);
}

