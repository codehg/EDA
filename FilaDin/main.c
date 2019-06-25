#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
Fila *fi; //ponteiro para o no descritor
fi = cria_Fila(fi);
libera_Fila(fi);
int x = tamanho_Fila(fi);

int x = Fila_cheia(fi);
//if(Fila_cheia(fi))

int x = Fila_vazia(fi);
//if(Fila_vazia(fi))
int x = insere_Fila(fi, dados_aluno);
int x = remove_Fila(fi);
int x = consulta_Fila(fi, &dados_aluno);

    return 0;
}
