#include "fila.h"

struct pilha{
    int qtd;
    struct aluino dados[MAX];
};

//Cria pilha
Pilha* cria_Pilha(){
    Pilha *pi;
    pi = (Pilha*)malloc(sizeof(pilha));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}