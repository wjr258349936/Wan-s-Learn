#include "miniHeap.h"
#include "heapSort.h"
#include <stdio.h>

void test01(){
    int data[]={9,3,7,6,5,1,10};
    int n=20;
    MiniHeap *mini_Heap = createMiniHeap(n);
    if(mini_Heap == NULL){
        return;
    }
    for(int i=0;i<sizeof (data)/sizeof data[0];++i){
        insertMiniHeap(mini_Heap,data[i]);
    }
    /*printf("array: ");
    for(int i=1;i<=mini_Heap->len;++i){
        printf("%d ",mini_Heap->data[i]);
    }*/
    printf("\n extra: ");
    for(int i=1;i<=sizeof(data)/sizeof (data[0]);++i ){
        printf("\t%d", extractMiniHeap(mini_Heap));
    }
    releaseMiniHeap(mini_Heap);
}

void test02(){
    int n=10000;
    SortTable *table = generateRandomArray(n,0,n+1000);
    testSort("MiniSort: ",MiniHeapSort,table);
    releaseSortTable(table);
}

int main(){
    test02();
    return 0;
}