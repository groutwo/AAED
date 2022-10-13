#ifndef PILA_ENLA_H
#define PILA_ENLA_H
#include <cassert>
template <typename T> class Pila
{
public:
    Pila();
    Pila(const Pila<T>& P);
    Pila<T>& operator =(const Pila<T>& P);
    bool vacia() const;
    const T& tope() const;
    void pop();
    void push(const T& x);
    ~Pila();
    void copiar(const Pila<T>& P);
private:
    struct nodo
    {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0): elto(e), sig(p) {}
    };
    nodo* tope_;
};
template <typename T> inline Pila<T>::Pila() : tope_(0) {}

template <typename T> Pila<T>::Pila(const Pila<T>& P) : tope_(0)
{
    copiar(P);
}
template <typename T> Pila<T>& Pila<T>::operator =(const Pila<T>& P)
{
    if (this != &P)   // evitar autoasignaci�n
    {
        this->~Pila(); // vaciar la pila actual
        copiar(P);
    }
    return *this;
}
template <typename T> inline bool Pila<T>::vacia() const
{
    return (!tope_);
}
template <typename T> inline const T& Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}
template <typename T> inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    delete p;
}
template <typename T> inline void Pila<T>::push(const T& x)
{
    tope_ = new nodo(x, tope_);
}

template <typename T> Pila<T>::~Pila()
{
    nodo* p;
    while (tope_)
    {
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}

template <typename T> void Pila<T>::copiar(const Pila<T>& P)
{
    if (!P.vacia())
    {
        tope_ = new nodo(P.tope()); // copiar el primer elto
// Copiar el resto de elementos hasta el fondo de la pila.
        nodo* p = tope_; // recorre la pila destino
        nodo* q = P.tope_->sig; // 2� nodo, recorre la pila origen
        while (q)
        {
            p->sig = new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}

template <typename T> void muestraPila(Pila <T> P1)
{
   while(!P1.vacia())
        std::cout<<P1.tope()<<" ", P1.pop();
   std::cout << std::endl;
}
#endif // PILA_ENLA_H
