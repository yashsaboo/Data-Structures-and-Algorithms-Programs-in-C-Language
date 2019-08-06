/** 
WAP  to perform array search using:
1.Linear Search 
2.Binary Search
3.Binary Search using Recursion
**/

#include <stdio.h>
#include <conio.h>
void linearsearch(int a[], int n, int r)
{
 	 int i=0; int c=0;
 	 for(i=0;i<n;i++)
 	 {
	  			if(a[i]==r)
	  			{
 		        if(c==0)
 		        {
			 	 printf("\nSearch Successful");  		   
 		   		 printf("\nElement is at:");
				}
				printf("\n%d",i+1);
	  			c=1;
				}
	 }
	 if(c==0)
	 {
	 printf("\nSearch Unsuccessful");
	 }
	 getch();
}

void binarysearch1(int a[], int n, int r)
{
 	 int i=0; int c=0; int t=0;
 	 int lb=0; int ub=n; int mid;
 	 while(lb!=ub)
 	 {
	            mid=(lb+ub)/2;
	  			if(a[mid]==r)
	  			{
	  			c++; t=mid;
	  			break;
				}
				if(a[mid]>r)
	  			{
	  			ub=mid-1;
				}
				if(a[mid]<r)
	  			{
	  			lb=mid+1;
				}
	 }
	 if(lb==ub)
	 {
	  	if(a[lb]==r)
	  			{
	  			c++; t=lb;
				}	   
     }
	 if(c==0)
	 printf("\nSearch Unsuccessful");
	 else
	 printf("\nSearch Successful. \nThe position is: %d",t+1);
}
void binarysearch2(int a[], int lb, int ub, int r)
{
 	 int i=0; int c=0; int t=0;
 	  int mid;
 	 if(lb==ub)
	 {
	  	if(a[lb]==r)
	  			{
	  			c++; t=lb;
				}
		else
		{
		  printf("\nSearch Unsuccessful");
		}
					   
     }
     	 else
 	 {
	            mid=(lb+ub)/2;
	            
	  			if(a[mid]==r)
	  			{
				printf("%d",mid);
	  			c++; t=mid;
	
				}
				if(a[mid]>r)
	  			{
				printf("%d",mid);
	  			binarysearch2(a, lb, mid-1,  r);
				}
				if(a[mid]<r)
	  			{
				printf("%d",mid);
	            binarysearch2(a, mid+1,  ub, r);
				}
	 }
	 if(c==1)
	 printf("\nSearch Successful. \nThe position is: %d",t+1);
}
void sort(int a[], int n, int x)
{
 	 int i=0, j=0;
 	 int t,z;
 	 for(i=0;i<n;i++)
 	 {
	  				 t=i;
		 for(j=i;j<n;j++)
		 {
		  				 if(a[t]>a[j])
		  				  t=j;
		 }
		 z=a[i];
		 a[i]=a[t];
		 a[t]=z;
		 printf("%d  ",a[i]);
	 }
		binarysearch1(a,9,x);
}
main()
{
 	 int n=0; int a[10]; int x; int i;
	  printf("\nEnter your choice: \n1.Linear Search \n2.Binary Search \n3.Binary Search using Recursion");
	  scanf("%d", &n);
	  for(i=0;i<10;i++)
	  {
      printf("\nEnter the array element");
	  scanf("%d", &a[i]);				   
      }
      printf("\nEnter the array element to be searched");
	  scanf("%d", &x);
	  switch(n)
	  {
	   		   case 1:
			   		linearsearch(a,10,x);
			   		break;
               case 2:
			   	    sort(a,10,x);
			   	    break;
			   	case 3:
					 binarysearch2(a,0,9,x);
					 break;			  	 	  
      }
		getch();	   		
	   
}





