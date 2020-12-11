#include <stdlib.h>
#include <assert.h>
#include "stacknqueue.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void test_empty() {
    Queue q1 = queue_new(2);
    Queue *q = &q1;
    assert(queue_empty(q));
}

void test_add() {
    Queue q1 = queue_new(3);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, 10, &res);
    q = queue_add(q, 20, &res);
    q = queue_add(q, 30, &res);

    assert(queue_length(q) == 3);
    assert(res.status == QUEUE_FULL);
    assert(queue_full(q));
}

void test_Qdelete(){
    Queue q1 = queue_new(3);
    Queue *q = &q1;
    QueueResult res;

    q = queue_add(q, 10, &res);
    q = queue_add(q, 20, &res);
    q = queue_add(q, 30, &res);

    q = queue_delete(q, &res);
    assert(res.data == 10);
    assert(queue_length(q) == 2);
    q = queue_delete(q, &res);
    q = queue_delete(q, &res);
    q = queue_delete(q, &res);
    assert(res.status == QUEUE_EMPTY);
    assert(queue_empty(q));
    assert(queue_length(q) == 0);

}

void test_newstack(){
    Stack s1 = stack_new(10);
    Stack *stk = &s1;

    assert(stk->top == -1);
    assert(stk->size == 10);
    assert(stk->data[0] == 0);

}

void test_stack_full(){
    Stack s1 = stack_new(10);
    Stack *stk = &s1;

    assert(stack_full(stk) == 0);
}

void test_stack_empty(){
    Stack s1 = stack_new(10);
    Stack *stk = &s1;

    assert(stack_empty(stk) == 1);
}

void test_full_stack() {
    Stack s1 = stack_new(2);
    Stack *stk = &s1;
    StackResult res;

    stk = stack_push(stk, 10, &res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk, 20, &res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk, 30, &res);
    assert(res.status == STACK_FULL);
}

void test_stack() {
    Stack s1 = stack_new(5);
    Stack *stk = &s1;
    StackResult res;
    stk = stack_pop(stk, &res);
    assert(res.status == STACK_EMPTY);

    stk = stack_push(stk, 10, &res);
    assert(res.status == STACK_OK);
    stk = stack_push(stk, 20, &res);
    stk = stack_peek(stk, &res);
    assert(res.status == STACK_OK && res.data == 20);

    stk = stack_pop(stk, &res);
    assert(res.status == STACK_OK && res.data == 20);
    stk = stack_peek(stk, &res);
    assert(res.status == STACK_OK && res.data == 10);

    stk = stack_pop(stk, &res);
    assert(stack_empty(stk) == 1);

}

void test_expression(){
    assert(areBracketsBalanced("{()}[]")==true);
    assert(strcmp(evaluatePostfix("6 5 2 3 + 8 * + 3 + * "),"$")==0);
}

int main() {
    test_empty();
    test_add();
    test_Qdelete();
    test_newstack();
    test_stack_full();
    test_stack_empty();
    test_full_stack();
    test_stack();
    test_expression();

    return 0;
}
