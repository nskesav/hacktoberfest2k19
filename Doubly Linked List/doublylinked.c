#include<stdio.h>
#include<stdlib.h>
//PrograM tO cREATE AND uSE dOUBLY LINKED lIST
typedef struct node 
{
	struct node *rlink;
	int data;
	struct node *llink;
}NODE;

typedef struct list
{
	NODE *head;
	int length;
}List;

List* create_list() {
        List *newList = (List*)malloc(sizeof(List));
        newList->head = NULL;
        newList->length = 0;
        return newList;
}
void insertat(List *list, int data, int pos)
{
	NODE *temp,*p;
	temp = (NODE *)malloc(sizeof(NODE));
	temp->llink = NULL;
	temp->data = data;
	temp->rlink = NULL;
	p = list->head;
	int i;
	if(pos >= 0 && pos <= (list->length)){
	if(list->head == NULL)
	{
		list->head = temp;
		list->length++;
		return;
	}
	else if(pos == 0)
	{
		temp->rlink = p;
		p->llink = temp;
		temp->llink = NULL;
		list->head = temp;
		list->length++;
		return;
	}
	else
	{
		for(i = 1; i<pos;i++)
		{
			p = p->rlink;
		}
		temp->rlink = p->rlink;
		if(p->rlink != NULL)
			p->rlink->llink = temp;
		p->rlink = temp;
		temp->llink = p;
		list->length++;
		return;
	}
	}
	else 
		return;
}
void deleteat(List *list, int pos)
{
	NODE *prev,*p;
	p = list->head;
	int i;
	if(pos >= 0 && pos <= (list->length)){
	if(list->head == NULL)
	{
		return;
	}
	else if(pos == 0 && list->head->rlink == NULL)
	{
		free(p);
		list->head = NULL;
		return;
	}
	else if(pos == 0)
	{
		prev = p;
		list->head = p->rlink;
		list->head->llink = NULL;
		list->length--;
		free(prev);
		return;
	}
	else
	{
		for(i = 0; i<pos;i++)
		{
			prev = p;
			p = p->rlink;
		}
		prev->rlink = p->rlink;
		if(p->rlink != NULL)
			p->rlink->llink = prev;
		else
			p->rlink = NULL;
		free(p);
		list->length--;
		return;
	}
	}
	else 
		return;
}
void display(List *list)
{
	NODE * temp;
	temp = list->head;
	if(temp == NULL)
			printf("List EMPTY!!!!!!!!!!!!!!!!\n\n ");
	else
	{
		while(temp!= NULL)
		{
			printf("%d --> ", temp->data);
			temp = temp->rlink;
		}
		printf("\n\n");
	}
}
void main()
{
	int choice;
	int data,pos = 0;
	List *list  = create_list();
	while(1)
	{
		printf("\n\nEnter\n 1. For insert begining\n 2. For insert at position\n \
3. insert at end \n 4. delete at beginning\n 5. delete at position \n 6. delete at end\n\
 7. display \n\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
					printf("Enter the data:- ");
					scanf("%d",&data);
					insertat(list,data,pos);
					break;
			case 2:
					printf("Enter the data:- ");
					scanf("%d",&data);
					printf("Enter the position:- ");
					scanf("%d",&pos);
					insertat(list,data,pos);
					break;
			case 3:
					printf("Enter the data:- ");
					scanf("%d",&data);
					insertat(list,data,pos = (list->length));
					break;
			case 4:
					deleteat(list,pos = 0);
					break;
			case 5:
					printf("Enter the position:- ");
					scanf("%d",&pos);
					deleteat(list,pos);
					break;
			case 6:
					deleteat(list,pos = (list->length)-1);
					break;
			case 7:
					display(list);
					break;
			case 8:
					exit(0);
			default:
					printf("Invalid INPUT");
		}
	}
}
