#include "arvbin.c"
#include "arvoreMF.c"
#include <stdio.h>
#include <stdlib.h>

/*
Considere uma ARVORE COM MULTIPLOS FILHOS, que armarena valores inteiros positivos, com parametro K=3.
Implemente uma funcao que faca o percurso EM ORDEM na arvore com multiplos filhos e que cada valor seja
inserido em uma ARVORE BINARIA, retornando a arvore contruida como resposta.
*/

tipoArvBin* percorre_arvM(tipo_arv_mf *arv);
void insereArvBin2(tipoArvBin **arv,int valor);

int main(){
    printf("\nEstrutura de dados I - QUESTAO 1");
    
    //cria a arvore binaria
    tipoArvBin *arvoreBIN;
	arvoreBIN = NULL;
    //cria a arvore multiplos filhos
    tipo_arv_mf *arvoreMF;
    arvoreMF = NULL;

    insere_arv_mf(&arvoreMF,50);
    insere_arv_mf(&arvoreMF,20);
    insere_arv_mf(&arvoreMF,10);
    
    insere_arv_mf(&arvoreMF,30);
    insere_arv_mf(&arvoreMF,15);
    insere_arv_mf(&arvoreMF,22);
    
    insere_arv_mf(&arvoreMF,21);
    insere_arv_mf(&arvoreMF,17);
    insere_arv_mf(&arvoreMF,28);

    printf("\nimpressao ordenada arvore MF\n");
    impressao_ordem_arvMF(arvoreMF);    
    
    arvoreBIN = percorre_arvM(arvoreMF);
    
    printf("\nimpressao ordenada arvore binaria\n");    
    
    printf("\nqtd dados - %d\n",qtd_dados_arv_mf(arvoreMF));
    impressao_ordem(arvoreBIN);
    printf("\nqtd dados - %d\n",qtd_no_arv(arvoreBIN));

}

void insereArvBin2(tipoArvBin **arv,int valor){
	if((*arv) == NULL){	
		tipoArvBin *novo_no;
		novo_no = (tipoArvBin*) malloc(sizeof(tipoArvBin));
		novo_no->dado = valor;
		novo_no->dir = NULL;
		novo_no->esq = NULL;
		(*arv) = novo_no;
        printf("no alocado %d\n", novo_no->dado);
	}else{
		if(valor < (*arv)->dado){
			insereArvBin2(&(*arv)->esq,valor);
            printf("valor inserido a esquerda\n");
		}else{
			insereArvBin2(&(*arv)->dir,valor);
            printf("valor inserido a direita\n");
		}
	}
}

tipoArvBin* percorre_arvM(tipo_arv_mf *arv){
    tipoArvBin *arvBINAux;
    int i;
	if(arv!=NULL){
        for(i=0;i<arv->qtd_dados;i++){
            printf("\n%d\n",i);
            percorre_arvM(arv->filhos[i]);
            insereArvBin2(&arvBINAux,arv->dados[i]);
		}
	}
    return arvBINAux;
}
