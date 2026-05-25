#ifndef BST_H
#define BST_H

#include "types.h"

typedef struct {
    TrainNode *root;
    int count;
} TrainBST;

void bst_init(TrainBST *tree);
void bst_insert(TrainBST *tree, Train t);
TrainNode *bst_find(TrainBST *tree, char *train_no);
void bst_delete(TrainBST *tree, char *train_no);
void bst_show_all(TrainBST *tree);
TrainNode *bst_find_by_name(TrainBST *tree, char *name);
void bst_clear(TrainBST *tree);

#endif
