//
// Created by lenovo on 2025/11/3.
//
#include <stdio.h>
#include "arrayQueue.h"
#include "linkQueue.h"
void test01(){
    ArrayQueue queue;
    initArrayQueue(&queue);
    for(int i = 1;i < 5; ++i){
        pushArrayQueue(&queue,i*10);
    }
    pushArrayQueue(&queue,50);
    printf("queue front = %d\n", getFrontArrayQueue(&queue));
    popArrayQueue(&queue);
    popArrayQueue(&queue);
    printf("queue front = %d\n", getFrontArrayQueue(&queue));
    while (!isEmptyArrayQueue(&queue)){
        printf("queue element:%d\n", getFrontArrayQueue(&queue));
        popArrayQueue(&queue);
    }
    printf("=================\n");
    popArrayQueue(&queue);
}

void test02(){
    LinkQueue *queue = createLinkQueue();
    for(int i=1;i<5;++i){
        pushLinkQueue(queue,i*10);
    }
    element_t val;
    popLinkQueue(queue,&val);
    printf("dequeue element:%d\n",val);
    popLinkQueue(queue,&val);
    printf("dequeue element:%d\n",val);
    pushLinkQueue(queue,50);
    pushLinkQueue(queue,60);
    while(popLinkQueue(queue,&val)==0){
        printf("dequeue element:%d\n",val);
    }
    popLinkQueue(queue,&val);
    releaseLinkQueue(queue);
}


int main(){
    //test01();
    test02();
    return 0;
}