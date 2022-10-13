#include <iostream>
#include <cassert>
#include "polinom.h"
#include "E_S_polinomio.h"
using namespace std;
const int gradoMax=20;

polinomio leePolinomio()
{
    int grado;
    int coef;
    int i;

    polinomio p1(gradoMax);

    cout<<"Dame el grado del polinomio a crear:";
    cin>>grado;

    for(i = grado; i >= 0; i--)
    {
        cout<<"Sea el exponente "<<i<<", indica el coeficiente: ";
        cin>>coef;
        /**Sea el polinomio p1, le asignamos el coeficiente recibido al grado que corresponde*/
        p1.coeficiente(i,coef);
    }
    puts("");
    return p1;
}

void muestraPolinomio(polinomio p)
{
    cout<<"P(x) = ";

    for(int i = p.grado(); i >0; i--)
            cout<<p.coeficiente(i)<<"x^"<<i<<" + ";
    cout<<p.coeficiente(0)<<endl;

}
