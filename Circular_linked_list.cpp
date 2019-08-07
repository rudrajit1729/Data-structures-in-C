#include <stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *link;
}N;
N *start;
void insert_at_end(int v)
{
	N *nu=(N*)malloc(sizeof(N)),*ptr;
	nu->data=v;
	nu->link=NULL;
	if (start==NULL)
	{
		start=nu;
		nu->link=start;
		return;
	}
	for(ptr=start;ptr->link!=start;ptr=ptr->link);
	ptr->link=nu;
	nu->link=start;
}
void insert_at_beg(int v)
	{
		N *nu=(N*)malloc(sizeof(N)),*ptr;
		nu->data=v;
		nu->link=NULL;
		if(start==NULL)
		{
			start=nu;
			start->link=start;
			return;
		}
		for(ptr=start;ptr->link!=start;ptr=ptr->link);
		nu->link=start;
		start=nu;
		ptr->link=start;
	}

void delete_from_beg()
{
	N *ptr=start,*ptr2=start;
	if(start==NULL)
	{
		printf("\nEmpty\n");
		return;
	}
	printf("\nDeleted item =%d\n",ptr2->data);
	if(start==start->link)
	{
		start=NULL;
		return;
	}
	for(ptr=start;ptr->link!=start;ptr=ptr->link);
	start=start->link;
	ptr->link=start;
	free(ptr2);
}
void delete_from_end()
{
	N *ptr=start,*prev=start;
	if(start==NULL)
	{
		printf("\nEmpty\n");
		return;
	}
	while(ptr->link!=start)
	{
		prev=ptr;
		ptr=ptr->link;
	}
	if(ptr==start)
	start=NULL;
	else
		prev->link=start;
	printf("\nDeleted item =%d\n",ptr->data);
	free(ptr);	
}
void display()
{
	N *ptr=start;
	printf("\nThe linked list:\n");
	if(start==NULL)
	{
		printf("Empty\n");
		return;
	}
	do
	{
		printf("%d  ",ptr->data);
		ptr=ptr->link;
	}while(ptr!=start);
}
int search(int key)
	{
		N *ptr=start;int i=0;
		if (start==NULL)
		return -1;
		do
		{
			i++;
			if (key==ptr->data)
			return i;
			ptr=ptr->link;
		}while(ptr!=start);
		return -1;
	}
int main()
{
	int ch,ch2,v,p,key;
	while(1)
	{
		printf("\nPress 1/2/3/4/5 for insert ,delete,display,search,exit:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nPress 1/2 to insert at beg/end:");
				scanf("%d",&ch2);
				printf("\nEnter value:");
				scanf("%d",&v);
				switch(ch2)
				{
					case 1:
						insert_at_beg(v);
						display();
						break;
					case 2:
						insert_at_end(v);
						display();
						break;
					default:
						printf("\nEnter correct choice!!!");
				}
				break;
			case 2:
				printf("\nPress 1/2 to delete from beg/end:");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						delete_from_beg();
						display();
						break;
					case 2:
						delete_from_end();
						display();
						break;
					default:
						printf("\nEnter correct choice!!!");
				}
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\nEnter key:");
				scanf("%d",&key);
				p=search(key);
				if(p==-1)
				printf("\nNot found\n");
				else
				printf("\nFound at position %d",p);
				break;
			case 5:
				printf("Thank You!!!Visit Again!!!");
				return 0;
			default:
				printf("\nEnter correct choice!!!");
			}
		}
	}
	
	
	
	
