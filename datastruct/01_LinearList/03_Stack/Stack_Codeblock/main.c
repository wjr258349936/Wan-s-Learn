//
// Created by lenovo on 2025/10/31.
//
#include "arrayStack.h"
#include "LinkListStack.h"

void test01(){
    Array_Stack stack;
    initArrayStack(&stack);
    for(int i = 1;i<=10;++i){
        pushArrayStack(&stack,i+100);
    }
    showArrayStack(&stack);
    popArrayStack(&stack);
    showArrayStack(&stack);
    deleteArrayStack(&stack);
    showArrayStack(&stack);
    popArrayStack(&stack);
}

void test02(){
    LinkListStack start;
    initLinkListStack(&start);
    for(int i=1;i<=10;++i){
        pushLinkListStack(&start,i+100);
    }
    showLinkListStack(&start);
    popLinkListStack(&start);
    showLinkListStack(&start);
    deleteLinkLIstStack(&start);
    showLinkListStack(&start);
    popLinkListStack(&start);
}

int main(){
    //test01();
    test02();
}