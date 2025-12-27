#include "bubbleSort.h"

/* 冒泡法，遍历n轮，每一轮发现一个最大值，第一次遍历[0...n-1)，第二次遍历[0...n-2)
 * 第j个元素 比 第j+1个元素比大  交换，第一次比完后，最大值放入第n-1个位置，这个值一定不会再变
 */
void bubbleSortV1(SortTable *table) {
	for (int i = 0; i < table->length - 1; ++i) {
		for (int j = 0; j < table->length - 1 - i; ++j) {
			if (table->data[j].key > table->data[j + 1].key) {
				swapElement(&table->data[j], &table->data[j + 1]);
			}
		}
	}
}

void bubbleSortV2(SortTable *table) {
	for (int i = 0; i < table->length - 1; ++i) {
		int isSorted = 1;
		for (int j = 0; j < table->length - 1 - i; ++j) {
			if (table->data[j].key > table->data[j + 1].key) {
				swapElement(&table->data[j], &table->data[j + 1]);
				isSorted = 0;
			}
		}
		if (isSorted)
			break;
	}
}

/* 引入newIndex标记交换的位置 下次冒泡时候查找区间到newIndex */
void bubbleSortV3(SortTable *table) {
	int newIndex;
	int n = table->length;
	do {
		newIndex = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (table->data[i].key > table->data[i + 1].key) {
				swapElement(&table->data[i], &table->data[i + 1]);
				newIndex = i + 1;
			}
		}
		n = newIndex;
	} while (newIndex > 0);
}
