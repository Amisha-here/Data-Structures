
#include<bits/stdc++.h>
#define ll long long
#define MAX 1000003
#define V vector<int>
#define pii pair<int,int>
#define VP vector< pii >
#define MOD 1000000007
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define all(v) (v).begin(),(v).end()
#define S(x) scanf("%d",&(x))
#define S2(x,y) scanf("%d%d",&(x),&(y))
#define SL(x) scanf("%lld",&(x))
#define SL2(x) scanf("%lld%lld",&(x),&(y))
#define test() ll t;cin>>t;while(t--)
#define P(x) printf("%d\n",(x))
#define FF first
#define SS second

using namespace std;

struct node {
		int data;
		struct node *left;
		struct node *right;
};

struct node *newNode(int data) {
	struct node *treeNode = new node;
	treeNode->data = data;
	treeNode->left = NULL;
	treeNode->right = NULL;
	return treeNode;
}

int heightTree(struct node *root) {
	if(root == NULL) return 0;
	int lDepth = heightTree(root->left);
	int rDepth = heightTree(root->right);

	if(lDepth > rDepth) return lDepth+1;
	else return rDepth+1;
}

void inOrder(struct node *root) {
	if(root == NULL) return;

	inOrder(root->left);
	cout<< root->data;
	inOrder(root->right);
}

void preOrder(struct node *root) {
	if(root == NULL) return;

	cout<<root->data;
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(struct node *root) {
	if(root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data;
}

void printGivenLevel(struct node *root,int i){
	if(root == NULL) return;
	if(i == 1) cout<< root->data;

	printGivenLevel(root->left, i-1);
	printGivenLevel(root->right, i-1);
}

void levelOrder(struct node *root) {
	int h = heightTree(root);

	for(int i=1;i<h;i++) {
		printGivenLevel(root, i);
	}
}

void levelOrderUsingQueue(struct node *root) {
	if(root == NULL) return;
	queue<struct node *> q;
	q.push(root);

	while(!q.empty()) {
	   struct node *temp = q.front();
	   cout<< temp->data<<" ";
	   if(temp->left!=NULL) q.push(temp->left);
	   if(temp->right!=NULL) q.push(temp->right);
	   q.pop();
	}
}



int main(){

			/* 
		           1 
		       /       \ 
		      2          3 
		    /   \        
		   4     5    
		        /
		       6 
		*/

	// struct node *root = newNode(1);
	// root->left = newNode(2);
	// root->right = newNode(3);
	// root->left->left = newNode(4);
	// root->left->right = newNode(6);
	// root->right->right = newNode(5);

	struct node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(6);


	cout<< "In-order: ";
	inOrder(root);
	cout<<endl;

	cout<< "Pre-order: ";
	preOrder(root);
	cout<<endl;

	cout<< "Post-order: ";
	postOrder(root);
	cout<<endl;

	cout<< "Level-Order (BFS): In O(n^2) ";
	levelOrder(root);
	cout<<endl;

	cout<< "Level-Order (BFS): Using queue in O(n) ";
	levelOrder(root);
	cout<<endl;

	

return 0;
}

/*
Code by : 
Rishabh Patel
Integrated Post Graduation (IPG)
Indian Institute of Information Technology and Management, Gwalior (ABV-IIITM Gwalior)
In order to understand recursion, one must first understand recursion. 
*/
