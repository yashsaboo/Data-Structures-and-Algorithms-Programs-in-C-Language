/*WAP to create a Matrix using Dynamic Allocation and perform arithmetic functions upon it.*/

#include <stdio.h>
#include <conio.h>

void create(int *m, int r, int c)
{
	int i=0, j=0;;
	printf("\nEnter the elements for the matrix");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("\nEnter the element");
			scanf("%d",m+i*c+j);
	    }
    }
}

void display(int *m, int r, int c)
{
	int i=0, j=0;;
	printf("\nThe elements for the matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",*(m+i*c+j));
	    }
	    printf("\n");
    }
}

int * addsub(int *m1, int *m2, int r, int c, int x)
{
	int *m3 = (int *) malloc (sizeof(int)*r*c);
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(x==1)
			*(m3+i*c+j)=(*(m1+i*c+j))+(*(m2+i*c+j));
			if(x==2)
			*(m3+i*c+j)=(*(m1+i*c+j))-(*(m2+i*c+j));
	    }
    }
    return m3;
}

int * mul(int *m1, int *m2, int r1, int c1, int r2, int c2)
{
	int *m3 = (int *) malloc (sizeof(int)*r1*c2);
	int i,j,k,t=0;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			for(k=0;k<r2;k++)
			{
				t+=(*(m1+i+j*k))*(*(m2+i*k+j));
			}
			*(m3+i*c2+j) = t;
			t=0;
		}
	}
	return m3;			
}

int * transpose(int *m1, int r, int c)
{
 	int *m3 = (int *) malloc (sizeof(int)*r*c);
	int i,j,k,t=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
				*(m3+i+j*r) = (*(m1+i*c+j)) ;
		}
	}
	return m3;	
}

main()
{
	int *m1, *m2, *m3;
	int i,j,row1,col1, row2, col2,n, counter =0;
	printf("Enter the value of row for first matrix");
	scanf("%d",&row1);
	printf("Enter the value of column for first matrix");
	scanf("%d",&col1);
	printf("Enter the value of row for second matrix");
	scanf("%d",&row2);
	printf("Enter the value of column for second matrix");
	scanf("%d",&col2);
	m1=(int *) malloc (sizeof(int)*row1*col1);
	m2=(int *) malloc (sizeof(int)*row2*col2);
	m3=(int *) malloc (sizeof(int)*row1*col2);
	create(m1, row1, col1);
	create(m2, row2, col2);
	display(m1, row1, col1);
	display(m2, row2, col2);
	while (counter ==0)
	{
	printf("Enter you choice: \n1.Addition \n2.Subtraction \n3.Multiplication \n4.Transpose \n5.Exit");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			if((row1==row2)&&(col1==col2))
			{
			m3 = addsub(m1, m2, row1, col1, 1);
			display(m3, row1, col2);
		    }
		    else
		    printf("The matrix couldnt be added");
			break;
		case 2:
			if((row1==row2)&&(col1==col2))
			{
			m3 = addsub(m1, m2, row1, col1, 2);
			display(m3, row1, col2);
		    }
		    else
		    printf("The matrix couldnt be subtracted");
			break;
		case 3:
			if(col1==row2)
			{
			m3 = mul(m1, m2, row1, col1, row2, col2);
			display(m3, row1, col2);
			}
			else
			printf("The matrix couldnt be multiplied");
			break;
		case 4:
			 if(col1==row1)
			{
			m3 = transpose(m1, row1, col1);
			display(m3, row1, col1);
			}
			else
			printf("The matrix couldnt be transposed");
			break;
			 
		case 5:
			counter=1;
			break;
		default:
			printf("Wrong choice.");
	}
    }
}
