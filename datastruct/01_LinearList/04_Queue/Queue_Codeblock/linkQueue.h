//
// Created by lenovo on 2025/11/3.
//

#ifndef DATASTRUCT_LINK_QUEUE_H
#define DATASTRUCT_LINK_QUEUE_H

typedef int element_t;

typedef struct linknode{
    struct linknode *next;
    element_t data;
}QNode;

typedef struct{
    QNode * front;
    QNode * rear;
    int count;
}LinkQueue;

LinkQueue * createLinkQueue();
void releaseLinkQueue(LinkQueue*queue);
int pushLinkQueue(LinkQueue*queue,element_t val);
int popLinkQueue(LinkQueue*queue,element_t *val);

#endif //DATASTRUCT_LINK_QUEUE_H
