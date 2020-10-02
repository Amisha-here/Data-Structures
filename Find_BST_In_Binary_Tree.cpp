//8
//70 65 50 66 67 68 80 72
//50 65 66 67 68 80 70 72
//if(T==NULL)
//	return 0;
//	if(T->data<Min || T->data>Max)
//    {
//	M=max(M,Find(T,INT_MAX));
//    return 0;
//    }
//	if(T->rChild==NULL && T->lChild==NULL)
//    return 1;
//	long long int X=Find(T->lChild,T->data);
//	long long int Y=Find(T->rChild,Max); 
//	if(X!=0  && Y!=0)
//	{
//		if(T->lChild->data<T->data  &&  T->rChild->data>T->data)
//		{
//			M=max(M,X+Y+1);
//			return max(X,Y)+1;
//		}
//		else if(T->lChild->data<T->data)
//		{
//			M=max(M,X+1);
//			return X+1;
//		}
//		else if(T->rChild->data>T->data)
//		{
//			M=max(M,Y+1);
//			return Y+1;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//	else if(X==0  &&  Y!=0)
//	{
//		if(T->rChild->data>T->data)
//		{
//			M=max(M,Y+1);
//			return Y+1;
//		}
//		return 1;
//	}
//	else if(X!=0  && Y==0)
//	{
//		if(T->lChild->data<T->data)
//		{
//			M=max(M,X+1);
//			return X+1;
//		}
//		return 1;
//	}
//	else
//	{
//		return 1;
//	}
#include<iostream>
#include<queue>
#include<stack>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
class Node{
	public:
		long long int data;
		Node *lChild,*rChild;		
}*Root=NULL;
long long int M=0;
Node* CreateNode(long long int Val)
{
	Node *A=new Node;
	A->data=Val;
	A->lChild=A->rChild=NULL;
	return A;
}
Node * Create(long long int A[],long long int B[],long long int S,long long int E)
{
	static long long int i=0;
	long long int j,Mid;
	if(S>=E)
	return NULL;
	long long int X=A[i];
	Node *T=CreateNode(X);
	for(j=S;j<E;j++)
	{
		if(B[j]==X)
		{
			Mid=j;
		}
	}
	++i;
	T->lChild=Create(A,B,S,Mid);
	T->rChild=Create(A,B,Mid+1,E);
	return T;
}
int isBST(Node *T,int Max,int Min)
{
	if(T==NULL)
	return true;
	if(T->data>Min  &&  T->data<Max)
	{
		bool X=isBST(T->lChild,T->data,Min);
		bool Y=isBST(T->rChild,Max,T->data);
		if(X==true  &&  Y==true)
		return true;
	}
	return false;
}
int size(Node *T)
{
	if(T==NULL)
    return 0;
	return 1+size(T->lChild)+size(T->rChild); 
}
int LargestBST(Node *T)
{
	if(T==NULL)
	return 0;
	if(isBST(T,INT_MAX,INT_MIN))
	{
		return size(T);
	}
	return max(LargestBST(T->lChild),LargestBST(T->rChild));
}
void PreOrder(Node *R)
{
	if(R==NULL)
    return;
    cout<<R->data<<" ";
	PreOrder(R->lChild);
	PreOrder(R->rChild);
}
int main()
{
	long long int N,i;
	cin>>N;
	long long int A[N],B[N];
	for(i=0;i<N;i++)
	{
		cin>>A[i];
	}
	for(i=0;i<N;i++)
	{
		cin>>B[i];
	}
	Root=Create(A,B,0,N);
	cout<<LargestBST(Root);
}
