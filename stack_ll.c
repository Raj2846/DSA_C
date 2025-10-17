#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;

void push_ll(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    // first node
    newnode->data = x;
    // here the next part is null as its a first node
    newnode->link = top;
    // now top is pointing to newnode
    top = newnode;
}

void display()
{
    struct node *temp;
    temp = top;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        printf("Top most element is %d\n", top->data);
    }
}

void pop()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Underflow condition\n");
        return;
    }
    else
    {
        top = top->link;
        printf("Popped item is %d\n", temp->data);
        fee(temp);
    }
}

void main()
{
    int ch, x;
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to be pushed");
            scanf("%d", &x);
            push_ll(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    } while (1);
}