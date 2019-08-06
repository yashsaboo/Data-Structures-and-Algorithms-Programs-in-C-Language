/*WAP to implement: 1.Infix to Postfix and 2.Infix to Prefix*/

#include <stdio.h>
#include <conio.h>

#define MAX 10

struct stack
{
	char data[MAX];
	int top;
}s;

void initialise()
{
	s.top=-1;
}

int empty()
{
	if(s.top==-1)
	return 1;
	else
	return 0;
}

int full()
{
	if(s.top==MAX-1)
	return 1;
	else
	return 0;
}

void push(int n)
{
	if(full()==1)
	printf("\nStack Overflow");
	else
	{
	s.top++;
	s.data[s.top]=n;
	}
}

char pop()
{
	if(empty()==1)
	{
		printf("\nStack Underflow");
	} 
	else
	{
		return s.data[s.top--];
	}
}

void display()
{
	if(empty()==1)
	{
		printf("\nStack Underflow");
	} 
	else
	{
		int i=0;
		printf("\n");
		for(i=0;i<=s.top;i++)
		{
			printf("%s",s.data);
		}
	}
}

void intopost()
{
	initialise();
	char s1[20];
	char ch;
	int k;
	int i;
	printf("\nEnter the expression");
	scanf("%s",s1);
	printf("\nThe expression in infix is: %s",s1);
	printf("\nThe expression in postfix is: ");
	for(i=0;s1[i]!='\0';i++)
	{
		ch=s1[i];
		if(ch=='^')
		{
			push(ch);
		}
		else if((ch=='*')||(ch=='/'))
		{
			char c = s.data[(s.top)];
			if(c=='^')
			{
			printf("%c",pop());
			push(ch);
			}
			else
			push(ch);
		}
		else if((ch=='+')||(ch=='-'))
		{
			char c = s.data[s.top];
			if((c=='^')||(ch=='*')||(ch=='/'))
			{
			printf("%c",pop());
			push(ch);
			}
			else
			push(ch);
		}
		else if((ch=='(')||(ch=='{')||(ch=='['))
		{
			push(ch);
		}
		else if((ch==')')||(ch=='}')||(ch==']'))
		{
			printf("%c",pop());
			ch=pop();
		}
		else
		{
			printf("%c",ch);
		}
		display();
	}
	while(empty()==0)
	{
		printf("%c",pop());
	}
}

main()
{
	int i=0; int choice;
	printf("\nWhich method would you like to implement: \n1.Infix to Postfix \n2.Infix to Prefix");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			intopost();
			break;
			
		case 2:
			intopre();
			break;
	}
	getch();
}
