	#include<stdio.h>
	#include<conio.h>
	#include<malloc.h>
	
	struct node
	{
		int data;
		struct node* next;
	};
	
	typedef struct node NODE;
	typedef struct node* PNODE;
	typedef struct node** PPNODE;
	
	void InsertFirst(PPNODE,int);
	void display(PNODE);
	void InsertLast(PPNODE,int);
	void DeleteFirst(PPNODE);
	void DeleteLast(PPNODE);
	int main()
	{
		PNODE Head=NULL;
		InsertFirst(&Head,101);
		InsertFirst(&Head,51);
		InsertFirst(&Head,21);
		InsertFirst(&Head,11);
		display(Head);
		InsertLast(&Head,201);
		display(Head);
		InsertLast(&Head,251);
		display(Head);
		DeleteFirst(&Head);
		display(Head);
		DeleteLast(&Head);
		display(Head);
		InsertLast(&Head,300);
		display(Head);
		return 0;
	}
	
	void InsertFirst(PPNODE first,int no)
	{
		PNODE newn=NULL;
		newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		
		if(*first==NULL)
		{
			*first=newn;
		}
		else
		{
			newn->next=*first;
			*first=newn;
		}
		printf("%d is Added : At First \n",newn->data);
	}
	
	
	void display(PNODE first)
	{
		printf("\n+---------------------------------------------+\n");
		printf("|\tLinked List\t\t\t      |");
		printf("\n+---------------------------------------------+\n|");
		if(first==NULL)
		{
			printf("\nLink List Is Empty");
		}
		while(first!=NULL)
		{
			printf("%d\t",first->data);
			first=first->next;
		}
		
		printf("\n+---------------------------------------------+\n");
		printf("\n");
	}
	
	void InsertLast(PPNODE first,int no)
	{
		PNODE newn=(PNODE)malloc(sizeof(NODE));
		newn->data=no;
		newn->next=NULL;
		PNODE temp=*first;
		if(*first==NULL)
		{
			*first=newn;
		}
		else
		{
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newn;
		}
		printf("%d is Inserted at Last Position \n",newn->data);
	}
	void DeleteFirst(PPNODE first)
	{
		PNODE temp=*first;
		(*first)=temp->next;
		printf("\n%d is Removed : First Node Deleted\n",temp->data);
		free(temp);		
	}
	
	void DeleteLast(PPNODE first)
	{
		PNODE temp=*first;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		printf("\n%d is Removed : One Node Deleted\n",(temp->next)->data);
		free(temp->next);
		
		temp->next=NULL;
	}
