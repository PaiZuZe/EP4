/*Nome: Victor Chiaradia Gramuglia Araujo
 *nºUSP:9793756
 */
#ifndef __TABELASIMBOLO_LD_H
#define __TABELASIMBOLO_LD_H

/*esta função uma tabela de simbolos que usa uma Lista ligada e conta o números
 *de elementos presentes nela.
 */
int nElementosLD(apontadorLG inicio);
/*esta função uma tabela de simbolos que usa uma Lista ligada e ira criar um
 *vetor com os elementos desta tabela.
 */
data *LDtoVD(apontadorLG inicio);
/*esta função recebe uma tabela de simbolos feita com lista ligada e a imprime
 *na saida padrão em ordem alfabetica.
 */
void imprimeLD_A(apontadorLG stable);
/*esta função recebe uma tabela de simbolos feita com lista ligada e a imprime
 *na saida padrão em ordem de frequencia.
 */
void imprimeLD_O(apontadorLG stable);
/*função cria uma variavel com o começo da tabela de simbolos.
 */
apontadorLG criaStableLD();
/*função recebe o inicio da tabela de simbolos e ira desalocar a memória de
 *todos seus elementos.
 */
void destroiStableLD(apontadorLG inicio);
/*função recebe o inicio da tabela de simbolos e uma string e ira inserir essa
 *string no fim da tabela se ela não se encontar na tabela, se o ultímo for
 *verdade a função ira aumentar a frequencia da palavra.
 */
apontadorLG insereStableLD(char *key ,apontadorLG inicio);

#endif
