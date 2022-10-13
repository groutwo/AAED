#ifndef ENTRADA_Y_SALIDA_DE_LISTAS
#define ENTRADA_Y_SALIDA_DE_LISTAS

#include <iostream>
#include <ctime>
#include "listaCircular.h"

using namespace std;

const int min_ = 0;
const int max_ = 20;

template <typename T> void inicializa(listaCircular<T>& lista)
{
    typename listaCircular<int>::posicion p = lista.inipos();

    srand(time(nullptr));
    int numero_aleatorio;
    for(int i = 0; i<5; ++i)
    {   numero_aleatorio =  min_ + rand() % (max_ - min_ + 1),
        cout<<"nAleat: "<<numero_aleatorio<<endl;
        lista.insertar(numero_aleatorio,p);
        p=lista.siguiente(p);
        //muestraLista(lista);
    }
}

template <typename T> void muestraLista(listaCircular<T>& lista)
{
    cout<<"muestra lista"<<endl;
    if(lista.siguiente(lista.inipos())==nullptr )
        cout<<"Lista vacia!"<<endl;
    else
    {
        typename listaCircular<int>::posicion p = lista.inipos();
        do{
            cout<<"Con i="<<lista.elemento(p);
            cout<<" Su anterior es " <<lista.elemento(lista.anterior(p))<<endl;
            cout<<" Su siguiente es "<<lista.elemento(lista.siguiente(p))<<endl;
            p = lista.siguiente(p);
        } while(lista.siguiente(p) != lista.siguiente(lista.inipos()));
    }
}
#endif // ENTRADA_Y_SALIDA_DE_LISTAS
