#include <iostream>
#include <fstream>
#include "pila.h"
#include "E_S_ficheros.h"
using namespace std;

int main()
{
    string nombre_f = "fichero.txt"; // nombre del fichero de datos
    // Obtener nombre del fichero
    fstream f(nombre_f); // Abrir el fichero en modo lectura/escritura y
    // asociarlo al flujo f.
    Pila<int> P;
    Pila<int> Q;
    Pila<int> R;
    f >> P >> Q; // Extraer de f los números (pilas) P y Q
    // Calcular el resultado en la pila R

    f.close();

    muestraPila(P);
    muestraPila(Q);

    system("pause");
    R = sumaPilas(P,Q);

    cout<<"112e12e"<<endl;
    system("pause");
    muestraPila(R);

    f.open("fichero.txt",ios::app);
    f << R;
    f.close (); // Cerrar el fichero asociado a f
    cout<<"Fin"<<endl;
    return 0;
}
