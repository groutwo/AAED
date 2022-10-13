#ifndef PilaEnlazada
#define PilaEnlazada
#include <cassert>
using namespace std;
template <typename tEle> class Pila
{
public:
    Pila();
    Pila(const Pila<tEle>&); // ctor. de copia
    Pila<tEle>& operator =(const Pila<tEle>&); // asignación entre pilas
    bool vacia() const;
    const tEle& tope() const;
    void pop();
    void push(const tEle& x);
    ~Pila(); // destructor
private:
    struct nodo
    {
        tEle elto;
        nodo* sig;
        nodo(const tEle& e,nodo* p=0):
            elto(e),sig(p){}
    };
    nodo* tope_;
    void copiar(const Pila<tEle>&);
};

template <typename tEle> inline Pila<tEle>::Pila():tope_(0){}

template <typename tEle>
Pila<tEle>::Pila(const Pila<tEle>& P) : tope_(0) { copiar(P); }

template <typename tEle>
Pila<tEle>& Pila<tEle>::operator =(const Pila<tEle>& P)
{if (this != &P) this->~Pila(), copiar(P); return *this; }

template <typename tEle>
inline bool Pila<tEle>::vacia() const { return (!tope_); }


template <typename tEle>
inline const tEle& Pila<tEle>::tope() const
{ assert(!vacia()); return tope_->elto; }

template <typename tEle>
inline void Pila<tEle>::pop()
{ assert(!vacia()); nodo* p = tope_; tope_ = p->sig; delete p; }

template <typename tEle>
inline void Pila<tEle>::push(const tEle& x)
{   tope_ = new nodo (x , tope_); }

template <typename tEle>
inline Pila<tEle>::~Pila()
{   nodo* p;
    while (tope_)
        p = tope_->sig, delete tope_, tope_ = p;
}

template <typename tEle>
void Pila<tEle>::copiar(const Pila<tEle>&P)
{
    assert(!P.vacia());
    tope_ = new nodo(P.tope()); /** Copiar el primer elemento */
    ///Copiar el resto de elementos hasta el fondo de la pila:

    nodo* p = tope_; //Recorre la pila desino
    nodo* q = P.tope_->sig;//2º nodo, recorre la pila origen

    while(q)
        p->sig = new nodo(q->elto), p=p->sig,q=q->sig;
}

template <typename T> void muestraPila(Pila <T> P1)
{ while(!P1.vacia())
        cout<<P1.tope()<<" ", P1.pop();
    cout<<endl;

}
#endif
