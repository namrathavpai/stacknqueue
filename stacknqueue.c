#include <assert.h>
#include "stacknqueue.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

Queue queue_new(uint32_t size){
    size = (size > 0 && size < Q_LEN)? size: Q_LEN;
    Queue q1 = {size, 0, 0, 0, {0}};
    return q1;
}

uint8_t queue_full(Queue *q){
    assert(q != NULL);
    return (q->count == q->size);
}

uint8_t queue_empty(Queue *q){
    assert(q != NULL);
    return (q->count == 0);
}

Queue* queue_add(Queue *q, int32_t ele, QueueResult *res) {
    assert(q != NULL);
    if (q->count < q->size){
        q->data[q->rear] = ele;
        q->rear = (q->rear + 1) % q->size;
        ++q->count;
        res->status = QUEUE_OK;
    } else {
        res->status = QUEUE_FULL;
    }

    return q;
}

Queue* queue_delete(Queue *q, QueueResult *res){
    assert(q != NULL);
    if (q->count != 0){
        res->data = q->data[q->front];
        q->front = (q->front + 1) % q->size;
        --q->count;
        res->status = QUEUE_OK;
    } else {
        res->status = QUEUE_EMPTY;
    }
    return q;
}

uint32_t queue_length(Queue *q) {
    assert(q != NULL);
    return q->count;
}

Stack stack_new(uint32_t size){
    size = (size > 0 && size < MAX_DEPTH)? size: MAX_DEPTH;
    Stack s1 = { size, -1, {0} };
    return s1;
}

uint8_t stack_full(const Stack *stk){
    assert (stk != NULL);
    return ( (stk->top + 1 == stk->size));
}

uint8_t stack_empty(const Stack *stk){
    assert (stk != NULL);
    return (stk->top == -1);
}

Stack* stack_push(Stack *stk, float ele, StackResult *res){
    assert (stk != NULL);
    if ((stk->top + 1) < stk->size) {
        stk->data[++stk->top] = ele;
        res->status = STACK_OK;
        res->data = ele;


    } else {
        res->status = STACK_FULL;
    }

    return stk;
}

Stack* stack_pop(Stack *stk, StackResult *res){
    assert(stk != NULL);
    if (stk->top != -1){
        res->data = stk->data[stk->top];
        --stk->top;
        res->status = STACK_OK;
    } else {
        res->status = STACK_EMPTY;
    }

    return stk;
}

Stack* stack_peek(Stack *stk, StackResult *res){
    assert(stk != NULL);
    if (stk->top != -1){
        res->data = stk->data[stk->top];
        res->status = STACK_OK;
    } else {
        res->status = STACK_EMPTY;
    }

    return stk;
}

bool isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

bool areBracketsBalanced(char exp[]) {
    int i = 0;
    Stack* stack = NULL;
    StackResult res;
    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            stack_push(&stack, exp[i],&res);

        if (exp[i] == '}' || exp[i] == ')'
            || exp[i] == ']') {

            if (stack == NULL)
                return 0;

            else if (!isMatchingPair(stack_pop(&stack,&res), exp[i]))
                return 0;
        }
        i++;
    }
    if (stack == NULL)
        return 1;
    else
        return 0;
}

int evaluatePostfix(char* exp)
{
    Stack stack = stack_new(strlen(exp));
    StackResult res;
    int i;

    if (!stack_empty) return -1;

    for (i = 0; exp[i]; ++i)
    {
        if (isdigit(exp[i]))
            stack_push(&stack, exp[i] - '0',&res);

        else
        {
            int val1 = stack_pop(&stack, &res);
            int val2 = stack_pop(&stack, &res);
            switch (exp[i])
            {
            case '+': stack_push(&stack, val2 + val1, &res); break;
            case '-': stack_push(&stack, val2 - val1, &res); break;
            case '*': stack_push(&stack, val2 * val1, &res); break;
            case '/': stack_push(&stack, val2/val1, &res); break;
            }
        }
    }
    return stack_pop(&stack, &res);
}
