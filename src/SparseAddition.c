/*WAP to perform Sparse Addition*/

#include <stdio.h>
#include <conio.h>
int a[100][100];
int b[100][100];
int c[100][100];
int d[100][100];
int s[100][100];
int x;
int m1,m2, n1, n2;
int i=0,j=0;

main()
{
	int n;
	int totalrow=0;
		int totalcol=0;
		int a1=1, a2=1;

	printf("Enter the value of m and n for 1st matrix");
	scanf("%d %d",&m1,&n1);
	printf("Enter the value of m and n for 2nd matrix");
	scanf("%d %d",&m2,&n2);
	int k=0; int x=0;
	int z1=1; int z2=1;
	int col1,col2,row1,row2;
	if((m1==m2)&&(n1==n2))
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
 

		c[0][0]= i;
		c[0][1]= j;

		for(i=0;i<m1;i++)
		{
		for(j=0;j<n1;j++)
		{
	 	 if(a[i][j]!=0)
		 {
		 	c[z1][0]= i;
			c[z1][1]= j;
			c[z1][2]= a[i][j];
			x++;
			z1++;
		 }
		}
		}
		c[0][2]= x;

for(i=0;i<=x;i++)
	{
	for(j=0;j<3;j++)
	{
	 printf("%d ",c[i][j]);
	}
	printf("\n");
	}
		x=0;
		printf("Enter the number for second  matrix \n");
		for(i=0;i<m1;i++)
		{
		printf("Enter for the %d row",(i+1));
		for(j=0;j<n1;j++)
		{
		 scanf("%d",&b[i][j]);
		}
		}
		d[0][0]= i;
		d[0][1]= j;
		s[0][0]= i;
		s[0][1]= j;
		for(i=0;i<m1;i++)
		{
		for(j=0;j<n1;j++)
		{
	 	 if(a[i][j]!=0)
		 {
		 	d[z2][0]= i;
			d[z2][1]= j;
			d[z2][2]= a[i][j];
			x++;
			z2++;
		 }
		}
		}
		d[0][2]= x;
		for(i=0;i<=x;i++)
		{
			for(j=0;j<3;j++)
			{
			 printf("%d ",d[i][j]);
			}
			printf("\n");
		}
		row1=c[a1][0];
		col1=c[a1][1];
		row2=d[a2][0];
		col2=d[a2][1];
		    k=z1+z2;
		z1--;
		z2--;
	
		for(i=1;i<=(z1+z2);i++)
		{
			 if(row1<row2)
			{
			 s[i][0]=c[a1][0]; printf("%d ",s[i][0]);
			 s[i][1]=c[a1][1]; printf("%d ",s[i][1]);
			 s[i][2]=c[a1][2]; printf("%d ",s[i][2]);
			 a1++; 	printf("\n");
			 row1=c[a1][0];
			 col1=c[a1][1];
			}
			else if(row2<row1)
			{
			 s[i][0]=d[a2][0]; printf("%d ",s[i][0]);
			 s[i][1]=d[a2][1]; printf("%d ",s[i][1]);
			 s[i][2]=d[a2][2]; printf("%d ",s[i][2]);
			 a2++; 	printf("\n");
			 row2=d[a2][0];
			 col2=d[a2][1];
			}
			else
			{
			 	if(col1<col2)
				{
				 s[i][0]=c[a1][0];  printf("%d ",s[i][0]);
				 s[i][1]=c[a1][1];  printf("%d ",s[i][1]);
				 s[i][2]=c[a1][2];  printf("%d ",s[i][2]);
				 a1++; 	printf("\n");
				 row1=c[a1][0];
				 col1=c[a1][1];
				}
				else if(col2<col1)
				{
				 s[i][0]=d[a2][0]; printf("%d ",s[i][0]);
				 s[i][1]=d[a2][1]; printf("%d ",s[i][1]);
				 s[i][2]=d[a2][2]; printf("%d ",s[i][2]);
				 a2++; 	printf("\n");
				 row2=d[a2][0];
				 col2=d[a2][1];
				}
				else
				{
				 s[i][0]=d[a2][0]; printf("%d ",s[i][0]);
				 s[i][1]=d[a2][1]; printf("%d ",s[i][1]);
				 s[i][2]=d[a2][2]+c[a1][2]; printf("%d ",s[i][2]);
				 a1++; a2++; 	printf("\n");
				 row2=d[a2][0];
				 col2=d[a2][1];
				 row1=c[a1][0];
				 col1=c[a1][1];
                 k--;
				}
			}
			printf("\n");
		}
	}
	 printf("YOOOO %d ",s[2][2]);
	 s[0][2]= k;
	 for(i=0;i<=k;i++)
	{
	for(j=0;j<3;j++)
	{
	 printf("%d ",s[i][j]);
	}
	printf("\n");
	}
	getch();
}
