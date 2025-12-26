//
// Created by lenovo on 2025/12/21.
//

#include "AVLTree.h"

AVLTree *createAVLTree() {
    AVLTree* tree = malloc(sizeof(AVLTree));
    if(tree==NULL){
        return NULL;
    }
    initAVLTree(tree);
    return tree;
}

AVLNode *createAVLNode(element_t data) {
    AVLNode *node = malloc(sizeof(AVLNode));
    if(node==NULL){
        return NULL;
    }
    node->data=data;
    node->right==NULL;
    node->left==NULL;
    return node;
}

void initAVLTree(AVLTree *tree) {
    tree->root==NULL;
    tree->count==0;
}

void linkAVLNode(AVLNode *parent, AVLNode *left, AVLNode *right) {
    parent->left=left;
    parent->right=right;
}
