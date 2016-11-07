#include<stdlib.h>
#include<string.h>
#include"tabelaSimbolo_VO.h"

stableVO *criaStableVO()
{
    stableVO *stable = malloc(sizeof(stableVO));
    stable->max = 16;
    stable->ultPos = 0;
    stable->bob = malloc(stable->max*sizeof(dataVO));
    return(stable);
}

void destroiStableVO(stableVO *stable)
{
    int i;
    for(i = 0; i < stable->ultPos; i++)
        free(stable->bob[i].palavra);
    free(stable->bob);
    free(stable);
    return;
}

void insereStableVO(char *key, stableVO *stable)
{
    int i,k;
    /*antes de posivelmente inserir um novo elemento, iremos verificar se a
     *tebala esta cheia.
     */
    if(stable->ultPos == stable->max){
        stable = realocaStableVO(stable);
    }
    /*com uma busca binaria podemos descobrir se o elemento se encontra na
     *tabela e também se a palavra não se encontar podemos descobrir sua posição
     */
    i = buscaBin(stable, key);
    if(strcmp(key,stable->bob[i].palavra)){
        stable->bob[i].freq++;
        return;
    }
    for(k = stable->ultPos - 1; k > i;k--){
        stable->bob[k + 1].palavra = malloc(strlen(stable->bob[k].palavra)*sizeof(char));
        strcpy(stable->bob[k + 1].palavra,stable->bob[k].palavra);
        stable->bob[k + 1].freq = stable->bob[k].freq;
    }
    stable->bob[i + 1].palavra = malloc(strlen(key)*sizeof(char));
    strcpy(stable->bob[i + 1].palavra,key);
    /*como é possivel que adicionamos um iten na ultima possição, devemos
     *atualizar ultPos caso nescessario
     */
    if(stable->ultPos == i + 1)
        stable->ultPos++;
    return;
}

stableVO *realocaStableVO(stableVO *stable)
{
    stableVO *stableNova;
    int i;
    stableNova = criaStableVO(stable->max*2);
    stableNova->ultPos = stable->ultPos;
    /*ao dobrarmos o tamanho garantimos que não iremos fazer essa operação
     *muitas vezes
     */
    for(i = 0; i < stable->ultPos; i++){
        stableNova->bob[i].freq = stable->bob[i].freq;
        stableNova->bob[i].palavra = malloc(strlen(stable->bob[i].palavra)*sizeof(char));
        strcpy(stableNova->bob[i].palavra, stable->bob[i].palavra);
    }
    destroiStableVO(stable);
    return(stableNova);
}

int buscaBin(stableVO *stable, char *key)
{
    int inicio, meio, fim, temp;
    inicio = 0;
    fim = stable->ultPos -1;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        temp = strcmp(key, stable->bob[meio].palavra);
        if(temp == 0) return(meio);
        else if(temp == 1) inicio = meio + 1;
        else fim = meio - 1;
    }
    return fim;
}
