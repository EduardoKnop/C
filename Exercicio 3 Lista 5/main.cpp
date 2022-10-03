#include <iostream>
#include "Fracao.h"

using namespace std;

int main()
{
    int num = 0;
    int den = 0;
    Fracao Valor1;

    cout << "Entre com o Numerador da Fracao: ";
    cin >> num;
    cout << "Entre com o Denominador da Fracao: ";
    cin >> den;

    Valor1.IniciaFracao(num, den);
    Valor1.FracaoVazia();
    ++Valor1;
    num = Valor1.Numerador();
    cout << num << "/" << den << endl;
    --Valor1;
    num = Valor1.Numerador();
    cout << num << "/" << den << endl;
}
