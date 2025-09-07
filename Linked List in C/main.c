#include <stdlib.h>
#include <stdio.h>

typedef struct Node Node;

struct Node {
    int value;
    Node* next;
};

Node* create_node(Node* previous_node) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    if (previous_node != NULL) {
        previous_node -> next = new_node;
    }
    return new_node;
}

void delete_node(Node* previous_node) {
    Node* exact_node = previous_node->next;
    previous_node->next = exact_node->next;
    free(exact_node);
}

Node* search_node(Node* head_node, int index) {
    int i = 0;
    Node* node = head_node;
    while (node != NULL) {
        if (i == index) {
            return node;
        }
        node = node->next;
        i++;
    }
    return NULL;
}

void change_node_value(Node* head_node, int index, int value) {
    Node* searched_void = search_node(head_node, index);
    if (searched_void == NULL) {
            printf("Out of range\n");
    } else {
            Node* searched = searched_void;
            searched->value = value;
    }
}

void travel_all_nodes(Node* head_node) {
    Node* node = head_node;
    int i = 0;
    while (node != NULL) {
        printf("%d. Node & Value is = %d\n", i, node->value);
        node = node->next;
        i++;
    }
}

int main(void) {
    printf("Hello World\n");

    Node* head_node= create_node(NULL);
    head_node->value = 0;

    printf("How many node do you want ?\n");
    int node_count = 0;
    scanf("%d", &node_count);


    Node* previous_node = head_node;
    for (int i = 0; i<node_count-1;i++) {
        create_node(previous_node);
        previous_node = previous_node->next;
        previous_node->value = i+1;
    }

    travel_all_nodes(head_node);

    printf("Which node do you want to be deleted ?\n");
    int delete_index = 0;
    scanf("%d", &delete_index);
    if (delete_index == 0) {
        Node* head_node_will_be_deleted = head_node;
        head_node = head_node->next;
        free(head_node_will_be_deleted);
    } else {
        void* searched_previous_void = search_node(head_node, delete_index-1);
        if (searched_previous_void == NULL) {
            printf("Out of range\n");
            return -1;
        } else {
            Node* searched_previous = searched_previous_void;
            if (searched_previous->next != NULL) {
                delete_node(searched_previous);
                printf("Deleted\n");
            } else {
                printf("Out of range\n");
                return -1;
            }
        }
    }

    travel_all_nodes(head_node);

    printf("Which node do you want to change it's value ?\n");
    int change_node_value_index = 0;
    scanf("%d", &change_node_value_index);

    printf("What value do you want to assign ?\n");
    int new_node_value = 0;
    scanf("%d", &new_node_value);
    change_node_value(head_node, change_node_value_index, new_node_value);

    travel_all_nodes(head_node);
}