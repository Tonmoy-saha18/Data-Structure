#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a;
void INSERTION_SORT(int b[]);
int liniersearch(int *p,int c);
void binarysearch(int *p,int c);
int main()
{
	FILE *fp1;
	fp1=fopen("int.txt","w");
	int i,k,A[50000],l,m;
	clock_t l1,l2,c1,c2;
	for(i=0;i<50000;i++)
	{
		k=rand()%500-250;
		fprintf(fp1,"%d\n",k);
		A[i]=k;
	}
	INSERTION_SORT(A);
	printf("Enter the number to search:");
	scanf("%d",&l);
	l1=clock();
	for(i=0;i<1000;i++)
	{
		m=liniersearch(a,l);
	}
	l2=clock();
	if(m==1)
	{
		printf("Found\n");
	}
	if(m==-1)
	{
		printf("Not Found\n");
	}
	printf("Time in linier search:%lf\n",((double)(l2-l1)/CLOCKS_PER_SEC));
	c1=clock();
	binarysearch(a,l);
	c2=clock();
	printf("Time for binary search:%lf\n",((double)(c2-c1)/CLOCKS_PER_SEC));
	return 0;
}
void INSERTION_SORT(int b[])
{
	int i,j,k,l;
	FILE *fp2,*fp3;
	fp2=fopen("out.txt","w");
	fp3=fopen("out.txt","r");
	for(i=1;i<50000;i++)
	{
		k=b[i];
		j=i-1;
		while(j>=0&&b[j]>k)
		{
			b[j+1]=b[j];
			j=j-1;
		}
		b[j+1]=k;
	}
	for(l=0;l<50000;l++)
	{
		fprintf(fp2,"%d\n",b[l]);
	}
	a=(int*)malloc(50000*sizeof(int));
	for(l=0;l<50000;l++)
	{
		fscanf(fp3,"%d",(a+l));
	}
	return;
}
int liniersearch(int *p,int c)
{
	int i;
	for(i=0;i<50000;i++)
	{
		if(*(p+i)==c)
		{
			return 1;
		}
	}
	return -1;
}
void binarysearch(int *p,int c)
{
	int first=0,last=49999,mid,j=0;
	for(;first!=last;)
	{
		mid=first+(last-first)/2;
		if(mid==c)
		{
			j=1;
			break;
		}
		if(c>mid)
		{
			first=mid+1;
		}
		if(c<mid)
		{
			last=mid-1;
		}
	}
	if(j==0)
	{
		printf("Not found\n");
	}
	if(j==1)
	{
		printf("Found\n");
	}
	return;
}

	




