#include "appconst.h"
#include <stdbool.h>
#include <stdint.h>
#ifndef STACKNQUEUE_H_INCLUDED
#define STACKNQUEUE_H_INCLUDED

typedef struct _stack_ Stack;

struct _stack_{
    uint32_t size;
    int32_t top;
    float data[MAX_DEPTH];
};

typedef struct _stack_result_ StackResult;


struct _stack_result_{
    float data;
    uint8_t status;
};

/* Public interfaces */

Stack stack_new(uint32_t size);
uint8_t stack_full(const Stack *stk);
uint8_t stack_empty(const Stack *stk);
Stack* stack_push(Stack *stk, float ele, StackResult *res);
Stack* stack_pop(Stack *stk, StackResult *res);
Stack* stack_peek(Stack *stk, StackResult *res);
Stack* stack_push(Stack *stk, float ele, StackResult *res);
Stack* stack_pop(Stack *stk, StackResult *res);
Stack* stack_peek(Stack *stk, StackResult *res);
bool areBracketsBalanced(char exp[]);
int evaluatePostfix(char* exp);

typedef struct _queue_ Queue;

struct _queue_ {
    uint32_t size;
    uint32_t count;
    uint32_t rear;
    uint32_t front;
    int32_t data[Q_LEN];
};

typedef struct  _queue_result_ QueueResult;

struct _queue_result_ {
    int32_t data;
    uint32_t status;
};

/* Public interfaces */
Queue queue_new (uint32_t size);
uint8_t queue_full(Queue *q);
uint8_t queue_empty(Queue *q);
Queue* queue_add(Queue *q, int32_t ele, QueueResult *res);
Queue* queue_delete(Queue *q, QueueResult *res);
Queue* queue_delete(Queue *q, QueueResult *res);
uint32_t queue_length(Queue *q);

#endif // STACKNQUEUE_H_INCLUDED
