/*WAP to create a Circular Queue Program which features: Enqueue, Dequeue and Display*/

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
    if((q.rear-q.front)==MAX-1)
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
void enqueue(int n)
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
     q.d[(q.rear%MAX)]=n;
     }
}
int dequeue()
{
    printf("\nFront=%d ",q.front);
    printf("\nRear=%d ",q.rear);
    if(empty())
               printf("\nUnderflow");
    else
    {
        q.front++;
        return q.d[((q.front-1)%MAX)];
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
          printf("%d ",q.d[i%MAX]);
         }
     }
}
main()
{
      initialise();
      int c=0; int d,b;
      while(c==0)
      {
              printf("1.Enqueue 2.Dequeue 3.Display");
              scanf("%d",&d);
              if(d==1)
              {
                      printf("Enter the element");
                      scanf("%d",&c);
                      enqueue(c);  
              }
              if(d==2)
              {
                      printf("\nPop = %d",dequeue());
              } 
              if(d==3)
              {
                      display();
              }
              printf("Do you want to continue, press 0.");
              scanf("%d",&c);
      }
}
