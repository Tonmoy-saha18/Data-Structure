#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct record
{
	char a[100];
};
struct record data[26];
void insert(char c[],char b[])
{
	int index,i,j;
	index=c[0]-'a';
	i=0;
	while(i<26)
	{
		if(strcmpi(data[index].a,b)==0)
		{
			strcpy(data[index].a,c);
			return;
		}
		else
		{
			index++;
			if(index==26)
			{
				index=0;
			}
		}
		i++;
	}
	printf("Hashtable is full\n");
	return;
}
void del(char c[],char b[])
{
	int index,i;
	index=c[0]-'a';
	i=0;
	while(i<26)
	{
		if(strcmpi(data[index].a,c)==0)
		{
			strcpy(data[index].a,b);
			return;
		}
		else
		{
			index++;
			if(index==26)
			{
				index=0;
			}
		}
		i++;
	}
	printf("The word is not found\n");
	return;
}
int search(char c[],char b[])
{
	int index,i=0;
	index=c[0]-'a';
	while(i<26)
	{
		if(strcmpi(data[index].a,c)==0)
		{
			return 1;
		}
		else
		{
			index++;
			if(index==26)
			{
				index=0;
			}
		}
		i++;
	}
	return 0;
}
void print(record C[])
{
	int i=0;
	while(i<26)
	{
		printf("%d:",i);
		puts(data[i].a);
		i++;
	}
	return;
}
int main()
{
	char d[100],b[2];
	int n,i,D=0,j;
	printf("1:Insert\n2:Delete\n3:Search\n4:Print\n5:Exit\n");
	gets(b);
	for(i=0;i<26;i++)
	{
		strcpy(data[i].a,b);
	}
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
		case 1:fflush(stdin);
			gets(d);
			insert(d,b);
			break;
		case 2:printf("Enter the word to delete:");
			fflush(stdin);
			gets(d);
			del(d,b);
			break;
		case 3:printf("Enter a word to search:");
			fflush(stdin);
			gets(d);
			j=search(d,b);
			if(j==0)
			{
				printf("Not found\n");
			}
			else
			{
				printf("Found\n");
			}
			break;
		case 4:printf("The words are:\n");
			print(data);
			break;
		default:D=1;
			break;
		}
		if(D==1)
		{
			break;
		}
	}
	return 0;
}

