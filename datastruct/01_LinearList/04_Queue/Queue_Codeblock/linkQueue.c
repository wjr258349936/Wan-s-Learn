//
// Created by lenovo on 2025/11/3.
//

#include "linkQueue.h"
#include <stdlib.h>
#include <stdio.h>

LinkQueue * createLinkQueue(){
    LinkQueue *queue = malloc(sizeof(LinkQueue));
    if(queue == NULL){
        return NULL;
    }
    queue->front = queue->rear = NULL;
    queue->count = 0;
    return queue;
}

void releaseLinkQueue(LinkQueue *queue) {
    if(queue == NULL) return;
    QNode  *p = queue->front;
    while (p){
        QNode *temp = p;
        p=p->next;
        free(temp);
        --queue->count;
    }
    printf("LinkQueue have %d node\n",queue->count);
    free(queue);
}

int pushLinkQueue(LinkQueue *queue, element_t val) {
    QNode *newnode = malloc(sizeof (QNode));
    if(newnode == NULL) return -1;
    newnode->data = val;
    newnode->next = NULL;
    if(queue->rear == NULL) {
        queue->rear = newnode;
        queue->front = newnode;
    }else {
        queue->rear->next = newnode;
        queue->rear = newnode;
    }
    queue->count++;
    return 0;
}

int popLinkQueue(LinkQueue *queue, element_t *val) {
    if(queue->front == NULL) return -1;
    QNode *temp = queue->front;
    *val = temp->data;
    queue->front = queue->front->next;
    if(queue->front == NULL) queue->rear =NULL;
    free(temp);
    queue->count--;
    return 0;
}
