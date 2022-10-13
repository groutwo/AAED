#include <iostream>
#include "Bicola.h"
using namespace std;

Bicola<char> inicializaBicola();
void menu(void);
void funciones(int, Bicola<char>&);

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    Bicola<char> bicola = inicializaBicola();
    cout<<"Línea de texto: ";
    muestraBicola(bicola);
    int op;
    do
    {
        system("cls");
        cout<<"Sea el texto: ";
        muestraBicola(bicola);
        menu();
        cin>>op;
        funciones(op,bicola);
    }
    while(op!=7);
    return 0;
}

Bicola<char> inicializaBicola()
{
    Bicola<char> bicola;
    cout << "Introduzca un texto: ";
    string palabra;
    getline(cin,palabra);
    for(int i=0;palabra[i]!='\0';++i)
        bicola.pushCola(palabra[i]);

    system("pause"); system("cls");
    return bicola;
}

void menu()
{
    cout << "\n\nElija una opción:" << endl;
    cout << "\t1.- pop inicio" << endl;
    cout << "\t2.- pop fin" << endl;
    cout << "\t3.- push fin " << endl;
    cout << "\t4.- push inicio" << endl;
    cout << "\t5.- primerElemento" << endl;
    cout << "\t6.- ultimoElemento" << endl;
    cout << "\t7.- Salir." << endl;
}

void funciones(int op, Bicola<char>& bicola)
{
    switch(op)
    {
    case 1:
        bicola.popCola();
        break;
    case 2:
        bicola.popPila();
        break;
    case 3:
        cout << "Introduzca un carácter: " << endl;
        char elemento1;
        cin >> elemento1;
        bicola.pushCola(elemento1);
        break;
    case 4:
        cout << "Introduzca un carácter: " << endl;
        char elemento2;
        cin >> elemento2;
        bicola.pushPila(elemento2);
        break;
    case 5:
        cout<<"Elemento tope de la cola "<<bicola.topeCola();
        cout<<endl;system("pause");
        break;
    case 6:
        cout<<"Elemento tope de la pila "<<bicola.topePila();
        cout<<endl;system("pause");
        break;
    case 7:
        cout<<"Saliendo..."<<endl;
        break;
    default:
        cout<<"Opción inválida"<<endl;
    }
    system("cls");
}
