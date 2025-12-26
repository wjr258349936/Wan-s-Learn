//
// Created by lenovo on 2025/11/7.
//
#include <stdio.h>
#include <stdlib.h>
#include "Bitree.h"

BiTree *createBiTree() {
    BiTree *tree = (BiTree*)malloc(sizeof(BiTree));
    return tree;
}

void initBiTree(BiTree *tree) {
    BiTreeNode *root = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    tree->root = root;
    root->L_next = NULL;
    root->R_next = NULL;
    root->data = 0;
}

void releaseBiTree(BiTree *tree) {

}

void insertBiTree(BiTree *tree, BiTreeNode *parent, BiTreeNode *left, BiTreeNode *right) {
    parent->L_next = left;
    parent->R_next = right;
    ++tree->Count;
}

static void previsit(BiTreeNode *node){
    if(node==NULL){
        return ;
    }
    printf("%c",node->data);
    previsit(node->L_next);
    previsit(node->R_next);
}

void pre_visitBiTree(BiTree *tree) {
    if(tree==NULL){
        return ;
    }
    previsit(tree->root);
}


