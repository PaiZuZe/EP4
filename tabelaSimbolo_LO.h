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

/*esta função uma tabela de simbolos que usa uma Lista ligada e conta o números
 *de elementos presentes nela.
 */
int nElementosLO(apontadorLO inicio);
/*esta função uma tabela de simbolos que usa uma Lista ligada e ira criar um
 *vetor com os elementos desta tabela.
 */
dataLO *LOtoVD(apontadorLO inicio);
/*esta é uma função de mergeSort que ira ordenar um vetor de uma struct, a
 *ordenação é por frequencia.
 */
void mergeSortLO(int inicio, int fim, dataLO *V, char *tipoOrd);
/*função de merge modificada.
 */
void mergeLO(int inicio, int meio, int fim, dataLO *V, char *tipoOrd);
/*esta função recebe uma tabela de simbolos feita com lista ligada e a imprime
 *na saida padrão em ordem alfabetica.
 */
void imprimeLO_A(apontadorLO stable);
/*esta função recebe uma tabela de simbolos feita com lista ligada e a imprime
 *na saida padrão em ordem de frequencia.
 */
void imprimeLO_O(apontadorLO stable);
/*função cria uma variavel com o começo da tabela de simbolos.
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
