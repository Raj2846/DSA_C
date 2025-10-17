#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime(int n)
{    
    int i;
    if(n<2) return 0;
    for(i=2;i<=n/2;i++)
    {
        if(n % i==0)
        {
            return 0;
        }
    }
    return 1;
}


int count_dig(int n)
{
    int count=0;

    while(n>0)
    {
        count++;
        n=n/10;
    }
    return count;
}


void cir_pri(int n)
{
    int num=n;
    int i;
    int digit=count_dig(n);
    int is_cir_pri=1;

    for(i=0;i<digit;i++)
    {
        if(prime(num)==0)
        {
            is_cir_pri=0;
            break;
        }
        int rem=num%10;
        num=(num/10)+(rem*pow(10,digit-1));
    }

    if(is_cir_pri)
        printf("circular prime\n");
    else
        printf("not circular prime\n");
}


void main()
{

    int ch,n;

    do
    {
        printf("\n1.check circular prime\n2.exit\n");
        printf("Enter choice ");
        scanf("%d",&ch);
          
        switch(ch)
        {

            case 1:
                printf("Enter number :");
                scanf("%d",&n);
                cir_pri(n);
                break;

            case 2:
                exit(0);
                break;
            
            default:
                printf("Invalid choice");
                break;

        }
    } while (1);
   // return 0;
    
}