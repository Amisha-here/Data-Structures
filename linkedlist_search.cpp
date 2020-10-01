#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
void search(Node *head, int n, int val){
    Node *ptr = head;
    for(int i = 0;i<n;i++){
    if(ptr->data==val){
        cout<<"Value is found inside the linked list at node "<<i+1;
        break;
    }
        if(i == n-1){
            cout<<"Value is not found in the linked list";
            break;
        }
     ptr = ptr->next;
    }
}
Node* insert(Node *head, int n){
    Node *ptr = head;
    for(int i = 0;i<n;i++){
        cout<<"Enter the value "<<i+1<<" : ";
        cin>>ptr->data;
        if(i==n-1){
            break;
        }
        ptr->next = new Node();
        ptr = ptr->next;
    }
    ptr->next = NULL;

}
int main(){
    int n, val;
    Node* head = NULL;
    head = new Node();
    cout<<"Enter the no of elements: ";
    cin>>n;
    insert(head, n);
    cout<<"Enter the value you want to search in the linked list : ";
    cin>>val;
    search(head, n, val);
}
