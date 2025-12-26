//
// Created by lenovo on 2025/11/14.
//
#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
BSTree *initBSTree(){
    BSTree *tree = createBSTree();

    insertBSTreeNode(tree,22);
    insertBSTreeNode(tree,33);
    insertBSTreeNode(tree,45);
    insertBSTreeNode(tree,55);
    insertBSTreeNode(tree,8);
    insertBSTreeNode(tree,80);
    insertBSTreeNode(tree,130);
    insertBSTreeNode(tree,100);
    insertBSTreeNode(tree,120);
    insertBSTreeNode(tree,121);

    return tree;
}

void test01(){
    BSTree* tree = initBSTree();
    InOrderBSTree(tree);
    BSTreeNode *node = searchBSTreeNode(tree,120);
    if(node){
        printf("%d\n",node->data);
    }
   /* visitBSTreeNode(tree->root);*/
    printf("%d\n", heightBSTree(tree));
    releaseBSTree(tree);
}

void test02() {
    long long n = 1000000;
    srand(time(NULL) + 1);
    element_t *data = malloc(sizeof(element_t) * n);

    for (int i = 0; i < n; ++i) {
        data[i] = rand() % (n + 1000) + 1;
    }

    int cnt = 5000;
    clock_t start = clock();
    // 做了5000次实验
    for (int i = 0; i < cnt; ++i) {
        // 每次实验都从data里找一个不存在的值
        for (int j = 0; j < n; ++j) {
            if (data[j] == n + 5000) {
                printf("find error!\n");
            }
        }
    }
    clock_t end = clock();
    printf("linear find cost %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("==============================\n");
    BSTree *tree = createBSTree();
    for (int i = 0; i < n; ++i) {
        insertBSTreeNode(tree, data[i]);
    }
    start = clock();
    // 做了5000次实验
    for (int i = 0; i < cnt; ++i) {
        // 每次实验都从二叉搜索树中找一个不存在的值
        BSTreeNode *res = searchBSTreeNode(tree, n + 5000);
        if (res != NULL) {
            printf("BSTree find error!\n");
        }
    }

    end = clock();
    printf("BSTree find cost %fs\n", (double)(end - start) / CLOCKS_PER_SEC);
    releaseBSTree(tree);
    free(data);
}

int main(){
    /*test01();*/
    test02();
    return 0;
}

