#include <stdio.h>
#include <stdlib.h>

// Stack implementation
typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
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
}

int pop(Stack* stack) {
    if (isStackEmpty(stack))
        return -1; // Indicate error, could use a better error handling mechanism
    return stack->data[stack->top--];
}

// Queue implementation
typedef struct {
    int *data;
    int front, rear, size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
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
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1; // Indicate error
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int main() {
    // Stack demo
    Stack* stack = createStack(3);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Stack:\n");
    while (!isStackEmpty(stack)) {
        printf("Popped: %d\n", pop(stack));
    }
    free(stack->data);
    free(stack);

    // Queue demo
    Queue* queue = createQueue(3);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printf("Queue:\n");
    while (!isQueueEmpty(queue)) {
        printf("Dequeued: %d\n", dequeue(queue));
    }
    free(queue->data);
    free(queue);

    return 0;
}
