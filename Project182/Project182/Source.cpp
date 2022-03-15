#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	node *next;
};
struct node *insert(node *s,int n)
{
	struct node *temp;
	struct node *current=(node*)malloc(sizeof(node));
	current->value=n;
	temp=s;
	current->next=temp;
	s=current;
	return s;
}
struct node *add(node *s,node *f)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=f;
	return s;
}
void printlist(node *s)
{
	struct node *current;
	current=s;
	while(current->next!=NULL)
	{
		printf("%d->",current->value);
		current=current->next;
	}
	printf("%d\n",current->value);
	return;
}
int main()
{
	struct node *first=(node*)malloc(sizeof(node));
	first=NULL;
	struct node *scnd=(node*)malloc(sizeof(node));
	scnd=NULL;
	int i,j,n;
	for(i=0;i<2;i++)
	{
		scanf("%d",&j);
		first=insert(first,j);
	}
	for(i=0;i<2;i++)
	{
		scanf("%d",&n);
		scnd=insert(scnd,n);
	}
	first=add(first,scnd);
	printlist(first);
	return 0;
}

