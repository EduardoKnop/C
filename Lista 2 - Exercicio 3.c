#include <stdio.h>
#include <stdlib.h>

struct num_racional{
    int numerador;
    int denominador;
};

void obter_numeros(struct num_racional *num, char letra){

    printf("Numero racional %c:\n", letra);
    printf("Numerador:\t");
    fflush(stdin);
    scanf("%i", &num->numerador);
    printf("Denominador:\t");
    fflush(stdin);
    scanf("%i", &num->denominador);

}

struct num_racional simplificar(struct num_racional num){

    struct num_racional simplificado;
    int negativo = 0;

    if(num.numerador < 0){
        num.numerador = 0 - num.numerador;
        negativo = 1;
    }
    if(num.denominador < 0){
        num.denominador = 0 - num.denominador;
        negativo = 1;
    }
    for(int i = 1; i <= num.numerador && i <= num.denominador; i++){
        if(num.numerador % i == 0 && num.denominador % i == 0){
            simplificado.numerador = num.numerador / i;
            simplificado.denominador = num.denominador / i;
        }
    }
    if(negativo == 1)
        simplificado.numerador = 0 - simplificado.numerador;

    return simplificado;

}

float flutuante(struct num_racional num){

    float flu;

    flu = (float) num.numerador / num.denominador;

    return flu;
}

void soma(struct num_racional numA, struct num_racional numB){

    struct num_racional res_soma, simp_soma;

    res_soma.denominador = numA.denominador * numB.denominador;
    res_soma.numerador = numA.numerador * numB.denominador + numB.numerador * numA.denominador;
    simp_soma = simplificar(res_soma);
    printf("%i/%i + %i/%i = %i/%i = %i/%i",
          numA.numerador, numA.denominador, numB.numerador, numB.denominador,
          res_soma.numerador, res_soma.denominador,
          simp_soma.numerador, simp_soma.denominador);

}

void subtrae(struct num_racional numA, struct num_racional numB){

    struct num_racional res_sub, simp_sub;

    res_sub.denominador = numA.denominador * numB.denominador;
    res_sub.numerador = numA.numerador * numB.denominador - numB.numerador * numA.denominador;
    simp_sub = simplificar(res_sub);
    printf("%i/%i - %i/%i = %i/%i = %i/%i",
          numA.numerador, numA.denominador, numB.numerador, numB.denominador,
          res_sub.numerador, res_sub.denominador,
          simp_sub.numerador, simp_sub.denominador);

}

void multiplica(struct num_racional numA, struct num_racional numB){

    struct num_racional res_mul, simp_mul;

    res_mul.denominador = numA.denominador * numB.denominador;
    res_mul.numerador = numA.numerador * numB.numerador;
    simp_mul = simplificar(res_mul);
    printf("%i/%i * %i/%i = %i/%i = %i/%i",
           numA.numerador, numA.denominador, numB.numerador, numB.denominador,
           res_mul.numerador, res_mul.denominador,
           simp_mul.numerador, simp_mul.denominador);

}

void divide(struct num_racional numA, struct num_racional numB){

    struct num_racional res_div, simp_div;

    res_div.denominador = numA.denominador * numB.numerador;
    res_div.numerador = numA.numerador * numB.denominador;
    simp_div = simplificar(res_div);
    printf("%i/%i / %i/%i = %i/%i = %i/%i",
           numA.numerador, numA.denominador, numB.numerador, numB.denominador,
           res_div.numerador, res_div.denominador,
           simp_div.numerador, simp_div.denominador);

}

void main(){

    struct num_racional num_a, a_simp;
    struct num_racional num_b, b_simp;
    float a_flu, b_flu;
    int estado = 0;

    while(1){

        char leave = 0;
        enum{numeros = 0,
             adicao,
             subtracao,
             multiplicacao,
             divisao,
             sair = 99,
             selecao = 100};

        switch(estado){
            case numeros:
                obter_numeros(&num_a, 'A');
                obter_numeros(&num_b, 'B');
                a_simp = simplificar(num_a);
                b_simp = simplificar(num_b);
                a_flu = flutuante(a_simp);
                b_flu = flutuante(b_simp);
                printf("Numero A: %i/%i = %i/%i = %.3f\n",
                       num_a.numerador, num_a.denominador,
                       a_simp.numerador, a_simp.denominador,
                       a_flu);
                printf("Numero B: %i/%i = %i/%i = %.3f\n\n",
                       num_b.numerador, num_b.denominador,
                       b_simp.numerador, b_simp.denominador,
                       b_flu);
                estado = 100;
                break;
            case adicao:
                printf("Operacao escolhida: ADICAO\n");
                soma(num_a, num_b);
                printf(" = %.3f\n\n", a_flu + b_flu);
                estado = 100;
                break;
            case subtracao:
                printf("Operacao escolhida: SUBTRACAO\n");
                subtrae(num_a, num_b);
                printf(" = %.3f\n\n", a_flu - b_flu);
                estado = 100;
                break;
            case multiplicacao:
                printf("Operacao escolhida: MULTIPLICACAO\n");
                multiplica(num_a, num_b);
                printf(" = %.3f\n\n", a_flu * b_flu);
                estado = 100;
                break;
            case divisao:
                printf("Operacao escolhida: DIVISAO\n");
                divide(num_a, num_b);
                printf(" = %.3f\n\n", a_flu / b_flu);
                estado = 100;
                break;
            case sair:
                printf("Operacao escolhida: SAIR\n");
                leave = 1;
                break;
            case selecao:
                printf("Escolha uma operacao:\n\t"
                       "[0] para Mudar os Numeros Escolhidos\n\t"
                       "[1] para Adicao\n\t"
                       "[2] para Subtracao\n\t"
                       "[3] para Multiplicacao\n\t"
                       "[4] para Divisao\n\t"
                       "[99] para Sair\n\n");
                scanf("%i", &estado);
                break;
            default:
                estado = 100;
                printf("Operacao Invalida. Voce digitou um numero que nao faz parte da lista\n");
                break;
        }

        if(leave == 1)
            break;

    }

    printf("SAINDO.");
    for(int i = 1; i < 1000000000; i++){
        if(i % 100000000 == 0)
            printf(".");
    }

}
