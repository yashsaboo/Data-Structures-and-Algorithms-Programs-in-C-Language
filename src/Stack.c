/**
WAP to create a following operations using Stack data structure:
1.Palindrome
2.Decimal to Binary
3.Well Formness of Paranthesis
**/

#include <stdio.h>
#include <conio.h>
#define MAX 10

struct stack
{
	int data[MAX];
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
	{
	printf("\nStack Overflow");
	}
	else
	{
	s.top++;
	s.data[s.top]=n;
	}
}

int pop()
{
	if(empty()==1)
	{
		printf("\nStack Underflow");
		return -1;
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
			printf("%d",s.data[i]);
		}
	}
}

void palindrome()
{
	initialise();
	int c1,d=0;
	int i; int j=1;
	printf("Enter the number");
	scanf("%d",&c1);
	int c=c1;
	display();
	while(c>0)
	{
		push((c%10));
		c=c/10;
	}
	display();
	while(empty()==0)
	{
		d=pop()*j+d;
		j=j*10;
	}
	printf("\n%d",c);
	printf("\n%d",d);
	if(c1==d)
	printf("Palindrome");
	else
	printf("Not Palindrome");
}

void decimaltobinary()
{
	initialise();
	int c;
	printf("\nEnter the number");
	scanf("%d",&c);
	while(c>0)
	{
		push(c%2);
		c=c/2;
	}
	while(empty()==0)
	{
		printf("%d",pop());		
	}	
}

void para()
{
	initialise();
	char s[20];
	char ch;
	int k;
	int i;
	printf("\nEnter the expression");
	scanf("%s",s);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='(')
		{
			push(1);
		}
		if(s[i]=='[')
		{
			push(2);
		}
		if(s[i]=='{')
		{
			push(3);
		}
		if(s[i]==')')
		{
			k=pop();
			if(k==-1)
			{
				printf("Not Wellformed");
				break;
			}			
		}
		if(s[i]==']')
		{
			k=pop();
			if(k==-1)
			{
				printf("Not Wellformed");
				break;
			}			
		}
		if(s[i]=='}')
		{
			k=pop();
			if(k==-1)
			{
				printf("Not Wellformed");
				break;
			}			
		}
	}
	if(empty()==1)
	{
			printf("Wellformed");
	}
	else
	{
			printf("Not Wellformed");
	}
}

main()
{
	int i=0; int choice;
	printf("\nWhich method would you like to implement: \n1.Palindrome \n2.Decimal to Binary \n3.Well Formness of Paranthesis");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			palindrome();
			break;
			
		case 2:
			decimaltobinary();
			break;
			
		case 3:
			para();
			break;
					
	}
	getch();
}
