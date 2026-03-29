#include <stdio.h>
#include <stdlib.h>

// Stack implementation
typedef struct {
    int *data;
    int top;
    unsigned int capacity;
} Stack;

Stack* createStack(unsigned int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isStackFull(stack))
        return;
    stack->data[++stack->top] = item;
    printf("Stack: Push %d\n", item);
}

int pop(Stack* stack) {
    if (isStackEmpty(stack))
        return -1; // Or some other error value
    int popped = stack->data[stack->top--];
    printf("Stack: Pop: %d\n", popped);
    return popped;
}

// Queue implementation
typedef struct {
    int *data;
    int front, rear, size;
    unsigned int capacity;
} Queue;

Queue* createQueue(unsigned int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isQueueEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isQueueFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("Queue: Enqueue %d\n", item);
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1; // Or some other error value
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    printf("Queue: Dequeue: %d\n", item);
    return item;
}

int main() {
    // Stack demo
    Stack* stack = createStack(10);
    push(stack, 10);
    push(stack, 20);
    pop(stack);

    // Queue demo
    Queue* queue = createQueue(10);
    enqueue(queue, 100);
    enqueue(queue, 200);
    dequeue(queue);

    free(stack->data);
    free(stack);
    free(queue->data);
    free(queue);

    return 0;
}