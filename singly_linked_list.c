#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head=NULL;

void insertAtbegin(int value)
{  struct node *newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
   newnode->data=value;
  		
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	
	else
	{
		newnode->next=head;
		head=newnode;
	}
	
	printf("\n Inserted Successfully. \n");
}

void insertAtEnd(int value)
{
	struct node *newnode;
 newnode=(struct node*)malloc(sizeof(struct node));
	
	newnode->data=value;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		newnode->next=NULL;
		head=newnode;
	}
	else
	{
	  struct node *temp=head;
	  while(temp->next!=NULL)
	  temp=temp->next;
	  
	  temp->next=newnode;
	  newnode->next=NULL;	
	}
	return head;
   printf(" \n Inserted Successfully. \n");
}

void display()
{
   struct node *temp=head;
   printf("List is :");
	  while(temp!=NULL)
	  {
	  	printf("%d \t",temp->data);
	  	temp=temp->next;
	 }	
	 printf("\n");
}

 void deleteAtbegin()
 {
 	if(head==NULL)
 	printf("\n List is Empty \n");
 	else
 	{
 		struct node *temp=head;
 		if(head->next==NULL)
 		{
 			head=NULL;
 			free(temp);
		 }
		 else
		 {
		 	head=temp->next;
		 	free(temp);
		 	printf("\n Deleted at Beginning \n");
		 }
	 }
 }
 
 void deleteAtend()
 {
 	if(head==NULL)
 	printf("List is empty");
 	else
 	{
 		struct node *temp1=head,*temp2;
 		if(head->next==NULL)
 		head=NULL;
 		else
 		{
 			while(temp1->next!=NULL)
 			{
 				temp2=temp1;
 				temp1=temp1->next;
			 }
			 temp2->next=NULL;
		 }
		 free(temp1);
		 printf("\n Deleted at the end \n");
	 }
 }
 
 void insert(int value,int x)
 {
 	int i=0;
 	struct node *newnode;
 	newnode=(struct node*)malloc(sizeof(struct node));
 	
 	newnode->data=value;
 	
 	if(head==NULL)
 	{
 		newnode->next=NULL;
 		head=newnode;
	 }
	 else
	 {
	 	struct node *temp=head;
	 	
	 	for(i=0;i<x-1;i++)
	 	{
	 		temp=temp->next;
		 }
		newnode->next=temp->next;
		temp->next=newnode; 
	 }
	 printf("\n Node inserted successfully !! \n");
 }
 
 void delete(int x)
 {
 	int i=0,flag=0;
 	struct node *temp1=head,*temp2;
 	
 	if(x==1)
 	{
 		head=temp1->next;
 		free(temp1);
 		printf("\n deleted \n");
	 }
	else 
	{
		for(i=0;i<x-1;i++)
		{
			if(temp1->next!=NULL)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			else
			{
				flag=1;
				break;
			}
			
			if(flag==0)
			{
				temp2->next=temp1->next;
				free(temp1);
				printf("\n deleted \n");
			}
			else
			printf("\n position exceeds linked list \n");
		}
	}
 }

int main()
{  int choice,value,x;

   while(1){
   
	printf("\n Enter 1: Insert at beggining \n 2: Insert at end \n 3: Display \n  4: Delete at beggining\n  5.Delete at end \n 6. Insert at specific position \n 7.Delete at specific position \n 8.exit \n\n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			{
				printf("Enter value to be inserted: ");
				scanf("%d",&value);
				insertAtbegin(value);
				break;
			}
			
		case 2:
		{
			printf("Enter value to be inserted: ");
				scanf("%d",&value);
				insertAtEnd(value);
				break;
			}	
			
		case 3:
			{
				printf("\n");
				display();
				break;
			}
			
		case 4:
		{
			deleteAtbegin();
			break;
			}
			
		case 5:
		{
			deleteAtend();
			
			break;
				}		
			
		case 6:
		{
			printf("enter value to be inserted \n");
			scanf("%d",&value);
			printf("Enter position at which you want to insert \n");
			scanf("%d",&x);
			
			insert(value,x);
			break;
			}
			
		case 7:
		{
			printf("enter the position to be deleted \n");
			scanf("%d",&x);
			
			delete(x);
			break;
				}		
			
		case 8:
		exit(0);
		
		default:
		printf("TRY AGAIN!!! \n");	
			
	}
}
}




