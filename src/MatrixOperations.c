/**
WAP to perform operation on matrices such as: 
1.Addition
2.Subtraction
3.Multiplication
4.Lower Triangular Matrix
5.Upper Triangular Matrix
6.Sum of Major Diagonal
7.Symmetry
8.Maximum Number in each row
9.Minimum Number in each column
10.Sparse Matrix
**/

#include <stdio.h>
#include <conio.h>
int a[100][100];
int b[100][100];
int c[100][100];
int x;
int m1,m2, n1, n2;
int i=0,j=0;
void read(int r)
{
	if(r==1)
	{
		printf("Enter the number for first matrix \n");
		for(i=0;i<m1;i++)
		{
		printf("Enter for the %d row",(i+1));
		for(j=0;j<n1;j++)
		{
		 scanf("%d",&a[i][j]);
		}
		}
	}
	else
	{
		printf("Enter the number for first matrix \n");
		for(i=0;i<m1;i++)
		{
	 	printf("Enter for the %d row",(i+1));
		for(j=0;j<n1;j++)
		{
		 scanf("%d",&a[i][j]);
		}
		}
		printf("Enter the number for second  matrix \n");
		for(i=0;i<m2;i++)
		{
		printf("Enter for the %d row",(i+1));
		for(j=0;j<n2;j++)
		{
		 scanf("%d",&b[i][j]);
		}
		}
	}
}
void print(int l1, int l2)
{
 	 for(i=0;i<l1;i++)
	{
	for(j=0;j<l2;j++)
	{
	 printf("%d ",c[i][j]);
	}
	printf("\n");
	}
	getch();
}

void addsub(int y)
{
	read(2);
	for(i=0;i<m1;i++)
	{
	for(j=0;j<m2;j++)
	{
	if(y==1)
	 c[i][j]=a[i][j]+b[i][j];
    else
	 c[i][j]=a[i][j]-b[i][j];
	}
	}
	print(m1,m2);
}

void multiplication()
{
	int i=0,j=0; int k=0; int sum=0;
	read(2);
	for(i=0;i<m1;i++)
	{
	for(j=0;j<n2;j++)
	{
	for(k=0;k<m2;k++)
	{
	 sum=sum+a[i][k]*b[k][j];
	}
	c[i][j]=sum;
	sum=0;
	}
	}
	print(m1,n2);
	getch();
}

void lower()
{
	read(1);
	if(m1==n1)
	{
	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
	 if(j<=i)
	 printf("%d ",a[i][j]);
	 else
	 printf("0 ");
	}
	printf("\n");
	}
	}
	else
	{
	 	printf("Not a Square Matrix");
	}
	getch();
}

void upper()
{
	read(1);
	if(m1==n1)
	{
	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
	 if(j>=i)
	 printf("%d ",a[i][j]);
	 else
	 printf("0 ");
	}
	}
	printf("\n");
	}
	
	else
	{
	 	printf("Not a Square Matrix");
	}
	getch();
}

void majorDiagonal()
{
	read(1);
	x=0;
	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
		if(i==j)
		 x+=a[i][j];
	}
	}	
	printf("The sum of major diagonal is: %d",x);
	getch();
}

void symmetry()
{
	read(1);

	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
		c[j][i]=a[i][j];
	}
	}
	x=0;
	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
	 if(c[i][j]!=a[i][j])
	{
		x=1;
	}
    }
	}
	if(x==1)
	{
		printf("The matrix is not symmetrical");
	}
	else
	{
		printf("The matrix is symmetrical");
	}
	getch();
}

void maxRow()
{
	read(1);
	x=0;
	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
		if(x<a[i][j])
		x=a[i][j];
	}
	printf("The max of %d row is: %d \n",i,x);
	x=0;
	}
	getch();
}

void minColumn()
{
	read(1);

	for(i=0;i<m1;i++)
	{
	x=a[i][0];
	for(j=0;j<n1;j++)
	{
		if(x>a[j][i])
		x=a[j][i];
	}
	printf("The min of %d column is: %d \n",i,x);
	x=0;
	}
	getch();
}

void sparse()
{
    int k=0; int sum=0; int x=0;
	read(1);
	int z=1;
	c[0][0]= i;
	c[0][1]= j;

	for(i=0;i<m1;i++)
	{
	for(j=0;j<n1;j++)
	{
 	 if(a[i][j]!=0)
	 {
	 	c[z][0]= i;
		c[z][1]= j;
		c[z][2]= a[i][j];
		x++;
		z++;
	 }
	}
	}
	c[0][2]= x;
	print(z,3);
	getch();
}

main()
{
	int n;

	printf("Enter the choice : \n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Lower Triangular Matrix\n 5.Upper Triangular Matrix\n 6.Sum of Major Diagonal\n 7.Symmetry\n 8.Maximum Number in each row\n 9.Minimum Number in each column\n 10.Sparse Matrix");
	scanf("%d",&n);
	printf("Enter the value of m and n for 1st matrix");
	scanf("%d %d",&m1,&n1);
	printf("Enter the value of m and n for 2nd matrix");
	scanf("%d %d",&m2,&n2);
	switch(n)
	{
		case 1:
		addsub(1);
		break;

		case 2:
		addsub(2);
		break;

		case 3:
		multiplication();
		break;

		case 4:
		lower();
		break;

		case 5:
		upper();
		break;

		case 6:
		majorDiagonal();
		break;

		case 7:
		symmetry();
		break;

		case 8:
		maxRow();
		break;

		case 9:
		minColumn();
		break;

		case 10:
		sparse();
		break;
	}
	getch();

}
