#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

//Arquivo ListaDinEncad.h
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento* Lista;

//Cria lista
Lista* cria_lista();
//Libera lista
void libera_lista(Lista* li);
//Tamanho da lista
int tamanho_lista(Lista* li);
//Lista vazia
int lista_vazia(Lista* li);
//Insere no inico da lista
int insere_lista_inicio(Lista* li, struct aluno al);
//Insere no final da lista
int insere_lista_final(Lista* li, struct aluno al);
//Insere ordenada
int insere_lista_Ordenada(Lista* li, struct aluno al);
//Remove no inicio da lista
int remove_lista_inicio(Lista* li);
//Remove no inicio da lista
int remove_lista_final(Lista* li);

