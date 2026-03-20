#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation
typedef struct {
    int *items;
    int top;
    int capacity;
} Stack;

Stack *createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

int isStackFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Pushing: %d\n", item);
    stack->items[++stack->top] = item;
}

int pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Or some error value
    }
    return stack->items[stack->top--];
}

void freeStack(Stack *stack) {
    free(stack->items);
    free(stack);
}

// Queue implementation
typedef struct {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(Queue *queue) {
    return queue->front > queue->rear;
}

int isQueueFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;
}

void enqueue(Queue *queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enqueueing: %d\n", item);
    queue->items[++queue->rear] = item;
}

int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1; // Or some error value
    }
    return queue->items[queue->front++];
}

void freeQueue(Queue *queue) {
    free(queue->items);
    free(queue);
}

int main() {
    // Stack demo
    printf("Stack:\n");
    Stack *stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));

    freeStack(stack);

    // Queue demo
    printf("\nQueue:\n");
    Queue *queue = createQueue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Dequeueing: %d\n", dequeue(queue));
    printf("Dequeueing: %d\n", dequeue(queue));
    printf("Dequeueing: %d\n", dequeue(queue));

    freeQueue(queue);

    return 0;
}