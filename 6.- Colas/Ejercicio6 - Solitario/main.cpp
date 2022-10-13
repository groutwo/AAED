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
    // Generar las 40 cartas de la baraja española.
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
        cout << "Montón de reyes:\n";
        while (!reyes.vacia())
        {
            cout << "\t" << reyes.frente() << endl;
            reyes.pop();
        }
        cout << endl;
    }
    while (!victoria);   // Parar al ganar una partida.
    cout << "¡Conseguido! Bien hecho.\n" << endl;
}



bool solitario(tCarta* baraja, tfig inicio, tMonton& reyes)
{
    // Elementos del juego:
    tMonton cv(5); // Cola vacía para 5 cartas
    tMonton Monton[10] = {cv,cv,cv,cv,cv,cv,cv,cv,cv,cv};
    // Número de cartas ya colocadas de cada figura.
    int cont[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // Repartir 4 cartas en cada montón
    for (int i = 0, f = AS; f <= REY; f++)
        for (int k = 0; k < 4; k++, i++)
            Monton[f].push(baraja[i]),
        // Contar las cartas ya colocadas en su montón.
            if (baraja[i].fig() == f)
                cont[f]++;
    // Jugar
    tfig figura = inicio;
    tCarta carta;
    // Parar si 4 reyes colocados o al colocar carta 4 de figura.
    while (cont[REY] < 4 && cont[figura] < 4)
    {
    // Extraer carta del montón correspondiente a figura.
    // ...
    // Si la carta extraída ya estaba en su montón, hay que colocarla al
    // final del mismo, pero no contarla, ya se ha contado al repartir.
        if (figura != carta.fig())   // c. extraída no estaba en su montón
            figura = carta.fig(), // figura de la carta extraída
            cont[figura]++; // contar carta que se coloca en su montón

    // Introducir carta extraída en el montón de su figura.
    // ...
    }
    reyes = Monton[REY]; // Devolver el montón de los reyes.
    return cont[REY] == 4; // TRUE (éxito), si colocados los 4 reyes.
}
