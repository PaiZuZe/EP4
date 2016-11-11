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

stableVO *insereStableVO(char *key, stableVO *stable)
{
    int i,k;
    /*vamos ver antes se a tabela esta vazia ja que srcmp buga*/
    if(stable->ultPos == 0){
        stable->bob[0].palavra = malloc(strlen(key)*sizeof(char));
        strcpy(stable->bob[0].palavra,key);
        stable->bob[0].freq = 1;
        stable->ultPos++;
        return stable;
    }
    /*antes de posivelmente inserir um novo elemento, iremos verificar se a
     *tebala esta cheia.
     */
    if(stable->ultPos == stable->max){
        stable = realocaStableVO(stable);
    }
    /*com uma busca binaria podemos descobrir se o elemento se encontra na
     *tabela e também se a palavra não se encontar podemos descobrir sua posição
     */
    /*esquece a busca binaria*/
    for(i = 0; i < stable->ultPos; i++){
        if(!strcmp(key,stable->bob[i].palavra)){
            stable->bob[i].freq++;
            return stable;
        }
        if(strcmp(key, stable->bob[i].palavra) < 0){
            for(k = stable->ultPos - 1; k >= i; k--){
                stable->bob[k + 1].palavra = malloc(strlen(stable->bob[k].palavra)*sizeof(char));
                strcpy(stable->bob[k + 1].palavra,stable->bob[k].palavra);
                stable->bob[k + 1].freq = stable->bob[k].freq;
            }
            break;
        }
    }
    stable->bob[i].palavra = malloc(strlen(key)*sizeof(char));
    strcpy(stable->bob[i].palavra,key);
    stable->bob[i].freq = 1;
    stable->ultPos++;
    /*
    i = buscaBin(stable, key);
    if(!(stable->bob[i].palavra == NULL)){
        if(strcmp(key, stable->bob[i].palavra)){
            stable->bob[i].freq++;
            return stable;
        }
    }
    for(k = stable->ultPos - 1; k > i; k--){
        stable->bob[k + 1].palavra = malloc(strlen(stable->bob[k].palavra)*sizeof(char));
        strcpy(stable->bob[k + 1].palavra,stable->bob[k].palavra);
        stable->bob[k + 1].freq = stable->bob[k].freq;
    }
    stable->bob[i + 1].palavra = malloc(strlen(key)*sizeof(char));
    strcpy(stable->bob[i + 1].palavra,key);
    stable->bob[i +1].freq = 1;
    printf("%s\n", stable->bob[i + 1].palavra);
    stable->ultPos++;
    */
    /*deve estar errado*/
    /*como é possivel que adicionamos um iten na ultima possição, devemos
     *atualizar ultPos caso nescessario

    if(stable->ultPos == i + 1)
        stable->ultPos++;
    */
    return stable;
}

stableVO *realocaStableVO(stableVO *stable)
{
    stableVO *stableNova;
    int i;
    stableNova = malloc(sizeof(stableVO));
    stableNova->max = stable->max*2;
    stableNova->ultPos = stable->ultPos;
    stableNova->bob = malloc(stableNova->max*sizeof(dataVO));
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
        else if(temp < 0) inicio = meio + 1;
        else fim = meio;
    }
    return inicio;
}
