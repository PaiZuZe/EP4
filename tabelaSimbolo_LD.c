/*Nome: Victor Chiaradia Gramuglia Araujo
 *nºUSP:9793756
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myHeader.h"
#include"tabelaSimbolo_LD.h"
data *LDtoVD(apontadorLG inicio){
    int j;
    apontadorLG i;
    data *V = NULL;
    V = malloc(nElementosLG(inicio)*sizeof(data));
    for(i = inicio, j = 0; i != NULL; i = i->next, j++){
        V[j].palavra = malloc(strlen(i->info.palavra)*sizeof(char));
        strcpy(V[j].palavra, i->info.palavra);
        V[j].freq = i->info.freq;
    }
    return V;
}
void imprimeLD_A(apontadorLG stable)
{
    int i;
    data *V;
    /*como ordenar uma lista ligada é muito dificil iremos criar um vetor com
     *os elementos da tabela e ordenalo em NlogN.
     */
    V = LDtoVD(stable);
    mergeSortM(0, nElementosLG(stable), V, "A");
    for(i = 0; i < nElementosLG(stable); i++){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    /*vamos destruir nosso vetor auxiliar;
     */
    for(i = 0; i < nElementosLG(stable); i++)
        free(V[i].palavra);
    free(V);
    return;
}
void imprimeLD_O(apontadorLG stable)
{
    int i;
    data *V;
    /*como ordenar uma lista ligada é eneficiente iremos criar um vetor com
     *os elementos da tabela e ordenalo em NlogN usando um mergeSort modificado
     *iremos ordenar o vetor por ordem alfabetica para que quando formos
     *imprimir o vetor as palavras "menores" tomem prescedencia se tiverem a mesma
     *frequencia, como iremos usar um sort estavel isso é garantido.
     */
    V = LDtoVD(stable);
    mergeSortM(0, nElementosLG(stable), V, "A");
    mergeSortM(0, nElementosLG(stable), V, "O");
    for(i = nElementosLG(stable) -1; i >= 0; i--){
        printf("%s ", V[i].palavra);
        printf("%d\n", V[i].freq);
    }
    /*vamos destruir nosso vetor auxiliar;
     */
    for(i = 0; i < nElementosLG(stable); i++)
        free(V[i].palavra);
    free(V);
    return;
}
apontadorLG criaStableLD()
{
    apontadorLG inicio = NULL;
    return(inicio);
}
void destroiStableLD(apontadorLG inicio)
{
    apontadorLG prox;
    while(inicio != NULL){
        prox = inicio->next;
        free(inicio->info.palavra);
        free(inicio);
        inicio = prox;
    }
    return;
}
apontadorLG insereStableLD(char *key ,apontadorLG inicio)
{
    apontadorLG temp, anterior;
    apontadorLG novoItem;
    /*primeiro devemos verificar se a lista esta vazia.*/
    if(!inicio){
        inicio = malloc(sizeof(celulaLG));
        inicio->info.palavra = malloc(strlen(key)*sizeof(char));
        strcpy(inicio->info.palavra, key);
        inicio->info.freq = 1;
        inicio->next = NULL;
        return inicio;
    }
    /*como a lista não esta vazia, devemos procurar a palavra na tabela.*/
    anterior = NULL;
    for(temp = inicio; temp != NULL; anterior = temp, temp = temp->next){
        if(!strcmp(key, temp->info.palavra)){
            /*strcmp retorna 0 se duas strings forem iguais, assim basta
             *aumentar a frequencia e sair da função.
             */
            temp->info.freq++;
            return inicio;
        }
    }
    /*se a função chegou até este ponto, percorremos a tabela inteira sem
     *encontar a palavra, assim a iremos inserir a nova palavra no final.
     */
    novoItem = malloc(sizeof(celulaLG));
    novoItem->info.palavra = malloc(strlen(key)*sizeof(char));
    strcpy(novoItem->info.palavra, key);
    novoItem->info.freq = 1;
    novoItem->next = NULL;
    anterior->next = novoItem;
    return inicio;
}
