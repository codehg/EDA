#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main() {
    ArvBin* raiz;//inicia estrutura da raiz na main
    ArvBin* raiz = cria_ArvBin();//cria a raiz iniciando o no especial
    libera_ArvBin(raiz);//função do tipo void nao precisa armazenar
    int x = estaVazia_ArvBin(raiz); //Duas formas de referenciar...
    if(estaVazia_Arvbin(raiz))      //...armazenado em variavel ou checando com if
    int x = altura_ArvBin(raiz);//armazenamento trivial com retorno inteiro
    int x = totalNO_ArvBin(raiz);//armazena total em var int
    preOrdem_ArvBin(raiz);//a entrada é o endereco do no da raiz
    emOrdem_ArvBin(raiz);
    posOrdem_ArvBin(raiz);
    int x = insere_ArvBin(raiz, valor);
    int x = remove_ArvBin(raiz, valor);
    
    return 0;
}