#ifndef DATASTRUCT_MERGESORT_H
#define DATASTRUCT_MERGESORT_H
#include "../sortHelper.h"

/* 归并排序包括两部分：从上到下，从下往上
 * 从上往下：
 *  a. 分解 --- 当前分区一分为二
 *  b. 求解 --- 递归将两个子区间a[low,mid],a[mid,high]进行合并
 * 从下往上：
 *  合并
 */
void mergeSort(SortTable *table);
#endif //DATASTRUCT_MERGESORT_H
