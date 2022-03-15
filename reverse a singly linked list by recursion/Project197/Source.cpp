#include<stdio.h>
#include<stdlib.h>
int n=0;
struct node
{
	int value;
	node *next;
};
struct node *insert(node *s,int value)
{
	struct node *current;
	struct node *newnode=(node*)malloc(sizeof(node));
	newnode->value=value;
	newnode->next=NULL;
	if(s==NULL)
	{
		s=newnode;
		return s;
	}
	else
	{
		current=s;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newnode;
		return s;
	}
}
void display(node *s)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		printf("|%d|->",current->value);
		current=current->next;
	}
	printf("|%d|\n",current->value);
	return;
}
void reverse_singly_linked_list(node *s)
{
	if(s==NULL)
	{
		return;
	}
	else
	{
		n++;
		reverse_singly_linked_list(s->next);
		n--;
		if(n==0)
		{
			printf("|%d|\n",s->value);
		}
		else
		{
			printf("|%d|->",s->value);
		}
	}
}
int main()
{
	struct node *head=(node*)malloc(sizeof(node));
	head=NULL;
	int n,i,data;
	printf("how many numbers you wnat to isert:");
	scanf("%d",&n);
	printf("Enter the input:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		head=insert(head,data);
	}
	printf("Outout: ");
	display(head);
	printf("Output after reverse the linked list: ");
	reverse_singly_linked_list(head);
	return 0;
}

