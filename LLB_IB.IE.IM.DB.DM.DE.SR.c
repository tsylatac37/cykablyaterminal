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
    
    printf("ENTER VALUE AT BEGINNING: ");
    scanf("%d", &value);
    
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    
    return head;
}

struct node* im(struct node *head) {
    struct node *newnode, *temp;
    int pos, i = 1;

    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("ENTER VALUE TO INSERT IN MIDDLE: ");
    scanf("%d", &newnode->data);
    
    printf("ENTER POSITION TO INSERT: ");
    scanf("%d", &pos);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return head;
    }

    temp = head;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp != NULL) {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}

void sr(struct node *head) {
    struct node *temp = head;
    int value, pos = 1, found = 0;

    printf("Enter value to search: ");
    scanf("%d", &value);

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    
    if (found == 0) {
        printf("Element not found\n");
    }
}

struct node* db(struct node* head){
    struct node *temp;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct node* de(struct node* head){
    struct node *temp, *prevnode;
    temp = head;

    while(temp->next != NULL){
        prevnode = temp;
        temp = temp -> next;
    }
    if(head == temp){
        head = NULL;
    }
    else{
        prevnode->next = NULL;
    }
    free(temp);
    return head;
}

struct node* dm(struct node* head){
    struct node *temp,*nextnode;
    temp = head;
    int pos, i = 1;
    printf("ENTER POSITION (n): ");
    scanf("%d", &pos);

    while(i < pos-1){
        temp = temp -> next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    return head;
}

int main() {
    struct node *head = NULL;

    head = ie(head);
    disp(head);

    head = ib(head);
    disp(head);

    printf("INSERTING IN MIDDLE: \n");
    head = im(head);
    disp(head);

    printf("SEARCHING FOR ELEMENT: \n");
    sr(head);

    printf("DELETING BEGINNING ELEMENT: \n");
    head = db(head);
    disp(head);

    printf("DELETING ENDING ELEMENT: \n");
    head = de(head);
    disp(head);

    printf("DELETING AN ELEMENT OF POSITION n: \n");
    head = dm(head);
    disp(head);

    return 0;
}
