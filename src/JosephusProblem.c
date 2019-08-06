/**
* WAP to implement Josephus Problem. It is described as follows:
* Given a group of n men arranged in a circle under the edict that every mth man will be executed going around the circle until only one remains, 
* find the position L(n,m) in which you should stand in order to be the last survivor (Ball and Coxeter 1987)
**/

#include <stdio.h>
#include<conio.h>
#define MAX 20
struct queue
{
       int d[MAX];
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
void enqueue(int n)
{
     //printf("\nFront=%d ",q.front);
    // printf("\nRear=%d",q.rear);
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
int dequeue(int n)
{
    //printf("\nFront=%d ",q.front);
    //printf("\nRear=%d ",q.rear);
    if(empty())
               printf("\nUnderflow");
    else
    {
    	int i=0;
    	q.rear--;
        for(i=n;i<=q.rear;i++)
        {
        	q.d[i]=q.d[i+1];
		}
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
void perform(int n, int p,int previousvalueofi, int previousvalueofkill)
{
	int i;
	int kill=previousvalueofkill;
	if(q.front!=q.rear)
	{
		for(i=previousvalueofi;i<=q.rear;i++)
		{
			kill++;
			if(i>q.rear)
			{
				i=q.front;
			}
			if(kill==p)
			{
				dequeue(i);
				kill=0;
				break;
			}
		}
		if(i>q.rear)
		{
			i=q.front;
		}
		printf("\n");
		display();
		perform(n,p,i,kill);
	}
}

main()
{
	int i;
    initialise();
    int no, pos;
    printf("\nThere are n people standing in a circle waiting to be executed. The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom. Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.");
    printf("\nEnter the value of n and k");
    scanf("%d %d",&no, &pos);
    for(i=1;i<=no;i++)
	{
		enqueue(i);
	}
	perform(no,pos,q.front,0);
	printf("\nThe person who will be forever safe is ");
	display();
}
