// Given an integer array nums, return the length of the longest strictly increasing subsequence.
// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



#include<iostream>
#include<climits>
#include<vector>
using namespace std;

// bottom up approach
int lis(vector<int>arr){
    int n = arr.size();
    vector<int>dp(n,1);
    int len = 1;
    for(int i = 1; i<n; i++){
        for(int j = 0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], 1+dp[j]);
                len = max(len,dp[i]);
            }
        }
    }
    return len;
}
int main(){
   int n;
   cin>>n;
   vector<int>arrr(n);
   for(int i=0;i<n;i++){
       cin>>arrr[i];
   }
   cout<<lis(arrr)<<endl;
    return 0;
}
