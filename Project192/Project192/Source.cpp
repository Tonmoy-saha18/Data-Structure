#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int top;
	int stack_size;
	int *items;
};
int isfull(stack *st1)
{
	if(st1->top==st1->stack_size-1)
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
struct stack *createstack(int capacity)
{
	stack *pt=(stack*)malloc(sizeof(stack));
	pt->top=-1;
	pt->stack_size=capacity;
	pt->items=(int*)malloc(sizeof(int)*capacity);
	return pt;
}
struct stack *push(stack *st1,int value)
{
	if(!isfull(st1))
	{
		st1->top++;
		st1->items[st1->top]=value;
	}
	else
	{
		printf("stack is full\n");
	}
	return st1;
}
int pop(stack *st1)
{
	if(!isempty(st1))
	{
		int p=st1->items[st1->top];
		st1->top--;
		return p;
	}
}
int main()
{
	struct stack *pt=(stack*)malloc(sizeof(stack));
	int i,capacity,value,j;
	char A[100];
	printf("Enter string:");
	gets(A);
	printf("enter capacity of the stack:");
	scanf("%d",&capacity);
	pt=createstack(capacity);
	for(i=0;A[i]!='\0';i++)
	{
		if(A[i]=='{'||A[i]=='('||A[i]=='[')
		{
			pt=push(pt,A[i]-'0');
		}
		else
		{
			j=pop(pt);
			if((A[i]=='('&&j+'0'==')')||(A[i]=='{'&&j+'0'=='}')||(A[i]=='['&&j+'0'==']'))
			{
			}
			else
			{
				printf("Imbalanced\n");
				break;
			}
		}
	}
	if(isempty(pt))
	{
		printf("Balanced\n");
	}
	return 0;
}

