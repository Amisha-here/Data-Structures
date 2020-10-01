/*
Code by Urjita Sharma
Given an integer array nums, 
find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.
*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
        
     int n=nums.size();
     int dp[n];// sum of contiguous subarray .
     int sum=nums[0]; // max sum.
     dp[0]=nums[0];
               
     for(int i=1;i<n;i++){    
        dp[i]=max(nums[i],nums[i]+dp[i-1]);
        sum=max(sum,dp[i]);
    }
      
    return sum;
}

int main() {
cout<<"Enter length of array "<<endl;
int n; cin>>n;

vector<int> arr(n,0);
cout<<"Enter numbers in array "<<endl;
for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr[i]=x;
}
cout<<"Maximum sum of subarray is - "<<maxSubArray(arr)<<endl;

}
