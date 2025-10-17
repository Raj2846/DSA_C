#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp, *tail;

void create_list()
{
    int ch;
    head = 0;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data :");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    while (ch)
    {
        if (tail == 0)
        {
            tail = newnode;
            // if head pointer is not used only tail pointer is used
            tail->next = newnode;
        }
        else
        {
            // newnode next pointing to first node
            newnode->next = tail->next;
            // prev node contain address of newnode
            tail->next = newnode;
            // updating tail
            tail = newnode;
            // tail->next=head;
        }
        // tail->next=head; if head pointer is used

        printf("Do You Want To continue [0,1] :");
        scanf("%d", &ch);
    }
    display();
}

void display()
{
    if (tail == 0)
    {
        printf("List is empty");
    }
    else
    {
        temp = tail->next;
        do
        // while(temp->next!=tail)
        {
            printf("%d", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
        // for the last node to be display
        // printf("%d",temp->data);
    }
}

/*
void insert_beg()
{
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter data :");
    scanf("%d",&newnode->data);
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        // updating newnode next to head to isert at beg
        newnode->next=head;
        //updating head to newnode address
        head=newnode;
        //traversing to  last node
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        //updating last node address part to newnode address
        temp->next=head;
    }
    display();
}
*/

void insert_beg()
{
    head = 0;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (tail == 0)
    {
        tail = newnode;
        // as its only have one node the next part should contain address of itself
        tail->next = newnode;
        // tail->next=head;
    }
    else
    {
        // updating newnode next to the first node address
        newnode->next = tail->next;

        tail->next = newnode;

        // tail->next=head;
    }
}

void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("%d", &newnode->data);

    if (tail == 0)
    {
        printf("list is empty");
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insert_pos()
{
    int pos, i = 1, count;
    printf("Enter position :");
    scanf("%d", &pos);

    count = len_list();

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data :");
    scanf("%d", &newnode->data);

    if (pos < 0 && pos > count)
    {
        printf("Invalid Position ");
    }
    else if (pos == 1)
    {
        insert_beg();
    }
    else
    {
        // address of first node
        temp = tail->next;

        while (i < pos - 1)
        {
            temp = tail->next;
            i++;
        }

        // first updating newnode next to a node
        newnode->next = temp->next;
        // then  update temp next to newnode to connect the node
        temp->next = newnode;
    }
}

int len_list()
{
    int count = 0;
    temp = tail->next;

    while (temp != tail->next)
    {
        count++;
        temp = temp->next;
    }
    printf("%d", &count);
    return count;
}

void del_beg()
{
    temp = tail->next;
    if (temp == 0)
    {
        printf("List is empty");
    }
    else if (temp->next == temp)
    {
        // if only one node
        tail = 0;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
    display();
}

void del_end()
{
    struct node *prev;

    temp = tail->next;
    prev = temp;

    // as tail contain address of last node amd address of tail and temp->next become same at last node
    while (temp->next != tail->next)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = tail->next;
    tail = prev;
    free(temp);

    display();
}

void del_pos()
{
    struct node *current, *nextnode;
    int pos, i = 1, count;

    count = len_list();
    printf("Enter position :");
    scanf("%d", &pos);

    if (pos == -1 && pos > count)
    {
        printf("Invalid position ");
    }
    else if (pos == 1)
    {
        del_beg();
    }
    else
    {
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }

        nextnode = current->next;

        current->next = nextnode->next;

        free(nextnode);
    }

    display();
}

void rev_ll()
{
    struct node *current,*prev,*nextnode;
    //current for traversing

    //firs node
    current=tail->next;
    nextnode=current->next;
    if(tail==0)
    {
        printf("List is empty");
    }
    else if(tail->next==tail)
    {
        printf("There is only one node in list");
    }
    else
    {
        //last to update the first node address or link will be break
        prev=current;
        while(current !=tail)
        {
            //pointing current and nextnode to same location
            current=nextnode;
            //pointing nextnode to next node so that furthur traversing is possible
            nextnode=current->next;
            //updating current next to reverse the linklist
            current->next=prev;
        }

        //now to udpate first node address to last nopd address
        nextnode->next=tail;
        
        //updating tail to nextnode so that it contain address of first node
        tail=nextnode;
    }

    display();

}

void main()
{
    int ch;

    
    // clrscr();
    do
    {
        printf("1.creatw a link list\n 2.Exit\n");
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
            exit(0);
            break;
        default:
            printf("Invalid choice ");
            break;
        }
    } while (1);
}
