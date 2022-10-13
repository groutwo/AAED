#include <fstream>
#include <string>
#include "pila.h"
using namespace std;
fstream& operator >>(fstream& fe, Pila<int>& P);

fstream& operator <<(fstream& fs, Pila<int> P);

/**string nombre_f; // nombre del fichero de datos
// Obtener nombre del fichero
fstream f(nombre_f); // Abrir el fichero en modo lectura/escritura y
// asociarlo al flujo f.
Pila<int> P, Q, R;
f >> P >> Q; // Extraer de f los números (pilas) P y Q
// Calcular el resultado en la pila R
f << R; // Insertar en f el número (pila) R
f.close(); // Cerrar el fichero asociado a f*/

/*Para compilar el codigo anterior sin errores es necesario definir previamente la sobrecarga
de los operadores de extraccion e insercion de pilas en flujos de ficheros.*/

/// Apila en P los valores numericos de los digitos extraidos del flujo de entrada fe

fstream& operator >>(fstream& fe, Pila<int>& P)
{
    char cifra;
    while (fe.get( cifra ) && cifra != '\n') // leer caracteres hasta fin de linea
        P.push(cifra -= '0'); // convierte un digito en su valor numerico
    return fe;
}

// Inserta en el flujo de salida fs la pila P
fstream& operator <<(fstream& fs, Pila<int> P)
{
    while (!P.vacia())
    {
        fs << P.tope();
        P.pop();
    }
    fs << endl;
    return fs;
}
