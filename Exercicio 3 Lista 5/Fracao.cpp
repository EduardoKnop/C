#include <iostream>
#include "Fracao.h"

using namespace std;

void Fracao::IniciaFracao(int num, int den){
    numerador = num;
    denominador = den;
}

void Fracao::FracaoVazia(){
    cout << "Entre com o Numerador da Fracao:";
    cin >> denominador;
    cout << "Entre com o Denominador da Fracao:";
    cin >> numerador;
}

int Fracao::Numerador(){
    return numerador;
}

int Fracao::Denominador(){
    return denominador;
}

void Fracao::operator++(){
    numerador = numerador + denominador;
}

void Fracao::operator--(){
    numerador = numerador - denominador;
}
