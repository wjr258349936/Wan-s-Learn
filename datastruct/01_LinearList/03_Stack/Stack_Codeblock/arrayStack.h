//
// Created by lenovo on 2025/10/31.
//

#ifndef DATASTRUCT_ARRAY_STACK_H
#define DATASTRUCT_ARRAY_STACK_H

#define MAX_NUMB 100
typedef int element_t;

typedef struct arraystack{
    element_t arraystack[MAX_NUMB];
    int count;
}Array_Stack;

void initArrayStack(Array_Stack *stack);
void pushArrayStack(Array_Stack *stack,element_t val);
void popArrayStack (Array_Stack *stack);
void showArrayStack(Array_Stack *stack);
void deleteArrayStack(Array_Stack *stack);

#endif //DATASTRUCT_ARRAY_STACK_H
