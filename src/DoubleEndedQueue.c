/*WAP to create a Double Ended Queue Program which features: Enqueue, Dequeue and Display*/

#include <stdio.h>
#include<conio.h>
#define MAX 3
struct queue
{
       int d[10];
       int front;
       int rear;
}q;

int initialise()
{
    q.rear=q.front=-1;
}
int full()
{
    if((q.rear==MAX-1))
        return 1;
    else
        return 0;
}
int empty()
{
    if(((q.rear==q.front)&&(q.rear==-1))||(q.front>q.rear))    
    return 1;
    else
    return 0;
}
void enqueuefront(int n)
{
     printf("\nFront=%d ",q.front);
     printf("\nRear=%d",q.rear);
     if(q.front==-1)
         printf("\nOverflow");
     else
     {
     q.front--;
     q.d[(q.front)]=n;
     }
}
void enqueuerear(int n)
{
     printf("\nFront=%d ",q.front);
     printf("\nRear=%d",q.rear);
     if(full())
         printf("\nOverflow");
     else
     {
     if(q.front==-1)
                   q.front++;
     q.rear++;
     q.d[(q.rear)]=n;
     }
}
int dequeuefront()
{
    printf("\nFront=%d ",q.front);
    printf("\nRear=%d ",q.rear);
    if(empty())
               printf("\nUnderflow");
    else
    {
        q.front++;
        return q.d[((q.front-1))];
    }
}
int dequeuerear()
{
    printf("\nFront=%d ",q.front);
    printf("\nRear=%d ",q.rear);
    if(empty())
               printf("\nUnderflow");
    else
    {
        q.rear--;
        return q.d[q.rear];
    }
}
void display()
{
     if(empty())
               printf("\nUnderflow");
     else
     {
         int i;
         for(i=q.front;i<=q.rear;i++)
         {
          printf("%d ",q.d[i]);
         }
     }
}
int main()
{
      initialise();
      int c=0; int d,b,x;
      while(c==0)
      {
              printf("1.Enqueue 2.Dequeue 3.Display");
              scanf("%d",&d);
              if(d==1)
              {
              	printf("Enter the element");
                scanf("%d",&c);
                printf("1.Enqueue from Front 2.Enqueue from Rear");
              	scanf("%d",&x);
              	if(x==1)
                    enqueuefront(c); 
				else if(x==2)
					enqueuerear(c);
				else
					printf("Wrong Choice");
					 
              }
              if(d==2)
              {
              	printf("1.Dequeue from Front 2.Dequeue from Rear");
              	scanf("%d",&x);
              	if(x==1)
                    printf("\nPop = %d",dequeuefront());
				else if(x==2)
					printf("\nPop = %d",dequeuerear());
				else
					printf("Wrong Choice");
              } 
              if(d==3)
              {
                      display();
              }
              printf("Do you want to continue, press 0.");
              scanf("%d",&c);
      }
      getch();
      return 0;
}
