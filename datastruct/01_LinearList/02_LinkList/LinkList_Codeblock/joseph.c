//
// Created by lenovo on 2025/10/28.
//
#include <stdio.h>
#include <stdlib.h>
#include "joseph.h"

static void delete(JosephHeader *game,Node *p){
    Node* temp = p->next;
    p->next = p->next->next;
    free(temp);
}

void initJosephGame(JosephHeader *game, int n) {
    Node *node = NULL;
    for(int i =1;i<=n;++i){
        node = malloc(sizeof (Node));
        node ->data = i;
        if(game->head == NULL){
            game->head = game->tail = node;
        }else {
            game->tail->next = node;
            game->tail = node;
        }
        game->tail->next = game->head;
    }
}

void showJosephGame(const JosephHeader *game) {
    Node *p = game->head;
    do {
        printf("%d\t",p->data);
        p = p->next;
    }while(p != game->head);
    printf("\n");
}

void startJosephGame(JosephHeader *game, int k) {
    printf("start game:");
    Node *p = game->tail;
    while(p->next != p){
        for(int i = 1 ; i < k ; ++i){
            p = p->next;
        }
        printf("delete %d\n",p->next->data);
        delete(game,p);
    }
    printf("%d is alive",p->data);
}
