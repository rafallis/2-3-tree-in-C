#ifndef COMMON_H
#define COMMON_H

#include "common.h"
#include "../2-3-tree-lib/2-3-tree.h"

23tree tree;

// alloc test
void alloc_test() {
    tree = 23tree_alloc();

    assert(tree->n == 0);
    assert(tree->root->key1 == 0);
    assert(tree->root->key2 == 0);
    assert(tree->root->link_kind == LEAF);
    assert(tree->root->left.item == NULL);
    assert(tree->root->middle.item == NULL);
    assert(tree->root->right.item == NULL);

    PRINT_SUCCESS();
}

// free test
void free_test() {
    23tree_free(&tree);

    assert(root == NULL);
    PRINT_SUCCESS();
}

#endif
