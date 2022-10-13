#include "pruebas.h"

int main()
{
    listaCircular<int> lista;
    typename listaCircular<int>::posicion p = lista.inipos();
    lista.insertar(3,p);
    p=lista.inipos();

    cout<<"p->elto es "<<lista.elemento(p)<<endl;
    cout<<"p-sig es "<<lista.elemento(lista.siguiente(p))<<endl;
    cout<<"p-ant es "<<lista.elemento(lista.anterior(p))<<endl;

    p=lista.siguiente(p);A
    lista.insertar(5,p);

    cout<<"p->elto es "<<lista.elemento(p)<<endl;
    cout<<"p-sig es "<<lista.elemento(lista.siguiente(p))<<endl;
    cout<<"p-ant es "<<lista.elemento(lista.anterior(p))<<endl;

    p=lista.siguiente(p);A
    lista.insertar(7,p);

    cout<<"p->elto es "<<lista.elemento(p)<<endl;
    cout<<"p-sig es "<<lista.elemento(lista.siguiente(p))<<endl;
    cout<<"p-ant es "<<lista.elemento(lista.anterior(p))<<endl;

    p=lista.siguiente(p);A
    lista.insertar(9,p);

    cout<<"p->elto es "<<lista.elemento(p)<<endl;
    cout<<"p-sig es "<<lista.elemento(lista.siguiente(p))<<endl;
    cout<<"p-ant es "<<lista.elemento(lista.anterior(p))<<endl;
    /*inicializa(lista);
    muestraLista(lista);
    pruebas(lista);*/


    return 0;
}
