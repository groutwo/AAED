#include <iostream>
#include <cassert>
#include <algorithm>
#include "polinom.h"
#include "ARIT_polinomio.h"

polinomio operator + (polinomio p1, polinomio p2)
{
    int gradoMax= std::max(p1.grado(),p2.grado());
    polinomio p3 = polinomio(gradoMax);

    for(int i=0; i<=gradoMax; i++)
        p3.coeficiente(i,p1.coeficiente(i) + p2.coeficiente(i));

    return p3;
}

polinomio operator - (polinomio p1, polinomio p2)
{
    int gradoMax = std::max(p1.grado(),p2.grado());
    polinomio p3 = polinomio(gradoMax);

    for(int i=0; i<=gradoMax; i++)
        p3.coeficiente(i,p1.coeficiente(i) - p2.coeficiente(i));

    return p3;
}

polinomio operator * (polinomio p1, polinomio p2)
{
    polinomio p3 = polinomio(p1.grado()+p2.grado());

    for(unsigned i=0; i<=p1.grado(); i++)
        for(unsigned j=0; j<=p2.grado(); j++)
            p3.coeficiente(i+j,p3.coeficiente(i+j)+p1.coeficiente(i)*p2.coeficiente(j));

    return p3;
}

polinomio derivada(polinomio p1)
{
    polinomio p3(p1.grado()-1);
    for(unsigned i=0; i<p1.grado(); i++)
        p3.coeficiente(i,(i+1)*p1.coeficiente(i+1));
    return p3;
}

polinomio operator += (polinomio p1, polinomio p2)
{
    p1 = p1 + p2;

    return p1;
}

polinomio operator -= (polinomio p1, polinomio p2)
{
    p1 = p1 - p2;

    return p1;
}

polinomio operator *= (polinomio p1, polinomio p2)
{
    p1 = p1 * p2;

    return p1;
}

polinomio operator /= (polinomio p1, polinomio p2)
{
    polinomio p3 = polinomio(p1.grado()*p2.grado());

    for(unsigned i=0; i<=p1.grado(); i++)
        for(unsigned j=0; j<=p2.grado(); j++)
            p3.coeficiente(i-j,p3.coeficiente(i+j)+p1.coeficiente(i)/p2.coeficiente(j));

    p1 = p3;
    return p1;
}

polinomio operator + (polinomio p1)
{
    return p1;
}

polinomio operator - (polinomio p1)
{
    for(unsigned i =0; i<=p1.grado(); ++i)
        p1.coeficiente(i,-1*p1.coeficiente(i));
    return p1;
}

Polinomio::polinomio operator +(int n)
{
    for(int i=0; i<=this.grado(); i++)
        p1.coeficiente(i,p1.coeficiente(i) + n );
    return *this;
}

polinomio operator -(int n)
{
    for(int i=0; i<=this.grado(); i++)
        p1.coeficiente(i,p1.coeficiente(i) - n );
    return *this;
}

polinomio operator *(int n)
{
    for(int i=0; i<=this.grado(); i++)
        p1.coeficiente(i,p1.coeficiente(i) * n );
    return *this;
}

polinomio operator /(int n)
{
    for(int i=0; i<=this.grado(); i++)
        p1.coeficiente(i,p1.coeficiente(i) / n );
    return *this;
}

bool operator ==(polinomio p1, polinomio p2)
{
    if(p1.grado()!= p2.grado())
        return false;
    for(unsigned i=0; i<=p1.grado(); i++)
        if(p1.coeficiente(i)!=p2.coeficiente(i))
            return false;
    return true;
}

bool operator > (polinomio p1, polinomio p2)
{
    if(p1.grado()!=p2.grado())
        return p1.grado()>p2.grado();
    for(unsigned i=0; i<=p1.grado(); i++)
        if(p1.coeficiente(i)!=p2.coeficiente(i))
            return p1.coeficiente(i)>p2.coeficiente(i);
    return false;
}

bool operator !=(polinomio p1, polinomio p2)
{
    return !(p1==p2);
}

bool operator <=(polinomio p1, polinomio p2)
{
    return !(p1>p2);
}

bool operator >=(polinomio p1, polinomio p2)
{
    return (p1==p2) or (p1>p2);
}

bool operator <(polinomio p1, polinomio p2)
{
    return p2>p1;
}
