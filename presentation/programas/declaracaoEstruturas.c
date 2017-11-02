#include <stdio.h>
#include <stdlib.h>

#define SUCESSO  1
#define FALHA   -1

struct Celula { 
     int      chave;
     int      dado;
     Ponteiro prox;
};  

typedef 
   struct Celula* Ponteiro;

Ponteiro prim; 
