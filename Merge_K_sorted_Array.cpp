#include<iostream>
#include<queue>
using namespace std;
class Node{
	public:
		int data;
		int I;
		int J;
};
class cmp {
public:
	bool operator()(Node A,Node B) {
		return A.data>B.data;
	}
};
int main()
{ 
	priority_queue<Node,vector<Node>,cmp> Q;
	int i,j,K,N;
    cin>>K>>N;
    int A[K][N];
    for(i=0;i<K;i++)
    {
    	for(j=0;j<N;j++)
    	{
    		cin>>A[i][j];
		}
	}
	for(i=0;i<K;i++)
	{
		Node P;
		P.data=A[i][0];
		P.I=i;
		P.J=0;
		Q.push(P);
	}
	while(!Q.empty())
	{
		Node X=Q.top();
		Q.pop();
		cout<<X.data<<" ";
		if((X.J+1)<N)
		{
			i=X.I;
			j=X.J+1;
		Node E;
		E.data=A[i][j];
		E.I=i;
		E.J=j;
		Q.push(E);
		}
	}
	return 0;
}
