//
// Created by lenovo on 2025/10/30.
//

#ifndef DATASTRUCT_DOUBLELOOPLINK_H
#define DATASTRUCT_DOUBLELOOPLINK_H

typedef int element_t;
typedef struct double_node{
    struct double_node* prev;
    element_t data;
    struct double_node* next;
}DuLNode;

typedef struct {
    DuLNode header;
    int num;
}DuLoopLink;

void initDuLoopLink(DuLoopLink* loop_link);
void insertDuLoopLinkHeader(DuLoopLink* loop_link,element_t val);
void insertDuLoopLinkRear(DuLoopLink* loop_link,element_t val);
void showDuLoopLink(const DuLoopLink* loop_link);
int  deleteValueDuLoopLink(DuLoopLink* loop_Link,element_t val);
void deleteAllLinkLoop(DuLoopLink* loop_link);
#endif //DATASTRUCT_DOUBLELOOPLINK_H
