/*WAP to create a Priority Queue using Circular Queue Program which features: Enqueue, Dequeue and Display*/

#include <stdio.h>
#include<conio.h>
#define MAX 5
struct queue
{
       int d[10];
	   int pr[10];
       int front;
       int rear;
}q;

void sort()
{
int m,n,i,j;
int temp1,temp2,temp3;
	for(i=q.front;i<q.rear;i++)
         {
			 temp3=i;
          for(j=i+1;j<=q.rear;j++)
	      {
			  if(q.pr[j%MAX]>q.pr[temp3%MAX])
			  {
			   temp3=j;
			  }
		  }
		  if(temp3!=i)
			  {
			   temp1=q.pr[i%MAX];
			   temp2=q.d[i%MAX];
			   q.pr[i%MAX]=q.pr[temp3%MAX];
			   q.d[i%MAX]=q.d[temp3%MAX];
			   q.pr[temp3%MAX]=temp1;
			   q.d[temp3%MAX]=temp2;
			  }
         }
}

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
void enqueue(int n, int p)
{
     if(full())
         printf("\nOverflow");
     else
     {
     if(q.front==-1)
                   q.front++;
     q.rear++;
     q.d[(q.rear%MAX)]=n;
	 q.pr[(q.rear%MAX)]=p;
	 sort();
     }
	 printf("\nFront=%d ",q.front);
     printf("\nRear=%d",q.rear);
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
          printf("\nData=%d ",q.d[i%MAX]);
		  printf("\nPriority=%d ",q.pr[i%MAX]);
         }
     }
}
main()
{
      initialise();
      int c=0,p=0; int d,b;
      while(c==0)
      {
              printf("1.Enqueue 2.Dequeue 3.Display");
              scanf("%d",&d);
              if(d==1)
              {
                      printf("Enter the element");
                      scanf("%d",&c);
					  printf("Enter the priority");
                      scanf("%d",&p);
                      enqueue(c,p);
              }
              if(d==2)
              {
                      printf("\nPop = %d",dequeue());
              } 
              if(d==3)
              {
                      display();
              }
              printf("\nDo you want to continue, press 0.");
              scanf("%d",&c);
      }
}
