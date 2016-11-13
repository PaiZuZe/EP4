/*Nome: Victor Chiaradia Gramuglia Araujo
 *nºUSP:9793756
 */
#include<stdlib.h>
#include<string.h>
#include<myHeader.h>
void mergeSortM(int inicio, int fim, data *V, char *tipoOrd)
{
    int meio;
    if (inicio < fim - 1) {
        meio = (inicio + fim)/2;
        mergeSortM(inicio, meio, V, tipoOrd);
        mergeSortM(meio, fim, V, tipoOrd);
        mergeM(inicio, meio, fim, V, tipoOrd);
    }
}

void mergeM(int inicio, int meio, int fim, data *V, char *tipoOrd)
{
    int i, j, k;
    data *w;
    w = malloc ((fim - inicio) * sizeof (data));
    i = inicio; j = meio;
    k = 0;
    while (i < meio && j < fim) {
        if(!strcmp(tipoOrd, "A")){
            if (strcmp(V[i].palavra,V[j].palavra) <= 0){
                w[k].palavra = malloc(strlen(V[i].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[i].palavra);
                w[k].freq = V[i].freq;
                k++;
                i++;
            }
            else{
                w[k].palavra = malloc(strlen(V[j].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[j].palavra);
                w[k].freq = V[j].freq;
                k++;
                j++;
            }
        }
        else{
            if (V[i].freq <=  V[j].freq){
                w[k].palavra = malloc(strlen(V[i].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[i].palavra);
                w[k].freq = V[i].freq;
                k++;
                i++;
            }
            else{
                w[k].palavra = malloc(strlen(V[j].palavra)*sizeof(char));
                strcpy(w[k].palavra, V[j].palavra);
                w[k].freq = V[j].freq;
                k++;
                j++;
            }
        }
    }
    while (i < meio){
        w[k].palavra = malloc(strlen(V[i].palavra)*sizeof(char));
        strcpy(w[k].palavra, V[i].palavra);
        w[k].freq = V[i].freq;
        k++;
        i++;
    }

    while (j < fim){
        w[k].palavra = malloc(strlen(V[j].palavra)*sizeof(char));
        strcpy(w[k].palavra, V[j].palavra);
        w[k].freq = V[j].freq;
        k++;
        j++;
    }
    for (i = inicio; i < fim; ++i){
        V[i].palavra = malloc(strlen(w[i - inicio].palavra)*sizeof(char));
        strcpy(V[i].palavra, w[i - inicio].palavra);
        V[i].freq = w[i - inicio].freq;
    }
    free (w);
}
Buffer *criaBuffer()
{
    Buffer *B = malloc(sizeof(Buffer));
    B->max = 8;
    B->top = 0;
    B->palavra = malloc(B->max*sizeof(char));
    return B;
}
void realocaBuffer(Buffer *B)
{
    int i;
    Buffer *novoBuffer = malloc(sizeof(Buffer));
    novoBuffer->max = 2*B->max;
    novoBuffer->top = B->top;
    novoBuffer->palavra = malloc(novoBuffer->max*sizeof(char));
    for(i = 0; i < B->max; i++)
        novoBuffer->palavra[i] = B->palavra[i];
    free(B->palavra);
    B->max = novoBuffer->max;
    B->palavra = novoBuffer->palavra;
    return;
}
void adicionaNoBuffer(Buffer *B, char c)
{
    /*antes de adicionadar no buffer presisamos ver se ele esta cheio.
     */
    if(B->top == B->max) realocaBuffer(B);
    B->palavra[B->top] = c;
    B->top++;
    return;
}
void destroiBuffer(Buffer *B)
{
    free(B->palavra);
    free(B);
    return;
}
void clearBuffer(Buffer *B)
{
    /*para "resetar" o buffer só é nescessario mudar o seu topo para 0.
     */
    B->top = 0;
    return;
}
