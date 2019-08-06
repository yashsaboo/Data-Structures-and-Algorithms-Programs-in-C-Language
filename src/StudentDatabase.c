/**
WAP to create a Student Databse in C which performs following operations:
1.Insert
2.Update
3.Delete 
4.Display
**/

#include <stdio.h>
#include <conio.h>

//insert, update, delete, display
int x =-1;
int front =0;
int end;
int max=10;
int i=0,j=0;
int k;
int pos;
int temp;
struct student
{
 	   int prn;
 	   char name[20];
 	   int marks[5];
}s[10];

insert()
{
 		printf("Enter the position at which the data is to be inserted");
		scanf("%d",&pos);
		if(front>=pos-1)
		{
		         if(x!=-1)
				 {
				 for(k=pos-1;k<=front;k++)
				 {
			  	 s[k+1].prn = s[k].prn;
				 }
				 for(k=pos-1;k<=front;k++)
				 {
				 strcpy(s[k+1].name,s[k].name);
				 }
				 for(k=pos-1;k<=front;k++)
				 {
		  			 for(j=0;j<5;j++)
					 {				 		 
				  	 s[k+1].marks[j] = s[k].marks[j];
					 }
				 }
				 }
				 x++;
				 k=pos-1;
				 front++;
	 	 		 printf("Enter the PRN");
				 scanf("%d",&s[k].prn);
		 		 printf("Enter the name of the student");
				 scanf("%s",&s[k].name);
				 printf("Enter the marks of the student");
				 for(k=0;k<5;k++)
				 {
				 scanf("%d",&s[pos-1].marks[k]);
				 }

		}
		else
		{
		 	printf("The data cant be entered at that postion");
		}
		getch();
}

delete()
{
 		printf("Enter the position at which the data is to be deleted");
		scanf("%d",&pos);
		if(front>=pos-1)
		{
				 for(k=pos-1;k<front;k++)
				 {
			  	 s[k].prn = s[k+1].prn;
				 }
				 for(k=pos-1;k<front;k++)
				 {
				 strcpy(s[k].name,s[k+1].name);
				 }
				 for(k=pos-1;k<front;k++)
				 {
		  			 for(j=0;j<5;j++)
					 {				 		 
				  	 s[k].marks[j] = s[k+1].marks[j];
					 }
				 }
				 x--;
				 front--;
        }
		
		else
		{
		 	printf("The data cant be deleted at that postion");
		}
				getch();
}

update()
{
 		int n; int counter =0;
 		printf("Enter the PRN of which the data is to be updated");
		scanf("%d",&pos);
		for(k=0;k<=front;k++)
		{
		 		if(s[k].prn==pos)
				{
				 				 counter =1;
			 	printf("Enter the value: 1.Name 2.Marks 3.PRN");
				scanf("%d",&n);
				if(n==3)
				{	  					  
	 	 		 printf("Enter the PRN");
				 scanf("%d",&(s[k].prn));
				 }
				 else if(n==1)
				 {
		 		 printf("Enter the name of the student");
				 scanf("%s",&(s[k].name));
				 }
				 else if(n==2)
				 {
				 printf("Enter the marks of the student");
				 for(j=0;j<5;j++)
				 {
				 scanf("%d",&(s[k].marks[j]));
				 }
				 }
				 else
				 {
				 printf("The data couldnt be updated due to wrong choice");
				 }
				 }
	 }
				if(counter==0)
				{
				 	printf("The data couldnt be updated due to wrong PRN");
				}
		
		getch();
}

display()
{
 		 if(x!=-1)
 		 {
		  		  int v=0; int j=0, m=0; char l1[20];
		  		  struct student s1[10]; int l=0;
		  		  
		  		  for(k=0;k<front;k++)
		  		  { 
		  				s1[k].prn = s[k].prn;
			            strcpy(s1[k].name,s[k].name);
											 for(j=0;j<5;j++)
												 {				 		 
											  	 s1[k].marks[j] = s[k].marks[j];
												 }	  
		          }					  
		          for(k=0;k<front;k++)
		  		  { 
 					  for(v=k+1;v<front;v++)
 					  { 					   					  
 					   					  if(s[k].prn>s[v].prn)
 					   					  {
										   	l=s1[k].prn;
										  	 s1[k].prn = s1[v].prn;
										  	 s1[v].prn = l;
										  	 strcpy(l1,s1[k].name);
										  	 strcpy(s1[k].name,s1[v].name);
											 strcpy(s1[v].name,l1);
											 
									  			 for(j=0;j<5;j++)
												 {	
												 				 l= s1[k].marks[j];			 		 
											  	 s1[k].marks[j] = s[v].marks[j];
											  	 s1[v].marks[j]=l;
												 }
											 	   
					   					  }
 					  }
		  		 }
 		 for(k=0;k<front;k++)
 		 {
		 		 printf("\nPRN: ");
				 printf("%d",s1[k].prn);
		 		 printf("\nName of the student: ");
				 printf("%s",s1[k].name);
				 printf("\nMarks of the student: ");
				 for(j=0;j<5;j++)
				 {
				 printf("%d \t",s1[k].marks[j]);
				 }
				 printf("\n");
		 } 	
		 }
		 else
		 	 printf("The data couldnt be displayed due to empty database");
			 		getch();
}


main()
{
	int n; int ch;
	int choice=0;
	while(choice==0)
	{
	printf("Enter the value: 1.Insert 2.Update 3.Delete 4.Display");
	scanf("%d",&n);
	switch(n)
	{
	 		 case 1:
			 insert();
			 break;
			 case 2:
			 update();
			 break;
			 case 3:
			 delete();
			 break;
			 case 4:
			 display();
			 break;
			 default:
 		 	 printf("Wrong Choice");
			 break;
			 	 
    }
    printf("Enter the value: 0.Continue 1.Stop");
	scanf("%d",&ch);
	choice = ch;
	}	
	getch();
}
