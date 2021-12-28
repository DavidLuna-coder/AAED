#ifndef _COLAPSEUDO_
#define _COLAPSEUDO_
#include <iostream>
#include <cassert>

template<typename T>
class Cola
{
public:
    Cola(unsigned TMax);
    Cola(const Cola& C);
    Cola& operator = (const Cola& C);
    bool vacia() const;
    bool llena() const;
    const T& frente() const;
    void pop();
    void push(const T& x);
    ~Cola();
private:
    unsigned LMax;
    T* elementos;
    unsigned inicio,fin;
};

template<typename T>
Cola<T>::Cola(unsigned TMax)
{
    elementos = new T[TMax + 1];
    LMax = TMax + 1;
    inicio = 0;
    fin = (TMax);
}

template<typename T>
Cola<T>::Cola(const Cola<T>& C):

    elementos (new T [C.LMax]),
    LMax (C.LMax),
    inicio (C.inicio),
    fin(C.fin)
{//Copiar elementos
    for (unsigned i = 0; i != ((fin + 1) % LMax); i = (i+1) % LMax)
    {
        elementos[i] = C.elementos[i];
    }
    
}

template<typename T>
Cola<T>& Cola<T>::operator=(const Cola<T>& C)
{
    if (this != &C)
    {
        if (LMax != C.LMax)
        {
            delete elementos;
            LMax = C.LMax;
            elementos = new T [LMax];
        }

        inicio = C.inicio;
        fin = C.fin;

        for (unsigned i = 0; i != (fin + 1) % LMax; i = (i + 1) % LMax)
        {
            elementos[i] = C.elementos[i];
        }
        
    }
    
    return *this;
}

template<typename T>
bool Cola<T>:: vacia() const
{
    return ((fin + 1) % LMax == inicio);
}

template<typename T>
bool Cola<T>::llena() const
{
    return ((fin + 2) % LMax == inicio);
}

template<typename T>
const T& Cola<T>::frente() const
{
    assert(!vacia());
    return (elementos[inicio]);
}

template<typename T>
void Cola<T>::pop()
{
    assert(!vacia());
    inicio = (inicio + 1) % LMax;
}

template<typename T>
void Cola<T>:: push(const T& x)
{
    assert (!llena());
    fin = (fin + 1) % LMax;
    elementos[fin] = x;
}

template<typename T>
Cola<T>::~Cola()
{
    delete elementos;
}

#endif