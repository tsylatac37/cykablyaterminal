#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* ie(struct node *head) {
    struct node *newnode, *temp;
    int ch = 1;
    int value;

    while (ch != 0) {
        newnode = (struct node*)malloc(sizeof(struct node));
        
        printf("Enter value: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to insert? (1-yes, 0-no): ");
        scanf("%d", &ch);
    }
    return head;
}

void disp(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* ib(struct node *head) {
    struct node *newnode;
    int value;

    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter value at beginning: ");
    scanf("%d", &value);
    
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    
    return head;
}

int main() {
    struct node *head = NULL;

    head = ie(head);
    disp(head);

    head = ib(head);
    disp(head);

    return 0;
}
