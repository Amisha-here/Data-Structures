//Practise this problem here: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

// Should reverse list and return new head.
struct Node* reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    if(head==NULL)
        return head=NULL;

    Node* curr=head;
    Node* prev=NULL;
    Node* next;
    
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return head=prev;
}
