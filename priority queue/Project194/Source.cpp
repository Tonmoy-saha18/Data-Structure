#include<stdio.h>
#include<stdlib.h>
int queue_size;
int rear=0;
int front=0;
int occupied=0;
int i=0;
int A[1000];
int isfull()
{
	if(occupied==queue_size)
	{
		return 1;
	}
	return 0;
}
int isempty()
{
	if(occupied==0)
	{
		return 1;
	}
	return 0;
}
void enqueue(int data)
{
	int j,k;
	if(!isfull())
	{
		if(isempty())
		{
			A[rear]=data;
			rear=(rear+1)%queue_size;
			occupied++;
			return;
		}
		else if(data>A[rear-1])
		{
			A[rear]=data;
			rear=(rear+1)%queue_size;
			occupied++;
			return;
		}
		else
		{
			k=rear;
			while(k-->=0&&A[k]>data)
			{
				A[k+1]=A[k];
			}
			A[k+1]=data;
			rear=(rear+1)%queue_size;
			occupied++;
			return;
		}
	}
}
int dequeue()
{
	int top;
	if(!isempty())
	{
		top=A[front];
		front++;
		occupied--;
		if(front==queue_size)
		{
			front=0;
		}
		return top;
	}
	else
	{
		printf("queue is empty\n");
		return 0;
	}
}
int main()
{
	int i,n,value,N;
	printf("Enter queue size:");
	scanf("%d",&queue_size);
	printf("How many numbers:");
	scanf("%d",&N);
	printf("Enter the numbers:");
	for(i=0;i<N;i++)
	{
		scanf("%d",&value);
		enqueue(value);
	}
	printf("The outputs are below:\n");
	for(i=0;i<N;i++)
	{
		n=dequeue();
		printf("|%d|\n",n);
	}
	return 0;
}