#include<stdio.h>
#include<stdlib.h>
struct node
{
	int value;
	struct node *next;
};
struct hash
{
	struct node *head;
	int count;
};
struct hash *hashtable=NULL;
int elecount=0;
void insert(int key)
{
	int index;
	index=key%elecount;
	struct node *current;
	struct node *newnode=(node*)malloc(sizeof(node));
	newnode->value=key;
	newnode->next=NULL;
	if(hashtable[index].head==NULL)
	{
		hashtable[index].head=newnode;
		return;
	}
	else
	{
		current=hashtable[index].head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newnode;
		return;
	}
}
int search(int key)
{
	struct node *current;
	int index;
	index=key%elecount;
	current=hashtable[index].head;
	if(current==NULL)
	{
		return 0;
	}
	while(current->next!=NULL)
	{
		if(current->value==key)
		{
			return 1;
		}
		else
		{
			current=current->next;
		}
	}
	if(current->value==key)
	{
		return 1;
	}
	return 0;
}
struct node *del(int key)
{
	struct node *current;
	int index;
	index=key%elecount;
	current=hashtable[index].head;
	if(current->value==key)
	{
		current=current->next;
		hashtable[index].head=current;
		return current;
	}
	else
	{
		while(current->next->next!=NULL)
		{
			if(current->next->value==key)
			{
				current->next=current->next->next;
				return current;
			}
			current=current->next;
		}
		if(current->next->value==key)
		{
			current->next=NULL;
			return current;
		}
	}
}
void display()
{
	int i;
	struct node *current;
	for(i=0;i<elecount;i++)
	{
		current=hashtable[i].head;
		printf("Buket number %d:",i);
		if(current!=NULL)
		{
			while(current->next!=NULL)
			{
			printf("%d-> ",current->value);
			current=current->next;
			}
			printf("%d\n",current->value);
		}
		else
		{
			printf("\n");
		}
	}
	return;
}
int main()
{
	int n,i,j,k,l;
	char a[2];
	printf("Enter the number of bukets:");
	scanf("%d",&n);
	elecount=n;
	hashtable=(hash*)malloc(sizeof(hash)*n);
	struct node *pt;
	for(i=0;i<n;i++)
	{
		hashtable[i].head=NULL;
	}
	printf("a:insert\nb:search\nc:delete\nd:display\n");
	for(i=0;i<30;i++)
	{
		gets(a);
		if(a[0]=='a')
		{
			printf("Enter the number:");
			scanf("%d",&j);
			insert(j);
		}
		if(a[0]=='b')
		{
			printf("Enter the number to search:");
			scanf("%d",&k);
			l=search(k);
			if(l==1)
			{
				printf("The number is found\n");
			}
			else
			{
				printf("The number is not found\n");
			}
		}
		if(a[0]=='c')
		{
			printf("enter a number to delete:");
			scanf("%d",&k);
			pt=del(k);
		}
		if(a[0]=='d')
		{
			display();
		}
	}
	return 0;
}



		

