#include <cassert>
#include "polinom.h"

polinomio::polinomio(unsigned gradoMax):
    v(new double[gradoMax+1]),
    coef(gradoMax),grad(0)
{
    for(unsigned i=0; i<=coef; i++)
        v[i]=0.0;
}

polinomio::polinomio(const polinomio& pol):
    v(new double[pol.coef+1]), coef(pol.coef),grad(pol.grad)
{
    for(unsigned i=0; i<=coef; i++)
        v[i]=pol.v[i];
}

polinomio& polinomio::operator=(const polinomio&pol)
{
    if(this!=&pol)
    {
        if(coef!=pol.coef)
        {
            delete[]v;
            coef=pol.coef;
            v=new double[coef+1];
        }
        grad=pol.grad;
        for(unsigned i=0; i<=coef; i++)
            v[i]=pol.v[i];
    }
    return*this;
}

unsigned polinomio::grado()const
{
    return grad;
}

double polinomio::coeficiente(unsigned n)const
{
    return n>coef?0.0:v[n];
}

void polinomio::coeficiente(unsigned n,double c)
{
    assert(n<=coef);
    v[n]=c;
    if(c!=0.0&&n>grad)
        grad=n;
    else
        while(v[grad]==0.0 &&grad>(0))
            --grad;
}

polinomio::~polinomio()
{
    delete[]v;
}
