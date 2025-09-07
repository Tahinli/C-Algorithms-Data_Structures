#include <stdio.h>
#include <string.h>

typedef struct Queue Queue;

const int QUEUE_SIZE = 10;

struct Queue {
    int* elements;
    int last;
};

int* enqueue(Queue* queue, int element) {
    if (queue->last <= 0) {
        return NULL;
    }

    queue->elements[queue->last] = element;
    queue->last--;
    return &queue->elements[queue->last+1];
}

void* dequeue(Queue* queue, int* result) {
    if(queue->last == QUEUE_SIZE-1) {
        return NULL;
    }
    *result = queue->elements[QUEUE_SIZE-1];
    memcpy(&queue->elements[queue->last+2], &queue->elements[queue->last+1], QUEUE_SIZE-queue->last-1);
    queue->last++;
    return queue;
}

int* get(Queue* queue, int index) {
    if(index > QUEUE_SIZE-1 || index < queue->last) {
        return NULL;
    }

    return &queue->elements[index];
}

int search(Queue* queue, int value) {
    int current_index = QUEUE_SIZE-1;
    while(current_index >= queue->last) {
        if (queue->elements[current_index] == value) {
            return current_index;
        }
        current_index--;
    }
    return -1;
}

int main() {
    printf("Hello World\n");

    Queue queue;
    queue.last = QUEUE_SIZE-1;
    int elements[10];
    queue.elements = elements;

    int* result_enqueue = enqueue(&queue, 3);
    if(!result_enqueue) {
        printf("Error: Enqueue\n");
        return -1;
    }

    int* result_enqueue_2 = enqueue(&queue, 5);
    if(!result_enqueue_2) {
        printf("Error: Enqueue 2\n");
        return -1;
    }

    int* result_get = get(&queue, 9);

    if(!result_get) {
        printf("Error: Get\n");
        return -1;
    }

    printf("9. Index = %d\n", *result_get);

    int dequeued = 0;
    int* result_dequeue = dequeue(&queue, &dequeued);

    if(!result_dequeue) {
        printf("Error: Dequeue\n");
        return -1;
    }

    printf("First Element = %d\n", dequeued);

    int result_search = search(&queue, 5);

    if(result_search == -1) {
        printf("Error: Search\n");
        return -1;
    }

    printf("Searched Index = %d\n", result_search);

    int result_search_2 = search(&queue, 10);

    if(result_search_2 == -1) {
        printf("Error: Search 2\n");
        return -1;
    }

}