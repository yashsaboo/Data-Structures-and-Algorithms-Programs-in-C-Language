/** 
WAP to perform Sorting of array using:
1.Selection Sort
2.Bubble Sort
3.Insertion Sort
4.Merge Sort
5.Quick Sort using first element as pivot
6.Quick Sort using last element as pivot
7.Quick Sort using median element as pivot
**/

#include <conio.h>
#include<stdio.h>

int n;

acceptarray(int *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n the element no %d", i+1);
		scanf("%d", (a+i));
	}
}

printarray(int *a)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ", *(a+i));
	}
}

selection(int a[])
{
	int i,j;
	int min, temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i;j<n;j++)
		{
			if(a[min]>a[j])
			{
				min=j;
			}
		}
		temp=a[min];
		a[min]=a[i];
		a[i]=temp;
	}
	printarray(a);
			
}

bubble(int a[])
{
	int i,j;
	int temp; int change=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				change++;	
			}
			printarray(a);
			printf("\n");
		}	
		if(change==0)
		break;
	}
	printarray(a);	
}

insertion(int a[])
{
	int i,j;
	int min,temp;
	for(i=1;i<n;i++)
	{
		min=i;
		for(j=i-1;j>-1;j--)
		{
			if(a[j]>a[min])
			{
				temp=a[min];
				a[min]=a[j];
				a[j]=temp;
				min=j;
			}
			else
			{
				break;
			}
		}		
	}
	printarray(a);
}

mergesort(int a[], int start, int end)
{
	int mid = (int)((start+end)/2);
	if(start<end)
	{
	mergesort(a, start, mid);
	mergesort(a, mid+1,end);
	merge(a, start, mid, end);
    }
}

merge(int a[], int s, int m, int e)
{
 		  int i,j,k,temp,temp1;
 		  for(i=m+1; i<=e;i++)
 		  {
		   		   for(j=s;j<=m;j++)
		   		   {
				   	if(a[i]<a[j])
					{
						temp1=a[i];
						for(k=i-1;k>=j;k--)
						{
							a[k+1]=a[k];
						}
						a[j]=temp1;
						break;
			        }		   
		   		   }
		  }
		  {
		  /*Another Way using While Loop
		  
		  int b[5];
		  k=0;i=s;j=m+1;
		  printf("\ns=%d",s);
		  printf("\nm=%d",m);
		  printf("\ne=%d",e);
		  while(i<=m && j<=e)
		  {
		  	if(a[i]<a[j])
		  	{
		  		b[k++]=a[i++];
		  	}
		  else
		  	b[k++]=a[j++];
		  }
		  	
		while(i<=m)
		{
			b[k++]=a[i++];
		}
		while(j<=e)
		{
			b[k++]=a[j++];
		}
		for(i=e;i>=s;i--)
		{
			a[i]=b[--k];
		}
		printf("\n");
		printarray(a);
		printf("\n");
		*/
		 /* for(i=s;i<e;i++)
		  {
		  printf("%d ", a[i]);
		  }
		  
		*/
	}
}

quicksort(int a[], int start, int end, int r)
{
	int pivot;
	if(start<end)
	{
		pivot = quick(a, start, end,r);
		quicksort(a, start, pivot-1,r);
		quicksort(a, pivot+1, end,r);
	}
}

int quick(int a[], int s, int e, int r)
{
	if(r==1)
	{
		int p = a[s];
		int i=s+1,j=e; 
		int t;
		while(j>=i)
		{
			while(a[i]<=p)
			i++;
			while(a[j]>p)
			j--;
			if(j>i)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		a[s]=a[j];
		a[j]=p;
		return j;
	}
	if(r==2)
	{
		printf("\ns=%d",s);
		printf("\ne=%d",e);
		//printf("=%d",s)
		int p=a[e];
		int i=s, j=e-1;
		int t;
		while(j>=i)
		{
			while(a[j]>=p)
			j--;
			while(a[i]<p)
			i++;
						
			if(j>i)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		a[e]=a[i];
		a[i]=p;
		return i;
	}
	if(r==3)
	{
		int p=(s+e)/2;
		//int i=s, j=e;
		int t;
		int i=0, j=0; int k;
		for(i=s;i<=p;i++)
		{
			for(j=e;j>=p;j--)
			{
				if(a[i]>a[j])
				{
					t=a[i];
					a[i]=a[j];
					a[j]=t;
				}
			}
		}
		printarray(a);
		return p;
	}
}

main()
{
	int a[10];
	int i=0; int choice;
	printf("\nEnter the number of elements you want in an array");
	scanf("%d", &n);
	acceptarray(a);
	printarray(a);
	printf("\nWhich method would you like to implement for sorting: \n1.Selection Sort \n2.Bubble Sort \n3.Insertion Sort \n4.Merge Sort"); 
	printf("\n5.Quick Sort using first element as pivot \n6.Quick Sort using last element as pivot \n7.Quick Sort using median element as pivot");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			selection(a);
			break;
			
		case 2:
			bubble(a);
			break;
			
		case 3:
			insertion(a);
			break;
			
		case 4:
			mergesort(a,0,n-1);
			printarray(a);
			break;
			
		case 5:
			quicksort(a,0,n-1,1);
			printarray(a);
			break;
		
		case 6:
			quicksort(a,0,n-1,2);
			printarray(a);
			break;
			
		case 7:
			quicksort(a,0,n-1,3);
			printarray(a);
			break;
			
		default:
			printf("Wrong Choice.");
	}
	getch();
}
