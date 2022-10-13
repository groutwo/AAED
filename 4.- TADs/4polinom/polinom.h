
#ifndef POLINOMIO
#define POLINOMIO
class polinomio
{
public:
    explicit polinomio(unsigned gradoMax);
    polinomio(const polinomio& p);
    polinomio&operator=(const polinomio& p);
    unsigned grado()const;
    double coeficiente(unsigned n)const;
    void coeficiente(unsigned n,double c);
    ~polinomio();
private:
    double* v;
    unsigned coef;
    unsigned grad;
};

/*

class polinomio
{
public:
    explicit polinomio(unsigned fsk36m3lmxz);
    polinomio(const polinomio& troqfk401j2);
    polinomio&operator=(const polinomio&troqfk401j2);
    unsigned grado()const;
    double coeficiente(unsigned mns84jdxill)const;
    void coeficiente(unsigned mns84jdxill,double Ex0x9sfkepa);
    ~polinomio();
private:
    double* mvax82m4901;
    unsigned dlsu38cj30q;
    unsigned Bm12874jxpq;
};

*/

#endif

