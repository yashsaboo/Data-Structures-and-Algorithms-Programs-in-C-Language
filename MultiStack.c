/*WAP to create a Multi-Stack data structure*/

#include <stdio.h>
#include <conio.h>
#define MAX 10
int no;
struct stack
{
	int data[MAX];
	int top[MAX];
	int bottom[MAX];
}s;

void initialise(int z)
{
	s.top[z]=(MAX/no*z)-1;
	s.bottom[z]=(MAX/no*z);
}

int empty(int z)
{
	if(s.top[z]==(s.bottom[z]-1))
	return 1;
	else
	return 0;
}

int full(int z)
{
	if(s.top[z]==((MAX/no)*(z+1))-1)
	return 1;
	else
	return 0;
}

void push(int n,int z)
{
	if(full(z)==1)
	{
	printf("\nStack Overflow");
	}
	else
	{
	s.top[z]++;
	s.data[s.top[z]]=n;
	}
}

int pop(int z)
{
	if(empty(z)==1)
	{
		printf("\nStack Underflow");
		return -11;
	}
	else
	{
		return s.data[s.top[z]--];
	}
}

void display(int z)
{
	if(empty(z)==1)
	{
		printf("\nStack Underflow");
	}
	else
	{
		int i=0;
		printf("\n");
		for(i=s.bottom[z];i<=s.top[z];i++)
		{
			printf("%d ",s.data[i]);
		}
	}
}

main()
{
	int i=0;
	int t;
	int pushn;
	int popn;
	int z;
	int flag=1;
	printf("\nHow many stacks you want to create");
	scanf("%d",&no);
	while(flag==1)
	{
		printf("Enter the stack number where you want to update");
		scanf("%d",&z);
		z--;
		initialise(z);
		printf("\nHow many numbers you want to push");
		scanf("%d",&pushn);
		printf("\nHow many numbers you want to pop");
		scanf("%d",&popn);
		for(i=0;i<pushn;i++)
		{
			printf("\nEnter the number to push");
			scanf("%d",&t);
			push(t,z);
		}
		for(i=0;i<popn;i++)
		{
			t=pop(z);
			if(t!=-11)
			printf("\nPop element = %d",t);
		}
		display(z);
		printf("\nDo you want to continue? 1 for YES");
		scanf("%d",&flag);
	}
	getch();
}
