#include <stdio.h>
#include<stdlib.h>

typedef int element_t;

typedef struct node {
	element_t data;
	struct node* next;
}LNode;

typedef struct {
	LNode header;
	int num;
}LinkTable;

typedef struct {
	LNode* ptr_head;
	int num;
}LinkList;

static int	insertLNode(LNode* prev, element_t v);          //核心三步操作（思想：找前置节点）
static void delLNode(LNode* prev);
static void showLNode(const LNode* start);

/*带头节点的链表接口*/

void insertHeaderTable(LinkTable* table, element_t v);        //头插法
void insertPosTable(LinkTable* table, int pos, element_t v);  //指定位置插入
void insertRaerTable(LinkTable* table, element_t v);		  //尾插法

void deleteVauleTable(LinkTable* table, element_t v);		  //删除特定的值
void deleteAllLinkTable(LinkTable* table);					  //删除链表中的所有节点
void showLinkTable(const LinkTable* table);					  //展示链表中的内容

/*带头指针的链表接口*/
void insertHeaderList(LinkList* list, element_t v);
void insertPosList(LinkList* list, int pos, element_t v);
void insertRaerList(LinkList* list, element_t v);
void deleteVauleList(LinkList* list, element_t v);
void deleteAllLinkList(LinkList* list);
void showLinkList(const LinkList* list);

LNode* insertLink(LNode* header,element_t v);



static int insertLNode(LNode* prev, element_t v) {
	LNode* node = malloc(sizeof(LNode));
	if (node == NULL) {
		return 0;
	}
	node->data = v;
	node->next = prev->next;
	prev->next = node;
	return 1;
}
static void delLNode(LNode* prev) {
	LNode* tmp = prev->next;
	prev->next = tmp->next;
	free(tmp);
}
static void showLNode(const LNode* start) {
	while (start) {
		printf("%d ", start->data);
		start = start->next;
	}
	printf("\n");
}

void insertHeaderTable(LinkTable* table, element_t v) {
	LNode* prev = &table->header;
	if (insertLNode(prev, v)) {
		++table->num;
	}
}
void insertRaerTable(LinkTable* table, element_t v) {
	LNode* prev = &table->header;
	while (prev->next) {
		prev = prev->next;
	}

	if (insertLNode(prev, v)) {
		++table->num;
	}

}
void insertPosTable(LinkTable* table, int pos, element_t v) {
	if (pos < 0 || pos > table->num) {
		return;
	}
	LNode* prev = &table->header;
	int i = 0;
	while (i < pos && prev != NULL) {
		prev = prev->next;
		i++;
	}
	if (prev && insertLNode(prev, v)) {
		++table->num;
	}
}
void deleteVauleTable(LinkTable* table, element_t v) {
	LNode* prev = &table->header;
	while (prev && prev->next) {
		if (prev->next->data == v) {
			break;
		}
		prev = prev->next;
	}

	if (prev && prev->next) {
		delLNode(prev);
		--table->num;
	}
}
void deleteAllLinkTable(LinkTable* table) {
	LNode* prev = &table->header;
	while (prev->next) {
		delLNode(prev);
		--table->num;
	}
	printf("table num = %d\n", table->num);
}
void showLinkTable(const LinkTable* table) {
	printf("table[%d]:", table->num);
	LNode* start = table->header.next;
	showLNode(start);
}

void insertHeaderList(LinkList* list, element_t v) {
	LNode header;
	header.next = list->ptr_head;
	LNode* prev = &header;
	if (insertLNode(prev, v)) {
		++list->num;
	}
	list->ptr_head = header.next;
}
void insertPosList(LinkList* list, int pos, element_t v) {
	if (pos < 0 || pos > list->num) {
		return;
	}
	LNode header;
	header.next = list->ptr_head;
	LNode* prev = &header;
	int i = 0;
	while (i < pos && prev != NULL) {
		prev = prev->next;
		i++;
	}
	if (prev && insertLNode(prev, v)) {
		list->ptr_head = header.next;
		++list->num;
	}
}
void insertRaerList(LinkList* list, element_t v) {
	LNode header;
	header.next = list->ptr_head;
	LNode* prev = &header;
	while (prev->next) {
		prev = prev->next;
	}

	if (insertLNode(prev, v)) {
		list->ptr_head = header.next;
		++list->num;
	}
}
void deleteVauleList(LinkList* list, element_t v) {
	LNode header;
	header.next = list->ptr_head;
	LNode* prev = &header;
	while (prev && prev->next) {
		if (prev->next->data == v) {
			break;
		}
		prev = prev->next;
	}

	if (prev && prev->next) {
		delLNode(prev);
		list->ptr_head = header.next;
		--list->num;
	}
}
void deleteAllLinkList(LinkList* list) {
	LNode header;
	header.next = list->ptr_head;
	LNode* prev = &header;
	while (prev->next) {
		delLNode(prev);
		--list->num;
	}
	printf("list num = %d\n", list->num);
	list->ptr_head = header.next;
}
void showLinkList(const LinkList* list) {
	LNode header;
	header.next = list->ptr_head;
	printf("list[%d]:", list->num);
	LNode* start = list->ptr_head;
	showLNode(start);
}

LNode* insertLink(LNode* header, element_t v) {
	LNode dummy;
	dummy.next = header;
	LNode* prev = &dummy;
	if (insertLNode(prev,v)) {
		return dummy.next;
	}
}

void test01() {
	LinkTable table;
	table.num = 0;
	table.header.next = NULL;

	for (int i = 0; i < 5; ++i) {
		//insertHeaderTable(&table, i + 100);
		insertRaerTable(&table, i + 100);
	}
	showLinkTable(&table);
	insertPosTable(&table, 2, 500);
	showLinkTable(&table);
	deleteVauleTable(&table, 500);
	showLinkTable(&table);
	deleteAllLinkTable(&table);
}

void test02() {
	LinkList list;
	list.num = 0;
	list.ptr_head = NULL;
	for (int i = 1; i <= 5; ++i) {
		insertRaerList(&list, i+200);
	}
	showLinkList(&list);
	insertPosList(&list, 2, 500);
	showLinkList(&list);
	deleteVauleList(&list, 500);
	showLinkList(&list);
	deleteAllLinkList(&list);
}

void test03() {
	LNode* header;
	header = NULL;
	for (int i = 1; i <= 5; ++i) {
		header = insertLink(header, i + 10);
	}
	LNode* p = header;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	//test01();
	//test02();
	test03();
	return 0;
}