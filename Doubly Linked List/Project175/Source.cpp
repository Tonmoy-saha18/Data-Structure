#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	node *next;
	node *prev;
};
struct node *insert(node *s,int value)
{
	struct node *current;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->next=NULL;
	newnode->prev=NULL;
	if(s==NULL)
	{
		s=newnode;
	}
	else
	{
		current=s;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newnode;
		newnode->prev=current;
	}
	return s;
}
struct node*printlist(struct node*s)
{
	struct node*current;
	current=s;
	printf("The values are:\n");
	printf("%d\n",current->data);
	while(current->next!=NULL)
	{
		current=current->next;
		printf("%d\n",current->data);
	}
	return s;
}
struct node *del(struct node *s,int value)
{
	struct node *current;
	struct node *temp;
	current=s;
	if(current->data==value)
	{
		temp=current;
		temp=temp->next;
		temp->prev=current->prev;
		s=temp;
	}
	else
	{
		current=s;
		while(current->next!=NULL)
		{
			if(current->next->data==value)
			{
				temp=current->next;
				current->next=temp->next;
				if(current->next==NULL)
				{
					break;
				}
				current->next->prev=temp->prev;
			}
			else
			{
				current=current->next;
			}
		}
	}
	return s;
}
struct node *rev(struct node *s)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	printf("Data after reverse:\n");
	while(current->prev!=NULL)
	{
		printf("%d\n",current->data);
		current=current->prev;
	}
	printf("%d\n",current->data);
	return s;
}
int main()
{
	int i,j,n,c;
	struct node *head=NULL;
	printf("Enter the number:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",&n);
		head=insert(head,n);
	}
	head=printlist(head);
	printf("Enter the number to delete:");
	scanf("%d",&j);
	head=del(head,j);
	head=printlist(head);
	head=rev(head);
	return 0;
}