#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* head = NULL;

struct node* createnode(int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void create_list(int val) {
    struct node* newNode = createnode(val);

    if (head == NULL) {
        head = newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Node %d inserted successfully.\n", val);
}

void insert_left(int target, int val) {
    if (head == NULL) {
        printf("List is empty. Cannot search for %d.\n", target);
        return;
    }

    struct node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Target node %d not found.\n", target);
        return;
    }

    struct node* newNode = createnode(val);

    if (temp == head) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
    printf("Inserted %d to the left of %d.\n", val, target);
}

void delete_val(int val) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node* temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node %d not found.\n", val);
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else {
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);
    printf("Node %d deleted successfully.\n", val);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("\nList contents: NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, target;

    while (1) {
        printf("\n\n--- DOUBLY LINKED LIST MENU ---");
        printf("\n1. Create List (Insert End)");
        printf("\n2. Insert to LEFT of a node");
        printf("\n3. Delete based on value");
        printf("\n4. Display contents");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                create_list(val);
                break;
            case 2:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new value to insert to the left: ");
                scanf("%d", &val);
                insert_left(target, val);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                delete_val(val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
