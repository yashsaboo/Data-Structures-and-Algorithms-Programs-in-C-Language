/** 
WAP  to perform  Polynomial Operations (using pointers)
1.       Creation
2.       Print
3.       Addition
4.       Subtraction
5.       Multiplication
**/

#include <stdio.h>
#include <conio.h>
int i,j,m=0;
typedef struct poly
{
	int co[10];
	int exp[10];
}p;

void create(p *p1, p *p2, int v, int w)
{
	printf("\nEnter the values of coefficient and exponent for 1st polynomial.");
	for(i=0;i<v;i++)
	{
		printf("\nEnter the %dth coefficient",i+1);
		scanf("%d", &((*p1).co[i]));
		printf("\nEnter the %dth exponent",i+1);
		scanf("%d", &(*p1).exp[i]);
	}
	printf("\nEnter the values of coefficient and exponent for 2nd polynomial.");
	for(j=0;j<w;j++)
	{
		printf("\nEnter the %dth coefficient",j+1);
		scanf("%d", &((*p2).co[j]));
		printf("\nEnter the %dth exponent",j+1);
		scanf("%d", &((*p2).exp[j]));
	}
	
}

void print(p *p1, int x)
{
	if(x==0)
	 x++;
	printf("%d",x);
	printf("\nThe polynomial is: ");
	for(i=0;i<x;i++)
	{		
		if(i!=0)
			printf(" + ");
		printf("%dx^%d", (*p1).co[i], (*p1).exp[i]);
	}
	getch();
}

p addsub(p *p1, p *p2, int v, int w, int r)
{
	p p3; int g; m=0;
	int l=0, k=0;
	for(i=0; i<v+w; i++)
	{
			
		if(((*p1).exp[l]<(*p2).exp[k])&&(l<=v+1)&&(k<=w+1))
		{
			
			p3.co[m]=(*p1).co[l];
			p3.exp[m]=(*p1).exp[l];
			l++; m++;
			if(l==v)
			l++;
			
		}		
		if(((*p1).exp[l]>(*p2).exp[k])&&(l<=v+1)&&(k<w+1))
		{
			
			p3.co[m]=(*p2).co[k];
			p3.exp[m]=(*p2).exp[k];
			k++; m++;
			if(k==w)
			k++;
			
		}
		if(((*p1).exp[l]==(*p2).exp[k])&&(l<=v+1)&&(k<=w+1))
		{
			p3.exp[m]=(*p1).exp[l];
			if(r==1)
			p3.co[m]=(*p1).co[l]+(*p2).co[k];
			else
			p3.co[m]=(*p1).co[l]-(*p2).co[k];
			m++; l++; k++; i++;
		}
	}
	return p3;	
}

p mul(p *p1, p *p2, int v, int w)
{
	p p3[v],p4; 
	int i1;
	m=0;
	for(i=0; i<v; i++)
	{
		for(j=0; j<w;j++)
		{
			p3[i].exp[j]=((*p1).exp[i])+((*p2).exp[j]);
			
			p3[i].co[j]=((*p1).co[i])*((*p2).co[j]);
			printf("%dx^",p3[i].co[j]);
			printf("%d \n",p3[i].exp[j]);
		}
	}
	for(i1=1; i1<v || i1<w; i1++)
	{
	p3[i1]= addsub(&p3[i1-1], &p3[i1], v, w, 1);
	//print(&p3[i],w);
	//printf("\n");
	}
	printf("v in mul = %d \n",v);
	printf("w in mul = %d \n",w);
	printf("i1 in mul = %d \n",(i1-1));
	printf("%d \n",p3[v-1].exp[0]);
	printf("%d \n",p3[v-1].co[0]);
	return p3[v-1];
	
}

main()
{
  	p p1, p2, p3; int n; int counter =0; int v,w;
  	printf("\nEnter the number of terms for 1st polynomial");
	scanf("%d",&v);
	printf("\nEnter the number of terms for 1st polynomial");
	scanf("%d",&w);
  	//int v=1,w=1;
  	while(counter==0)
  	{
  	printf("\nEnter your choice: \n1.Creation \n2.Print \n3.Addition \n4.Subtraction \n5.Multiplication \n6.Exit");
	scanf("%d",&n);
	m=0;
	switch(n)
	{
		case 1:
			create(&p1, &p2, v, w);
			break;
			
		case 2:
			print(&p1, v);
			print(&p2, w);
			break;
			
		case 3:
			p3=addsub(&p1, &p2, v, w, 1);
			print(&p3, m);
			break;
			
		case 4:
			p3=addsub(&p1, &p2, v, w, 2);
			print(&p3, m);
			break;
			
		case 5:
			p3=mul(&p1, &p2, v, w);
			print(&p3, m);
			break;
			
		case 6:
			counter =1;
			break;
		
		default:
			printf("Wrong Choice. Enter again.");
	}
	}
	getch();	
}
