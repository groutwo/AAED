#include "E_S_Listas.h"

const int min_ = 0;
const int max_ = 20;

void inicializa(listaCircular<int>& lista)
{
    typename listaCircular<int>::posicion p = lista.inipos();

    srand(time(nullptr));
    int numero_aleatorio;
    for(int i = 0; i<5; ++i)
    {
        numero_aleatorio =  min_ + rand() % (max_ - min_ + 1),
        cout<<"nAleat: "<<numero_aleatorio<<endl;
        lista.insertar(numero_aleatorio,p);
        p=lista.siguiente(p);
        //muestraLista(lista);
    }
}

void muestraLista(listaCircular<int>& lista)
{
    cout<<"muestra lista"<<endl;
    if(lista.siguiente(lista.inipos())==nullptr )
        cout<<"Lista vacia!"<<endl;
    else
    {
        typename listaCircular<int>::posicion p = lista.inipos();
        do{
            cout<<"Con i="<<lista.elemento(p);system("pause");
            cout<<" Su anterior es " <<lista.elemento(lista.anterior(p))<<endl;system("pause");
            cout<<" Su siguiente es "<<lista.elemento(lista.siguiente(p))<<endl;
            p = lista.siguiente(p);
        } while(lista.siguiente(p) != lista.siguiente(lista.inipos()));
    }
}

/*void inicializa(ListaCirDobleSinCabecera<int>& lista)
{
    srand(time(nullptr));
    int numero_aleatorio;
    for(int i = 0; i<10; ++i)
        numero_aleatorio = min_ + rand() %(max_ - min_ + 1),
        lista.insertar(numero_aleatorio,lista.buscar(i));
}

void inicializa(ListaCirDobleConCabecera<int>& lista)
{
    srand(time(nullptr));
    int numero_aleatorio;
    for(int i = 0; i<10; ++i)
        numero_aleatorio = min_ + rand() %(max_ - min_ + 1),
        lista.insertar(numero_aleatorio,lista.buscar(i));
}

*/



/*
void muestraLista(ListaCirDobleSinCabecera<int>& lista)
{
    typename ListaCirDobleSinCabecera<int>::posicion p = lista.inipos();
    while(p->sig!=lista.inipos())
    {
        std::cout<<"Con i="<<lista.elemento(lista.buscar(p->elto))
                 <<" Su anterior es "<<lista.elemento(lista.anterior(lista.buscar(p->elto)))
                 <<" Su siguiente es "<<lista.elemento(lista.siguiente(lista.buscar(p->elto)))<<std::endl;
        p=p->sig;
    }
}

void muestraLista(ListaCirDobleConCabecera<int>& lista)
{
    typename ListaCirDobleConCabecera<int>::posicion p = lista.inipos();
    while(p->sig!=lista.inipos())
    {
        std::cout<<"Con i="<<lista.elemento(lista.buscar(p->elto))
                 <<" Su anterior es "<<lista.elemento(lista.anterior(lista.buscar(p->elto)))
                 <<" Su siguiente es "<<lista.elemento(lista.siguiente(lista.buscar(p->elto)))<<std::endl;
        p=p->sig;
    }
}
*/
