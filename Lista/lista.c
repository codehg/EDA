#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct elemento{
    aluno dados;
    elemento *prox;
};
typedef struct elemento Elem;

//Cria Lista
Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

//Librea lista
void libera_lista(Lista* li){
    if (li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

//Tamanho da lista
int tamanho_lista(Lista* li){
    if(li == NULL)
    return 0;

    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

//Lista vazia
int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

//Insere no inicio
int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

//Insere no final
int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    
    if((*li) == NULL){ //Lista vazia: insere inicio
        *li = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

//Insere lista ordenada
int insere_lista_ordenada(Lista* li, struct alunos al){
    if(li == NULL)
        return 0;
    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if(lista_vazia(li)){ //insere inicio
        no->prox = (*li);
        *li = no;
        return 1;
    }else{ //procura onde inserir
        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
        ant = atual;
        atual = atual->prox;
        }
        if(atual == *li){ //insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ant->prox;
            ant->prox = no;
        }
        return 1;
    }
    
}

//Remove do inicio da lista
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL) //lista vazia
        return 0;
    
    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

//Remove do final da lista
int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL) //lista vazia
        return 0;
   
    //Percorre lista até o final dela
    //ant e no são auxiliares com no sendo
    //o primeiro item da lista
    Elem *ant, *no = *li;      
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }
    //eh o primeiro da lista?
    if(no == (*li)) //sim
        *li = no->prox;
    else //nao
        ant->prox = no->prox; 
    free(no);
    return 1;    
}

//Remove um elemento qualquer da lista
int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    
    Elem *ant, *no = *li;

    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL) //Nao encontrado
        return 0;
    //Primeiro da lista?
    if(no == *li) //SIM
        *li = no->prox;
    else    //NAO - ta no meio, ou no final
        ant->prox = no->prox;
    free(no)
    return 1;
}

//Busca elemento pela posicao
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL) //Cheguei no final da lista e nao encontrei a pos (ou lista vazia)
        return 0;
    else{ //Se achou, o ponteiro auxiliar (*al) recebe o conteudo do no
        *al = no->dados; //auxiliar recebe o campo dados do no
        return 1; //retorno 1 pq deu certo
    }  
}

//Busca elemento pela matricula
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);{
    if(li == NULL)
        return 0;
    
    Elem *al, *no = *li;

    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)  //Nao achei
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}
