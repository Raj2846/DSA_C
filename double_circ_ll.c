typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *newnode, *nextnode, *current, *tail, *head;

void create__ll()
{
    int ch;
    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);

        if (head == 0)
        {
            head = tail = newnode;
            // if single node then prev and next will contain address of itself i.e first node address
            newnode->prev = head;
            nextnode->next = head;
        }
        else
        {
            // if its more than 1 node than to link the list you will have to update 5 things
            // 1.next address of previous node
            tail->next = newnode;
            // 2. then prev address of newnode
            newnode->prev = tail;
            // 3.next address of newnode
            newnode->next = head;
            // 4.prev address of head node
            head->prev = newnode;
            // 5.tail to last node
            tail = newnode;
            printf("Do you wan to continue 0,1");
            scanf("%d", &ch);
        }
    }
}

void display()
{
    node *temp;
    temp = head;
    if (head == 0)
    {
        printf("List empty");
    }
    else
    {
        do
        {
            printf("%d", temp->data);
            temp = temp->next;
        } while (temp != tail->next);
    }
}

void insert_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &newnode->data);

    if (head == 0)
    {
        // head=tail=newnode;
        create__ll();
    }
    else
    {
        // 1.first update newnode next to the first node in linklist
        newnode->next = head;
        // 2.updating the first node prev to newnode address to link it
        head->prev = newnode;
        // 3.updating newnode previous to last node address
        newnode->prev = tail;
        // 4.updating last node next to the newnode address as it tis first node now
        tail->next = newnode;
        // 5.lastly updating head to finally make newnode as first node of linklist
        head = newnode;
    }
}

void insert_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data :");
    scanf("%d", &newnode->data);

    if (head == 0)
    {
        // head=tail=newnode;
        create__ll();
    }
    else
    {
        // update previous of newnode to the last node that is in tail pointer
        newnode->prev = tail;
        // now using tail pointer we will access last noe and update the next part of last node to newnode sonewnode become last node
        tail->next = newnode;
        // now link last node to first node by updating next part of lsat node to head address
        newnode->next = head;
        // now update the first node previous should contain last node address
        head->prev = newnode;
        // update tail pointer to the new last node
        tail = newnode;
    }
    display();
}

int length()
{
    int count = 0;
    node *temp;
    temp = head;
    if (head == 0)
    {
        return 0;
    }
    else
    {
        do
        {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        return count;
    }
}

void insert_pos()
{
    int pos, i = 1, l;
    struct node *temp;

    l = length();
    printf("enter position :");
    scanf("%d", &pos);
    
    if (head == 0)
    {
        create_ll();
    }
    else if (pos == 1)
    {
        insert_beg();
    }
    else if(pos >l)
    {
        insert_end();
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d", &newnode->data);
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }

        //updating th newnode prev to temp
        newnode->prev=temp;
        //updating newnode next to temp next
        newnode->next=temp->next;

        //updating the temp next to newnode
        temp->next=newnode;

        //updating the next node using address in newnode 
        newnode->next->prev=newnode;

    }
}

void delete_beg()
{
    node * temp;
    temp=head;
    if(head==0)
    {
        printf("list is empty");
    }
    else if(head=head->next)
    {
        head=tail=temp;
        free(temp);
    }
    else
    {
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void delete_end()
{
    node *temp = tail;

    if(head==0)
    {
        printf("List is empty ");
    }
    else if(head==head->next)
    {
        head=tail=temp;
        free(temp);
    }
    else
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp); 
    }
}

void delete_pos()
{
    int pos,i=1,l;
    node *temp;
    temp=head;
    l=length();

    printf("Enter position to delete");
    sacnf("%d",&pos);

    //if condition for del beg and del end and invalid pos after that this in else
    while(i<pos)
    {
        temp=temp->next;
        i++;
    }
    //updating the previous node next to next node
    temp->prev->next=temp->next;
    //updating the next node prev to previous node
    temp->next->prev=temp->prev;

    free(temp);
}

void main()
{
    int ch;
    do
    {
        printf("1.create 2.display 3.insert_beg 4.insert_end 5.insert_pos 6.delete_beg 7.delete_end 8.delete_pos 9.length 10.exit");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create__ll();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_beg();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            insert_pos();
            break;
        case 6:
            delete_beg();
            break;
        case 7:
            delete_end();
            break;
        case 8:
            delete_pos();
            break;
        case 9:
            printf("Length is %d", length());
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid input");
            break;
        }
    } while (ch != 10);
}