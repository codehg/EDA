#include "arvore.h"

//Estrutura da arvore baseada em Lista
struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

//Cria Arvore (cria o no raiz que inicialmente aponta pra null)
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL) //Se deu certo a alocação
        *raiz = NULL; //No aponta pra NULL
    return raiz;
}
//Libera Arvore (função recursiva)
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada um dos nos
    free(raiz);//libera a raiz
}
//Verifica se esta vazia
int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL) //Se a raiz for igual a NULL
        return 1;
    if(*raiz == NULL) //Se o conteudo da raiz for igual a NULL
        return 1;
    return 0;
}
//Verifica altura da Arvore
int altura_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    //armazenando a altura de cada lado puxando pelo endereço do no
    int alt_esq = altura_Arvbin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    //contagem recursiva
    if(alt_esq > alt_dir)//Se esq for maior que dir, incrementa esq
        return (alt_esq + 1);
    else//Se nao, encrementa dir
        return(alt_dir + 1);  
}
//Verifica total de nos
int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    //percorre os dois lados da arvore
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    //simplesmente conta a quantidade de vezes que passou por nos na arvore
    return(alt_esq + alt_dir + 1);//soma direita com esq + o pai
}
//PreOrder
void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);//imprime info da raiz
        preOrdem_ArvBin(&((*raiz)->esq));//visita o filho esq
        preOrdem_ArvBin(&((*raiz)->dir));//visita o filho dir
    }
}
//InOrder
void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}
//PostOrder
void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrder_ArvBin(&((*raiz)->esq));
        posOrder_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}
//Insere valor na arvore
int insere_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    
    struct NO* novo; //alocando novo no
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL) //caso erro
        return 0;
    
    novo->info = valor; //copia valor a ser inserido do campo info
    novo->dir = NULL; 
    novo->esq = NULL;
    //procurar onde inserir!
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        //Navega nos nós da arvore até chegar em um nó folha
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento ja existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;     
        }
        //insere como filho desse nó folha
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }        
    return 1;
}
//Busca nó a ser removido
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;

    while(atual != NULL){
        //achou o no a ser removido, tratar o lado da remoção
        if(valor == atual->info){ //achei a posição
            if(atual == *raiz) //se atual = conteudo da raiz
                *raiz = remove_atual(atual); 
            else{ //procura filho ou folha
                if(ant->dir == atual) //se dir = atual
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);           
            }
        }
        return 1;
    }
    //continua percorrendo a arvore a procura do nó a ser removido
    ant = atual;
    if(valor > atual->info)
        atual = atual->dir;
    else
        atual = atual->esq;
    
}
//Trata os 3 tipos de remoção
struct NO* remove_atual(struct NO* atual){
    struct NO* *no1, *no2;
    //Sem filho da esquerda
    //Apontar para o filho da direita
    //trata no folha com 1 filho
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    //Procura filho mais a direita..
    //..na sub-arvore da esquerda
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    //Copia filho mais a direita..
    //..na sub-arvore a esquerda para..
    //..o lugar do no removido
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}