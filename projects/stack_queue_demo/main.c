#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack implementation
typedef struct Stack {
    int *data;
    int top;
    unsigned capacity;
} Stack;

Stack* createStack(unsigned capacity) {
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
    printf("Pushing %d onto the stack.\n", item);
}

int pop(Stack* stack) {
    if (isStackEmpty(stack))
        return -1; // Or some error value
    return stack->data[stack->top--];
}

int peek(Stack* stack) {
    if (isStackEmpty(stack))
        return -1; // Or some error value
    return stack->data[stack->top];
}

// Queue implementation

typedef struct Queue {
    int *data;
    int front, rear, size;
    unsigned capacity;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // Important: See explanation
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
    printf("Enqueuing %d into the queue.\n", item);
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1; // Or some error value
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int queueFront(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1; // Or some error value
    return queue->data[queue->front];
}

int queueRear(Queue* queue) {
    if (isQueueEmpty(queue))
        return -1; // Or some error value
    return queue->data[queue->rear];
}

int main() {
    // Stack Demo
    printf("Stack Demo:\n");
    Stack* stack = createStack(10);
    push(stack, 10);
    push(stack, 20);
    printf("Popping from the stack: %d\n", pop(stack));
    printf("Popping from the stack: %d\n", pop(stack));
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
    }
    free(stack->data);
    free(stack);

    // Queue Demo
    printf("\nQueue Demo:\n");
    Queue* queue = createQueue(10);
    enqueue(queue, 10);
    enqueue(queue, 20);
    printf("Dequeuing from the queue: %d\n", dequeue(queue));
    printf("Dequeuing from the queue: %d\n", dequeue(queue));
    if (isQueueEmpty(queue)) {
        printf("Queue is empty.\n");
    }
    free(queue->data);
    free(queue);

    return 0;
}