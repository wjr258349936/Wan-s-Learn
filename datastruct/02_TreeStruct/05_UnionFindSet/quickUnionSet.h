#ifndef DATASTRUCT_QUICKUNIONSET_H
#define DATASTRUCT_QUICKUNIONSET_H
#include "common.h"
/*quickUnion方法：每个元素只保存父编号，通过不断找父元素，最终找到根元素编号*/
typedef struct {
    element_t *data;
    int *parentID;      //parentID[i]表示第i个元素的父元素编号
    int *size;          //size[i]表示：当i为根元素时，表示这棵树的节点个数
    int n;              //集合中有效元素的个数
    int capacity;       //集合的总容量
}QuickUnionSet;

/*定义一个链表节点，当做栈空间维护，保护路径查找过程中的节点信息*/
typedef struct set_node{
    int index;
    struct set_node*next;
}SetNode;

QuickUnionSet *createQuickUnionSet(int capacity);
void releaseQuickUnionSet(QuickUnionSet*setQU);
void initQuickUnionSet(QuickUnionSet* setQU,const element_t*data,int n);

//查：在并查集中，判断两个元素是不是同一个集团
int isSameQU(const QuickUnionSet*setQU,element_t a,element_t b);

//并：在并查集中，合并两个元素
void unionQU(const QuickUnionSet* setQU,element_t a,element_t b);
#endif //DATASTRUCT_QUICKUNIONSET_H
