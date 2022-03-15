#include<stdio.h>
int stack_size=10;
int top=-1;
int stack[1000];
int isfull()
{
	if(top==stack_size-1)
	{
		return 1;
	}
	return 0;
}
int isempty()
{
	if(top==-1)
	{
		return 1;
	}
	return 0;
}
void push(int value)
{
	if(!isfull())
	{
		top++;
		stack[top]=value;
	}
}
int pop()
{
	int n;
	if(!isempty())
	{
		n=stack[top];
		top--;
		return n;
	}
}
int main()
{
	char a[100];
	int i,j,k,z,l;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			push(a[i]-48);
		}
		else
		{
			j=pop();
			k=pop();
			if(a[i]=='+')
			{
				push(j+k);
			}
			if(a[i]=='-')
			{
				push(k-j);
			}
			if(a[i]=='*')
			{
				push(j*k);
			}
			if(a[i]=='/')
			{
				push(k/j);
			}
		}
	}
	l=pop();
	printf("the result is: %d\n",l);
	return 0;
}