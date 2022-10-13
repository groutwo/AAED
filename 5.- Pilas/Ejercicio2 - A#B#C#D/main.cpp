#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include "Pila.h"

using namespace std;

bool esPalindromodo(string);
bool esPalindromodoCompuesto(string);
int main()
{
    string cadena1 ("Ab&bA#Cde&edC#Fgh&hgF#Ijk&kjI");
    string cadena2 ("ase&ewa#as&sa");

    if(esPalindromodoCompuesto(cadena1))
        cout<<"La cadena1 si cumple la propiedad"<<endl;
    else
        cout<<"La cadena1 no cumple la propiedad"<<endl;

    /*system("pause");
    system("cls");*/
    cout<<"-----------------------------------------------------------------"<<endl;

    if(esPalindromodoCompuesto(cadena2))
        cout<<"La cadena2 si cumple la propiedad"<<endl;
    else
        cout<<"La cadena2 no cumple la propiedad"<<endl;
    return 0;
}

bool esPalindromodoCompuesto(string cadena)
{
    string cadAux="";
    //("Ab&bA#Cde&edC#Fgh&hgF#Ijk&kjI");

    for (unsigned i=0; i<cadena.size(); i++)
        if(cadena.at(i)=='#')
        {
            if(!esPalindromodo(cadAux))
                return false;
            cadAux="";
        }
        else
            cadAux+=cadena.at(i);
    if(!esPalindromodo(cadAux))
        return false;
    return true;
}


bool esPalindromodo(string cadena)
{
    if(!cadena.size()%2)
        return false;

    if(cadena.at(cadena.size()/2)!='&')
        return false;

    Pila<char> P;
    unsigned i=0;

    while(cadena.at(i)!='&')
    {
        P.push(cadena.at(i));
        i++;
    }

    i++;
    //muestraPila(P);

    while(i<cadena.size())
    {
        if(cadena.at(i)!=P.tope())
            return false;
        P.pop();
        i++;
    }

    if(P.vacia())
        return true;

    return false;
}
