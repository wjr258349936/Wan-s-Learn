#include "insertSort.h"

/* 默认的插入排序:
 * 1. 默认第一个元素是有序，那么从第二个元素开始和前面有序区域的值进行比较
 * 2. 待插入的元素i，和已经有序的区域从后往前依次查找
 */
void insertSortV1(SortTable *table) {
	for (int i = 1; i < table->length; ++i) {		// [1,n)
		if (table->data[i].key < table->data[i - 1].key) {
			// 用j辅助索引来找到待插入元素的真正位置，i的值不变，他指向待排序的索引号
			int j = i - 1;
			Element temp = table->data[i];		// 备份待插入的元素
			// 查找索引[0...i-1]的位置，j > -1临界条件，只要备份值比插入位置还要小，继续往前找
			while (j > -1 && temp.key < table->data[j].key) {
				table->data[j + 1] = table->data[j];		// 往后备份
				--j;
			}
			// 找到j位置比插入元素要小，那么j+1就是待插入的位置，由于j+1的元素已经移动到后面
			table->data[j + 1] = temp;
		}
		// 待插入的元素比之前有序区域的值还大，那么i位置就是这个元素的位置
	}
}

// 等价于扑克牌摸牌的效果，不断的和前面的元素交换
void insertSortV2(SortTable *table) {
	for (int i = 1; i < table->length; ++i) {
		Element e = table->data[i];
		int j;
		for (j = i; j > 0 && e.key < table->data[j - 1].key; --j) {
			swapElement(&table->data[j], &table->data[j - 1]);
		}
		// table->data[j] = e;
	}
}

void shellSort(SortTable *table) {
	// 按照gap进行分组
	for (int gap = table->length / 2; gap > 0; gap /= 2) {
		// 每一组都进行插入排序
		for (int i = gap; i < table->length; ++i) {
			Element e = table->data[i];
			int j;
			for (j = i; j >= gap && e.key < table->data[j - gap].key; j -= gap) {
				swapElement(&table->data[j], &table->data[j - gap]);
			}
			// table->data[j] = e;
		}
	}
}
