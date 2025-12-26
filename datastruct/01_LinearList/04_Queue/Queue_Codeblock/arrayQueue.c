//
// Created by lenovo on 2025/11/3.
//
#include <stdio.h>
#include "arrayQueue.h"

void initArrayQueue(ArrayQueue *queue) {
    queue->front = 0;
    queue->rear = 0;
}

int isEmptyArrayQueue(const ArrayQueue *queue) {
    return queue->front == queue->rear;
}

int isFullArrayQueue(const ArrayQueue *queue) {
    return (queue->rear + 1) % MaxQueueSize == queue->front;
}

void pushArrayQueue(ArrayQueue *queue, element_t val) {
    if(isFullArrayQueue(queue)){
        printf("queue is full!\n");
        return;
    }
    queue ->data[queue->rear] = val;
    queue->rear = (queue->rear+1)%MaxQueueSize;
}

void popArrayQueue(ArrayQueue *queue) {
    if(isEmptyArrayQueue(queue)){
        printf("queue is empty!\n");
        return;
    }
    queue->front = (queue->front+1)%MaxQueueSize;
}

element_t getFrontArrayQueue(const ArrayQueue *queue) {
    return queue->data[queue->front];
}
