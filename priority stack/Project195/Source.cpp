#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int top;
	int size;
	int *items;
};
struct stack *createstack(int capacity)
{
	struct stack *st1=(stack*)malloc(sizeof(stack));
	st1->top=-1;
	st1->size=capacity;
	st1->items=(int*)malloc(sizeof(int)*capacity);
	return st1;
}
int isfull(stack *st1)
{
	if(st1->top==st1->size-1)
	{
		return 1;
	}
	return 0;
}
int isempty(stack *st1)
{
	if(st1->top==-1)
	{
		return 1;
	}
	return 0;
}
struct stack *pop(stack *pt)
{
	if(!isempty(pt))
	{
		pt->top--;
		return pt;
	}
	else
	{
		printf("stack is empty\n");
		return pt;
	}
}
int peek(stack *pt)
{
	int j;
	j=pt->items[pt->top];
	return j;
}
struct stack *push(stack *pt,int value)
{
	int k;
	if(!isfull(pt))
	{
		if(isempty(pt))
		{
			pt->top++;
			pt->items[pt->top]=value;
			return pt;
		}
		else if(value<pt->items[pt->top])
		{
			pt->top++;
			pt->items[pt->top]=value;
			return pt;
		}
		else
		{
			k=pt->top;
			pt->top++;
			while(k>=0&&pt->items[k]<value)
			{
				pt->items[k+1]=pt->items[k];
				k=k-1;
			}
			pt->items[k+1]=value;
			return pt;
		}
	}
	else
	{
		printf("stack is full\n");
		return pt;
	}
}
int main()
{
	struct stack *pt;
	int i,j,capacity,value;
	printf("Enter the capacity of the stack:");
	scanf("%d",&capacity);
	pt=createstack(capacity);
	printf("Enter the value:");
	for(i=0;i<capacity;i++)
	{
		scanf("%d",&value);
		pt=push(pt,value);
	}
	printf("Output are below:\n");
	for(i=0;i<capacity;i++)
	{
		j=peek(pt);
		printf("|%d|\n",j);
		pt=pop(pt);
	}
	return 0;
}
			








