no23 *quebraNo(no23 *no, int val, int *rval, no23 *subarvore){
    no23 *paux;

    if (val > no->rkey) {  // val esta mais a direita
       *rval = no->rkey;   // promove a antiga maior
       paux = no->right;
       no->right = NULL;   // elimina o terceiro filho
       no->nkeys = 1;      // atualiza o n�mero de chaves
       return criaNo(val, 0, 1, paux, subarvore, NULL);
    } else if (val >= no->lkey){ // val esta no meio
       *rval = val;        // continua sendo promovido
       paux = no->right;
       no->right = NULL;
       no->nkeys = 1;
       return criaNo(no->rkey, 0, 1, subarvore, paux, NULL);
    } else {              // val esta a mais a esquerda
       *rval = no->lkey;
       // primeiro cria o n� a direita
       paux = criaNo(no->rkey, 0, 1, no->center, no->right, NULL);
       no->lkey = val;   // em seguida arruma o n� a esquerda
       no->nkeys = 1;
       no->right = NULL;
       no->center = subarvore;
       return paux;
    }
}