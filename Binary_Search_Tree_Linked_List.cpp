#include <iostream>
using namespace std;


template <class type>
class node
{
	public:
		node * left;
		node * right;
		type key;

		
		node()
		{
			right = NULL;
			left = NULL;
		}

		node(type val)
		{
			key = val;
			right = NULL;
			left = NULL;
		}
		
		int print(type key)
		{
			cout << key << endl;
		}

		int traverse()
		{
			if(this == NULL) {
				return 0;
			}

			left->traverse();
			print(key);
			right->traverse();


		}

};



template <class type>
node <type> * createNode(node <type> * current, type key)
{
	if(current == NULL) {
		current = new node <type> (key);
		return current;
	}

	if(current->key > key) {
		current->left = createNode(current->left, key);
	}

	else {
		current->right = createNode(current->right, key);
	}

	return current;


}

int main()
{
	node <int> * tree  = NULL;
	int n = 5;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		tree = createNode(tree, x);
	}

	tree->traverse();
}

