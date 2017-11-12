#include "2-3-tree.h"

/********** 23tree_alloc **********/
23tree *23tree_alloc() {
  23tree *tree;
  23tree_node *root;

  tree = malloc(sizeof(23tree));
  tree->n = 0;
  root = tree->root = malloc(sizeof(23tree_node));
  tree->stack = malloc(STACK_SIZE * sizeof(23tree_node *));
  root->key1 = r->key2 = 0;
  root->link_kind = LEAF;
  root->left->node = root->middle->node = root->right->node = NULL;

  return tree;
}

/********** 23tree_free **********/
void 23tree_free(23tree *tree) {
  int tos;
  23tree_node *p, *stack;

  stack = malloc(2 * STACK_SIZE * sizeof(23tree_node *));
  stack[0] = tree->root;
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

  free(tree->stack);
  free(tree);
}

/********** 23tree_insert **********/
void *23tree_insert(23tree *tree, int item) {

    23tree_node *temp = NULL;
    23tree_node *temp2 = NULL;

    if(tree->n == 0) {
        tree->root->key1 = item;
        tree->root->n++;
    }
    else {
        //only root node with one key
        if(tree->n == 1) {
            if(item > tree->root->key1) {
                tree->root->key2 = tree->root->key1;
                tree->root->key1 = item;
            } else {
                tree->root->key2 = item;
            }
        }

        //only root node with two keys
        else if(tree->n == 2) {
            temp = malloc(sizeof(*23_node));
            temp->key1 = temp->key2 = 0;
            temp->left = temp->middle = temp->right = NULL;
            temp->link_kind = LEAF;

            temp2 = malloc(sizeof(*23_node));
            temp2->key1 = temp2->key2 = 0;
            temp2->left = temp2->middle = temp2->right = NULL;
            temp->link_kind = LEAF;

            if(item < tree->root->key1) {
                temp->key1 = item;
                temp2->key1 = tree->root->key2;
                tree->root->key2 = 0;
            } else if (item < tree->root->key2) {
                temp->key1 = tree->root->key1;
                temp2->key1 = tree->root->key2;
                tree->root->key1 = item;
                tree->root->key2 = 0;
            } else {
                temp->key1 = tree->root->key1;
                temp2->key1 = item;
                tree->root->key1 = tree->root->key2;
                tree->root->key2 = 0;
            }
            tree->root->left = temp;
            tree->root->right = temp2;
        }

        //tree has more than 2 keys
        else {
            if(item < tree->root->key1) {
                
            } else if item < tree->root->key2) {

            } else {

            }
        }

        tree->n++;
    }
}

/********** 23tree_find **********/
void *23tree_find(23tree *tree, int key_item) {

}

/********** 23tree_find_min **********/
void *23tree_find_min(23tree *tree) {
  return t->min_item;
}
