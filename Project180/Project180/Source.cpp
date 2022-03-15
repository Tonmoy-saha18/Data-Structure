#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	node *next;
};
struct node *insert(node *s,int data)
{
	struct node *current;
	struct node *temp=(node*)malloc(sizeof(node));
	temp->value=data;
	temp->next=NULL;
	if(s==NULL)
	{
		s=temp;
	}
	else
	{
		current=s;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
	}
	return s;
}
struct node *display(node*s)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		printf("%d -> ",current->value);
		current=current->next;
	}
	printf("%d\n",current->value);
	return s;
}
struct node *midpoint(node *s)
{
	struct node *current;
	struct node *mid;
	int i=0,j=0;
	current=s;
	mid=s;
	while(current->next!=NULL)
	{
		current=current->next;
		i++;
	}
	while(j!=(i/2))
	{
		mid=mid->next;
		j++;
	}
	printf("mid value-> %d\n",mid->value);
	return s;
}
struct node *deletee(node *s,int data)
{
	struct node *current;
	struct node *temp;
	current=s;
	if(current->value==data)
	{
		current=current->next;
		s=current;
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
void search(node *s,int data)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		if(current->value==data)
		{
			printf("Found\n");
			return;
		}
		else
		{
			current=current->next;
		}
	}
	if(current->value==data)
	{
		printf("Found\n");
		return;
	}
	printf("Not found\n");
	return;
}
int main()
{
	struct node *first=(node*)malloc(sizeof(node));
	first=NULL;
	int i,j,value,delnum,srch;
	printf("How many numbers?");
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		scanf("%d",&value);
		first=insert(first,value);
	}
	first=display(first);
	first=midpoint(first);
	printf("Enter a number to delete:");
	scanf("%d",&delnum);
	first=deletee(first,delnum);
	printf("data after delete: ");
	first=display(first);
	printf("Enter a number to search:");
	scanf("%d",&srch);
	search(first,srch);
	return 0;
}
