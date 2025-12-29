#ifndef DATASTRUCT_MINIHEAP_H
#define DATASTRUCT_MINIHEAP_H
#include "../sortHelper.h"
//小顶堆的结构
typedef struct {
    keyType *data;
    int len;
    int capacity;
}MiniHeap;

MiniHeap *createMiniHeap(int n);
void releaseMiniHeap(MiniHeap *heap);

void insertMiniHeap(MiniHeap *heap,keyType e);
keyType extractMiniHeap(MiniHeap *heap);
#endif //DATASTRUCT_MINIHEAP_H
