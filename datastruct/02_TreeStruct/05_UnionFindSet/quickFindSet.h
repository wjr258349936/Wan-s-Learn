#ifndef DATASTRUCT_QUICKFINDSET_H
#define DATASTRUCT_QUICKFINDSET_H
#include "common.h"
typedef struct {
    element_t *data;
    int *groupID;
    int n;
    int capacity;
}QuickFindSet;
QuickFindSet* createQuickFindSet(int capacity);
void releaseQuickFindSet(QuickFindSet* setQF);
void initQuickFindSet(QuickFindSet *setQF,const element_t *data,int n);

//查：在并查集中，判断两个元素是不是同一个集团
int isSameQF(const QuickFindSet* setQF,element_t a,element_t b);

//并：在并查集中，合并两个元素
void unionQF(const QuickFindSet* setQF,element_t a,element_t b);
#endif //DATASTRUCT_QUICKFINDSET_H
