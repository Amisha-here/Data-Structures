#include <bits/stdc++.h> 
using namespace std; 
  
int knapSackRec(int W, int wt[], int val[], 
                int i, int** dp) 
{ 
    if (i < 0) 
        return 0; 
    if (dp[i][W] != -1) 
        return dp[i][W]; 
  
    if (wt[i] > W) { 
  
        dp[i][W] = knapSackRec( W, wt, val, i - 1, dp); 
        return dp[i][W]; 
    } 
    else { 
   
        dp[i][W] = max( 
            val[i] + knapSackRec( 
                         W - wt[i], wt, val, i - 1, dp), 
            knapSackRec(W, wt, val, i - 1, dp)); 
  
        return dp[i][W]; 
    } 
} 
  
int knapSack(int W, int wt[], int val[], int n) 
{ 
     
    int** dp; 
    dp = new int*[n]; 
  
    for (int i = 0; i < n; i++) 
        dp[i] = new int[W + 1]; 
   
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < W + 1; j++) 
            dp[i][j] = -1; 
    return knapSackRec(W, wt, val, n - 1, dp); 
} 
  
int main() 
{ 
    int n;
    cout << "Enter the number of values you want to enter" << endl;
    cin >> n;
    int val[n], wt[n];
    cout << "Enter values and their weights" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i] >> wt[i];
    }
    int W;
    cout << "Enter total weight" << endl;
    cin >> W; 
    cout << knapSack(W, wt, val, n); 
    return 0; 
} 