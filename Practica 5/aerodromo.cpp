#include "ColaPseudo.hpp"
#include "ColaDinamica.hpp"
#include <iostream>
#include <cstring>

struct Avion
{
    unsigned Matricula;
    //Flags
    bool In,Out,Wait;

    Avion(unsigned M, bool I = false, bool O = true, bool W = false ) : Matricula(M),In(I),Out(O),Wait(W){}
};

int main()
{
    Cola<Avion> Aparcamiento(12);
    ColaD<Avion> Espera;
    return 0;
}


void Estacionar(Avion& A,Cola<Avion>& Aparcamiento,ColaD<Avion> Espera)
{
    if (A.In == false)
    {
        if (Aparcamiento.llena())
        {
            A.Wait = true;
            Espera.push(A);
        }
        else 
        {
            Aparcamiento.push(A);
            A.Out = false;
            A.In = true;
            A.Wait = false;
        }
    }   
}

void Sacar(Avion& A, Cola<Avion>& Aparcamiento, ColaD<Avion>& Espera)
{
    ColaD<Avion> Temporal;

    while (A.Matricula != Aparcamiento.frente().Matricula && !Aparcamiento.vacia())
    {
        Temporal.push(Aparcamiento.frente());
        Aparcamiento.pop();
    }
    if (!Aparcamiento.vacia())
    {
        Aparcamiento.pop();
        A.In = false;
        A.Out = true;
        A.Wait = false;
    }

    while (!Espera.vacia()&&!Aparcamiento.llena())
    {
        Aparcamiento.push(Espera.frente());
        Espera.frente().In = true;
        Espera.frente().Wait = false;
        Espera.pop();
    }
}