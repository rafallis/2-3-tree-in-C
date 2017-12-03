// insere val em no (se necessario retorna o novo no e um valor
// rval)
no23 *insere( no23 **no, int val, int *rval){
    no23 *paux, *paux2;
    int   vaux, promov;

    if (*no == NULL) {    // arvore vazia
       *no = (no23 *) malloc (sizeof(no23));
       *no = criaNo(val, 0, 0, NULL, NULL, NULL); 
             // cria no folha com um valor 
       return NULL;       // nada a fazer depois
    }
    if (isLeaf(*no)){     // chegou a folha
       if ((*no)->nkeys == 1){ // caso f�cil
          adicionaChave(*no, val, NULL);
          return NULL;
       } else {
          paux = quebraNo(*no, val, &vaux, NULL);
          *rval = vaux;
          return paux;
       }
    } else {             // continua a procura
       if (val < (*no)->lkey)
          paux = insere( &((*no)->left), val, &vaux);
       else if (((*no)->nkeys == 1) || (val < (*no)->rkey))
          paux = insere( &((*no)->center), val, &vaux);
       else   
          paux = insere( &((*no)->right), val, &vaux);
       if (paux == NULL) // nao promoveu
          return NULL;
       else
          if ((*no)->nkeys == 1){
             adicionaChave(*no, vaux, paux);
             return NULL;
          } else {
             paux2 = quebraNo(*no, vaux, &promov, paux);
             *rval = promov;
             return paux2;
          }
     }
}
