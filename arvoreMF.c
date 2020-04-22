#ifndef ARVMF_C
#define ARMMF_C
#include <stdlib.h>
#include <stdio.h>
//constante
#define T 3
//definicao da estrutura
struct estrutura_arv_mf{
	int dados[T];
	int qtd_dados;
	struct estrutura_arv_mf *filhos[T+1];
};
typedef struct estrutura_arv_mf tipo_arv_mf;

//prototipo das funcoes
tipo_arv_mf *aloca_no(int);
void insere_arv_mf(tipo_arv_mf**,int);
void impressao_arv_preordem(tipo_arv_mf*);
void impressao_arv_posordem(tipo_arv_mf*);
void impressao_arv_ordem(tipo_arv_mf*);
void imprime_folhas_arv_mg(tipo_arv_mf*);
//TO DO:
int qtd_dados_arv_mf(tipo_arv_mf*);//CONCLUIDO
int qtd_nos_arv_mf(tipo_arv_mf*);//CONCLUIDO
int eh_folha(tipo_arv_mf*);//CONCLUIDO
int busca_valor_arvMF(tipo_arv_mf*,int);//CONCLUIDO
int altura_arvMF(tipo_arv_mf*);
int num_nohs_por_nivel_arvMF(tipo_arv_mf*,int,int);
int eh_folha_arvMF(tipo_arv_mf*);
int maior_arvMF(tipo_arv_mf*);
int menor_arvMF(tipo_arv_mf*);
void removea_arvMF(tipo_arv_mf*);
//FUNCAO QUE RETORNA TODOS OS VALORES DE UM CERTO NIVEL

//funcoes
tipo_arv_mf *aloca_no(int valor){
	tipo_arv_mf *novo_no;
	int i;
	novo_no = (tipo_arv_mf*)malloc(sizeof(tipo_arv_mf));
	novo_no->qtd_dados = 1;
	novo_no->dados[0] = valor;
	for(int i=1;i<T;i++){
		novo_no->dados[i] = 0;
	}for(int i=0;i<T+1;i++){
		novo_no->filhos[i] = NULL;
	}
	return novo_no;
}

void insere_arv_mf(tipo_arv_mf **arv,int valor){
	int i;
	if((*arv) == NULL){
		(*arv) = aloca_no(valor);
	}else{
		if((*arv)->qtd_dados < T){
			i = (*arv)->qtd_dados;
			while((i>0)&&((*arv)->dados[i-1] > valor)){
				(*arv)->dados[i] = (*arv)->dados[i-1];
				i--;
			}
			(*arv)->dados[i] = valor;
			(*arv)->qtd_dados++;
		}else{
			if((*arv)->qtd_dados == T){
				i=0;
				while((i<(*arv)->qtd_dados)&&(valor>(*arv)->dados[i])){
					i++;
				}
				insere_arv_mf(&(*arv)->filhos[i],valor);
			}
		}
	}
}

int qtd_dados_arv_mf(tipo_arv_mf *arv){
	if(arv == NULL){
		return 0;
	}else{
		int i,qtd;
		qtd = arv->qtd_dados;
		for(i=0;i<T+1;i++){
			qtd += qtd_dados_arv_mf(arv->filhos[i]);
		}
		return qtd;
	}
}
void impressao_pre_ordem_arvMF(tipo_arv_mf *arv){
	int i;
	if(arv!= NULL){
		//prioriza a impressao dos valores
		for(i=0;i<arv->qtd_dados;i++){
			printf("[%d]",arv->dados[i]);
		}
		//executa a chamada recursiva
		for(i=0;i<arv->qtd_dados+1;i++){
			impressao_pre_ordem_arvMF(arv->filhos[i]);
		}
	}

}
void impressao_ordem_arvMF(tipo_arv_mf *arv){
	int i;
	if(arv!=NULL){
		for(i=0;i<arv->qtd_dados;i++){
			impressao_ordem_arvMF(arv->filhos[i]);
			printf("[%d]",arv->dados[i]);
		}
		impressao_ordem_arvMF(arv->filhos[i]);
	}
}
void impressao_pos_ordem_arvMF(tipo_arv_mf *arv){
	int i;
	if(arv !=NULL){
		//prioriza a impressao dos filhos
		for(i=0;i<arv->qtd_dados+1;i++){
			impressao_pos_ordem_arvMF(arv->filhos[i]);
		}
		//imprime valores
		for(i=0;i<arv->qtd_dados;i++){
			printf("[%d]",arv->dados[i]);
		}
	}
}

int eh_folha(tipo_arv_mf *no){
	if(no == NULL){
		return 0;
	}else{
		int i;
		for(i=0;i<T+1;i++){
			if(no->filhos[i] != NULL){
				return 0;
			}
			return 1;
		}
	}
}

void imprime_folhas_arv_mf(tipo_arv_mf *arv){
	if(arv!=NULL){
		int i;
		if(eh_folha(arv)){
			printf("[");
			for(i=0;i<arv->qtd_dados;i++){
				printf("%d,",arv->dados[i]);
			}
			printf("]");
		}else{
			for(i=0;i<T+1;i++){
			imprime_folhas_arv_mf(arv);
		}
		}
		
	}
}
int busca_valor_arvMF(tipo_arv_mf *arv,int valor){
	int i;
    int vaux = 0;
    if (arv != NULL) {
        for (i=0; i<arv->qtd_dados+1; i++){
            if(valor == arv->dados[i]){
                vaux = arv->dados[i];
                return vaux;
            }else{
                busca_valor_arvMF(arv->filhos[i],valor);
            }
        }
    }
    return vaux;
}

int altura_arvMF(tipo_arv_mf *arv){
	int i;
	if(arv !=NULL){
		return 0;
	}else{
		int h[T];
		for(i=0;i<arv->qtd_dados;i++){
			h[i] = altura_arvMF(arv->filhos[i]);
		}
		for(i=0;i<T+1;i++){
			if(h[i]>h[i+1]){
				return h[i];
			}else{
				return h[i+1];
			}
		}
	}
}
/*
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
*/
#endif
