#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_LD.h"

apontador criaStableLD()
{
    apontador inicio = NULL;
    return(inicio);
}
void destroiStableLD(apontador inicio)
{
    apontador prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->bob.palavra);
        /*free(inicio->bob);*/
        free(inicio);
        inicio = prox;
    }
    return;
}
void insereStableLD(char *key ,apontador inicio)
{
    apontador temp, anterior;
    apontador novoItem;
    /*primeiro devemos verificar se a lista esta vazia.*/
    if(!inicio){
        inicio = malloc(sizeof(celula));
        strcpy(key,inicio->bob.palavra);
        inicio->bob.freq = 1;
        inicio->next = NULL;
        return;
    }
    /*como a lista não esta vazia, devemos procurar a palavra na tabela.*/
    anterior = NULL;
    for(temp = inicio; temp != NULL; anterior = temp, temp = temp->next){
        if(!strcmp(key, temp->bob.palavra)){
            temp->bob.freq++;
            return;
        }
    }
    /*se a função chegou até este ponto, percorremos a tabela inteira sem
     *encontar a palavra, assim a iremos inserir no final.
     */
    novoItem = malloc(sizeof(celula));
    strcpy(key,novoItem->bob.palavra);
    novoItem->bob.freq = 1;
    novoItem->next = NULL;
    anterior->next = novoItem;
}
/**/
