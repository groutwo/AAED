#include <iostream>
#include <ctime>
#include "listaOrdenada.h"
using namespace std;

int main()
{
    srand(time(nullptr));
    int min=1,max=9;
    ListaOrdenada<int> lista;

    for(int i=0;i<10;++i)
    {
        int numero_a_introducir=min+rand()%(max-min+1);
        lista.insertar(numero_a_introducir,lista.buscar(i));
    }
    lista.mostrarLista();
    return 0;
}
