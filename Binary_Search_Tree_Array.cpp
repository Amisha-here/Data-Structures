#include <iostream>
#include <cstring>

using namespace std;

int n;
int size;
int binary_tree[100];

int create_binary_tree(int x, int i)
{
	if(binary_tree[i] == -1) {
		binary_tree[i] = x;
		return 1;
	}

	if(binary_tree[i] > x) {
		create_binary_tree(x, 2 * i);
	}

	else {
		create_binary_tree(x, (2 * i) + 1);

	}

}

int inorder_traversal(int i)
{
	if(binary_tree[i] == -1) {
		return 0 ;
	}

	inorder_traversal(2 * i);
	cout << binary_tree[i] << endl;
	inorder_traversal(2 * i + 1);
}

	

int main()
{

	int x;
	
	cin >> n;
	memset(binary_tree, -1, sizeof(binary_tree));
	for (int i = 0; i < n; i++) {
		cin >> x;
		create_binary_tree(x, 1);
	}

	inorder_traversal(1);


}



