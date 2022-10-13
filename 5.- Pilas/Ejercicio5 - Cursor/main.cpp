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
        cout<<"L�nea de texto: ";
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
    cout << "\n\nElija una opci�n:" << endl;
    cout << "\t1.- Avanzar el cursor una posici�n" << endl;
    cout << "\t2.- Retrasar el cursor una posici�n" << endl;
    cout << "\t3.- Ir al final de la l�nea" << endl;
    cout << "\t4.- Ir al principio de la l�nea" << endl;
    cout << "\t5.- Borrar el car�cter de la posici�n del cursor" << endl;
    cout << "\t6.- Borrar el car�cter anterior al cursor" << endl;
    cout << "\t7.- Insertar un car�cter en la posici�n del cursor" << endl;
    cout << "\t8.- Sobreescribir el car�cter del cursor" << endl;
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
        cout << "Introduzca un car�cter: " << endl;
        cin >> aux;
        Pila1.push(aux);
        break;
    case 8:
        char aux2;
        cout << "Introduzca un car�cter: " << endl;
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
        cout<<"Opci�n inv�lida"<<endl;
    }
    system("cls");
}
