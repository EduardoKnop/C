#include <stdio.h>
#include <stdlib.h>

char tabuleiro[11] = {'I',' ',' ',' ',' ',' ',' ',' ',' ',' ','\0'};
char restart;
int casa, player, estado = 0, jogadas = 0, jogo = 1;

void jogo_da_velha(int casa1, int casa2, int casa3){
    system("color 02");
    printf("\t     VITORIA\n\n");
    if(casa1 == 7 || casa2 == 7 || casa3 == 7)
        printf("\t [%c] |", tabuleiro[7]);
    else
        printf("\t  %c  |", tabuleiro[7]);
    if(casa1 == 8 || casa2 == 8 || casa3 == 8)
        printf(" [%c] |", tabuleiro[8]);
    else
        printf("  %c  |", tabuleiro[8]);
    if(casa1 == 9 || casa2 == 9 || casa3 == 9)
        printf(" [%c]\n", tabuleiro[9]);
    else
        printf("  %c\n", tabuleiro[9]);
        if(casa1 == 4 || casa2 == 4 || casa3 == 4)
        printf("\t [%c] |", tabuleiro[4]);
    else
        printf("\t  %c  |", tabuleiro[4]);
    if(casa1 == 5 || casa2 == 5 || casa3 == 5)
        printf(" [%c] |", tabuleiro[5]);
    else
        printf("  %c  |", tabuleiro[5]);
    if(casa1 == 6 || casa2 == 6 || casa3 == 6)
        printf(" [%c]\n", tabuleiro[6]);
    else
        printf("  %c\n", tabuleiro[6]);
    if(casa1 == 1 || casa2 == 1 || casa3 == 1)
        printf("\t [%c] |", tabuleiro[1]);
    else
        printf("\t  %c  |", tabuleiro[1]);
    if(casa1 == 2 || casa2 == 2 || casa3 == 2)
        printf(" [%c] |", tabuleiro[2]);
    else
        printf("  %c  |", tabuleiro[2]);
    if(casa1 == 3 || casa2 == 3 || casa3 == 3)
        printf(" [%c]\n", tabuleiro[3]);
    else
        printf("  %c\n", tabuleiro[3]);

    if(player == 1)
        printf("Player 2 ganhou! Parabens!!!");
    else if(player == 2)
        printf("Player 1 ganhou! Parabens!!!");

    jogo = 0;
}

void main(){
    system("color 0F");
    enum{ jog_player1 = 0,
          jog_player2,
          casa_usada1,
          casa_usada2,
          empate,
          analise_jog,
          analise_part};

    printf("=-=-=-=Jogo da Velha=-=-=-=\n\n");
    printf("Comandos: 7 | 8 | 9\n\t  4 | 5 | 6\n\t  1 | 2 | 3\n\n");
    system("color 06");
    printf("Loading");
    for(int i = 0;i < 100000000; i++){
        if(i % 10000000 == 10)
                printf(".");
        fflush(stdout);
   }
    system("color 0F");
    printf("\n\n\t   |   |\n\t   |   |\n\t   |   |\n\n");

    while(1){
        switch(estado){
            case jog_player1:
                player = 1;
                printf("Player 1: Que casa voce escolhe? ");
                fflush(stdin);
                scanf("%i", &casa);
                estado = analise_jog;
                break;
            case jog_player2:
                player = 2;
                printf("Player 2: Que casa voce escolhe? ");
                fflush(stdin);
                scanf("%i", &casa);
                estado = analise_jog;
                break;
            case casa_usada1:
                printf("Voce ja utilizou essa casa! Tente outra\n");
                if(player == 1)
                    estado = jog_player1;
                else if(player == 2)
                    estado = jog_player2;
                break;
            case casa_usada2:
                printf("Seu adversario ja utilizou essa casa! Tente outra\n");
                if(player == 1)
                    estado = jog_player1;
                else if(player == 2)
                    estado = jog_player2;
                break;
            case empate:
                system("color 04");
                printf("\t  EMPATE");
                printf("\n\t %c | %c | %c\n\t %c | %c | %c\n\t %c | %c | %c\n\n",
                       tabuleiro[7], tabuleiro[8], tabuleiro[9],
                       tabuleiro[4], tabuleiro[5], tabuleiro[6],
                       tabuleiro[1], tabuleiro[2], tabuleiro[3]);
                jogo = 0;
                break;
            case analise_jog:
                if(casa <= 9 && casa >= 1){
                    if(tabuleiro[casa] == ' '){
                        if(player == 1){
                            tabuleiro[casa] = 'X';
                            estado = analise_part;
                            player = 2;
                            jogadas++;
                        }
                        else if(player == 2){
                            tabuleiro[casa] = 'O';
                            estado = analise_part;
                            player = 1;
                            jogadas++;
                        }
                    }
                    else if(tabuleiro[casa] == 'X'){
                        if(player == 1)
                            estado = casa_usada1;
                        else if(player == 2)
                            estado = casa_usada2;
                    }
                    else if(tabuleiro[casa] == 'O'){
                        if(player == 1)
                            estado = casa_usada2;
                        else if(player == 2)
                            estado = casa_usada1;
                    }
                }
                else{
                    printf("Comando nao reconhecido. Tente novamente\n\n");
                    if(player == 1)
                        estado = jog_player1;
                    else if(player == 2)
                        estado = jog_player2;
                }
                printf("\n\t %c | %c | %c\n\t %c | %c | %c\n\t %c | %c | %c\n\n",
                       tabuleiro[7], tabuleiro[8], tabuleiro[9],
                       tabuleiro[4], tabuleiro[5], tabuleiro[6],
                       tabuleiro[1], tabuleiro[2], tabuleiro[3]);
                break;
            case analise_part:
                if(jogadas < 5){
                    if(player == 1)
                        estado = jog_player1;
                    else if(player == 2)
                        estado = jog_player2;
                }
                else{
                    if(tabuleiro[7] == tabuleiro[8] && tabuleiro[8] == tabuleiro[9] && tabuleiro[9] != ' ')
                        jogo_da_velha(7, 8, 9);
                    else if(tabuleiro[4] == tabuleiro[5] && tabuleiro[5] == tabuleiro[6] && tabuleiro[6] != ' ')
                        jogo_da_velha(4, 5, 6);
                    else if(tabuleiro[1] == tabuleiro[2] && tabuleiro[2] == tabuleiro[3] && tabuleiro[3] != ' ')
                        jogo_da_velha(1, 2, 3);
                    else if(tabuleiro[7] == tabuleiro[4] && tabuleiro[4] == tabuleiro[1] && tabuleiro[1] != ' ')
                        jogo_da_velha(7, 4, 1);
                    else if(tabuleiro[8] == tabuleiro[5] && tabuleiro[5] == tabuleiro[2] && tabuleiro[2] != ' ')
                        jogo_da_velha(8, 5, 2);
                    else if(tabuleiro[9] == tabuleiro[6] && tabuleiro[6] == tabuleiro[3] && tabuleiro[3] != ' ')
                        jogo_da_velha(9, 6, 3);
                    else if(tabuleiro[7] == tabuleiro[5] && tabuleiro[5] == tabuleiro[3] && tabuleiro[3] != ' ')
                        jogo_da_velha(7, 5, 3);
                    else if(tabuleiro[1] == tabuleiro[5] && tabuleiro[5] == tabuleiro[9] && tabuleiro[9] != ' ')
                        jogo_da_velha(1, 5, 9);
                    else if(jogadas == 9)
                        estado = empate;
                    else{
                        if(player == 1)
                            estado = jog_player1;
                        else if(player == 2)
                            estado = jog_player2;
                    }
                }
                break;
        }

        if(jogo == 0){
            printf("\nVoce quer reiniciar o jogo? S/N ");
            fflush(stdin);
            scanf("%c", &restart);
            if (restart == 'n' || restart == 'N')
                break;
            else if(restart == 's' || restart == 'S'){
                for(int i = 1; tabuleiro[i] != '\0'; i++)
                    tabuleiro[i] = ' ';

                estado = 0;
                jogadas = 0;
                jogo = 1;

                printf("\n=-=-=-=Jogo da Velha=-=-=-=\n");
                system("color 0F");
                printf("\n\t   |   |\n\t   |   |\n\t   |   |\n\n");
            }
        }
    }
}
