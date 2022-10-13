#include <iostream>
#include <algorithm>

#include "carta.h"
#include "colacir.h"

using namespace std;
typedef Cola<tCarta> tMonton;

int main()
{
    tCarta baraja[40];
    tMonton reyes(5); // cola de hasta 5 cartas
    // Generar las 40 cartas de la baraja espa�ola.
    for (int i = 0, p = OROS; p <= BASTOS; p++)
        for (int f = AS; f <= REY; f++, i++)
            baraja[i] = tCarta(tpalo(p), tfig(f));
    srand(time(0));
    bool victoria = false;
    int partidas = 0;
    do
    {
        tfig montonI = tfig(rand() % 10); // Figura aleatoria
        random_shuffle(baraja, baraja+40); // Barajar las cartas
        victoria = solitario(baraja, montonI, reyes); // Jugar
        // Mostrar resultado
        cout << "Partidas jugadas = " << ++partidas << endl;
        cout << "Mont�n de reyes:\n";
        while (!reyes.vacia())
        {
            cout << "\t" << reyes.frente() << endl;
            reyes.pop();
        }
        cout << endl;
    }
    while (!victoria);   // Parar al ganar una partida.
    cout << "�Conseguido! Bien hecho.\n" << endl;
}



bool solitario(tCarta* baraja, tfig inicio, tMonton& reyes)
{
    // Elementos del juego:
    tMonton cv(5); // Cola vac�a para 5 cartas
    tMonton Monton[10] = {cv,cv,cv,cv,cv,cv,cv,cv,cv,cv};
    // N�mero de cartas ya colocadas de cada figura.
    int cont[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // Repartir 4 cartas en cada mont�n
    for (int i = 0, f = AS; f <= REY; f++)
        for (int k = 0; k < 4; k++, i++)
            Monton[f].push(baraja[i]),
        // Contar las cartas ya colocadas en su mont�n.
            if (baraja[i].fig() == f)
                cont[f]++;
    // Jugar
    tfig figura = inicio;
    tCarta carta;
    // Parar si 4 reyes colocados o al colocar carta 4 de figura.
    while (cont[REY] < 4 && cont[figura] < 4)
    {
    // Extraer carta del mont�n correspondiente a figura.
    // ...
    // Si la carta extra�da ya estaba en su mont�n, hay que colocarla al
    // final del mismo, pero no contarla, ya se ha contado al repartir.
        if (figura != carta.fig())   // c. extra�da no estaba en su mont�n
            figura = carta.fig(), // figura de la carta extra�da
            cont[figura]++; // contar carta que se coloca en su mont�n

    // Introducir carta extra�da en el mont�n de su figura.
    // ...
    }
    reyes = Monton[REY]; // Devolver el mont�n de los reyes.
    return cont[REY] == 4; // TRUE (�xito), si colocados los 4 reyes.
}
