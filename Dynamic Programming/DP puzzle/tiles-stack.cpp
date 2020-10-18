#include <bits/stdc++.h> 

using namespace std;

#define N 100 
  
int possibleWays(int n, int m, int k) 
{ 
    int dp[N][N]; 
    int presum[N][N]; 
    memset(dp, 0, sizeof dp); 
    memset(presum, 0, sizeof presum); 
  
    for (int i = 1; i < n + 1; i++) { 
        dp[0][i] = 0; 
        presum[0][i] = 1; 
    } 
  
    for (int i = 0; i < m + 1; i++) 
        presum[i][0] = dp[i][0] = 1; 
  
    for (int i = 1; i < m + 1; i++) { 
  
        for (int j = 1; j < n + 1; j++) { 
  
            dp[i][j] = presum[i - 1][j]; 
            if (j > k) { 
                dp[i][j] -= presum[i - 1][j - k - 1]; 
            } 
        } 
  
        for (int j = 1; j < n + 1; j++) 
            presum[i][j] = dp[i][j] + presum[i][j - 1]; 
    } 
  
    return dp[m][n]; 
} 
  
int main() 
{ 
    
    int n, m, k;
    cin >> n >> m >> k;

    cout << possibleWays(n, m, k) << endl; 
    return 0; 
} 