#include <iostream>
#include "Pila.h"
#include "Cola.h"
using namespace std;
template <typename tEle> void inicializa(Pila<tEle>&,Cola<tEle>&);
template <typename tEle> bool esIsomorfica(Pila<tEle>&,Cola<tEle>&);
int main()
{
    setlocale(LC_CTYPE, "Spanish");

    cout<<"Introduzca una longitud: ";
    int tam;
    cin>>tam;

    Pila<int> P(tam);
    Cola<int> C(tam);
    inicializa(P,C);

    cout<<"La pila es: ";
    muestraPila(P);
    cout<<"La cola es: ";
    muestraCola(C);

    if(esIsomorfica(P,C)) cout<<"La pila es isomórfica"<<endl;

    else cout<<"La pila no es isomórfica"<<endl;
}

template <typename tEle> void inicializa(Pila <tEle>& P, Cola<tEle>& C)
{
    int elemento;
    puts("");
    for(unsigned i=0; i<P.tam(); i++)
        cout<<"Introduzca elemento "<< i+1<<" de la pila:",
        cin>>elemento,
        P.push(elemento);
    puts("");
    for(unsigned i=0; i<C.tam(); i++)
        cout<<"Introduzca elemento "<< i+1<<" de la cola:",
        cin>>elemento,
        C.push(elemento);
}

template <typename tEle> bool esIsomorfica(Pila <tEle>& P, Cola<tEle>& C)
{
    cout<<"Quitamos el primer elemento de la pila, osea el "<< P.tope()<<endl;
    P.pop();
    int pos = 1;
    bool cumplePropiedad = true;
    while ( !P.vacia() && !C.vacia() && cumplePropiedad )
        if(P.tope() == C.frente())
        {
            cout<<"En la posicion "<<pos<<" de la cola, y por tanto, en la "<<(pos+1)<<" de la pila, ";
            cout<<"ambos elementos coinciden (es el numero "<<P.tope()<<" )"<<endl, system("pause");
            P.pop(), C.pop(),pos+=2;
            if(!P.vacia() && !C.vacia()) P.pop(),C.pop();
        }
        else
            cout<<"En la posicion "<<pos<<" de la cola, y por tanto, en la "<<(pos+1)<<" de la pila, ",
            cout<<"ambos elementos NO coinciden (el tope de la pila es "<<P.tope()<<" y el tope de la ",
            cout<<"cola es "<<C.frente()<<")"<<endl, cumplePropiedad = false;
    return cumplePropiedad;
}

