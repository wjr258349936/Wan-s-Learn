//
// Created by lenovo on 2025/10/31.
//

#include "LinkListStack.h"
#include <stdio.h>
#include <stdlib.h>

void initLinkListStack(LinkListStack *start) {
    start->count = 0;
    start->pos = NULL;
}

void pushLinkListStack(LinkListStack *start, element_t val) {
    LNode* new_node = malloc(sizeof(LNode));
    new_node->data = val;
    new_node->next = start->pos;
    start->pos = new_node;
    ++start->count;
}

int popLinkListStack(LinkListStack *start) {
    if(start->pos==NULL){
        printf("stack empty!\n");
        return 0;
    }
    LNode *temp = start->pos;
    start->pos = start->pos ->next;
    free(temp);
    --start->count;
    return 1;
}

void deleteLinkLIstStack(LinkListStack *start) {
    while(start->count) {
        popLinkListStack(start);
    }
}

void showLinkListStack(LinkListStack *start) {
    if(start->pos==NULL){
        printf("stack empty!\n");
        return;
    }
    LNode *p = start->pos;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
