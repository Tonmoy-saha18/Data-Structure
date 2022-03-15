#include<stdio.h>
#include<stdlib.h>
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
struct node *printlist(node *s)
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
struct node *print_fst_3(node *s)
{
	struct node *current;
	int i=0;
	current=s;
	printf("first 3: ");
	while(current->next!=NULL&&i!=3)
	{
		printf("%d -> ",current->value);
		current=current->next;
		i++;
	}
	return s;
}
struct node *print_lst_3(node *s)
{
	int i=1,j=0,k=0;
	struct node *current;
	struct node *temp;
	current=s;
	temp=s;
	while(current->next!=NULL)
	{
		i++;
		current=current->next;
	}
	while(j!=i-3)
	{
		temp=temp->next;
		j++;
	}
	printf("\n");
	printf("Last 3: ");
	while(temp->next!=NULL)
	{
		printf("%d -> ",temp->value);
		temp=temp->next;
	}
	printf("%d\n",temp->value);
	return s;
}
int minimum(node *s)
{
	int min;
	struct node *current;
	current=s;
	min=current->value;
	while(current->next!=NULL)
	{
		if(min>current->value)
		{
			min=current->value;
		}
		current=current->next;
	}
	return min;
}
struct node *insert_at_head(node *s,int value)
{
	struct node *newnode=(node*)malloc(sizeof(node));
	newnode->value=value;
	newnode->next=s;
	s=newnode;
	return s;
}
int main()
{
	struct node *first=(node*)malloc(sizeof(node));
	first=NULL;
	int i,j,n,l;
	printf("how many num?");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		first=insert(first,j);
	}
	first=printlist(first);
	first=print_fst_3(first);
	first=print_lst_3(first);
	l=minimum(first);
	first=insert_at_head(first,l);
	printf("print aFter insert minimum: ");
	first=printlist(first);
	return 0;
}