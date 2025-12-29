#include <stdlib.h>
#include "quickUnionSet.h"

QuickUnionSet *createQuickUnionSet(int capacity) {
    QuickUnionSet *setQU = malloc(sizeof(QuickUnionSet));
    if(setQU==NULL){
        return NULL;
    }
    setQU->data= malloc(sizeof (element_t)*capacity);
    setQU->parentID= malloc(sizeof (int)*capacity);
    setQU->size= malloc(sizeof (int)*capacity);
    setQU->n=0;
    setQU->capacity=capacity;
    return setQU;
}

void releaseQuickUnionSet(QuickUnionSet *setQU) {
    if(setQU) {
        free(setQU->data);
        free(setQU->parentID);
        free(setQU->size);
        setQU->n = 0;
        setQU->capacity = 0;
        free(setQU);
    }
}

void initQuickUnionSet(QuickUnionSet *setQU, const element_t *data, int n) {
    for(int i=0;i<n;++i){
        setQU->data[i]=data[i];
        setQU->parentID[i]=i;
        setQU->size[i]=1;
    }
    setQU->n=n;
}

static int findIndex(const QuickUnionSet*setQU,element_t e){
    for(int i=0;i<setQU->n;++i){
        if(setQU->data[i]==e) return i;
    }
    return -1;
}

//找e元素的根节点索引号，查找效率与树的高度有关
static int findRootIndex(const QuickUnionSet* setQU,element_t e){
    int index = -1;
    index = findIndex(setQU,e);
    if(index==-1){
        return -1;
    }
    //从parentID中不断找父节点，直到某一个点的父节点就是他本身，这个点就是根
    while(setQU->parentID[index]!=index){
        index=setQU->parentID[index];
    }
    return index;
}

static int findRootIndexWithPathCompress(const QuickUnionSet*setQU,element_t e){
    int index=-1;
    index=findIndex(setQU,e);
    if(index==-1){
        return -1;
    }
    //利用练市栈，保存路径上的节点信息
    SetNode *stackTop = NULL;
    while(setQU->parentID[index]!=index){
        //当前节点入栈
        SetNode *newNode = malloc(sizeof(SetNode));
        newNode->index=index;
        newNode->next=stackTop;
        stackTop = newNode;
        index = setQU->parentID[index];
    }
    //根节点找到了，路径压缩，上一步找根的路径的节点都更新其parentID指向根索引（index）
    while(stackTop!=NULL){
        SetNode *temp = stackTop;
        setQU->parentID[stackTop->index]=index;
        stackTop=stackTop->next;
        free(temp);
    }
    return index;
}

int isSameQU(const QuickUnionSet *setQU, element_t a, element_t b) {
    int rootA = findRootIndexWithPathCompress(setQU,a);
    int rootB = findRootIndexWithPathCompress(setQU,b);
    if(rootA==-1||rootB==-1){
        return 0;
    }
    return rootA==rootB;
}

void unionQU(const QuickUnionSet *setQU, element_t a, element_t b) {
    int rootA = findRootIndexWithPathCompress(setQU,a);
    int rootB = findRootIndexWithPathCompress(setQU,b);
    if(rootA==-1||rootB==-1){
        return;
    }
    if(rootA==rootB){
        return;
    }
    //根管理了这个集合，根据根对用的size情况，来进行合并
    if(setQU->size[rootA]<setQU->size[rootB]){
        setQU->parentID[rootA]= rootB;
        setQU->size[rootB] +=setQU->size[rootA];
    }else {
        setQU->parentID[rootB] = rootA;
        setQU->size[rootA] += setQU->size[rootB];
    }
}
