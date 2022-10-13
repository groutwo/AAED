#ifndef _RACIONAL_
#define _RACIONAL_
class racional
{
public:
    racional(long nu = 0, long de = 1);
    long num() const
    {
        return n;
    }
    long den() const
    {
        return d;
    }
// Operadores aritméticos externos
    friend racional operator +(const racional& r, const
                               racional& s);
    friend racional operator *(const racional& r, const
                               racional& s);
    friend racional operator -(const racional& r);
    friend racional inv(const racional& r);

    racional& operator+=(const racional&);
    racional& operator-=(const racional&);
    racional& operator*=(const racional&);
    racional& operator/=(const racional&);
private:
    long n, d;
    static long mcd(long, long);
    static long mcm(long, long);
};
// Operadores de comparación externos


const racional& operator+(const racional& r);
racional operator-(const racional& r1,const racional& r2);
racional operator/(const racional& r1,const racional& r2);

// Definiciones en línea
inline bool operator ==(const racional& r, const racional& s)
{
    return (r.num() == s.num()) && (r.den() == s.den());
}

inline bool operator <(const racional& r, const racional& s)
{
    return racional(r + -s).num() < 0;
}

inline bool operator !=(const racional& r, const racional& s)
{
    return !(r==s);
}

inline bool operator <=(const racional& r, const racional& s)
{
    return (r<s || r==s);
}

inline bool operator >(const racional& r, const racional& s)
{
    return (s<r);
}

inline bool operator >=(const racional& r, const racional& s)
{
    return !(r<s);
}

#endif // _RACIONAL_
