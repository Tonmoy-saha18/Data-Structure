#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct btnode
{
	int value;
	btnode *right;
	btnode *left;
};
struct btnode *A[100];
int queuesize=100;
int front=0;
int rear=0;
int occupied=0;
int isempty()
{
	if(occupied==0)
	{
		return 1;
	}
	return 0;
}
int isfull()
{
	if(occupied==queuesize)
	{
		return 1;
	}
	return 0;
}
void enqueue(btnode *root)
{
	if(!isfull())
	{
		A[rear]=root;
		rear=(rear+1)%queuesize;
		occupied++;
		return;
	}
	else
	{
		printf("The queue is full\n");
		return;
	}
}
void dequeue()
{
	if(!isempty())
	{
		front=(front+1)%queuesize;
		occupied--;
		return;
	}
	else
	{
		printf("queue is empty\n");
		return;
	}
}
struct btnode *top()
{
    btnode  *a;
	a=A[front];
	return a;
}
struct btnode *insert(btnode *root,int value)
{
	struct btnode *newnode=(btnode*)malloc(sizeof(btnode));
	struct btnode *current;
	struct btnode *temp;
	newnode->value=value;
	newnode->left=NULL;
	newnode->right=NULL;
	current=root;
	if(root==NULL)
	{
		root=newnode;
		return root;
	}
	else 
	{
		temp=root;
		while(current!=NULL)
		{
			temp=current;
			if(value>current->value)
			{
				current=current->right;
			}
			else
			{
				current=current->left;
			}
		}
		if(value>temp->value)
		{
			temp->right=newnode;
		}
		else
		{
			temp->left=newnode;
		}
		return root;
	}
}
void inordertraversal(btnode *root)
{
	if(root==NULL)
	{
		return;
	}
	inordertraversal(root->left);
	printf("%d ",root->value);
	inordertraversal(root->right);
}
void preorder(btnode *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->value);
	preorder(root->left);
	preorder(root->right);
}
void postorder(btnode *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->value);
}
void levelorder(btnode *root)
{
	struct btnode *current;
	enqueue(root);
	while(!isempty())
	{
		current=top();
		printf("%d ",current->value);
		dequeue();
		if(current->left!=NULL)
		{
			enqueue(current->left);
		}
		if(current->right!=NULL)
		{
			enqueue(current->right);
		}
	}
	return;
}
int search(btnode *root,int key)
{
	struct btnode *current;
	current=root;
	if(current==NULL)
	{
		return 0;
	}
	else
	{
		current=root;
		if(current->value==key)
		{
			return 1;
		}
		else
		{
			while(current!=NULL)
			{
				if(key>current->value)
				{
					current=current->right;
					if(current==NULL)
					{
						return 0;
					}
					if(current->value==key)
					{
						return 1;
					}
				}
				else
				{
					current=current->left;
					if(current==NULL)
					{
						return 0;
					}
					if(current->value==key)
					{
						return 1;
					}
				}
			}
		}
	}
}
int minimum(btnode *root)
{
	struct btnode *current;
	current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current->value;
}
int maximum(btnode *root)
{
	struct btnode *current;
	current=root;
	while(current->right!=NULL)
	{
		current=current->right;
	}
	return current->value;
}
int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}
int height(btnode *root)
{
	if(root==NULL)
	{
		return -1;
	}
	else if(root->left==NULL&&root->right==NULL)
	{
		return 0;
	}
	else
	{
		return max(height(root->right),height(root->left))+1;
	}
}
struct btnode *min(btnode *root)
{
	btnode *current;
	current=root;
	while(current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}
struct btnode *del(btnode *root,int key)
{
	int a;
	struct btnode *current;
	current=root;
	if(root==NULL)
	{
		return root;
	}
	else if(key<root->value)
	{
		root->left=del(root->left,key);
	}
	else if(key>root->value)
	{
		root->right=del(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			struct btnode *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct btnode *temp=root->left;
			free(root);
			return temp;
		}
		struct btnode *temp;
		temp=min(root->right);
		root->value=temp->value;
		root->right=del(root->right,temp->value);
	}
	return root;
}
int main()
{
	struct btnode *head=NULL;
	int k,i,n,j,d=0,K;
	printf("1:Insert\n2:Inordertraversal\n3:Minimum\n4:Maximum\n5:Heightoftree\n6:Search\n7:Levelordertraversal\n8:Preorder\n9:Postorder\n10:delete\n");
	printf("Exit->Anything except these:\n\n");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
		case 1:printf("Enter the number to insert:");
			scanf("%d",&k);
			head=insert(head,k);
			break;
		case 2:printf("Inorder traversal:");
			inordertraversal(head);
			printf("\n");
			break;
		case 3:j=minimum(head);
			printf("The minumum is:%d\n",j);
			break;
		case 4:j=maximum(head);
			printf("The maximum is:%d\n",j);
			break;
		case 5:j=height(head);
			printf("The height of the tree is:%d\n",j);
			break;
		case 6:printf("Enter a number to search:");
			scanf("%d",&n);
			j=search(head,n);
			if(j==0)
			{
				printf("Not found\n");
			}
			else
			{
				printf("Found\n");
			}
			break;
		case 7:printf("levelorder traversal:");
			levelorder(head);
			printf("\n");
			break;
		case 8:printf("Preorder traversa:");
			preorder(head);
			printf("\n");
			break;
		case 9:printf("Postorder traversal:");
			postorder(head);
			printf("\n");
			break;
		case 10:printf("Enter the number to delete:");
			scanf("%d",&K);
			head=del(head,K);
			break;
		default:d=1;
			break;
		}
		if(d==1)
		{
			break;
		}
	}
	return 0;
}




