//You are given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.
//
//Input Format
//First line contains integer t as number of test cases. Next t lines contains two lines. For each test case, 1st line contains two integers n and m which represents the number of books and students and 2nd line contains n space separated integers which represents the number of pages of n books in ascending order.
//
//Constraints
//1 < t < 50
//1< n < 100
//1< m <= 50
//1 <= Ai <= 1000
//
//Output Format
//Print the maximum number of pages that can be assigned to students.
//
//Sample Input
//1
//4 2
//12 34 67 90
//Sample Output
//113 
//Explanation
//1st students : 12 , 34, 67 (total = 113)
//2nd students : 90 (total = 90)
//Print max(113, 90)




#include<iostream>
using namespace std;
long long int Max_page(long long int A[],long long int N,long long int M)
{
	long long int S,i,mid,E=0,C,X,ans;
	S=A[N-1];
	for(i=0;i<N;i++)
    E=E+A[i];
	ans=0;
	while(S<=E)
	{
		mid=(S+E)/2;
		C=1;
		X=0;
		for(i=0;i<N;i++)
		{
			X+=A[i];
			if(X>mid)
			{
				X=A[i];
				++C; 
			}
			if(C>M)
			{
				S=mid+1;
				break;
			}
		}
		if(C<=M)
		{
			// if(C==M)
			ans=mid;
            E=mid-1;
		}
	}
	return ans;
}
int main() {
	long long int T,N,M,i;
	cin>>T;
	while(T--)
	{
		cin>>N>>M;
		long long int A[N];
		for(i=0;i<N;i++)
		cin>>A[i];
		cout<<Max_page(A,N,M)<<endl;
	}
	return 0;
}