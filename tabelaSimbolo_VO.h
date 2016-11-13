#ifndef __TABELASIMBOLO_VO_H__
#define __TABELASIMBOLO_VO_H__
/*esta função recebe uma tabela de simbolos feita com vetor dinamico e a imprime
 *na saida padrão em ordem de frequencia.
 */
void imprimeVO_A(stableV *stable);
/*Função que ira criar e devolver um ponteiro para uma tabela de simbolos que
 *usa um vetor desordenado.
 */
void imprimeVO_O(stableV *stable);
/*Função que ira criar e devolver um ponteiro para uma tabela de simbolos que
*usa um vetor ordenado.
 */
stableV *criaStableVO();

/*Função que receve uma de simbolos que usa um vetor ordenado e ira destruir ela.
 */
void destroiStableVO(stableV *stable);

/*Função que recebe uma string, uma tamabela de simbolos e ira inserir essa
 *palavra na tabela, a inserção ira manter a tabela ordenada, se a palavra já
 *estiver na tabela a função só ira acrecentar a frequencia dela, se a tabela se
 *encontar cheia a funçao ira chamar a função realocastableV.
 */
stableV *insereStableVO(char *key, stableV *stable);

/*Função que recebe uma tabela de simbolos e ira criar uma outra tabela de
 *simbolos com os mesmos itens porem com o dobro so tamanho da original.
 */
stableV *realocaStableVO(stableV *stable);

/*Função recebe uma tabela de simbolos ordenada, uma string e retorna o valor
 *da posição se a string estiver na tabela e -1 se não se encontar; buscaBin
 *modificada para ser usada em string's e não números
 */
#endif
