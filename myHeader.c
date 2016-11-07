#include<stdlib.h>
#include<myHeader.h>

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
    for(i = 0; i < B->max; i++)
        novoBuffer->palavra[i] = B->palavra[i];
    free(B);
    B = novoBuffer;
    return;
}
void adicionaNoBuffer(Buffer *B, char c)
{
    if(B->top == B->max)
        realocaBuffer(B);
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
    B->top = 0;
    return;
}
