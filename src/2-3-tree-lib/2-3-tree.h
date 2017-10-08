#ifndef NCURSES_FUNCTIONS
#define NCURSES_FUNCTIONS

#include "../common.h"

#define STACK_SIZE 1000

/**
 * 2-3 tree have two types of pointer nodes.
 * Those who pointes to leaf and those who points to other nodes.
 *
 * @node points to a 2-3 tree node.
 * @item item value of a node.
 */
struct 23tree_node;
typedef struct _23tree_link {
  struct 23tree_node *node;  //internal node
  int item;
} 23tree_link;

/**
 * @key1 points to items with the smallest key in the middle-child.
 * @key2 points to items with the smallest key in the right-child (NULL if not exists).
 * @left, @middle, @right stores the 3 possible paths of itens.
 * @link_kink defines if node is leaf or internal.
 */
typedef struct _23tree_node {
  int *key1, *key2;
  23tree_link left, middle, right;
  enum { LEAF, INTERNAL } link_kind;
} 23tree_node;

/**
 * @root points to the root node.
 * @n number of data items stored.
 * @min_item points to the minimum item in the tree.
 * @stack stack of items in the tree.
 */
typedef struct _23tree {
  23tree_node *root;
  int n;
  int *min_item;
  23tree_node **stack;
} 23tree;

/**
 * Allocates instances of 2-3 tree and returns a poninter to it
 */
23tree *23tree_alloc();

/**
 * Frees space used by the 2-3 tree.
 */
void 23tree_free(23tree *t);

/**
 * Inserts an item to 2-3 tree.
 * If the item already is in the tree, the function returns
 * the pointer to the existent item.
 */
void *23tree_insert(23tree *t, int *item);

void *23tree_find(23tree *t, int key_item);

void *23tree_find_min(23tree *t);

void *23tree_delete(23tree *t, int key_item);

void *23tree_delete_min(23tree *t);

#endif
