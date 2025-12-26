//
// Created by lenovo on 2025/10/30.
//

#include "DoubleLoopLink.h"
#include <stdio.h>
#include <stdlib.h>

static void addDuLNode(DuLNode *new_node,DuLNode *prev,DuLNode *next){
    next->prev = new_node;
    new_node->next = next;
    new_node->prev = prev;
    prev->next = new_node;
}

static void deleteNode(DuLNode *prev,DuLNode *next){
    next->prev = prev;
    prev->next = next;
}

void initDuLoopLink(DuLoopLink *loop_link) {
    loop_link->num=0;
    loop_link->header.next=&loop_link->header;
    loop_link->header.prev=&loop_link->header;
}

void insertDuLoopLinkHeader(DuLoopLink *loop_link, element_t val) {
    DuLNode* new_node = malloc(sizeof(DuLNode));
    if(new_node == NULL){
        printf("malloc failed!\n");
        return;
    }
    new_node->data = val;
    addDuLNode(new_node,&loop_link->header,loop_link->header.next);
    ++loop_link->num;
}

void insertDuLoopLinkRear(DuLoopLink *loop_link, element_t val) {
    DuLNode* new_node = malloc(sizeof(DuLNode));
    if(new_node == NULL){
        printf("malloc failed!\n");
        return;
    }
    new_node->data = val;
    addDuLNode(new_node,loop_link->header.prev,&loop_link->header);
    ++loop_link->num;
}

void showDuLoopLink(const DuLoopLink *loop_link) {
    DuLNode * p = loop_link->header.next;
    printf("DuLoopLink[%d]: ",loop_link->num);
    while(p != &loop_link->header){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int deleteValueDuLoopLink(DuLoopLink *loop_Link, element_t val) {
    DuLNode *pos = loop_Link->header.next;
    while(pos != &loop_Link->header){
        if(pos->data==val){
            deleteNode(pos->prev,pos->next);
            free(pos);
            --loop_Link->num;
            return 1;
        }
        pos = pos->next;
    }
    printf("Not find!\n");
    return 0;
}

void deleteAllLinkLoop(DuLoopLink *loop_link) {
    DuLNode *p = loop_link->header.next;
    while(p != &loop_link->header){
        DuLNode * temp = p;
        free(p);
        p = temp;
        p = p->next;
        --loop_link->num;
    }
    loop_link->header.next = &loop_link->header;
    loop_link->header.prev = &loop_link->header;
    printf("DuLoopLink[%d]\n",loop_link->num);
}
