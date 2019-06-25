#include <stdlib.h>
#include "fila.h"

struct fila{
    struct elemento *inicio;
    struct elemento *final;
};
struct elemento{//minha lista(representa cada no da fila)
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

//Cria fila
Fila* cria_Fila(Fila *fi){
    Fila* fi = (Fila*) malloc(sizeof(Fila));
    if(fi != NULL){//funcionou o malloc
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}
//Libera Fila
void libera_Fila(Fila *fi){
    if(fi == NULL)//tem fila
        return 0;

        Elem* no;//no auxiliar
        while(fi->inicio != NULL){
                no = fi->inicio;
                fi->inicio = fi->inicio->prox;
                free(no);
        }
        free(fi);    
}
//Tamanho da fila
int tamanho_fila(Fila* fi){
    if(fi == NULL)//se nao tem fila
        return 0;
    
    int cont = 0;
    Elem* no = fi->inicio;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}
//Fila cheia
int Fila_cheia(Fila* fi){
        return 0;
}
//Fila vazia
int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return 1;
    if(fi->inicio == NULL)
        return 1;
    return 0;
}
//Insere na fila
int insere_Fila(Fila* fi, struct aluno al){
    if(fi == NULL)
        return 0;
    
    Elem *no = (Elem*) malloc(sizeof(Elem));//novo elemento
    if(no == NULL)//se alocação falhou
        return 0;
    //deu certo -> copia os dados pro no
    no->dados = al;
    no->prox = NULL;

    if(fi->final == NULL)//fila vazia
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}
//Remove fila
int remove_Fila(Fila *fi){
    if(fi == NULL)//fila nao existe
        return 0;
    if(fi->inicio == NULL)//fila vazia
        return 0;
    
    Elem *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)//fila ficou vazia
        fi->final = NULL;
    free(no);
    return 1;
}
//Consulta Fila
int consulta_Fila(Fila *fi, struct aluno *al){
    if(fi == NULL) 
        return 0;
    if(fi->inicio == NULL)//lista vazia
        return 0;
    
    *al = fi->inicio->dados;
    return 1;
}