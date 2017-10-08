#include "2-3-tree.h"

/********** 23tree_alloc **********/
23tree *23tree_alloc() {
  23tree *t;
  23tree_node *r;

  t = malloc(sizeof(23tree));
  t->n = 0;
  t->min_item = NULL;
  t->stack = malloc(STACK_SIZE * sizeof(23tree_node *));
  r = t->root = malloc(sizeof(23tree_node));
  r->key1 = r->key2 = NULL;
  r->link_kind = LEAF;
  r->left.item = r->middle.item = r->right.item;

  return t;
}

/********** 23tree_free **********/
void 23tree_free(23tree *t) {
  int tos;
  23tree_node *p, *stack;

  stack = malloc(2 * STACK_SIZE * sizeof(23tree_node *));
  stack[0] = t->root;
  tos = 1;

  while(tos) {
    p = stack[--tos];
    if(p->link_kind == INTERNAL) {
      stack[tos++] = p->left.node;
      stack[tos++] = p->middle.node;
      if(p->right.node) stack[tos++] = p->right.node;
    }
    free(p);
  }

  free(stack);

  free(t->stack);
  free(t);
}

/********** 23tree_insert **********/
void *23tree_insert(23tree *t, int *item) {

    //comparar item com a esquerda
    //checar se já existe chave com o mesmo valor
    //se já existir, retornar o endereço do já existente
    //senão, definir se o valor será inserido no meio(item maior que o da esquerda) ou na esquerda
}

/********** 23tree_find **********/
void *23tree_find(23tree *t, int key_item) {

}

/********** 23tree_find_min **********/
void *23tree_find_min(23tree *t) {
  return t->min_item;
}
