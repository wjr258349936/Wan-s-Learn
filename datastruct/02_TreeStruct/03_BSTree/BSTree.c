//
// Created by lenovo on 2025/11/14.
//

#include <stdlib.h>
#include <stdio.h>
#include "BSTree.h"

BSTree *createBSTree() {
    BSTree *tree = malloc(sizeof(BSTree));
    tree->root=NULL;
    tree->count=0;
    return tree;
}

static void freeNode(BSTree *tree,BSTreeNode *node){
    if(node==NULL){
        return;
    }
    freeNode(tree,node->left);
    freeNode(tree,node->right);
    free(node);
    tree->count--;
}

void releaseBSTree(BSTree *tree) {
    if(tree == NULL){
        return;
    }
    freeNode(tree,tree->root);
    printf("BSTree have lost %d node\n",tree->count);
    free(tree);
}

static BSTreeNode *createBSTreeNode(element_t data){
    BSTreeNode* node = malloc(sizeof(BSTreeNode));
    if (node == NULL) {
        return NULL;
    }
    node->left = node->right = NULL;
    node->data = data;
    return node;
}

static BSTreeNode *insertBSNode(BSTree *tree,BSTreeNode *node,element_t data){
    if(node == NULL){
        tree->count++;
        return createBSTreeNode(data);
    }
    if (data < node->data) {
        node->left = insertBSNode(tree, node->left, data);
    } else if (data > node->data) {
        node->right = insertBSNode(tree, node->right, data);
    }
    return node;
}

void insertBSTreeNode(BSTree *tree,element_t data) {
    if (tree == NULL) {
        return;
    }
    tree->root = insertBSNode(tree,tree->root,data);
}

BSTreeNode *searchBSTreeNode(BSTree *tree, element_t data) {
    if(tree == NULL ){
        return NULL;
    }
    BSTreeNode *current = tree->root;
    while(current){
        if(data>current->data){
            current = current->right;
        }else if(data<current->data){
            current = current->left;
        }else if(data == current->data){
            return current;
        }
    }
    return NULL;
}

void visitBSTreeNode(BSTreeNode *node) {
    if(node == NULL){
        return ;
    }
    printf("%d ",node->data);
}

static int heightBSNode(BSTreeNode *node){
    if(node==NULL){
        return 0;
    }
    int left = heightBSNode(node->left);
    int right = heightBSNode(node->right);
    return (left > right)? left  +1: right + 1;
}

int heightBSTree(const BSTree *tree) {
    if(tree == NULL){
        return 0;
    }
    return heightBSNode(tree->root);
}

static void inOrderTree(BSTreeNode *node){
    if(node == NULL){
        return;
    }
    inOrderTree(node->left);
    visitBSTreeNode(node);
    inOrderTree(node->right);
}

void InOrderBSTree(BSTree *tree) {
    if(tree==NULL){
        return ;
    }
    printf("BSTree[%d] : ",tree->count);
    inOrderTree(tree->root);
    printf("\n");
}
