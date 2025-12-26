//
// Created by lenovo on 2025/11/12.
//
#include "ThreadBiTree.h"
#include <stdio.h>
#include <stdlib.h>

static ThreadBiTree  *initTestTree(){
    ThreadBiTree *tree = createThreadBiTree();

    TreeNode  *nodeA = createTreeNode('A');
    TreeNode  *nodeB = createTreeNode('B');
    TreeNode  *nodeC = createTreeNode('C');
    TreeNode  *nodeD = createTreeNode('D');
    TreeNode  *nodeE = createTreeNode('E');
    TreeNode  *nodeF = createTreeNode('F');
    TreeNode  *nodeG = createTreeNode('G');
    TreeNode  *nodeH = createTreeNode('H');
    TreeNode  *nodeK = createTreeNode('K');

    initThreadTree(tree,nodeA);
    insertThreadNode(tree, nodeA, nodeB,nodeE);
    insertThreadNode(tree, nodeB, NULL,nodeC);
    insertThreadNode(tree, nodeC, nodeD,NULL);
    insertThreadNode(tree, nodeE, NULL,nodeF);
    insertThreadNode(tree, nodeF, nodeG,NULL);
    insertThreadNode(tree, nodeG, nodeH,nodeK);
    return tree;
}

int main(){
    ThreadBiTree *tree = initTestTree();
    printf("tree node:%d\n",tree->count);
    InOrderThreading(tree);
    InOrderThreadTree(tree);
    printf("\n");
    releaseThreadBiTree(tree);
    return 0;
}