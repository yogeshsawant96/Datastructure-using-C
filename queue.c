#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * next;
};
typedef node NODE;
typedef node * PNODE;
typedef node ** PPNODE;

void insertLast(PPNODE first,int d)
{
	PNODE newn=(PNODE)malloc(sizeof(NODE));
	newn->data=d;
	newn->next=NULL;
	PNODE temp=*first;
	if(*first==NULL)//Empty LL
	{
		*first=newn;
		newn->next=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
}
void display(PNODE first)
{
	if(first==NULL)
	{
		printf("\nEmpty Queue\n");
	}
	while(first!=NULL)
	{
		printf("%d ",first->data);
		first=first->next;
	}
}

void deleteFirst(PPNODE first)
{
	PNODE temp=*first;
	if(first==NULL)
	{
		printf("\nEmpty Queue");
		return;
	}
	*first=temp->next;
	free(temp);
}


int main()
{
	
	printf("\nEnQueue\n");
	PNODE head=NULL;
	insertLast(&head,11);
	insertLast(&head,21);
	insertLast(&head,51);
	insertLast(&head,101);
	insertLast(&head,121);
	insertLast(&head,151);
	display(head);
	printf("\nDequeue\n");
	deleteFirst(&head);
	deleteFirst(&head);
	deleteFirst(&head);
	display(head);
	printf("\nEnque\n");	
	insertLast(&head,11);
	insertLast(&head,21);
	insertLast(&head,51);
	display(head);
	deleteFirst(&head);
	deleteFirst(&head);
	deleteFirst(&head);
	deleteFirst(&head);
	deleteFirst(&head);
	printf("\nDequeue\n");
	display(head);
	deleteFirst(&head);
	display(head);
	return 0;
}