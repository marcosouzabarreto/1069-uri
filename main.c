#include <stdio.h>
#include <string.h>
#include "pilha.h"

int conta_diamante(tp_pilha pilha, int tamanho, const char *expressao){
    char caractere, e;
    int diamante_direito = 0, diamante_esquerdo = 0, diamantes=0, verificador = 0;

    for(; tamanho>=0; tamanho--){
        caractere = expressao[tamanho];
        if((caractere==60)||(caractere==62)){
            push(&pilha, caractere);
        }
        while(!pilha_vazia(&pilha)){
            pop(&pilha, &e);
            if (e==62) {
                diamante_direito++;
                verificador++;
            } else {
                diamante_esquerdo++;
                verificador--;
                if(verificador<0) diamante_esquerdo--;
            }
        }
        while((diamante_direito > 0) && (diamante_esquerdo > 0)){

                diamante_direito--;
                diamante_esquerdo--;
                diamantes++;

        }
    }
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
