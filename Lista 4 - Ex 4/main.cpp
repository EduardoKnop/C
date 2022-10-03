#include <iostream>
#include "Complexo.h"

using namespace std;

int main()
{
    Complexo Valor1;

    cout << "*-* Realiza Operacoes Aritmeticas com Numeros Complexos *-*" << endl;
	Valor1.RecebeValores();
	Valor1.SelectOp();
    return 0;
}
