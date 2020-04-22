#include "arvbin.c"
#include "arvoreMF.c"
#include <stdio.h>
#include <stdlib.h>
#define N 10

/*
	Considere como etnrada um vetor ordenado contendo numeros inteiros positivos, com quantidade de valores conhecida.
	Implemente uma funcao que escolha apropriadamente os valores no vetor e insira numa arvore binaria, de modo que ela
	fique o melhor possivel balanceada.
*/

typedef struct Lista{
    int vetor[N];
    int qtd;
}tipoLista;

void insercao(tipoLista*,tipoArvBin**,int,int);


int main(){
    //cria arvore binaria
    tipoArvBin *arvoreBIN;
	arvoreBIN = NULL;
    tipoLista lista;

    insercao(&lista,&arvoreBIN,0,-1);
    
    return 0;
}


void insercao(tipoLista* lst,tipoArvBin **arvB,int comeco,int fim){
    int pos;
    pos = comeco + ((fim-comeco)/2);
    if(comeco<fim){
        insereArvBin(arvB,lst->vetor[pos]);
        insercao(lst,arvB,comeco,pos-1);
        insercao(lst,arvB,pos+1,fim);
    }else if(comeco == fim){
        insereArvBin(arvB,lst->vetor[pos]);
    }
}
