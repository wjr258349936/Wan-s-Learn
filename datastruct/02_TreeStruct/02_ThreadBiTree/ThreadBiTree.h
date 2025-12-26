//
// Created by lenovo on 2025/11/12.
//

#ifndef DATASTRUCT_THREAD_BI_TREE_H
#define DATASTRUCT_THREAD_BI_TREE_H
typedef char element_t;
typedef struct tree_node{
    element_t data;
    struct tree_node *left;
    int l_tag;
    struct tree_node *right;
    int r_tag;
}TreeNode;

typedef struct {
    TreeNode *root;
    int count;
}ThreadBiTree;

ThreadBiTree* createThreadBiTree();
void releaseThreadBiTree(ThreadBiTree *tree);
void initThreadTree(ThreadBiTree *tree,TreeNode *root);
TreeNode * createTreeNode(element_t data);
void visitTreeNode(const TreeNode *node);
void insertThreadNode(ThreadBiTree *tree,TreeNode *parent,TreeNode *left,TreeNode *right);
//在原始树中构建线索
void InOrderThreading(ThreadBiTree *tree);
//在已线索化的树中进行中序遍历
void InOrderThreadTree(ThreadBiTree *tree);

#endif //DATASTRUCT_THREAD_BI_TREE_H
