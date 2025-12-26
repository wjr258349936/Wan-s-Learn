//
// Created by lenovo on 2025/11/3.
//

#ifndef DATASTRUCT_ARRAY_QUEUE_H
#define DATASTRUCT_ARRAY_QUEUE_H
typedef int element_t;
#define MaxQueueSize 5
typedef struct{
    int front;
    int rear;
    element_t data[MaxQueueSize];
}ArrayQueue;

void initArrayQueue(ArrayQueue *queue);

int isEmptyArrayQueue(const ArrayQueue *queue);
int isFullArrayQueue(const ArrayQueue *queue);

void pushArrayQueue(ArrayQueue *queue ,element_t val);
void popArrayQueue(ArrayQueue *queue);

element_t getFrontArrayQueue(const ArrayQueue *queue);


#endif //DATASTRUCT_ARRAY_QUEUE_H
