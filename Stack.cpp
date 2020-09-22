#include <iostream>
#define SIZE 10000
using namespace std;

template <class type>
class stack
{
	private:
		int top;
		type a[SIZE];

	public:
		type pop()
		{
			if(isEmpty()) {
				cout << "Stack empty\n";
				return -1;
			}

			return a[top];
			top--;
		}

		type push(type x)
		{
			if(isFull()) {
				cout << "Stack is full\n";
				return -1;
			}

			else {
				top++;
				a[top] = x;
				return a[top];
			}
		}

		bool isFull()
		{
			return top == SIZE - 1;
		}

		bool isEmpty()
		{
			return top == -1;
		}

		type getTopElement()
		{
			if(isEmpty()) {
				return -1;
			}

			else {
				return a[top];
			}
		}




};



int main()
{
	stack <int> s;
	s.push(5);
	s.push(55);
	s.push(555);

	cout << s.getTopElement()<< endl;

}