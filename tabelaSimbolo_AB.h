#ifndef __TABELASIMBOLO_AB_H
#define __TABELASIMBOLO_AB_H
typedef struct{
                char *palavra;
                int freq;
                } dataAB;

typedef struct noAB{
                dataAB info;
                struct noAB *esq;
                struct noAB *dir;
                } celulaAB;

typedef celulaAB *apontadorAB;

/*função recursiva que recebe uma tabela de simbolo que usa ABB's e imprime ela
 *em ordem alfabetica.
 */
void imprimeAB_A(apontadorAB stable);
/*cria uma tabela de simbolos usando arvore de busca binaria, a função devolve
 *o inicio desta arvore.
 */
apontadorAB criaStableAB();
/*esta função recebe o inicio de uma ABB e destroi uma tabela de simbolos que
 *usa uma arvore de busca binaria.
 */
void destroiStableAB(apontadorAB inicio);
/*esta função recebe o começo de uma ABB e uma string, a função ira percorrer a
 *ABB e ira adicionar a string na arvore, se a string ja se encontrar nela, so
 *sua frequencia ira mudar, a função devolve a começo da arvore.
 */
apontadorAB insereStableAB(char *key, apontadorAB inicio);

#endif
