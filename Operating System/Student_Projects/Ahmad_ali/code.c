#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Structure to represent a process
typedef struct {
    int id;
    int priority;
    int burst_time;
} Process;

// Function to initialize a process
Process* createProcess(int id, int priority, int burst_time) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->id = id;
    process->priority = priority;
    process->burst_time = burst_time;
    return process;
}

// Structure to represent a queue
typedef struct {
    Process* queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if a queue is empty
int isQueueEmpty(Queue* q) {
    return (q->front == -1);
}

// Function to check if a queue is full
int isQueueFull(Queue* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// Function to enqueue a process into a queue
void enqueue(Queue* q, Process* process) {
    if (isQueueFull(q)) {
        printf("Queue is full. Cannot enqueue process.\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    }
    q->queue[q->rear] = process;
}

// Function to dequeue a process from a queue
Process* dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty. Cannot dequeue process.\n");
        return NULL;
    }
    Process* process = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    return process;

}
// Function to simulate process execution in multilevel queues
void runMultilevelQueue(Queue* highPriorityQueue, Queue* mediumPriorityQueue, Queue* lowPriorityQueue) {
    int time = 0;
    int quantum = 1;

    while (!isQueueEmpty(highPriorityQueue) || !isQueueEmpty(mediumPriorityQueue) || !isQueueEmpty(lowPriorityQueue)) {
        if (!isQueueEmpty(highPriorityQueue)) {
            Process* process = dequeue(highPriorityQueue);
            printf("Running process %d from High Priority Queue for time quantum %d\n", process->id, quantum);
            process->burst_time -= quantum;
            time = time + quantum;}

            if (process->burst_time <= 0) {
                printf("Process %d executed successfully.\n", process->id);
                free(process);
            } else {
                enqueue(mediumPriorityQueue, process);
            }
           else if (!isQueueEmpty(mediumPriorityQueue)) {
            Process* process = dequeue(mediumPriorityQueue);
            printf("Running process %d from Medium Priority Queue for time quantum %d\n", process->id, quantum);
            process->burst_time -= quantum;
            time = time + quantum;
}}}