//
// Created by lenovo on 2025/11/7.
//

#ifndef DATASTRUCT_BI_TREE_H
#define DATASTRUCT_BI_TREE_H

typedef int element_t;

typedef struct bitreenode{
    element_t data;
    struct bitreenode *L_next;
    struct bitreenode *R_next;
}BiTreeNode;

typedef struct {
    BiTreeNode * root;
    int Count;
}BiTree;

//安全创建树头
BiTree *createBiTree();
//初始化树头并安放一个空的根节点
void initBiTree(BiTree* tree);
//释放树空间
void releaseBiTree(BiTree *tree);
//创建树节点
void createBITreeNode(element_t data);
//在树结构中插入元素
void insertBiTree(BiTree *tree,BiTreeNode *parent,BiTreeNode *left,BiTreeNode *right);
//三种方式遍历二叉树
void pre_visitBiTree(BiTree *tree);
void mid_visitBiTree(BiTree *tree);
void end_visitBiTree(BiTree *tree);

#endif //DATASTRUCT_BI_TREE_H
