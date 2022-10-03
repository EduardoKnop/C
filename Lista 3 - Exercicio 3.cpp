/*  Autor: Eduardo Knop
    Exercício 3 da Lista 3 de Programação Orientada a Objetos */

#include <iostream>

using namespace std;

class Nascimento{
private:
    int dia, mes, ano;

    bool Bissexto(int a){

        if((a % 4 == 0 && a % 100 != 0) || a % 400 == 0){
            return true;
        }

        return false;

    }
        void MesExtenso(){
        switch(mes){
            case 1:
               cout << "janeiro";
               break;
            case 2:
               cout << "fevereiro";
               break;
            case 3:
               cout << "marco";
               break;
            case 4:
               cout << "abril";
               break;
            case 5:
               cout << "maio";
               break;
            case 6:
               cout << "junho";
               break;
            case 7:
               cout << "julho";
               break;
            case 8:
               cout << "agosto";
               break;
            case 9:
               cout << "setembro";
               break;
            case 10:
               cout << "outubro";
               break;
            case 11:
               cout << "novembro";
               break;
            case 12:
               cout << "dezembro";
               break;
        }
    }
    void Signo(){
        switch(mes){
            case 1:
                if(dia <= 19){
                    cout << "Capricornio" << endl;
                }
                else{
                    cout << "Aquario" << endl;
                }
                break;
            case 2:
                if(dia <= 18){
                    cout << "Aquario" << endl;
                }
                else{
                    cout << "Peixes" << endl;
                }
                break;
            case 3:
                if(dia <= 20){
                    cout << "Peixes" << endl;
                }
                else{
                    cout << "Aries" << endl;
                }
                break;
            case 4:
                if(dia <= 19){
                    cout << "Aries" << endl;
                }
                else{
                    cout << "Touro" << endl;
                }
                break;
            case 5:
                if(dia <= 20){
                    cout << "Touro" << endl;
                }
                else{
                    cout << "Gemeos" << endl;
                }
                break;
            case 6:
                if(dia <= 20){
                    cout << "Gemeos" << endl;
                }
                else{
                    cout << "Cancer" << endl;
                }
                break;
            case 7:
                if(dia <= 22){
                    cout << "Cancer" << endl;
                }
                else{
                    cout << "Leao" << endl;
                }
                break;
            case 8:
                if(dia <= 22){
                    cout << "Leao" << endl;
                }
                else{
                    cout << "Virgem" << endl;
                }
                break;
            case 9:
                if(dia <= 22){
                    cout << "Virgem" << endl;
                }
                else{
                    cout << "Libra" << endl;
                }
                break;
            case 10:
                if(dia <= 22){
                    cout << "Libra" << endl;
                }
                else{
                    cout << "Escorpiao" << endl;
                }
                break;
            case 11:
                if(dia <= 21){
                    cout << "Escorpiao" << endl;
                }
                else{
                    cout << "Sagitario" << endl;
                }
                break;
            case 12:
                if(dia <= 21){
                    cout << "Sagitario" << endl;
                }
                else{
                    cout << "Capricornio" << endl;
                }
                break;
        }
    }
public:
    bool Validate(int d, int m, int a){

        if(a < 1900 || a > 2020 || m < 1 || m > 12 || d < 0 || d > 31){
            cout << "Data Invalida! Informe outra." << endl;
            return false;
        }

        if(d > 30 && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11)){
            cout << "Data Invalida! Informe outra." << endl;
            return false;
        }
        else if(d > 28 && m == 2){
            if(Bissexto(a) == false || d == 30){
                cout << "Data Invalida! Informe outra." << endl;
                return false;
            }
        }

        dia = d; mes = m; ano = a;

        return true;
    }
    void Print(){

        cout << "\n\nData de Nascimento: " << dia << " de ";
        MesExtenso();
        cout << " de " << ano << endl;
        cout << "Signo: ";
        Signo();
        if(Bissexto(ano) == true){
            cout << "Nascido em um ano Bissexto" << endl;
        }
        else{
            cout << "O ano de nascimento Nao e Bissexto" << endl;
        }

    }
};

int main() {

    int dia, mes, ano;
    bool verificado = false;
    Nascimento pessoa1;

    cout << "Este programa:\n\t• Recebe a Data de Nascimento do Usuario"
            << "\n\t• Faz a Validacao da Data"
            << "\n\t• Imprime a Data por Extenso, o Signo e Se o Ano e Bissexto.\n\n\n";

    cout << "Informe abaixo as informacoes referentes a sua data de nascimento\n";

    while(verificado == false){
        cout << "\n\tDia: ";
        cin >> dia;
        cout << "\tMes: ";
        cin >> mes;
        cout << "\tAno: ";
        cin >> ano;

        verificado = pessoa1.Validate(dia, mes, ano);
    }

    pessoa1.Print();

    return 0;

}
