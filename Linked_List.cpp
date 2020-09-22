#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;

		Node(int d)
		{
			this->data = d;
			next = NULL;
		}

		void appendToTail(int d)
		{
			
			Node *temp;

			temp = this;


			while(temp->next != NULL) {
				temp = temp->next;
			}

			temp->next = new Node(d);
		}

};

Node* deleteNode(Node *head, int d)
{
	if(head->data == d) {
		return head->next;
	}
			
	Node *temp = head;

	while(temp->next != NULL) {
		if(temp->next->data == d) {
			temp->next = temp->next->next;
			return head;
		}
		temp = temp->next;

	}

	return head;

}


int display(Node * head)
{
	Node * temp = head;

	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

int main()
{

	int n;
	int x;

	Node * head;
	head = NULL;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if(head == NULL) {
			head = new Node(x);
		}

		else {
			head->appendToTail(x);
		}

	}

	display(head);

	head = deleteNode(head, 4);
	head = deleteNode(head, 5);
	head = deleteNode(head, 2);
	head = deleteNode(head, 5);
	
	display(head);

}
		





