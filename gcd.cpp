#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if(a==0)
		return b;
	else
		return gcd(b%a,a);
}

int main()
{
	int x,y;
	cin>>x>>y;
	cout<<gcd(x,y)<<"\n";
	return 0;
}
