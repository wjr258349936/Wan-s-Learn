//
// Created by lenovo on 2025/10/31.
//

#include "arrayStack.h"
#include <stdio.h>
#include <stdlib.h>

void initArrayStack(Array_Stack *stack) {
    stack->count = 0;
}

void pushArrayStack(Array_Stack *stack, element_t val) {
    stack->arraystack[stack->count] = val;
    ++stack->count;
}

void popArrayStack(Array_Stack *stack) {
    if(stack->count<=0){
        printf("stack empty!\n");
        return;
    }
    --stack->count;
}

void showArrayStack(Array_Stack *stack) {
    if(stack->count==0){
        printf("stack empty!\n");
        return;
    }
    int i = 0;
    while(i<stack->count){
        printf("%d ",stack->arraystack[i]);
        ++i;
    }
    printf("\n");
}

void deleteArrayStack(Array_Stack *stack) {
    stack->count = 0;
}

