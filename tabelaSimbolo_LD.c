#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_LD.h"

apontadorLD criaStableLD()
{
    apontadorLD inicio = NULL;
    return(inicio);
}
void destroiStableLD(apontadorLD inicio)
{
    apontadorLD prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->bob.palavra);
        free(inicio);
        inicio = prox;
    }
    return;
}
void insereStableLD(char *key ,apontadorLD inicio)
{
    apontadorLD temp, anterior;
    apontadorLD novoItem;
    /*primeiro devemos verificar se a lista esta vazia.*/
    if(!inicio){
        inicio = malloc(sizeof(celulaLD));
        inicio->bob.palavra = malloc(strlen(key)*sizeof(char));
        strcpy(inicio->bob.palavra, key);
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
    novoItem = malloc(sizeof(celulaLD));
    novoItem->bob.palavra = malloc(strlen(key)*sizeof(char));
    strcpy(novoItem->bob.palavra, key);
    novoItem->bob.freq = 1;
    novoItem->next = NULL;
    anterior->next = novoItem;
}
/**/
