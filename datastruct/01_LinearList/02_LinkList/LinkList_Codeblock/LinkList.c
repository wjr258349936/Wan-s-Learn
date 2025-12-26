//
// Created by lenovo on 2025/10/28.
//
#include<stdio.h>
#include<stdlib.h>
#include "LinkList.h"

static void insert(LinkLoop* link_loop, LNode* prev, element_t val) {
    LNode* node = (LNode*)malloc(sizeof(LNode));
    if (node == NULL) {
        return;
    }
    node->data = val;
    node->next = prev->next;            //先新后旧
    prev->next = node;
    if (link_loop->rear == prev) {
        link_loop->rear = node;
    }
    ++link_loop->num;
}

static void delete(LinkLoop* link_loop, LNode* pre) {
    LNode* prev = pre;
    if (!prev || prev->next == &link_loop->header) {
        return;
    }
    LNode* temp = prev->next;
    prev->next = temp->next;
    if (temp == link_loop->rear) {
        link_loop->rear = prev;
    }
    free(temp);
    --link_loop->num;
}


void initLinkLoop(LinkLoop *link_loop) {
    link_loop->header.next = &link_loop->header;
    link_loop->rear = &link_loop->header;
    link_loop->num = 0;
}

void linkLoopInsertHeader(LinkLoop *link_loop, element_t val) {
    LNode  *prev = link_loop->rear->next;
    insert(link_loop,prev,val);
}

void linkLoopInsertRear(LinkLoop *link_loop, element_t val) {
    LNode  *prev = link_loop->rear;
    insert(link_loop,prev,val);
}

void showLinkLoop(const LinkLoop *link_loop) {
    LNode *prev = link_loop->header.next;
    printf("LinkLoop[%d]:",link_loop->num);
    while(prev != &link_loop->header){
        printf("%d ",prev->data);
        prev = prev -> next;
    }
    printf("\n");
}

int linkLoopDeleteEle(LinkLoop *link_loop, element_t val) {
    LNode  *prev = &link_loop->header;
    while(prev->next != &link_loop->header){
        if(prev->next->data == val){
            delete(link_loop,prev);
            return 1;
        }
        prev = prev->next;
    }
    return 0;
}

void linkLoopDeleteAll(LinkLoop *link_loop) {
    LNode *prev = &link_loop->header;
    while(prev->next != &link_loop->header){
        delete(link_loop,prev);
    }
    link_loop->rear = &link_loop->header;
    printf("list num = %d\n",link_loop->num);
}


