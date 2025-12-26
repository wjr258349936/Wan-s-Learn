//
// Created by lenovo on 2025/10/28.
//

#ifndef DATASTRUCT_JOSEPH_H
#define DATASTRUCT_JOSEPH_H
/* Joseph环的节点结构*/
typedef struct node{
    int data;
    struct node *next;
} Node;
/*Joseph环的表头结构，只保留头尾指针，不包含头节点*/
typedef struct {
    Node *head;
    Node *tail;
} JosephHeader;

// 初始化Joseph环的n个节点
void initJosephGame(JosephHeader *game,int n);
// 开始按照k个步长执行Joseph环的执行过程
void startJosephGame(JosephHeader *game,int k);

void showJosephGame(const JosephHeader *game);
#endif //DATASTRUCT_JOSEPH_H
