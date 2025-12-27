#include "quickSort.h"

int (*partition)(SortTable *table, int startIndex, int endIndex);

static int partitionDouble(SortTable *table, int startIndex, int endIndex) {
	int pivot = startIndex;
	int left = startIndex;
	int right = endIndex;

	while (left != right) {
		while (left < right && table->data[right].key > table->data[pivot].key) right--;
		while (left < right && table->data[left].key <= table->data[pivot].key) left++;
		if (left < right) {
			swapElement(&table->data[right], &table->data[left]);
		}
	}
	swapElement(&table->data[pivot], &table->data[left]);
	return left;
}

static int partitionSingle(SortTable *table, int startIndex, int endIndex) {
	int mark = startIndex;
	keyType tmp = table->data[startIndex].key;

	for (int i = startIndex + 1; i <= endIndex; ++i) {
		if (table->data[i].key < tmp) {			// 发现了比犄点小的值
			++mark;								// 挡板往后移动一位，此时这个值比犄点大
			swapElement(&table->data[mark], &table->data[i]);
		}
	}
	swapElement(&table->data[mark], &table->data[startIndex]);
	return mark;
}

static void quickSort(SortTable *table, int startIndex, int endIndex) {
	// 递归的结束条件，startIndex 大于等于 endIndex
	if (startIndex >= endIndex) {
		return;
	}
	// 得到基准元素的索引号
	int pivot = partition(table, startIndex, endIndex);
	quickSort(table, startIndex, pivot - 1);
	quickSort(table, pivot + 1, endIndex);
}

// 双标查找法确定犄点的快排
void quickSortV1(SortTable *table) {
	partition = partitionDouble;
	quickSort(table, 0, table->length - 1);
}
// 单边查找法确定犄点的快排
void quickSortV2(SortTable *table) {
	partition = partitionSingle;
	quickSort(table, 0, table->length - 1);
}
