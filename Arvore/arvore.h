#include <stdio.h>
#include <stdib.h>
#include "arvore.c"

typedef struct NO* ArvBin; //Raiz

//Cria Arvore (inicia o no especial 'raiz')
ArvBin* cria_ArvBin();
//Libera Avore
void libera_ArvBin(ArvBin *raiz);
//Verifica se esta vazia
int estaVazia_ArvBin(ArvBin *raiz);
//Verifica altura da Arvore
int altura_ArvBin(ArvBin *raiz);
//Verifica quantidade de nos na Arvore
int totalNO_ArvBin(ArvBin *raiz);
//Percorre da raiz, o filho da esquerda depois direita
void preOrdem_ArvBin(ArvBin *raiz);
//Percorre do filho da esquerda, raiz depois filho da direita
void emOrdem_ArvBin(ArvBin *raiz);
//Percorre do filho esquerda, filho direita depois raiz
void posOrdem_ArvBin(ArvBin *raiz);
//Insere valor na arvore
int insere_ArvBin(ArvBin *raiz, int valor);
//Busca nó a ser removido
int remove_ArvBin(ArvBin *raiz, int valor);