#ifndef COLA_VEC_H
#define COLA_VEC_H
#include <cassert>

using namespace std;

template <typename tEle> class Cola
{
public:
    explicit Cola(size_t); // constructor, requiere ctor. T()
    Cola(const Cola<tEle>&); // ctor. de copia, requiere ctor. T()
    Cola<tEle>& operator =(const Cola<tEle>&); // asig. colas, req. T()
    bool vacia() const;
    bool llena() const; // Requerida por la implementaci�n
    const tEle& frente() const;
    void pop();
    void push(const tEle&);
    ~Cola(); // destructor
    unsigned int tam() { return Lmax; }


private:
    tEle *elementos; // vector de elementos
    int Lmax; // tama�o del vector
    int fin; // posici�n del �ltimo
};

template <typename tEle> inline Cola<tEle>::Cola(size_t TamaMax) :
    elementos(new tEle[TamaMax]), Lmax(TamaMax), fin(-1) {}

template <typename tEle> Cola<tEle>::Cola(const Cola<tEle>& C) :
    elementos(new tEle[C.Lmax]), Lmax(C.Lmax), fin(C.fin)
{ for (int i = 0; i <= fin; i++) elementos[i] = C.elementos[i]; }

template <typename tEle> Cola<tEle>& Cola<tEle>::operator =(const Cola<tEle>& C)
{   if (this != &C)   // evitar autoasignaci�n
    {   // Destruir el vector y crear uno nuevo si es necesario
        if (Lmax != C.Lmax)
        {   delete[] elementos;
            Lmax = C.Lmax;
            elementos = new tEle[Lmax];
        }
        // Copiar el vector
        fin = C.fin;
        for (int i = 0; i <= fin; i++)
            elementos[i] = C.elementos[i];
    }
    return *this;
}

template <typename tEle> inline bool Cola<tEle>::vacia() const
{ return (fin == -1); }

template <typename tEle> inline bool Cola<tEle>::llena() const
{ return (fin == Lmax - 1); }

template <typename tEle> inline const tEle& Cola<tEle>::frente() const
{ assert(!vacia()); return elementos[0]; }

template <typename tEle> void Cola<tEle>::pop()
{   assert(!vacia());
    for (int i = 0; i < fin; i++) elementos[i] = elementos[i+1];
    fin--;
}

template <typename tEle> inline void Cola<tEle>::push(const tEle& x)
{ assert(!llena()); fin++; elementos[fin] = x; }

template <typename tEle> inline Cola<tEle>::~Cola()
{ delete[] elementos; }

template <typename tEle> void muestraCola(Cola <tEle> C)
{ while(!C.vacia()) cout<<C.frente()<<" ", C.pop(); cout<<endl; }

#endif // COLA_VEC_H
