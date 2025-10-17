#include <stdio.h>
#include <stdlib.h>

// doubly link list
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *temp, *newnode, *tail;

void create_list()
{
    int ch;
    head = 0;

    while (ch)
    {

        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data :");
        scanf("%d", &newnode->data);
        newnode->prev = 0;
        newnode->next = 0;

        if (head == 0)
        {
            head = temp = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    printf("Do you want to continue(0,1) :");
    scanf("%d", &ch);
}

// Maintaning tail pointrt at th last node for operations
void insert_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data :");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    // linking newnode to head node
    head->prev = newnode;
    // linking newnode to head
    newnode->next = head;
    // updating head to newnode as it is the first node now
    head = newnode;
    // pointing previous part of newnode to null as it is the first node
    newnode->prev = 0;
}

void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data :");
    scanf("%d", &newnode->data);
    newnode->prev = 0;
    newnode->next = 0;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    newnode->next = 0;
    tail = newnode;
}

void insert_pos()
{
    int pos, i = 1;
    printf("Enter position :");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid POsition");
    }
    else if (pos == 1)
    {
        insert_beg();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter date :");
        scanf("%d", &newnode->data);

        temp = head;
        // traversing to (pos-1)th node as insdex is positino -1
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        // newnode ke next par aage ka address hai(newnode->next) usko access kar ke fir uska prev ko access karenga (newnode->next->perv) and usme newnode ka address dal dega
        newnode->next->prev = newnode;
    }
}

void insert_after_pos()
{
    int pos, i = 1;
    printf("Enter position :");
    scanf("d", &pos);

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &newnode->data);

    if (pos < 1)
    {
        printf("Invalid position :");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void del_beg()
{
    temp = head;
    head = head->next;
    head->prev = 0;
    // clearing memory of first node
    free(temp);
}

void del_end()
{
    temp = tail;
    tail = tail->prev;
    tail->next = 0;
    // clearing memory of last node
    free(temp);
}

void del_pos()
{
    int pos, i = 1;
    printf("Enter position to delete :");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid Position ");
    }
    else
    {
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

void reverse()
{
    struct node *nextnode, *current;

    current = head;

    while (current != 0)
    {
        // using pointer to point to swap next and prev
        nextnode = current->next;

        // swaping address of next anf prev for each node
        current->next = current->prev;
        current->prev = nextnode;
        // updating current and nextnode to next node
        current = nextnode;
    }
    // updating head to tail as it is the first node now
    current = head;

    // updating tail to head as it is the last node now
    head = tail;

    // updating tail to current as it is the last node now
    tail = current;
}

void main()
{
    int ch;
    // clrscr();
    do
    {
        printf("1.create list\n 2.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create_list();
            break;
        case 2:
            insert_beg();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_pos();
            break;
        case 5:
            insert_after_pos();
            break;
        default:
            printf("Invalid choice ");
            break;
        }
    } while (1);
}
