no23 *find(no23 *raiz, int key) {
    if (raiz==NULL)
        return NULL;      // n�o encontrou
    if (key == raiz->lkey)
        return raiz;      // � a chave esquerda
    if ((raiz->nkeys == 2) && (key == raiz->rkey))
        return raiz;      // � a chave direita
    if (key < raiz->lkey)
        return find(raiz->left, key);
    else if (raiz->nkeys == 1)
        return find(raiz->center, key);
    else if (key < raiz->rkey)
        return find(raiz->center, key);
    else
        return find(raiz->right, key);
}