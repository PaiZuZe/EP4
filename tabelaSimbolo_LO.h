#ifndef __TABELASIMBOLO_LO_H
#define __TABELASIMBOLO_LO_H

typedef struct{
                char *palavra;
                int freq;
                } dataLO;
typedef struct noLO {
                    dataLO info;
                    struct noLO *next;
                    }celulaLO;

typedef celulaLO *apontadorLO;

int nElementosLO(apontadorLO inicio);

dataLO *LOtoVD(apontadorLO inicio);

void mergeSortLO(int inicio, int fim, dataLO *V, char *tipoOrd);

void mergeLO(int inicio, int meio, int fim, dataLO *V, char *tipoOrd);

/*função cria uma variavel com o começo da lista.
 */
apontadorLO criaStableLO();
/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLO(apontadorLO inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no local que ira deixar a tabela ordenada se ela não se encontar na
 tabela, se o ultímo for verdade a função ira aumentar a frequencia da palavra,
 a função devolve o inicio da tabela pois ele pode mudar;
 */
apontadorLO insereStableLO(char *key ,apontadorLO inicio);

#endif
