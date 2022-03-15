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
};
struct hash *table1=NULL;
int A[100];
int queuesize=100;
int occupied=0;
int front=0;
int rear=0;
int B[100];
int font=-1;
int stacksize=100;
int qisfull()
{
	if(occupied==queuesize)
	{
		return 1;
	}
	return 0;
}
int qisempty()
{
	if(occupied==0)
	{
		return 1;
	}
	return 0;
}
void enqueue(int a)
{
	if(!qisfull())
	{
		A[rear]=a;
		rear=(rear+1)%queuesize;
		occupied++;
		return;
	}
	printf("The queue is full\n");
	return;
}
int qtop()
{
	int a;
	if(!qisempty())
	{
		a=A[front];
		return a;
	}
}
void dequeue()
{
	if(!qisempty())
	{
		front=(front+1)%queuesize;
		occupied--;
		return;
	}
	printf("The queue isa empty\n");
	return;
}
int sisfull()
{
	if(font==stacksize-1)
	{
		return 1;
	}
	return 0;
}
int sisempty()
{
	if(font==-1)
	{
		return 1;
	}
	return 0;
}
void push(int a)
{
	if(!sisfull())
	{
		font++;
		B[font]=a;
		return;
	}
	printf("stack is full\n");
	return;
}
int s_top()
{
	int a;
	a=B[font];
	return a;
}
void pop()
{
	if(!sisempty())
	{
		font--;
		return;
	}
	printf("stack is empty\n");
	return;
}
void insert(int a,int b)
{
	struct node *newnode=(node*)malloc(sizeof(node));
	struct node *current;
	newnode->value=b;
	newnode->next=NULL;
	if(table1[a].head==NULL)
	{
		table1[a].head=newnode;
	}
	else
	{
		current=table1[a].head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=newnode;
	}
	return;
}
void BFS(int source,int a[])
{
	int b;
	struct node *C;
	enqueue(source);
	//a[source]=1;
	while(!qisempty())
	{
		b=qtop();
		dequeue();
		printf("%d ",b);
		C=table1[b].head;
		while(C!=NULL)
		{
			if(a[C->value]==0)
			{
				enqueue(C->value);
			}
			C=C->next;
		}
		a[b]=1;
	}
	return;
}
void DFS(int source,int b[])
{
	int a;
	struct node *s;
	push(source);
	//b[source]=1;
	while(!sisempty())
	{
		a=s_top();
		pop();
		printf("%d ",a);
		s=table1[a].head;
		while(s!=NULL)
		{
			if(b[s->value]==0)
			{
				push(s->value);
			}
			s=s->next;
		}
		b[a]=1;
	}
	return;
}
int main()
{
	int vert,ed,path,l,i,n;
	printf("1:Insert\n2:BFS Search\n3:DFS Search\nOtherwise exit\n\n");
	printf("How many vertices:");
	scanf("%d",&vert);
	table1=(hash*)malloc(sizeof(hash)*vert);
	for(i=0;i<vert;i++)
	{
		table1[i].head=NULL;
	}
	printf("How many edges:");
	scanf("%d",&ed);
	int a[20]={0};
	int b[20]={0};
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&n);
		if(n==1)
		{
			for(i=0;i<ed;i++)
			{
				printf("Enter the path number %d:",i+1);
				scanf("%d%d",&path,&l);
				insert(path,l);
			
			}
		}
		else if(n==2)
		{
			printf("Enter the source:");
			scanf("%d",&n);
			BFS(n,a);
			printf("\n");
		}
		else if(n==3)
		{
			printf("Enter the source:");
			scanf("%d",&n);
			DFS(n,b);
			printf("\n");
		}
		else
		{
			break;
		}
	}
	return 0;
}





