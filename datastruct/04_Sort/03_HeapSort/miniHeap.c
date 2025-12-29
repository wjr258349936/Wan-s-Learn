#include <stdio.h>
#include <stdlib.h>
#include "miniHeap.h"
#include <string.h>

MiniHeap *createMiniHeap(int n) {
    MiniHeap *heap = malloc(sizeof (MiniHeap));
    if(heap==NULL){
        return NULL;
    }
    heap->data = malloc(sizeof (keyType)*(n+1));    //从1号下标开始算
    if(heap->data==NULL){
        free(heap);
        return NULL;
    }
    memset(heap->data,0,sizeof (keyType)*(n+1));
    heap->len=0;        //每次插入是先加一，再放入元素，模拟一个满空间
    heap->capacity=n;
    return heap;
}

void releaseMiniHeap(MiniHeap *heap) {
    if(heap&&heap->data){
        free(heap->data);
        heap->data=NULL;
        free(heap);
    }
}

//从k索引位置上开始判断父节点，循环上移
static void shiftUp(MiniHeap *heap, int k){
    while (k > 1 && heap->data[k / 2] > heap->data[k]) {
        keyType tmp = heap->data[k];
        heap->data[k] = heap->data[k / 2];
        heap->data[k / 2] = tmp;
        k /= 2;
    }
}

void insertMiniHeap(MiniHeap *heap, keyType e) {
    //判断堆空间还能放入新元素
    if(heap->len+1>heap->capacity){
        printf("MiniHeap No Space!\n");
        return ;
    }
    //根据完全二叉树的性质，满足结构特点
    heap->data[++heap->len] = e;
    //上浮操作
    shiftUp(heap,heap->len);
}

//从k索引位置处，根据堆性质进行下沉
static void shiftDown(MiniHeap *heap, int k) {
    while (2 * k <= heap->len) {			// 保证有左孩子
        int index = 2 * k;
        if (index + 1 <= heap->len && heap->data[index + 1] < heap->data[index]) {
            index += 1;
        }
        if (heap->data[k] <= heap->data[index]) {
            break;
        }
        keyType tmp = heap->data[k];
        heap->data[k] = heap->data[index];
        heap->data[index] = tmp;
        k = index;
    }
}

keyType extractMiniHeap(MiniHeap *heap) {
    // 判断是否空
    if (heap->len <= 0) {
        printf("MiniHeap No Data!\n");
        return 0;
    }
    // 取出堆顶元素
    keyType result = heap->data[1];
    // 最后一个元素和根交换
    heap->data[1] = heap->data[heap->len];
    --heap->len;
    // 开始下沉
    shiftDown(heap, 1);
    return result;
}
