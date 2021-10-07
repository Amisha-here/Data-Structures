#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

void DoublylinkedListTraversal(struct Node *ptr){
	while(ptr != NULL){
	printf("Elements: %d\n",ptr->data);
	ptr=ptr->next;
}
}/*
void DoublylinkedListTraversal(struct Node *head)
{
    struct Node * ptr = head;
    while (ptr->next != NULL)
    {
        printf("Elements: %d\n",ptr->data);
        ptr = ptr->next;
    }
    printf("Elements: %d\n",ptr->data);
    printf("\n");
    while (ptr != NULL)
    {
        printf("Elements: %d\n",ptr->data);
        ptr = ptr->prev;
    }  
}
*/
int main(){
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	
	//Allocate memory to Nodes in heap
	head=(struct Node*)malloc(sizeof(struct Node));
	second=(struct Node*)malloc(sizeof(struct Node));
	third=(struct Node*)malloc(sizeof(struct Node));
	fourth=(struct Node*)malloc(sizeof(struct Node));
	
	//Link first to second as well prev to NULL
	head->data=23;
	head->prev=NULL;
	head->next=second;
	
	//Link second to third as well prev to first
	second->data=34;
	second->prev=head;
	second->next=third;
	
	//Link third to fourth as well prev to second
	third->data=56;
	third->prev=second;
	third->next=fourth;
	
	//Link fourth to NULL as well prev to third
    fourth->data=52;
    fourth->prev=third;
    fourth->next=NULL;
    
    DoublylinkedListTraversal(head);
    //printf("\n");
    //DoublylinkedListTraversal(fourth);
  
  return 0;
}
