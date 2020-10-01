#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;


	void bubblesort(int *arr, int n){
		int lv = 0;
		int jc = 0;
		while(jc < n-1){
			lv=0;
			while((lv + jc) <= n-2){
				if(arr[lv] > arr[lv+1]){
					int c = arr[lv];
					arr[lv] = arr[lv+1];
					arr[lv+1] = c;
				}
				lv++;
			}
			jc++;
		}
	}

int main(){

	int n = 10000;
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i] = rand();
	}
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	bubblesort(arr, n);
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}


}
