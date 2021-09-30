#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	int search;
	cin>>search;

	int i=0, j = m-1;
	while(i>=0 and j>=0 and i<n and j<m){
		if(arr[i][j]==search){
			cout<< search <<" found at "<< i << ","<< j;
			return 0;
		}
		if(arr[i][j]<search){
			i+=1;
			

		}
		else
			j-=1;
	}
	cout<< -1;





	return 0;
}