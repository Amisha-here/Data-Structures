#include<iostream>
#include<queue>
#include<set>
#include<iterator>
using namespace std;
int main()
{
	long long int T,Z,N,M,i,X;
	cin>>T;
	Z=T;
	while(T--)
	{
		multiset<pair<long long int,long long int> > E;
		cin>>N>>M;
		multiset<pair<long long int,long long int> > :: iterator itr; 
		long long int A[N];
		for(i=0;i<N;i++)
		{
			cin>>A[i];
            X=A[i]/M;
            if(A[i]%M==0)
            X--;
			E.insert(make_pair(X+1,i+1));
		}
		cout<<"Case #"<<Z-T<<": ";
		for (itr = E.begin(); itr != E.end(); ++itr) 
        { 
        pair<long long int,long long int> P=*itr;
        cout <<P.second<<" "; 
        }
		cout<<endl;
    }   
}