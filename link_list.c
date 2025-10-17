#include <stdio.h>
#include <stdlib.h>

// singly link list
struct node
{
    int data;
    struct node *next;
};

// cirular link list
struct node2
{
    int data;
    struct node2 *next;
};

// doublu circular link list
struct node3
{
    int data;
    struct node3 *next;
    struct node3 *prev;
};

struct node *head, *temp, *newnode;

void display()
{
    // printing the link list
    temp = head;
    while (temp != 0)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

void create_list()
{
    int ch;
    // creating pointer to save address of node
    // struct node *head,*newnode,*temp;
    head = 0;
    while (ch)
    {
        // Memory allocation
        newnode = (struct node *)malloc(sizeof(struct node));

        // taking input
        printf("Enter data :");

        // using arrow operator to access data member of structure
        scanf("%d", &newnode->data);

        // creating first node so the first node address part will be empty or null
        newnode->next = 0;

        // linking head to first node if head is empty
        if (head == NULL)
        {
            // linking head and temp to newnode as it is the first node
            head = temp = newnode;
        }
        // head=newnode;
        else
        {
            // linking new node to head node using temp pointer as its is link to head node
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue to add another node [0,1]");
        scanf("%d", &ch);
    }
    display();
}

void insert_beg()
{
    // struct node *head,*newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data ");
    scanf("%d", &newnode->data);
    // pointing to first node using head pointer
    newnode->next = head;
    // changing head to newnode as it is the first node now
    head = newnode;

    display();
}

void insert_end()
{
    // struct node *head,*newnode,*temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data ");
    scanf("%d", &newnode->data);

    temp = head;
    // temp is used to traverse to the last node after that only insertion is possible at end
    while (temp->next != NULL)
    {
        // temp is updated to next node till it reaches the last node
        temp = temp->next;
    }
    // linking last node to newnode
    temp->next = newnode;
    // pointing newnode to null as it is the last node
    newnode->next = 0;

    display();
}

void insert_pos()
{
    int pos, count, i = 1;
    // struct node *head,*newnode,*temp;
    count = len_list();

    // getting position to enter data
    printf("Enter position to enter data :");
    scanf("%d", &pos);

    if (pos > count)
    {
        printf("Invalid position ");
    }
    else
    {
        temp = head;
        // traversing to the position where data is to be entered
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }

        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter data :");
        scanf("%d", &newnode->data);

        // linking newnode to next node of temp
        newnode->next = temp->next;

        // linking temp to newnode
        temp->next = newnode;
    }

    display();
}

void del_beg()
{
    temp = head;
    // linking head to next node of first node
    head = temp->next;
    // freeing memory of first node
    free(temp);
    display();
}

void del_end()
{
    struct node *prevnode;
    temp = head;
    while (temp->next != 0)
    {
        // storing address of second last node
        prevnode = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        head = 0;
    }
    else
    {

        // linking second last node to null as it is the last node now
        prevnode->next = 0;
        free(temp);
    }

    display();
}

void del_pos()
{
    int pos, i = 1;
    struct node *nextnode;
    temp = head;

    printf("enter positon to delete :");
    scanf("%d", &pos);

    while (i < pos - 1)
    {
        // traversing to the node previous to the node to be deleted
        temp = temp->next;
        i++;
    }
    // storing address of node to be deleted
    nextnode = temp->next;

    // linking previous node to the next node of the node to be deleted
    temp->next = nextnode->next;

    // freeing memory of the node to be deleted
    free(nextnode);
    display();
}

int len_list()
{
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }

    printf("Length is %d", count);
    return count;
}

// three pointer are required prev,current,nextnode
void rev_list()
{
    struct node *prev, *nextnode, *current;

    prev = 0;
    current = head;
    nextnode = head;

    while (nextnode != 0)
    {
        // Step 1:updating nextnode value to next node so after link is break it still contains address of next node
        nextnode = nextnode->next;

        // step 2: change the next value of current(current->next) to previous node value

        current->next = prev;

        // step 3:updating prev node value to current as it is the previous node for next iteration
        prev = current;

        // step 4: updating current to nextnode as it is the next node for next iteration
        current = nextnode;
    }
    head = prev;
    display();
}

// Doubly link list functions

void main()
{
    int ch;
    // clrscr();
    do
    {
        printf("1.creatw a link list\n 2.Insert at begnning\n 3.Insert ata End\n 4.Insert at any position\n 5.Delete at begnning 6.Delete at End\n 7.Delete at Position\n 8.Length of list\n 9.Reverse Link list 10.Exit\n");
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
            del_beg();
            break;
        case 6:
            del_end();
            break;
        case 7:
            del_pos();
            break;
        case 8:
            len_list();
            break;
        case 9:
            rev_list();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid choice ");
            break;
        }
    } while (1);
}
