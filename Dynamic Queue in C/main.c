#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue Queue;

struct Queue {
    int* elements;
    int total_element_count;
};

int* enqueue(Queue* queue, int element) {
    int* new_allocation = (int*)realloc(queue->elements, (queue->total_element_count + 1)*sizeof(int));


    queue->elements[queue->total_element_count] = element;
    queue->total_element_count++;
    return &queue->elements[queue->total_element_count-1];
}

void* dequeue(Queue* queue, int* result) {
    if(queue->total_element_count == 0) {
        return NULL;
    }

    *result = queue->elements[0];
    memcpy(queue->elements, queue->elements+1, (queue->total_element_count-1)* sizeof(int));
    queue->total_element_count--;
    int* new_allocation = (int*)realloc(queue->elements, queue->total_element_count*sizeof(int));
    return queue;
}

int* get(Queue* queue, int index) {
    if(index >= queue->total_element_count) {
        return NULL;
    }

    return &queue->elements[index];
}

int search(Queue* queue, int value) {
    int current_index = 0;

    while(current_index < queue->total_element_count) {
        if (queue->elements[current_index] == value) {
            return current_index;
        }
        current_index++;
    }
    return -1;
}

int main() {
    printf("Hello World\n");

    Queue queue;
    
    int* first_allocation = (int*)malloc(0);
    if (!first_allocation) {
        printf("Error: First Allocation");
        return -1;
    }

    queue.elements = first_allocation;
    queue.total_element_count = 0;

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

    int* result_get = get(&queue, 0);

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