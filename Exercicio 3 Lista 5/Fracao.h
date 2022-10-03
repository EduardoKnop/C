#ifndef FRACAO_H_INCLUDED
#define FRACAO_H_INCLUDED

#include <iostream>

class Fracao{
    private:
        int numerador, denominador;
    public:
        void IniciaFracao(int num, int den);
        void FracaoVazia();
        int Numerador();
        int Denominador();
        void operator +(int num);
        void operator -(int num);
        void operator *(int num);
        void operator /(int num);
        void operator ++();
        void operator --();
};

#endif // FRACAO_H_INCLUDED
