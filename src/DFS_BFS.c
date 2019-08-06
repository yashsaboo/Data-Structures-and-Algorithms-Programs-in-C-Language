/*WAP to create a DFS and BFS Programs*/

#include <stdio.h>
#include <conio.h>
#define max 5
int adj[max][max];
int visited[max];
int source,counter;	
int top;
int stack[max];

void create()
{
	int i,j;
	printf("\nEnter the elements of adjacency matrix");
	for(i=0;i<max;i++)
	{
		printf("\nEnter the elements for %d node",i);
		for(j=0;j<max;j++)
		{
			if(i==j)
				adj[i][j]=0;
			else
			{
				printf("\nConnection for %d node to %d node",i,j);
				scanf("%d", &adj[i][j]);
			}
		}
	}
}

void initialise()
{
	int i,j;
	visited[0]=1;
	for(i=1;i<max;i++)
	{
		visited[i]=0;
	}//visited = {1,0,0,0,....0}
	source=counter=0;
	top=-1;
}

int isNotEmpty()
{
	if(top==-1)
		return 0;
	else
		return 1;
		
}

int isFull()
{
	if(top==max)
		return 1;
	else
		return 0;
}

void push(int x)
{
	if(isFull())
		printf("\nOverflow");
	else
		stack[++top]=x;
}

void pushAsQueue(int x)
{
	int i;
	if(isFull())
		printf("\nOverflow");
	else
	{
		for(i=top;i>=0;i--)
		{
			stack[i+1]=stack[i];
		}
		stack[0]=x;
		top++;
	}
}

int pop()
{
	if(!isNotEmpty())
		printf("\nUnderflow");
	else
		return stack[top--];
	return 0;
}

int notFinish()
{
	int i,j;
	for(i=0;i<max;i++)
	{
		if(visited[i]==0)
			return 1;
	}
	return 0;
}

void algoDFS()
{
	int i,j;
	initialise();
	create();
	push(source);
	printf("%d, ",source);
	while(notFinish())
	{
		if(isNotEmpty())
		{
			for(i=0;i<5;i++)
			{
				if((adj[source][i]!=0)&&(visited[i]==0))
				{
					source=i;
					push(source);
					printf("%d, ",source);
					counter=1;
					visited[i]=1;
					break;
				}
			}
			if(counter==0)
			{
				int x = pop();
				source=stack[top];
			}
			counter=0;
		}
		else
		{
			printf("\nNot a connected Graph");
			break;
		}
	}
}

void algoBFS()
{
	int i,j;
	initialise();
	push(source);
	printf("%d, ",source);
	while(notFinish())
	{
		if(isNotEmpty())
		{
			for(i=0;i<5;i++)
			{
				if((adj[source][i]!=0)&&(visited[i]==0))
				{
					pushAsQueue(i);
					printf("%d, ",i);
					counter=1;
					visited[i]=1;
				}
			}
			if(counter==0)
			{
				int x = pop();
				source=stack[top];
			}
			counter=0;
		}
		else
		{
			printf("\nNot a connected Graph");
			break;
		}
	}
}

void main()
{
	printf("\nDFS:");
	algoDFS();
	printf("\nBFS:");
	algoBFS();
}
		

