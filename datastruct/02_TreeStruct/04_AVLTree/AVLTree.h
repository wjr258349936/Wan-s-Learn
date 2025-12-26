//
// Created by lenovo on 2025/12/21.
//

#ifndef DATASTRUCT_AVLTREE_H
#define DATASTRUCT_AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

#define element_t int

typedef struct avlnode{
    element_t data;
    struct avlnode*left;
    struct avlnode*right;
}AVLNode;

typedef struct avltree{
    AVLNode* root;
    int count;
}AVLTree;

AVLTree *createAVLTree();
void initAVLTree(AVLTree *tree);
AVLNode *createAVLNode(element_t data);

void linkAVLNode(AVLNode *parent,AVLNode *left,AVLNode *right);

void insertAVLTree(AVLTree *tree,AVLNode* node);

#endif //DATASTRUCT_AVLTREE_H
