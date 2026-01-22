#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void create_end()
{
    struct node *head, *temp, *newnode;
    head = NULL;
    int value, ch = 1;

    while (ch != 0)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter value ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1)? ");
        scanf("%d", &ch);
    }

    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
