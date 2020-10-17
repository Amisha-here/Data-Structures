#include <bits/stdc++.h>

using namespace std;
  
bool isSubsetSum(int set[], int n, int sum) 
{ 
    bool subset[n + 1][sum + 1]; 
  
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
   
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 

    return subset[n][sum]; 
} 
  
int main() 
{ 
    int n, sum;
    cout << "Enter the number of item" << endl;
    cin >> n;
    int set[n];
    cout << "Enter values" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    cout << "Enter sum";
    cin >> sum;
   
    if (isSubsetSum(set, n, sum) == true) 
        printf("There exist a subset with given sum"); 
    else
        printf("No subset exist with given sum"); 
    return 0; 
} 