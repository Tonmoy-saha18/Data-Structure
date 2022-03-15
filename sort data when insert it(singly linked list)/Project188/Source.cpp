#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	node *next;
};
struct node *insertion(node *s,int value)
{
	struct node *current;
	struct node *temp;
	temp=s;
	struct node *newnode=(node*)malloc(sizeof(node));
	newnode->data=value;
	newnode->next=NULL;
	if(s==NULL)
	{
		s=newnode;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		if(value<s->data)
		{
			newnode->next=s;
			s=newnode;
		}
		if(value>s->data&&(temp->data<value||s->next==NULL))
		{
			temp->next=newnode;
		}
		current=s;
		while(current->next!=NULL)
		{
			if(value>current->data&&value<current->next->data)
			{
				newnode->next=current->next;
				current->next=newnode;
			}
			current=current->next;
		}
	}
	return s;
}
void prinlist(node *s)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		printf("%d -> ",current->data);
		current=current->next;
	}
	printf("%d\n",current->data);
	return;
}
int main()
{
	struct node *first=(node*)malloc(sizeof(node));
	first=NULL;
	int i,n;
	for(i=0;i<10;i++)
	{
		scanf("%d",&n);
		first=insertion(first,n);
	}
	prinlist(first);
	return 0;
}