#include <stdio.h>
#include <stdlib.h>

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila; //nó descritor
Fila* cria_Fila(Fila *fi);
void libera_Fila(Fila *fi);
int tamanho_fila(Fila* fi);
int Fila_cheia(Fila* fi);
int Fila_vazia(Fila* fi);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila *fi);
int consulta_Fila(Fila *fi, struct aluno *al);