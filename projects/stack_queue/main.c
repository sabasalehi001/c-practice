#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation
typedef struct {
    int *items;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
    printf("Pushing: %d\n", item);
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1; // Or some other error value
    }
    return stack->items[stack->top--];
}

// Queue implementation
typedef struct {
    int *items;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->items = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

int isQueueFull(Queue* queue) {
    return queue->rear == queue->capacity - 1;
}

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->items[++queue->rear] = item;
    printf("Enqueuing: %d\n", item);
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1; // Or some other error value
    }
    return queue->items[queue->front++];
}

int main() {
    // Stack example
    printf("Stack:\n");
    Stack* stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("Popping: %d\n", pop(stack));
    printf("Popping: %d\n", pop(stack));
    printf("Popping: %d\n", pop(stack));

    // Queue example
    printf("\nQueue:\n");
    Queue* queue = createQueue(3);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printf("Dequeuing: %d\n", dequeue(queue));
    printf("Dequeuing: %d\n", dequeue(queue));
    printf("Dequeuing: %d\n", dequeue(queue));

    free(stack->items);
    free(stack);
    free(queue->items);
    free(queue);
    return 0;
}