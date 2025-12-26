//
// Created by lenovo on 2025/10/31.
//

#ifndef DATASTRUCT_LINKLIST_STACK_H
#define DATASTRUCT_LINKLIST_STACK_H

typedef int element_t;
typedef struct linklistnode{
    struct linklistnode *next;
    element_t data;
}LNode;
typedef struct linkliststack{
    LNode *pos;
    int count;
}LinkListStack;

void initLinkListStack(LinkListStack *start);
void pushLinkListStack(LinkListStack *start,element_t val);
int  popLinkListStack (LinkListStack *start);
void deleteLinkLIstStack(LinkListStack *start);
void showLinkListStack(LinkListStack *start);

#endif //DATASTRUCT_LINKLIST_STACK_H