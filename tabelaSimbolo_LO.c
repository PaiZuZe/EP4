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
        free(inicio->bob.palavra);
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
