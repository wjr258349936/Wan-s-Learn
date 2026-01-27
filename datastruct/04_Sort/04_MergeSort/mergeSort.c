#include "mergeSort.h"
#include <stdio.h>
#include <stdlib.h>

//合并接口
static void merge(SortTable *table,int left,int mid,int right){
    // 分配临时子空间，便于比较
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Element *aux1 = malloc(sizeof(Element) * n1);
    Element *aux2 = malloc(sizeof(Element) * n2);
    if(aux1==NULL||aux2==NULL) return ;
    for(int i=0;i<n1;++i){
        aux1[i]=table->data[left+i];
    }
    for(int i=0;i<n2;++i){
        aux2[i]=table->data[mid + 1 +i];
    }
    //对已经有序的aux1和aux2进行归并
    int i = 0;      //aux1区域索引
    int j = 0;      //aux2区域索引
    int k = left;   //结果空间索引
    while(i<n1&&j<n2){
        if(aux1[i].key<=aux2[j].key){
            table->data[k] = aux1[i];
            i++;
        }else if(aux1[i].key>aux2[j].key){
            table->data[k] = aux2[j];
            j++;
        }
        k++;
    }
    //判断哪个区域还有值，并将剩余部分填入结果空间
    while(i < n1){
        table->data[k++] = aux1[i++];
    }
    while(j < n2){
        table->data[k++] = aux2[j++];
    }
    free(aux1);
    free(aux2);
}

//递归分解table的[left,right]区域
static void mergeLoop(SortTable *table,int left,int right){
    // 拆分
    if (left>=right) return ;
    int mid = (left + right) / 2;
    mergeLoop(table,left,mid);
    mergeLoop(table,mid + 1,right);
    // 合并
    merge(table,left,mid,right);
}

void mergeSort(SortTable *table) {
    mergeLoop(table,0,table->length);
}