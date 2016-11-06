#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_LO.h"

apontador criaStableLO()
{
    apontador inicio = NULL;
    return(inicio);
}

void destroiStableLO(apontador inicio)
{
    apontador prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->bob.palavra);
        free(inicio->bob);
        free(inicio);
        inicio = prox;
    }
    return;
}

apontador insereStableLO(char *key ,apontador inicio)
{
    apontador temp, anterior;
    apontador novoItem = malloc(sizeof(celula));
    temp = inicio;
    anterior = NULL;
    while(temp != NULL && strcmp(key, temp->bob.palavra) < 0){
        anterior = temp;
        temp = temp->next;
    }
    /*primeiro vamos verificar se a palavra já se encontra na tabela.
     */
    if(!strcmp(key, temp->bob.palavra)){
        temp->bob.freq++;
        return(inicio);
    }
    strcpy(novoItem->bob.palavra, key);
    novoItem->bob.freq = 1;
    novoItem->next = temp;
    /*vamos verificar se a tabela esta vazia ou se devemos inserir no começo.
     */
    if(temp == NULL){
        inicio = novoItem;
        return(inicio);
    }
    /*se não for o caso anterior existe e devemos ligar ele ao novoItem,
     *retornado o inicio original*/
    anterior->next = novoItem;
    return(inicio);
}
