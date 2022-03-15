#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void INSERTION_SORT(int A[]);
void BUBBLE_SORT(int A[]);
void SELECTION_SORT(int A[]);
int main()
{
	int i,n,A[50000],B[50000],C[50000];
	clock_t start,stop,start1,stop1,a,b;
	for(i=0;i<50000;i++)
	{
		n=rand()%50000;
		A[i]=n;
		B[i]=n;
		C[i]=n;
	}
	start=clock();
	INSERTION_SORT(A);
	stop=clock();
	printf("insertation sort:%lf\n",((double)(stop-start)/CLOCKS_PER_SEC));
	start1=clock();
	BUBBLE_SORT(B);
	stop1=clock();
	printf("Bubble sort:%lf\n",((double)(stop1-start)/CLOCKS_PER_SEC));
	a=clock();
	SELECTION_SORT(C);
	b=clock();
	printf("Selection sort:%lf\n",((double)(b-a)/CLOCKS_PER_SEC));
	return 0;
}
void INSERTION_SORT(int A[])
{
	int i,j,k,l;
	for(i=1;i<50000;i++)
	{
		k=A[i];
		j=i-1;
		while(j>=0&&A[j]>k)
		{
			A[j+1]=A[j];
			j=j-1;
		}
		A[j+1]=k;
	}
	return;
}
void BUBBLE_SORT(int A[])
{
	int i,j,k;
	for(i=0;i<50000-1;i++)
	{
		for(j=0;j<50000-i-1;j++)
		{
			if(A[j+1]<A[j])
			{
				k=A[j];
				A[j]=A[j+1];
				A[j+1]=k;
			}
		}
	}
	return;
}
void SELECTION_SORT(int A[])
{
	int i,j,l,k;
	for(i=0;i<50000;i++)
	{
		l=i;
		for(j=i+1;j<50000;j++)
		{
			if(A[l]>A[j])
			{
				l=j;
			}
		}
		if(l!=i)
		{
			k=A[i];
			A[i]=A[l];
			A[l]=k;
		}
	}
	return;
}