#ifndef __MYHEADER_H__
#define __MYHEADER_H__
typedef struct {
                char *palavra;
                int max;
                int top;
                }Buffer;
Buffer *criaBuffer();
void realocaBuffer(Buffer *B);
void adicionaNoBuffer(Buffer *B, char c);
void destroiBuffer(Buffer *B);
void clearBuffer(Buffer *B);
#endif
