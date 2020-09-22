#include<iostream>
using namespace std;

/* Linked list structure */
struct list {
	struct list *prev;
	int data;
	struct list *next;
} *node = NULL, *first = NULL, *last = NULL, *node1 = NULL, *node2 = NULL;

class linkedlist {
	public: 

		/* Function for create/insert node at the beginning of Linked list */
		void insert_beginning() {
			list *addBeg = new list;
			cout << "Enter value for the node:" << endl;
			cin >> addBeg->data;
			if(first == NULL) {
				addBeg->prev = NULL;
				addBeg->next = NULL;
				first = addBeg;
				last = addBeg;
				cout << "Linked list Created!" << endl;
			}
			else {
				addBeg->prev = NULL;
				first->prev = addBeg;
				addBeg->next = first;
				first = addBeg;
				cout << "Data Inserted at the beginning of the Linked list!" << endl;
			}
		}

		/* Function for create/insert node at the end of Linked list */
		void insert_end() {
			list *addEnd = new list;
			cout << "Enter value for the node:" << endl;
			cin >> addEnd->data;
			if(first == NULL) {
				addEnd->prev = NULL;
				addEnd->next = NULL;
				first = addEnd;
				last = addEnd;
				cout << "Linked list Created!" << endl;
			}
			else {
				addEnd->next = NULL;
				last->next = addEnd;
				addEnd->prev = last;
				last = addEnd;
				cout << "Data Inserted at the end of the Linked list!" << endl;
			}
		}

		/* Function for Display Linked list */
		void display() {
			node = first;
			cout << "List of data in Linked list in Ascending order!" << endl;
			while(node != NULL) {
				cout << node->data << endl;
				node = node->next;
			}
			node = last;
			cout << "List of data in Linked list in Descending order!" << endl;
			while(node != NULL) {
				cout << node->data << endl;
				node = node->prev;
			}
		}
	
		/* Function for delete node from Linked list */
		void del() {
			int count = 0, number, i;
			node = node1 = node2 = first;
			for(node = first; node != NULL; node = node->next)
				cout << "Enter value for the node:" << endl;
			count++;
			display();
			cout << count << " nodes available here!" << endl;
			cout << "Enter the node number which you want to delete:" << endl;
			cin >> number;
			if(number != 1) {
				if(number < count && number > 0) {
					for(i = 2; i <= number; i++)
						node = node->next;
					for(i = 2; i <= number-1; i++)
						node1 = node1->next;
					for(i = 2; i <= number+1; i++)
						node2 = node2->next;
					node2->prev = node1;
					node1->next = node2;
					node->prev = NULL;
					node->next = NULL;
					node = NULL;
				}
				else if(number == count) {
					node = last;
					last = node->prev;
					last->next = NULL;
					node = NULL;
				}
				else
					cout << "Invalid node number!" << endl;
			}
			else {
				node = first;
				first = node->next;
				first->prev = NULL;
				node = NULL;
			}
			cout << "Node has been deleted successfully!" << endl;
		}
	
};

int main() {
	int op = 0;
	linkedlist llist = linkedlist();
	while(op != 4) {
		cout << "1. Insert at the beginning\n2. Insert at the end\n3. Delete\n4. Display\n5. Exit" << endl;
		cout << "Enter your choice:" << endl;
		cin >> op;
		switch(op) {
			case 1:
				llist.insert_beginning();
				break;
			case 2:
				llist.insert_end();
				break;
			case 3:
				llist.del();
				break;
			case 4:
				llist.display();
				break;
			case 5:
				cout << "Bye Bye!" << endl;
				return 0;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
	}
	return 0;
}
