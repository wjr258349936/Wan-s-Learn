//
// Created by lenovo on 2025/11/14.
//

#ifndef DATASTRUCT_BSTREE_H
#define DATASTRUCT_BSTREE_H
typedef int element_t;
typedef struct treenode{
    element_t data;
    struct treenode*left;
    struct treenode*right;
}BSTreeNode;
typedef struct {
    BSTreeNode *root;
    int count;
}BSTree;

BSTree *createBSTree();
void releaseBSTree(BSTree *tree);
BSTreeNode *deleteBSTreeNodeV1(BSTree *tree,element_t val);
void insertBSTreeNode(BSTree *tree,element_t data);
BSTreeNode *searchBSTreeNode(BSTree *tree,element_t data);
void visitBSTreeNode(BSTreeNode *node);
int heightBSTree(const BSTree *tree);
void InOrderBSTree(BSTree *tree);

#endif //DATASTRUCT_BSTREE_H
