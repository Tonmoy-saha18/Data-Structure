#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[25];
	int age;
	int ph;
	struct node *next;
};
struct hash
{
	struct node *head;
	int count;
};
struct hash *hashtable=NULL;
int elecount=0;
void insert(int age,int num)
{
	int index;
	index=age-elecount;
	struct node *current;
	struct node *newnode=(node*)malloc(sizeof(node));
	printf("name:");
	fflush(stdin);
	gets(newnode->name);
	newnode->age=age;
	newnode->ph=num;
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
int search(int key,char B[])
{
	struct node *current;
	int index,l=1;
	index=key-elecount;
	current=hashtable[index].head;
	if(current==NULL)
	{
		return 0;
	}
	while(current->next!=NULL)
	{
		if(strcmpi(current->name,B)==0)
		{
			return 1;
		}
		else
		{
			current=current->next;
		}
	}
	if(strcmpi(current->name,B)==0)
	{
		return 1;
	}
	return 0;
}
struct node *del(int key,char B[])
{
	struct node *current;
	int index;
	index=key-elecount;
	current=hashtable[index].head;
	if(strcmpi(current->name,B)==0)
	{
		current=current->next;
		hashtable[index].head=current;
		return current;
	}
	else
	{
		while(current->next->next!=NULL)
		{
			if(strcmpi(current->next->name,B)==0)
			{
				current->next=current->next->next;
				return current;
			}
			current=current->next;
		}
		if(strcmpi(current->next->name,B)==0)
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
	for(i=0;i<elecount-11;i++)
	{
		current=hashtable[i].head;
		printf("bucket %d-> information of people in age %d\n",i,i+18);
		printf("-------------------\n");
		if(current!=NULL)
		{
			while(current->next!=NULL)
			{
				printf("name:%s\n",current->name);
				printf("phone number:%d\n\n",current->ph);
			    current=current->next;
			}
			printf("name:%s\n",current->name);
			printf("Phone number:%d\n\n",current->ph);
		}
		else
		{
			printf("\n");
		}
		printf("-------------------\n");
	}
	return;
}
int main()
{
	int n,i,j,k,phn,l;
	char a[2],A[100],B[100];
	printf("Enter the number of bukets:");
	scanf("%d",&n);
	elecount=n+11;
	hashtable=(hash*)malloc(sizeof(hash)*n);
	struct node *pt;
	for(i=0;i<n;i++)
	{
		hashtable[i].head=NULL;
	}
	printf("a:insert\nb:search\nc:delete\nd:display\n");
	for(i=0;i<30;i++)
	{
		printf("Enter your choice:");
		fflush(stdin);
		gets(a);
		if(a[0]=='a')
		{
			printf("Age:");
			scanf("%d",&j);
			printf("Phone number:");
			scanf("%d",&phn);
			insert(j,phn);
		}
		if(a[0]=='b')
		{
			printf("Enter the age and the name to search:");
			scanf("%d",&k);
			fflush(stdin);
			gets(B);
			l=search(k,B);
			if(l==0)
			{
				printf("Not found\n");
			}
			else
			{
				printf("found\n");
			}
		}
		if(a[0]=='c')
		{
			printf("Enter a age and name to delete:");
			scanf("%d",&k);
			fflush(stdin);
			gets(B);
			pt=del(k,B);
		}
		if(a[0]=='d')
		{
			display();
		}
	}
	return 0;
}