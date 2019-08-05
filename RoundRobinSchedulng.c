/*WAP to create a CPU scheduling algorithm called Round Robin Scheduling, where each process is assigned a fixed time slot in a cyclic way*/

#include <stdio.h>
#include<conio.h>
#include <stdbool.h>
#define MAX 5
int quan=0;
struct queue
{
       int at[MAX];
       int et[MAX];
       int wait[MAX];
       int turn[MAX];
       int start[MAX];
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
	int i, z=0;
    if(((q.rear==q.front)&&(q.rear==-1))||(q.front>q.rear))    
    return 1;
    else
    {
    	for(i=q.front;i<=q.rear;i++)
    	{
    		if(q.et[i]!=0)
    			z=1;
		}
		if(z==0)
		return 1;
		else
		return 0;
	}
}
void enqueue(int n1, int n2)
{
     //printf("\nFront=%d ",q.front);
     //printf("\nRear=%d",q.rear);
     if(full())
         printf("\nOverflow");
     else
     {
	     if(q.front==-1)
	    	q.front++;
	     q.rear++;
	     q.at[(q.rear)]=n1;
	     q.et[(q.rear)]=n2;
	     q.wait[(q.rear)]=n2;
	     q.turn[MAX]=0;
	     q.start[MAX]=0;
     }
}
int dequeue()
{
	int n1,n2;
    //printf("\nFront=%d ",q.front);
    //printf("\nRear=%d ",q.rear);
    if(empty())
    {
	}
        //printf("\nUnderflow");
    else
    {
    	for(n1=q.front;n1<=q.rear;n1++)
	    {
	        if(q.et[n1]<=quan)
	        {
	        	for(n2=q.front;n2<=q.rear;n2++)
	    		{
					if(q.et[n2]!=0)
					{
						q.turn[n2]+=q.et[n1];
			 		}
				}
				q.et[n1]=0;
			}
			else
			{
				for(n2=q.front;n2<=q.rear;n2++)
	    		{
					if(q.et[n2]!=0)
					{
						q.turn[n2]+=quan;
					}
				}
				q.et[n1]=q.et[n1]-quan;
			}
		}
	/*	int i1;
         for(i1=q.front;i1<=q.rear;i1++)
         {
          printf("\nET[%d] = %d", i1, q.et[i1]);
      	 }
		//display();
		*/
		dequeue();
    }
}
void display(int np)
{
	 float avgturn=0, avgwait=0;
     if(((q.rear==q.front)&&(q.rear==-1))||(q.front>q.rear))
               printf("\nUnderflow");
     else
     {
         int i;
         for(i=q.front;i<=q.rear;i++)
         {
		 	printf("\nP%d   \tTurnaround Time=%d\t     Waiting Time=%d ",i, (q.turn[i]-q.at[i]), (q.turn[i]-q.wait[i]-q.at[i]));
		 	avgturn+= (q.turn[i]-q.at[i]);
		 	avgwait+= (q.turn[i]-q.wait[i]-q.at[i]);
		 }
		 printf("\nAverage Turnaround Time = %f \nAverage Waiting Time    = %f",avgturn /np, avgwait /np);
		 
     }
}
main()
{
      initialise();
      int np,i=0,j=0;
      int at1,et1;
      int etTotal=0;
      bool b=false;
      do
      {
	      printf("\nEnter the number of processes");
	      scanf("%d",&np);
	      if(np<MAX)
	      {
	      	for(i=0;i<np;i++)
	      	{
	      		printf("\nEnter the arrival time for P%d ",i);
	      		scanf("%d",&at1);
	      		printf("\nEnter the execution time for P%d ",i);
	      		scanf("%d",&et1);
	      		etTotal+=et1;
	      		enqueue(at1,et1);
	      	}		
	      	printf("\nEnter the Quantum Number");
	      	scanf("%d",&quan);
	      	b=false;
		  }
		  else
		  {
		  	printf("\nPlease enter small number");
		  	b=true;
		  }
	  }while(b);
	  dequeue();
	  display(np);
}
