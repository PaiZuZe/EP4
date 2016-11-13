#ifndef __TABELASIMBOLO_LD_H
#define __TABELASIMBOLO_LD_H

typedef struct noLD {
                    data info;
                    struct noLD *next;
                    }celulaLD;

typedef celulaLD *apontadorLD;

/*esta função uma tabela de simbolos que usa uma Lista ligada e conta o números
 *de elementos presentes nela.
 */
int nElementosLD(apontadorLD inicio);
/*esta função uma tabela de simbolos que usa uma Lista ligada e ira criar um
 *vetor com os elementos desta tabela.
 */
data *LDtoVD(apontadorLD inicio);
/*esta função recebe uma tabela de simbolos feita com lista ligada e a imprime
 *na saida padrão em ordem alfabetica.
 */
void imprimeLD_A(apontadorLD stable);
/*esta função recebe uma tabela de simbolos feita com lista ligada e a imprime
 *na saida padrão em ordem de frequencia.
 */
void imprimeLD_O(apontadorLD stable);
/*função cria uma variavel com o começo da tabela de simbolos.
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
