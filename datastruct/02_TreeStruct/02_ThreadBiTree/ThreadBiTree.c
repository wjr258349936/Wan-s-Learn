//
// Created by lenovo on 2025/11/12.
//
#include <stdio.h>
#include <stdlib.h>
#include "ThreadBiTree.h"

ThreadBiTree *createThreadBiTree() {
    ThreadBiTree *tree = malloc(sizeof (ThreadBiTree));
    if(tree){
        tree->root=NULL;
        tree->count = 0;
    }
    return tree;
}

void initThreadTree(ThreadBiTree *tree, TreeNode *root) {
    if(tree&&tree->root == NULL){
        tree->root=root;
        tree->count = 1;
    }
}

TreeNode *createTreeNode(element_t data) {
    TreeNode *node = malloc(sizeof (TreeNode));
    if(node){
        node->data = data;
        node->left=NULL;
        node->l_tag=0;
        node->right=NULL;
        node->r_tag=0;
    }
    return node;
}

void visitTreeNode(const TreeNode *node) {
    if(node){
        printf("%c",node->data);
    }
}

void insertThreadNode(ThreadBiTree *tree, TreeNode *parent, TreeNode *left, TreeNode *right) {
    if(tree && parent){
        parent->right = right;
        parent->left = left;
        tree->count += (left ? 1:0) +(right ? 1:0);
    }
}

static TreeNode *prev = NULL;
static void InOrdering(TreeNode *node){
    if(node == NULL){
        return;
    }
    InOrdering(node->left);
    if(node->left == NULL) {
        node->l_tag = 1;
        node->left = prev;
    }
    if(prev!=NULL && prev->right==NULL){
        prev->r_tag = 1;
        prev->right = node;
    }
    prev = node;
    InOrdering(node->right);
}

void InOrderThreading(ThreadBiTree *tree) {
    if(tree&&tree->root){
        prev = NULL;
        InOrdering(tree->root);
        if(prev!=NULL){
            prev->right = NULL;
            prev->r_tag=1;
        }
    }
}

void InOrderThreadTree(ThreadBiTree *tree) {
    if(tree && tree->root){
        TreeNode *node = tree->root;
        //找中序遍历的第一个极左点
        while(node->l_tag == 0){
            node = node->left;
        }
        //线性遍历
        while(node){
            visitTreeNode(node);
            if(node->r_tag == 1){
                node = node->right;
            } else {
                //非虚线，则寻找下一个极左点
                node = node->right;
                while(node && node->l_tag == 0){
                    node = node->left;
                }
            }
        }
    }
}

static void freeTreeNode(ThreadBiTree*tree,TreeNode*node){
    if(node){
        if(node->l_tag==0){
            freeTreeNode(tree,node->left);
        }
        if(node->r_tag==0){
            freeTreeNode(tree,node->right);
        }
        free(node);
        tree->count--;
    }
}

void releaseThreadBiTree(ThreadBiTree *tree) {
    if(tree){
        freeTreeNode(tree,tree->root);
        printf("tree have lost %d node\n",tree->count);
        free(tree);
    }
}

