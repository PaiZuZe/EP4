#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_LD.h"

apontador criaStableLD()
{
    apontador inicio;
    inicio = malloc(sizeof(celula));
    inicio->bob = malloc(sizeof(celula));
    return(inicio);
}
void destroiStableLD(apontador inicio)
{
    apontador prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->bob->palavra);
        free(inicio->bob);
        free(inicio);
        inicio = prox;
    }
    return;
}
apontador insereStableLD(char *key ,apontador inicio)
{
    
}
