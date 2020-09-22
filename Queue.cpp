#include <iostream>
using namespace std;
#define SIZE 5
class queue {

	private:
	int front;
	int back;
	int a[SIZE];
	
	public:

	queue() {
		front = -1;
		back = -1;
	}


	bool isEmpty()
	{
		if(front == -1) {
			return true;
		}

		else {
			return false;
		}
	}

	int pop()
	{
		
		if(isEmpty()) {
			cout << "empty\n";
			return -1;
		}

		else {
			cout << "Poped"<<endl;

			if(front == back) {
				front = back = -1;

			}

			else {
				front = (front + 1) % SIZE;
			}
		}
	}

	int push(int x) 
	{	
		cout << "Pushed " << x << endl;
		if((back + 1) % SIZE == front) {
			cout << "full \n";
			return -1;
		}

		else {
			if(back == -1) {
				back = 0;
				front = 0;
			}

			else {
				back = (back + 1) % SIZE;
			}
			a[back] = x;

		}

	}

	int getFront()
	{	
		if(front == -1) {
			cout << "empty\n";
			return -1;
		}
		return a[front];
	}

	int getBack()
	{
		if(back != -1) {
			return a[back];
		}
		cout << "empty\n";

	}

	int traverse()
	{

		if(isEmpty()) {
			return -1;
		}
		
		for (int i = front; 1 ; i = ((i+1) % SIZE)) {
			cout << a[i]<< " ";

			if(i == back) {
				cout << endl;
				return 0;
			}

		}

		


 	}
};

int main()
{

	queue q;
	
	q.push(4);
	q.traverse();
	q.push(SIZE);
	q.traverse();
	q.push(6);
	q.pop();
	cout << q.getFront() << endl;
	cout << q.getBack() << endl;
	
	
	

	

}
