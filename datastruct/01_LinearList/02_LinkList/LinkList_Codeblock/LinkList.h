//
// Created by lenovo on 2025/10/28.
//

#ifndef DATASTRUCT_LINKLIST_H
#define DATASTRUCT_LINKLIST_H

/* 循环链表 */

typedef int element_t;

/* 链表结点数据 */
typedef struct link_node{
    element_t data;
    struct link_node* next;
}LNode;

/* 链表头定义 */
typedef struct {
    LNode header;       //头结点
    int num;            //链表长
    LNode* rear;        //尾指针
}LinkLoop;

//静态初始化表头
void initLinkLoop(LinkLoop* link_loop);

//插入，头插和尾插
void linkLoopInsertHeader(LinkLoop* link_loop, element_t val);
void linkLoopInsertRear(LinkLoop* link_loop, element_t val);

//删除指定元素
int linkLoopDeleteEle(LinkLoop* link_loop, element_t val);
//删除链表
void linkLoopDeleteAll(LinkLoop* link_loop);

//遍历
void showLinkLoop(const LinkLoop* link_loop);

#endif //DATASTRUCT_LINKLIST_H
