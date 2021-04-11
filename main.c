#include <stdio.h>
#include <string.h>
#include "pilha.h"

int conta_diamante(tp_pilha pilha, int tamanho, const char *expressao){
    char caractere, e;
    int abre_diamante = 0, fecha_diamante = 0, diamantes=0, verificador = -1;

    for(; tamanho>=0; tamanho--){
        caractere = expressao[tamanho];
        if((caractere==60)||(caractere==62)){
            push(&pilha, caractere);
        }

    }
    while (!pilha_vazia(&pilha)){
        pop(&pilha, &e);

        if(e==60){
            abre_diamante++;
            verificador++;
        } else if ((e==62)&&(verificador>=0)){
            fecha_diamante++;
            verificador--;
        }
    }
    while((abre_diamante>0)&&(fecha_diamante>0)){
        abre_diamante--;
        fecha_diamante--;
        diamantes++;
    }

    imprime_pilha(pilha);
    return diamantes;
}
int main() {
    tp_pilha pilha;
    char expressao[1000];
    int tamanho, diamantes;
    inicializa_pilha(&pilha);

    scanf("%[^\n]", expressao);
    tamanho = strlen(expressao);

    diamantes = conta_diamante(pilha, tamanho, expressao);
    printf("O numero total de diamantes formados foi %i", diamantes);
    return 0;
}
