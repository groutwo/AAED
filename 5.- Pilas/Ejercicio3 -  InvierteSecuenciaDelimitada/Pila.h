#ifndef _Pila_H_
#define _Pila_H_
#include <cassert>
using namespace std;
template <typename tElemento>
class Pila
{
public:
    explicit Pila(unsigned TamaMax); // ctor., requiere ctor. tElemento();
    Pila(const Pila& p); // ctor. de copia
    Pila& operator =(const Pila& p); // asignación entre pilas
    bool vacia() const;
    bool llena() const; // Requerida por la implementación
    const tElemento& tope() const;
    void pop();
    void push(const tElemento& x);
    ~Pila(); // destructor
    unsigned int tam()
    {
        return Lmax;
    }

private:
    tElemento *elementos; // vector de elementos
    int Lmax; // tamaño del vector
    int tope_; // posición del tope
};

//Implementación genérica vectorial pseudoestática
template <typename tElemento>
inline Pila<tElemento>::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    tope_(-1)
{}

template <typename tElemento>
Pila<tElemento>::Pila(const Pila<tElemento>& p) :
    elementos(new tElemento[p.Lmax]),
    Lmax(p.Lmax),
    tope_(p.tope_)
{
    for (int i = 0; i <= tope_; i++) // copiar el vector
        elementos[i] = p.elementos[i];
}

template <typename tElemento>
Pila<tElemento>& Pila<tElemento>::operator =(const Pila<tElemento>& p)
{
    if (this != &p)   // evitar autoasignación
    {
        // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != p.Lmax)
        {
            delete[] elementos;
            Lmax = p.Lmax;
            elementos = new tElemento[Lmax];
        }
        // Copiar el vector
        tope_ = p.tope_;
        for (int i = 0; i <= tope_; i++)
            elementos[i] = p.elementos[i];
    }
    return *this;
}

//Implementación genérica vectorial pseudoestática
template <typename tElemento>
inline bool Pila<tElemento>::vacia() const
{
    return (tope_ == -1);
}

template <typename tElemento>
inline bool Pila<tElemento>::llena() const
{
    return (tope_ > Lmax - 2);
}

template <typename tElemento>
inline const tElemento& Pila<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[tope_];
}

template <typename tElemento>
inline void Pila<tElemento>::pop()
{
    assert(!vacia());
    --tope_;
}

template <typename tElemento>
inline void Pila<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    ++tope_;
    elementos[tope_] = x;
}

template <typename tElemento>
inline Pila<tElemento>::~Pila()
{
    delete[] elementos;
}

template <typename T> void muestraPila(Pila <T> P1)
{
    while(!P1.vacia())
        std::cout<<P1.tope()<<" ", P1.pop();
    std::cout << std::endl;

}

template <typename T> Pila<T> invierte(Pila <T> P, int a,int b)
{
    Pila <T> Pf(P.tam());
    Pila <T> Paux(P.tam());

    //Buscamos a, almacenando los datos que vamos pasando en la pila final
    while(P.tope()!=a) Pf.push(P.tope()),P.pop();

    //Aqui ya hemos encontrado la primera aparicion de a en la pila, como queremos invertir la secuencia hasta b,
    //los almacenamos en una pila auxiliar
    while(P.tope()!=b) Paux.push(P.tope()),P.pop();
    Paux.push(P.tope()),P.pop();

    //El tope de Paux es b, y el ultimo elemento, el que se encuentra abajo del todo, es a, luego almacenamos los datos
    //de la pila auxiliar en el vector final
    while(!Paux.vacia()) Pf.push(Paux.tope()),Paux.pop();

    //Completamos el resto de elementos de la pila original
    while(!P.vacia()) Pf.push(P.tope()),P.pop();


    //Tenemos el resultado, pero con la pila invertida, luego invertimos la pila
    while(!Pf.vacia())P.push(Pf.tope()),Pf.pop();

    return P;
}
#endif
