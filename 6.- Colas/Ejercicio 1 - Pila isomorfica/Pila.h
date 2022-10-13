#ifndef _Pila_H_
#define _Pila_H_
#include <cassert>
using namespace std;

template <typename tEle>
class Pila
{
public:
    explicit Pila(unsigned); // ctor., requiere ctor. tEle();
    Pila(const Pila&); // ctor. de copia
    Pila& operator =(const Pila&); // asignación entre pilas
    bool vacia() const;
    bool llena() const; // Requerida por la implementación
    const tEle& tope() const;
    void pop();
    void push(const tEle&);
    ~Pila(); // destructor
    unsigned int tam() { return Lmax; }

private:
    tEle *elementos; // vector de elementos
    int Lmax; // tamaño del vector
    int tope_; // posición del tope
};

//Implementación genérica vectorial pseudoestática
template <typename tEle> inline Pila<tEle>::Pila(unsigned TamaMax) :
    elementos(new tEle[TamaMax]), Lmax(TamaMax), tope_(-1) {}

template <typename tEle> Pila<tEle>::Pila(const Pila<tEle>& p) :
    elementos(new tEle[p.Lmax]), Lmax(p.Lmax),tope_(p.tope_)
{   for (int i = 0; i <= tope_; i++) elementos[i] = p.elementos[i]; }

template <typename tEle> Pila<tEle>& Pila<tEle>::operator =(const Pila<tEle>& p)
{   if (this != &p)   // evitar autoasignación
    {   // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != p.Lmax)
           delete[] elementos,
            Lmax = p.Lmax,
            elementos = new tEle[Lmax];
        // Copiar el vector
        tope_ = p.tope_;
        for (int i = 0; i <= tope_; i++) elementos[i] = p.elementos[i];
    }
    return *this;
}

//Implementación genérica vectorial pseudoestática
template <typename tEle> inline bool Pila<tEle>::vacia() const
{ return (tope_ == -1); }

template <typename tEle> inline bool Pila<tEle>::llena() const
{ return (tope_ > Lmax - 2); }

template <typename tEle> inline const tEle& Pila<tEle>::tope() const
{ assert(!vacia()); return elementos[tope_]; }

template <typename tEle> inline void Pila<tEle>::pop()
{ assert(!vacia()); --tope_; }

template <typename tEle> inline void Pila<tEle>::push(const tEle& x)
{ assert(!llena()); ++tope_; elementos[tope_] = x; }

template <typename tEle> inline Pila<tEle>::~Pila()
{ delete[] elementos; }

template <typename tEle> void muestraPila(Pila <tEle> P1)
{ while(!P1.vacia()) cout<<P1.tope()<<" ", P1.pop(); cout<<endl; }

#endif


