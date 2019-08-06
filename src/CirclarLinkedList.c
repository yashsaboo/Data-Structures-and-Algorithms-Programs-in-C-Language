/*WAP to create a Circular Linked List Program which features: Create, Insert, Delete, Display, Concat, Search and Sort*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
	int data; //stores the sata of that node
	struct Node *ptr; //stores the address of the next node
} *head = NULL;
struct Node *current, *NN, *tmp; //'current' is counter pointer to list //'NN is a new Node
int nonodes; //sotres total number of nodes in the list
void create()
{
	int n;//stores no of nodes to be created
	if(head == NULL)
	{
		printf("\nEnter the number of nodes to be created");
		scanf("%d",&n);
		nonodes = n;
		
		while(n>0)
		{
	 		NN = (struct Node *) malloc (sizeof(struct Node)); 
	 		printf("\nEnter the data of the pointer");
			scanf("%d",&NN->data);
			NN->ptr=head;
			if(head==NULL)
			{
				head = NN;
				current = NN;
			}
			else
			{
				current->ptr = NN;
				current = NN;
			}
			n--;
		}
					
	}
	else
	{
		printf("\nThe list has already been created");
	}
}
void display()
{
	current = head;
	if(current->ptr != NULL)
	{
		//int n = nonodes;
		printf(" %d",current->data);
		while(current->ptr!=head)
		{
			current = current->ptr;
			printf(" --->  %d",current->data);
		}
		printf(" --->  %d",head->data);
	}
	else
	{
		printf("\nThe list is empty");
	}
	printf("\n");
}

void insertstart()
{
	struct Node *tmp;
	tmp=head;
	NN = (struct Node *) malloc (sizeof(struct Node)); 
	printf("\nEnter the data of the pointer");
	scanf("%d",&NN->data);
	NN->ptr=tmp;
	while(current->ptr!=head)
		{
			current = current->ptr;
		}
		current->ptr = NN;
	head=NN;
	current = head;
	
		
}

void insertend()
{
	current = head;
	
		while(current->ptr!=head)
		{
			current = current->ptr;
		}
	NN = (struct Node *) malloc (sizeof(struct Node)); 
	printf("\nEnter the data of the pointer");
	scanf("%d",&NN->data);
	NN->ptr=head;
	current->ptr=NN;
}

void insertany(int ins)
{
	current = head;
	if(current != NULL)
	{		
		while(ins>2)
		{
			current = current->ptr;			
			ins--;
		}
	}
	NN = (struct Node *) malloc (sizeof(struct Node)); 
	printf("\nEnter the data of the pointer");
	scanf("%d",&NN->data);
	//struct Node *tmp = current;
	NN->ptr=current->ptr;
	current->ptr=NN;
}

void insert()
{
	int ins;
	printf("Insert at which position");
	scanf("%d",&ins);
	//printf("%d",nonodes);
	nonodes++;
	if((ins<=nonodes)&&(ins>0))
	{		
		if(ins==1)
		{
			insertstart();
		}
		else if(ins==nonodes)
		{
			insertend();
		}
		else
		{
			insertany(ins);
		}
	}
	else
	{
		nonodes--;
		printf("Insertion is not possible");
	}
}

deletestart()
{
	while(current->ptr!=head)
		{
			current = current->ptr;
		}
	tmp=head->ptr;
	free(head);
	current->ptr=tmp;
	head=tmp;
	nonodes--;
}
		
deleteend()
{
	current = head;
	tmp=current;
	if(current != NULL)
	{
		while(current->ptr!=head)
		{
			tmp=current;
			current = current->ptr;
		}
	}
	free(current);
	tmp->ptr=head;
	nonodes--;
}
	
deleteany(ins)
{
	current = head;
	tmp=current;
	if(current != NULL)
	{		
		while(ins>1)
		{
			tmp=current;
			current = current->ptr;			
			ins--;
		}
	}	
	struct Node *tmp2;
	tmp2=current->ptr;
	free(current);
	tmp->ptr=tmp2;
	nonodes--;
}

void delete()
{
	int ins;
	printf("Delete at which position");
	scanf("%d",&ins);
	printf("%d",nonodes);
	//nonodes++;
	if((ins<=nonodes)&&(ins>0))
	{
		if(ins==1)
		{
			deletestart();
		}
		else if(ins==nonodes)
		{
			deleteend();
		}
		else
		{
			deleteany(ins);
		}
	}
	else
	{
		printf("Deletion is not possible");
	}
}

void concat()
{
	struct Node *current2, *NN2, *tmp2, *head2 = NULL;
	int n; int nonodes2;
	if(head2 == NULL)
	{
		printf("\nEnter the number of nodes to be created");
		scanf("%d",&n);
		nonodes2 = n;
		nonodes = nonodes + nonodes2;
		while(n>0)
		{
	 		NN2 = (struct Node *) malloc (sizeof(struct Node)); 
	 		printf("\nEnter the data of the pointer");
			scanf("%d",&NN2->data);
			NN2->ptr=head2;
			if(head2==NULL)
			{
				head2 = NN2;
				current2 = NN2;
			}
			else
			{
				current2->ptr = NN2;
				current2 = NN2;
			}
			n--;
		}
		current = head;
		if(current != NULL)
		{
			while(current->ptr!=head)
			{
				current = current->ptr;
			}
		}
		current->ptr=head2;
		current2->ptr=head;
		
	}
}

void search()
{
	int x;
	int pos = 1;
	printf("\nEnter the element you want to search ");
	scanf("%d" ,&x);
	int searchc=0;
	current = head;
	if(current != NULL)
	{
		if(current->data==x)
		{
			searchc = 1;;
			printf("\nsearch successful at %d",pos);
		}
		while((current->ptr!=head)&&(searchc==0))
		{
			pos++;
			current = current->ptr;
			if(current->data==x)
			{
				searchc = 1;;
				printf("\nsearch successful at %d",pos);
			}
		}
	}
	else
	{
		printf("\nThe list is empty");
	}
	if(searchc==0)
		printf("\nsearch unsuccessful");
	printf("\n");
}

void sort()
{
	current = head;
	int tmp1, tmp2, tmp3, i, j;
	if(current != NULL)
	{
		for(i=0;i<nonodes;i++)
		{
			current = head;
			for(j=0;j<nonodes-1-i;j++)
			{
				tmp1 = current->data;
				tmp2 = current->ptr->data;
				if(tmp1>tmp2)
				{
					current->data = tmp2;
					current->ptr->data = tmp1;
				}
				current = current->ptr;
			}
			
		}
	}
	else
	{
		printf("\nThe list is empty");
	}
	printf("\n");
}

void main()
{
	int exit=0;
	while(exit!=1)
	{
		int choice, choice1;
		printf("\nEnter your choice: \n1.Create \n2.Display\n3.Insert \n4.Delete \n5.Concat \n6.Search \n7.Sort");
		scanf("%d" , &choice);
		switch(choice)
		{
			case 1:
				create();
				break;
			case 2:
				printf("\nThe data is:");
				display();
				break;
			case 3:
				printf("\nEnter your choice: \n1.Insert in the start \n2.Insert in the end \n3.Insert at some position");
				scanf("%d" , &choice1);
				if(choice1==1)
				insertstart();
				else if(choice1==2)
				insertend();
				else if (choice1==3)
				insert();
				else
				printf("Wrong choice");
				break;
			case 4:
				printf("\nEnter your choice: \n1.Delete from the start \n2.Delete from the end \n3.Insert at some position");
				scanf("%d" , &choice1);
				if(choice1==1)
				deletestart();
				else if(choice1==2)
				deleteend();
				else if (choice1==3)
				delete();
				else
				printf("Wrong choice");
				break;
			case 5:
				concat();
				break;
			case 6:
				search();
				break;
			case 7:
				sort();
				break;
			default:
				exit=1;
		}
	}
	
}
