#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_LO.h"

apontadorLO criaStableLO()
{
    apontadorLO inicio = NULL;
    return(inicio);
}

void destroiStableLO(apontadorLO inicio)
{
    apontadorLO prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->info.palavra);
        free(inicio);
        inicio = prox;
    }
    return;
}

apontadorLO insereStableLO(char *key ,apontadorLO inicio)
{
    apontadorLO temp, anterior;
    apontadorLO novoItem = malloc(sizeof(celulaLO));
    temp = inicio;
    anterior = NULL;
    /*primeiro devemos verificar se a lista esta vazia.
     */
    if(!inicio){
        inicio = malloc(sizeof(celulaLO));
        inicio->info.palavra = malloc(strlen(key)*sizeof(char));
        strcpy(inicio->info.palavra, key);
        inicio->info.freq = 1;
        inicio->next = NULL;
        return inicio;
    }
    /*agora iremos procurar o iten desejado na lista e mudar sua frequencia se
     *ele estiver presente na lista.
     */
    while(temp != NULL && strcmp(key, temp->info.palavra) >= 0){
        if(!strcmp(key, temp->info.palavra)){
            temp->info.freq++;
            return(inicio);
        }
        anterior = temp;
        temp = temp->next;
    }
    novoItem->info.palavra = malloc(strlen(key)*sizeof(char));
    strcpy(novoItem->info.palavra, key);
    novoItem->info.freq = 1;
    novoItem->next = temp;
    /* Agora vamos verificar se temos que mudar o inicio da lista.
     */
    if(anterior == NULL){
        inicio = novoItem;
        return(inicio);
    }
    anterior->next = novoItem;
    return(inicio);
}
