#include <iostream>
#include <math.h>
#include <locale.h>
#include "Complexo.h"
using namespace std;

void Complexo::RecebeValores(){
    float real, imaginario;
    bool teste = false;
    while (teste == false){
        cout << "\nInforme a Parcela Real do 1 Termo: ";
        cin >> real;
        cout << "Informe a Parcela Imaginaria do 1 Termo: ";
        cin >> imaginario;
        teste = TestaValores(real, imaginario);
        if (teste == true){
            real_1 = real;
            imagin_1 = imaginario;
            break;
        }
    }

    teste = false;
    while (teste == false){
        cout << "\nInforme a Parcela Real do 2 Termo: ";
        cin >> real;
        cout << "Informe a Parcela Imaginaria do 2 Termo: ";
        cin >> imaginario;
        teste = TestaValores(real, imaginario);
        if (teste == true){
            real_2 = real;
            imagin_2 = imaginario;
        }
    }
}

bool Complexo::TestaValores(float real, float imaginario){
    if (imaginario == 0){
        cout << "\nO Numero informado nao possui Parcela Imaginaria! Informe outro com valor Imaginario nao nulo." << endl;
        return false;
    }

    return true;
}

void Complexo::SelectOp(){
    while(op != 99){
        cout << "\nSelecionar Operacao:\n\t[1] para Soma\n\t[2] para Subtracao\n\t[3] para Multiplicacao\n\t"
        << "[4] para Divisao\n\t[5] para Informar outros Valores\n\t[99] para Sair" << endl;
        cin >> op;
        switch(op){
            case 1:
                cout << "\nOperacao Selecionada: SOMA" << endl;
                Soma();
                break;
            case 2:
                cout << "\nOperacao Selecionada: SUBTRACAO" << endl;
                Subtracao();
                break;
            case 3:
                cout << "\nOperacao Selecionada: MULTIPLICACAO" << endl;
                Multiplicacao();
                break;
            case 4:
                cout << "\nOperacao Selecionada: DIVISAO" << endl;
                Divisao();
                break;
            case 5:
                cout << "\nOperacao Selecionada: INFORMAR OUTROS VALORES" << endl;
                RecebeValores();
                break;
        }
    }
}

void Complexo::Soma(){
    setlocale(LC_ALL,"");
    cout << "(" << real_1;
    if(imagin_1 > 0)
        cout << " + " << imagin_1 << "i) + (" << real_2;
    else
        cout << " - " << 0 - imagin_1 << "i) + (" << real_2;
    if(imagin_2 > 0)
        cout << " + " << imagin_2 << "i)\n";
    else
        cout << " - " << 0 - imagin_2 << "i)\n";

    cout << "Resultado na Forma Retangular: ";
    if(imagin_1 + imagin_2 >= 0)
        cout << "(" << real_1 + real_2 << " + " << imagin_1 + imagin_2 << "i)" << endl;
    else
        cout << "(" << real_1 + real_2 << " - " << 0 - (imagin_1 + imagin_2) << "i)" << endl;

    cout << "Resultado na Forma Polar: ";
    cout << sqrt(pow(real_1 + real_2, 2) + pow(imagin_1 + imagin_2, 2))
    << " (cos(" << atan((real_1 + real_2)/(imagin_1 + imagin_2)) * 57.29577951308
    << "°) + sen(" << atan((real_1 + real_2)/(imagin_1 + imagin_2)) * 57.29577951308
    << "°)i)" << endl;
}

void Complexo::Subtracao(){
    setlocale(LC_ALL,"");
    cout << "(" << real_1;
    if(imagin_1 > 0)
        cout << " + " << imagin_1 << "i) - (" << real_2;
    else
        cout << " - " << 0 - imagin_1 << "i) - (" << real_2;
    if(imagin_2 > 0)
        cout << " + " << imagin_2 << "i)\n";
    else
        cout << " - " << 0 - imagin_2 << "i)\n";

    cout << "Resultado na Forma Retangular: ";
    if(imagin_1 - imagin_2 >= 0)
        cout << "(" << real_1 - real_2 << " + " << imagin_1 - imagin_2 << "i)" << endl;
    else
        cout << "(" << real_1 - real_2 << " - " << 0 - (imagin_1 - imagin_2) << "i)" << endl;

    cout << "Resultado na Forma Polar: ";
    cout << sqrt(pow(real_1 - real_2, 2) + pow(imagin_1 - imagin_2, 2))
    << " (cos(" << atan((real_1 - real_2)/(imagin_1 - imagin_2)) * 57.29577951308
    << "°) + sen(" << atan((real_1 - real_2)/(imagin_1 - imagin_2)) * 57.29577951308
    << "°)i)" << endl;
}

void Complexo::Multiplicacao(){
    setlocale(LC_ALL,"");
    float res_real, res_imagin;
    res_real = real_1 * real_2 - imagin_1 * imagin_2;
    res_imagin = real_1 * imagin_2 + real_2 * imagin_1;
    cout << "(" << real_1;
    if(imagin_1 > 0)
        cout << " + " << imagin_1 << "i) X (" << real_2;
    else
        cout << " - " << 0 - imagin_1 << "i) X (" << real_2;
    if(imagin_2 > 0)
        cout << " + " << imagin_2 << "i)\n";
    else
        cout << " - " << 0 - imagin_2 << "i)\n";

    cout << "Resultado na Forma Retangular: ";
    if(res_imagin >= 0)
        cout << "(" << res_real << " + " << res_imagin << "i)" << endl;
    else
        cout << "(" << res_real << " - " << 0 - res_imagin << "i)" << endl;

    cout << "Resultado na Forma Polar: ";
    cout << sqrt(pow(res_real, 2) + pow(res_imagin, 2))
    << " (cos(" << atan((res_real)/(res_imagin)) * 57.29577951308
    << "°) + sen(" << atan((res_real)/(res_imagin)) * 57.29577951308
    << "°)i)" << endl;
}

void Complexo::Divisao(){
    setlocale(LC_ALL,"");
    float res_real, res_imagin;
    res_real = (real_1 * real_2 + imagin_1 * imagin_2)/
    (pow(imagin_1, 2) + pow(imagin_2, 2));
    res_imagin = (imagin_1 * real_2 - real_1 * imagin_2)/
    (pow(imagin_1, 2) + pow(imagin_2, 2));
    cout << "(" << real_1;
    if(imagin_1 > 0)
        cout << " + " << imagin_1 << "i) / (" << real_2;
    else
        cout << " - " << 0 - imagin_1 << "i) / (" << real_2;
    if(imagin_2 > 0)
        cout << " + " << imagin_2 << "i)\n";
    else
        cout << " - " << 0 - imagin_2 << "i)\n";

    cout << "Resultado na Forma Retangular: ";
    if(res_imagin >= 0)
        cout << "(" << res_real << " + " << res_imagin << "i)" << endl;
    else
        cout << "(" << res_real << " - " << 0 - res_imagin << "i)" << endl;

    cout << "Resultado na Forma Polar: ";
    cout << sqrt(pow(res_real, 2) + pow(res_imagin, 2))
    << " (cos(" << atan((res_real)/(res_imagin)) * 57.29577951308
    << "°) + sen(" << atan((res_real)/(res_imagin)) * 57.29577951308
    << "°)i)" << endl;
}

Complexo::~Complexo(){
    //Destructor
}
