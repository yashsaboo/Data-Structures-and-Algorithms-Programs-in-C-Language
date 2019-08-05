/*WAP to create a Doubly Linked List Program which features: Create, Insert, Delete, Display, Concat, Search and Sort*/

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct Node
{
	int data; //stores the sata of that node
	struct Node *prev; //stores the address of the prev node
	struct Node *next; //stores the address of the next node
	
} *start = NULL, *end = NULL;
struct Node *current, *NN, *p1, *n1, *tmp; //'current' is counter pointer to list //'NN is a new Node
int nonodes; //sotres total number of nodes in the list
void create()
{
	int n;//stores no of nodes to be created
	if(start == end)
	{
		printf("\nEnter the number of nodes to be created");
		scanf("%d",&n);
		nonodes = n;
		p1=NULL;
		while(n>0)
		{
	 		NN = (struct Node *) malloc (sizeof(struct Node)); 
	 		printf("\nEnter the data of the pointer");
			scanf("%d",&NN->data);
			NN->next=NULL;
			NN->prev=p1;
			if(start==NULL)
			{
				start = NN;
				current = NN;
				end = NN;
				p1=NN;
			}
			else
			{
				current->next = NN;
				p1=NN;
				current = NN;
				end = NN;
			}
			n--;
		}
					
	}
	else
	{
		printf("\nThe list has already been created");
	}
}

void displayfromstart()
{
	current = start;
	if(current != NULL)
	{
		//int n = nonodes;
		printf(" %d",current->data);
		while(current->next!=NULL)
		{
			current = current->next;
			printf(" --->  %d",current->data);
		}
		printf(" --->  NULL");
	}
	else
	{
		printf("\nThe list is empty");
	}
	printf("\n");
}

void displayfromend()
{
	current = end;
	if(current != NULL)
	{
		//int n = nonodes;
		printf(" %d",current->data);
		while(current->prev!=NULL)
		{
			current = current->prev;
			printf(" --->  %d",current->data);
		}
		printf(" --->  NULL");
	}
	else
	{
		printf("\nThe list is empty");
	}
	printf("\n");
}

display()
{
	int choice;
	/*printf("\nEnter your choice: \n1.Display from Start \n2.Display from end");
	scanf("%d" , &choice);
	switch(choice)
		{
			case 1:
				displayfromstart();
				break;
			case 2:
				displayfromend();
				break;
			default:
			   	printf("Wrong Choice");
		}*/
		displayfromstart();
}

void insertstart()
{
	struct Node *tmp;
	tmp=start;
	NN = (struct Node *) malloc (sizeof(struct Node)); 
	printf("\nEnter the data of the pointer");
	scanf("%d",&NN->data);
	NN->next=tmp;
	NN->prev=NULL;
	start->prev= NN;
	start=NN;
}

void insertend()
{
	NN = (struct Node *) malloc (sizeof(struct Node)); 
	printf("\nEnter the data of the pointer");
	scanf("%d",&NN->data);
	NN->next=NULL;
	NN->prev=end;
	end->next=NN;
	end=NN;
}

void insertany(int ins)
{
	current = start;
	if(current != NULL)
	{		
		while(ins>2)
		{
			current = current->next;			
			ins--;
		}
	}
	NN = (struct Node *) malloc (sizeof(struct Node)); 
	printf("\nEnter the data of the pointer");
	scanf("%d",&NN->data);
	NN->next=current->next;
	NN->prev=current;
	current->next->prev=NN;
	current->next=NN;
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
	tmp=start->next;
	free(start);
	start=tmp;
	tmp->prev=NULL;
	nonodes--;
}
		
deleteend()
{
	current = start;
	tmp=current;
	if(current != NULL)
	{
		while(current->next!=NULL)
		{
			tmp=current;
			current = current->next;
		}
	}
	free(current);
	tmp->next=NULL;
	nonodes--;
}
	
deleteany(ins)
{
	current = start;
	tmp = current;
	if(current != NULL)
	{		
		while(ins>1)
		{
			tmp=current;
			current = current->next;			
			ins--;
		}
	}	
	struct Node *tmp2;
	tmp2=current->next;
	free(current);
	tmp->next=tmp2;
	tmp2->prev=tmp;
	nonodes--;
}

void delete()
{
	int ins;
	printf("Delete at which position");
	scanf("%d",&ins);
	printf("%d",nonodes);
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
	struct Node *current2, *NN2, *tmp2, *start2 = NULL, *end2=NULL, *p1;
	int n; int nonodes2;
	if(start2 == NULL)
	{
		printf("\nEnter the number of nodes to be created");
		scanf("%d",&n);
		nonodes2 = n;
		p1=NULL;
		nonodes = nonodes + nonodes2;
		while(n>0)
		{
	 		NN2 = (struct Node *) malloc (sizeof(struct Node)); 
	 		printf("\nEnter the data of the pointer");
			scanf("%d",&NN2->data);
			NN2->next=NULL;
			NN2->prev=p1;
			if(start2==NULL)
			{
				start2 = NN2;
				current = NN2;
				end2 = NN2;
				p1=NN2;
			}
			else
			{
				current->next = NN2;
				p1=NN2;
				current = NN2;
				end2= NN2;
			}
			n--;
		}
		end->next=start2;
		end=end2;
	}
}

void search()
{
	int x;
	int pos=0;
	printf("\nEnter the element you want to search ");
	scanf("%d" ,&x);
	int searchc=0;
	current = start;
	if(current != NULL)
	{
		pos++;
		if(current->data==x)
		{			
			searchc = 1;;
			printf("\nsearch successful at position %d",pos);
		}
		while((current->next!=NULL)&&(searchc==0))
		{
			pos++;
			current = current->next;
			if(current->data==x)
			{
				searchc = 1;;
				printf("\nsearch successful at position %d",pos);
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
	current = start;
	int tmp1, tmp2, tmp3, i, j;
	if(current != NULL)
	{
		for(i=0;i<nonodes;i++)
		{
			current = start;
			for(j=0;j<nonodes-1-i;j++)
			{
				tmp1 = current->data;
				tmp2 = current->next->data;
				if(tmp1>tmp2)
				{
					current->data = tmp2;
					current->next->data = tmp1;
				}
				current = current->next;
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
		int choice;
		int choice1;
		printf("\nEnter your choice: \n1.Create \n2.Display \n3.Insert \n4.Delete \n5.Concat \n6.Search \n7.Sort");
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

				printf("\nEnter your choice: \n1.Insert in the start \n2.Insert in the end \n3.Insert in some position");
				scanf("%d" , &choice1);
				switch(choice1)
				{
					case 1:
						insertstart();
						break;
					case 2:
						insertend();
						break;
					case 3:
						insert();
					default:
						printf("Wrong choice");
				}
				break;
			case 4:
				printf("\nEnter your choice: \n1.Delete in the start \n2.Delete in the end \n3.Delete in some position");
				scanf("%d" , &choice1);
				switch(choice1)
				{
					case 1:
						deletestart();
					break;
					case 2:
						deleteend();
						break;
					case 3:
						delete();
					default:
						printf("Wrong choice");
				}
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
