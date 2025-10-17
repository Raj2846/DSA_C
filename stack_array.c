#include <stdio.h>
#include <stdlib.h>
#define N 10
int stack[N];
int top = -1;

void push()
{
    int x;
    printf("Enter value to be pushed");
    scanf("%d", &x);

    if (top == N - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        // ncrementing top from -1 to 0 and then adding value to stack
        top++;
        // top because it is the index where we want to add value i.e stack[0]
        stack[top] = x;
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        item = stack[top];
        top--;
        printf("Popped item is %d\n", item);
    }
}

void peek()
{
    
    if (top == -1)
    {
        printf("Underflow condition\n");
    }
    else
    {
        printf("Top most element is %d\n",stack[top]);
    }
}

void display()
{
    int i;
    for(i=top;i>-1;i--)
    {
        printf("%d",stack[i]);
        printf("\n");
    }
}

void main()
{
    int ch;
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice :");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
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
    }while(1);
}