#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bst_init(TrainBST *tree) {
    tree->root = NULL;
    tree->count = 0;
}

/* Insert train in BST (sorted by train number) */
static TrainNode *insert_node(TrainNode *node, Train t) {
    if (node == NULL) {
        TrainNode *new_node = (TrainNode *)malloc(sizeof(TrainNode));
        new_node->data = t;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    if (strcmp(t.train_no, node->data.train_no) < 0) {
        node->left = insert_node(node->left, t);
    } else {
        node->right = insert_node(node->right, t);
    }
    return node;
}

void bst_insert(TrainBST *tree, Train t) {
    tree->root = insert_node(tree->root, t);
    tree->count++;
}

TrainNode *bst_find(TrainBST *tree, char *train_no) {
    TrainNode *node = tree->root;

    while (node != NULL) {
        if (strcmp(train_no, node->data.train_no) == 0) {
            return node;
        }
        if (strcmp(train_no, node->data.train_no) < 0) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return NULL;
}

static TrainNode *find_min(TrainNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

static TrainNode *delete_node(TrainNode *node, char *train_no) {
    TrainNode *temp;

    if (node == NULL) {
        return NULL;
    }

    if (strcmp(train_no, node->data.train_no) < 0) {
        node->left = delete_node(node->left, train_no);
    } else if (strcmp(train_no, node->data.train_no) > 0) {
        node->right = delete_node(node->right, train_no);
    } else {
        if (node->left == NULL) {
            temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL) {
            temp = node->left;
            free(node);
            return temp;
        }
        temp = find_min(node->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data.train_no);
    }
    return node;
}

void bst_delete(TrainBST *tree, char *train_no) {
    if (bst_find(tree, train_no) != NULL) {
        tree->root = delete_node(tree->root, train_no);
        tree->count--;
    }
}

static void show_inorder(TrainNode *node, int *num) {
    if (node == NULL) {
        return;
    }
    show_inorder(node->left, num);
    (*num)++;
    printf("%d. %s - %s | %s to %s | Seats:%d/%d\n",
           *num, node->data.train_no, node->data.name,
           node->data.source, node->data.destination,
           node->data.available_seats, node->data.total_seats);
    show_inorder(node->right, num);
}

void bst_show_all(TrainBST *tree) {
    int num = 0;

    if (tree->root == NULL) {
        printf("No trains.\n");
        return;
    }
    printf("\n--- All Trains (BST) ---\n");
    show_inorder(tree->root, &num);
}

static TrainNode *search_name(TrainNode *node, char *name) {
    TrainNode *result;

    if (node == NULL) {
        return NULL;
    }
    if (strcmp(node->data.name, name) == 0) {
        return node;
    }

    result = search_name(node->left, name);
    if (result != NULL) {
        return result;
    }
    return search_name(node->right, name);
}

TrainNode *bst_find_by_name(TrainBST *tree, char *name) {
    return search_name(tree->root, name);
}

static void free_tree(TrainNode *node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void bst_clear(TrainBST *tree) {
    free_tree(tree->root);
    tree->root = NULL;
    tree->count = 0;
}
