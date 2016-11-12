#ifndef __TABELASIMBOLO_LD_H
#define __TABELASIMBOLO_LD_H

typedef struct{
                char *palavra;
                int freq;
                } dataLD;
typedef struct noLD {
                    dataLD info;
                    struct noLD *next;
                    }celulaLD;

typedef celulaLD *apontadorLD;

int nElementosLD(apontadorLD inicio);

dataLD *LDtoVD(apontadorLD inicio);

void mergeSortLD(int inicio, int fim, dataLD *V, char *tipoOrd);

void mergeLD(int inicio, int meio, int fim, dataLD *V, char *tipoOrd);

/*função cria uma variavel com o começo da lista.
 */
apontadorLD criaStableLD();

/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLD(apontadorLD inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no fim da tabela se ela não se encontar na tabela, se o ultímo for
 *verdade a função ira aumentar a frequencia da palavra.
 */
apontadorLD insereStableLD(char *key ,apontadorLD inicio);

#endif
