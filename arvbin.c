#include <stdio.h>
#include <stdlib.h>

#ifndef ARVBIN_C
#define ARVBIN_C
struct arvBinaria{
	int dado;
	struct arvBinaria *esq;
	struct arvBinaria *dir;
};
typedef struct arvBinaria tipoArvBin;
//PROTOTIPO DAS FUNCOES
void insereArvBin(tipoArvBin**,int);
void buscaArvBin(tipoArvBin**,int);
void impressao_pre_ordem(tipoArvBin*);
void impressao_pos_ordem(tipoArvBin*);
void impressao_ordem(tipoArvBin*);
void imprime_folhas(tipoArvBin*);
void imprime_nivel(tipoArvBin*,int);
int altura_arvore(tipoArvBin*);
int qtd_no_arv(tipoArvBin*);
int maior_valor_arv(tipoArvBin*);

void remove_valor_arv(tipoArvBin**);

//FUNCOES
void impressao_pre_ordem(tipoArvBin *arv){
	if(arv !=NULL){
		printf("[%d]",arv->dado);
		impressao_pre_ordem(arv->dir);
		impressao_pre_ordem(arv->esq);
	}
}
void impressao_ordem(tipoArvBin *arv){
	//printf("\nIMPRESSAO ARVORE BINARIA");
	if(arv != NULL){
		impressao_ordem(arv->dir);
		printf("[%d]",arv->dado);
		impressao_ordem(arv->esq);
	}
}
void impressao_pos_ordem(tipoArvBin *arv){
	if(arv !=NULL){
		impressao_pos_ordem(arv->dir);
		impressao_pos_ordem(arv->esq);
		printf("[%d]",arv->dado);
	}
}

void insereArvBin(tipoArvBin **arv,int valor){
	if((*arv) == NULL){	
		tipoArvBin *novo_no;
		novo_no = (tipoArvBin*) malloc(sizeof(tipoArvBin));
		novo_no->dado = valor;
		novo_no->dir = NULL;
		novo_no->esq = NULL;
		(*arv) = novo_no;
	}else{
		if(valor < (*arv)->dado){
			insereArvBin(&(*arv)->esq,valor);
		}else{
			insereArvBin(&(*arv)->dir,valor);
		}
	}
}
void buscaArvBin(tipoArvBin **arv,int valor){
	if((*arv) == NULL){
		printf("\nvalor nao encontrado");
	}else{
		if(valor == (*arv)->dado){
			printf("\nvalor encontrado!");
			printf("\n[%d]\n",(*arv)->dado);
		}else{
			buscaArvBin(&(*arv)->dir,valor);
			buscaArvBin(&(*arv)->esq,valor);
		}
	}
}
void imprime_folhas(tipoArvBin *arv){
	if(arv != NULL){
		if((arv->esq == NULL) && (arv->dir == NULL)){
			printf("[%d]",arv->dado);
		}else{
			imprime_folhas(arv->esq);
			imprime_folhas(arv->dir);
		}
	}
}

void imprime_nivel(tipoArvBin *arv,int nivel){
	if(arv != NULL){
		if(nivel ==0){
			printf("[%d]",arv->dado);
		}else{
			if(nivel>0){
				imprime_nivel(arv->esq,nivel-1);
				imprime_nivel(arv->dir,nivel-1);
			}
		}
	}
}

int altura_arvore(tipoArvBin *arv){
	if(arv != NULL){
		if((arv->esq = NULL) && (arv->dir = NULL)){
			return 0;
		}else{
			int h_esq, h_dir;
			h_esq = altura_arvore(arv->esq);
			h_dir = altura_arvore(arv->dir);
			if(h_esq > h_dir){
				return h_esq+1;
			}else{
				return h_dir+1;
			}
		}
	}
}

int qtd_no_arv(tipoArvBin *arv){
	if(arv == NULL){
		return 0;
	}else{
		int qtd_esq, qtd_dir;
		qtd_esq = qtd_no_arv(arv->esq);
		qtd_dir = qtd_no_arv(arv->dir);
		return qtd_esq + qtd_dir + 1;
	}
}

int maior_valor_arv(tipoArvBin *arv){
	if(arv != NULL){
		if(arv->dir != NULL){
			return maior_valor_arv(arv->dir);
		}else{
			return arv->dado;
		}
	}

}

int menor_valor_arv(tipoArvBin *arv){
	if(arv != NULL){
		if(arv->esq != NULL){
			return menor_valor_arv(arv->esq);
		}else{
			return arv->dado;
		}
	}
}

void remove_valor_arv(tipoArvBin **arv){
	if(((*arv)->esq == NULL)&&((*arv)->dir == NULL)){
		free((*arv));
		(*arv) = NULL;
	}else{
		if(((*arv)->esq == NULL)&&((*arv)->dir == NULL)){
			tipoArvBin *aux;
			if((*arv)->esq != NULL){
				aux = (*arv);
				(*arv) = (*arv)->esq;
				free(aux);
			}else{
				aux = (*arv);
				(*arv) = (*arv)->dir;
				free(aux);
			}
		}
	}
}

#endif
