#include <iostream>
#include "pila_dinamica.h"
#include "operaciones.h"
using namespace std;

Pila<char> inicializaPila();
void menu(void);
void funciones(int, Pila<char>&,Pila<char>&);

int main()
{
    setlocale(LC_CTYPE,"Spanish");

    Pila<char> P1 = inicializaPila();
    //inviertePila(P1);
    Pila<char> P2;

    int op;
    do
    {
        cout<<"Línea de texto: ";
        muestraPilas(P1,P2);
        menu();
        cin>>op;
        funciones(op,P1,P2);
    }
    while(op!=9);
    return 0;
}

Pila<char> inicializaPila()
{
    Pila<char> Pila1;
    int i=0;
    cout << "Introduzca un texto: ";
    string palabra;
    getline(cin,palabra);
    while(palabra[i] != '\0')
    {
        Pila1.push(palabra[i]);
        i++;
    }
    system("cls");
    return Pila1;
}

void menu()
{
    cout << "\n\nElija una opción:" << endl;
    cout << "\t1.- Avanzar el cursor una posición" << endl;
    cout << "\t2.- Retrasar el cursor una posición" << endl;
    cout << "\t3.- Ir al final de la línea" << endl;
    cout << "\t4.- Ir al principio de la línea" << endl;
    cout << "\t5.- Borrar el carácter de la posición del cursor" << endl;
    cout << "\t6.- Borrar el carácter anterior al cursor" << endl;
    cout << "\t7.- Insertar un carácter en la posición del cursor" << endl;
    cout << "\t8.- Sobreescribir el carácter del cursor" << endl;
    cout << "\t9.- Salir." << endl;
}


void funciones(int op, Pila<char>& Pila1,Pila<char>& Pila2)
{
    switch(op)
    {
    case 1:
        avanzar(Pila1,Pila2);
        break;
    case 2:
        retroceder(Pila1,Pila2);
        break;
    case 3:
        fin(Pila1,Pila2);
        break;
    case 4:
        principio(Pila1,Pila2);
        break;
    case 5:
        if(!Pila2.vacia())
            Pila2.pop();
        break;
    case 6:
        if(!Pila1.vacia())
            Pila1.pop();
        break;
    case 7:
        char aux;
        cout << "Introduzca un carácter: " << endl;
        cin >> aux;
        Pila1.push(aux);
        break;
    case 8:
        char aux2;
        cout << "Introduzca un carácter: " << endl;
        cin >> aux2;
        if(!Pila2.vacia())
            Pila2.pop();
        Pila2.push(aux2);
        retroceder(Pila1,Pila2); // con esta instruccion emula al boton "insert" del teclado.
        break;
    case 9:
        cout<<"Saliendo..."<<endl;
        break;
    default:
        cout<<"Opción inválida"<<endl;
    }
    system("cls");
}
