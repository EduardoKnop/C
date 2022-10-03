#include <stdio.h>

int converte_segundo(int hora, int min, int seg){
    seg = seg + min * 60 + hora * 3600;
    return seg;
    }

void main(){
    int hora, minuto, segundo, seg;

    printf("Voce ira digitar a hora, minuto e segundo separadamente.\n");
    printf("Informe primeiramente a hora: ");
    scanf("%d", &hora);
    printf("Agora informe os minutos: ");
    scanf("%d", &minuto);
    printf("Por ultimo informe os segundos: ");
    scanf("%d", &segundo);
    seg = converte_segundo(hora, minuto, segundo);
    printf("O horario %02d:%02d:%02d corresponde a %d segundos", hora, minuto, segundo, seg);

    return;
}
