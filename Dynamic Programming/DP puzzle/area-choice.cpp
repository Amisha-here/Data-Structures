#include <bits/stdc++.h> 
using namespace std; 
  
struct area 
{ 
    int a, b; 
    area(int a, int b) : a(a), b(b) 
    {} 
}; 
  
int max(int a, int b, int c) 
{ 
    return max(a, max(b, c)); 
} 
  
int maxSurvival(int A, int B, area X, area Y, area Z, 
                int last, map<pair<int, int>, int>& memo) 
{ 
    if (A <= 0 || B <= 0) 
        return 0; 
    pair<int, int> cur = make_pair(A, B); 
  
    if (memo.find(cur) != memo.end()) 
        return memo[cur]; 
  
    int temp; 
  
    switch(last) 
    { 
    case 1: 
        temp = 1 + max(maxSurvival(A + Y.a, B + Y.b, 
                                   X, Y, Z, 2, memo), 
                       maxSurvival(A + Z.a, B + Z.b, 
                                  X, Y, Z, 3, memo)); 
        break; 
    case 2: 
        temp = 1 + max(maxSurvival(A + X.a, B + X.b, 
                                  X, Y, Z, 1, memo), 
                       maxSurvival(A + Z.a, B + Z.b, 
                                  X, Y, Z, 3, memo)); 
        break; 
    case 3: 
        temp = 1 + max(maxSurvival(A + X.a, B + X.b, 
                                  X, Y, Z, 1, memo), 
                       maxSurvival(A + Y.a, B + Y.b, 
                                  X, Y, Z, 2, memo)); 
        break; 
    } 
  
    memo[cur] = temp; 
  
    return temp; 
} 
  
int getMaxSurvivalTime(int A, int B, area X, area Y, area Z) 
{ 
    if (A <= 0 || B <= 0) 
        return 0; 
    map< pair<int, int>, int > memo; 
  
    return
        max(maxSurvival(A + X.a, B + X.b, X, Y, Z, 1, memo), 
            maxSurvival(A + Y.a, B + Y.b, X, Y, Z, 2, memo), 
            maxSurvival(A + Z.a, B + Z.b, X, Y, Z, 3, memo)); 
} 
  
int main() 
{ 
    
    area X(3, 2); 
    area Y(-5, -10); 
    area Z(-20, 5); 
  
    int A = 21; 
    int B = 9; 
    cout << getMaxSurvivalTime(A, B, X, Y, Z); 
  
    return 0; 
} 