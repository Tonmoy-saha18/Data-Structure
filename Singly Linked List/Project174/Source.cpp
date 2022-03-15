#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	node *next;
};
struct node *insert(struct node *s,int value)
{
	struct node*current;
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->value=value;
	newnode->next=NULL;
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
	}
	return s;
}
struct node*printlist(struct node*s)
{
	struct node*current;
	current=s;
	printf("The values are:\n");
	printf("%d\n",current->value);
	while(current->next!=NULL)
	{
		current=current->next;
		printf("%d\n",current->value);
	}
	return s;
}
struct node*del(node *s,int data)
{
	struct node*current;
	struct node*temp;
	current=s;
	if(current->value==data)
	{
		s=current->next;
		free(current);
		return s;
	}
	else
	{
		while(current->next!=NULL)
		{
			if(current->next->value==data)
			{
				temp=current->next;
				current->next=temp->next;
				free(temp);
				return s;
			}
			else
			{
				current=current->next;
			}
		}
	}
	return s;
}
struct node*src(node *s,int data)
{
	struct node*current;
	current=s;
	while(current->next!=NULL)
	{
		if(current->value==data)
		{
			printf("Found\n");
			return s;
		}
		else
		{
			current=current->next;
		}
	}
	if(current->value==data)
	{
		printf("Found\n");
		return s;
	}
	printf("Not found\n");
	return s;
}
int length(node *s)
{
	struct node*current;
	current=s;
	int n=1;
	if(current==NULL)
	{
		n--;
	}
	while(current->next!=NULL)
	{
		current=current->next;
		n++;
	}
	return n;
}
int main()
{
	struct node*head=NULL;
	int n,i,a,b,c,d;
	printf("1.Insert\n2.print\n3.delete\n4.search\n5.delete\n");
	for(i=0;i<20;i++)
	{
		printf("Enter you choice:");
		scanf("%d",&d);
		if(d==1)
		{
			printf("Enter the number to insert:");
			scanf("%d",&n);
			head=insert(head,n);
		}
		if(d==2)
		{
			head=printlist(head);
		}
		if(d==3)
		{
			printf("Enter the number to delete:");
			scanf("%d",&a);
			head=del(head,a);
		}
		if(d==4)
		{
			printf("Enter a number to search:");
			scanf("%d",&c);
			head=src(head,c);
		}
		if(d==5)
		{
			b=length(head);
			printf("The length is:%d\n",b);
		}
	}
	return 0;
}



