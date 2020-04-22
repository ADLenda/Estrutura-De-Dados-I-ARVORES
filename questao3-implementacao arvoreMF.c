#include "arvoreMF.c"
#include <stdio.h>
#include <stdlib.h>

#define T 3

/*
	Considere uma arvore com multiplos filhos, com capacidade de K valores. Imagine a necessidade de percorrer os valores
	armazenados em ordem inversa, ou seja, do maior para o menor.
	Defina o tipo de dado desta arvore, especifique os prototipos e implemente as funcoes que percorrem esta arvore em pre-ordem
	ordem e pos-ordem.
*/

typedef struct Arvore{
    int valores[T];
    struct Arvore* filhos[T+1];
    int qtd;
}tipoArvore;

void preOrdem(tipoArvore*);
void posOrdem(tipoArvore*);
void ordem(tipoArvore*);

int main(){


    return 0;
}


void preOrdem(tipoArvore *arv){
    int i;
    if(arv != NULL){
        for(i=arv->qtd-1;i>=0;i--){
            printf("[%d]",arv->valores[i]);
        }
        for(i=arv->qtd;i>0;i--){
            preOrdem(arv->filhos[i]);
        }
    }
}

void posOrdem(tipoArvore *arv){
    int i;
    if(arv != NULL){
        for(i=arv->qtd;i>0;i--){
            posOrdem(arv->filhos[i]);
        }
        for(i=arv->qtd-1;i>=0;i--){
            printf("[%d]",arv->valores[i]);
        }
    }
}

void ordem(tipoArvore *arv){
    int i;
    if(arv != NULL){
        ordem(arv->filhos[arv->qtd]);
        for(i=arv->qtd-1;i>0;i--){
            printf("[%d]",arv->valores[i]);
            ordem(arv->filhos[i]);
        }
    }
}
