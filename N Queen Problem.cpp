#include<iostream>
using namespace std;
#define N 6

void Print(int matrix[N][N]) 
{ 
    for (int i = 0; i <N; i++) 
    { 
        for (int j = 0; j <N; j++)
        {
           cout<<" "<<matrix[i][j]<<" ";
        }
        cout<<endl;
    } 
} 
bool queen(int matrix[N][N], int r, int c) 
{ 
    int i, j; 
    for (i = 0; i < c; i++) 
    {
        if (matrix[r][i]) 
        {
            return false; 
        }
    }
    for (i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (matrix[i][j]) 
        {
            return false; 
        }
    }
    for (i = r, j = c; j >= 0 && i <N; i++, j--) 
    {
        if (matrix[i][j]) 
        {
            return false;
        }
    }
    return true; 
} 
bool solve(int matrix[N][N], int c) 
{ 
    if (c>=N) 
    {
        return true;
    }
    for (int i = 0; i <N; i++) 
    { 
        if (queen(matrix, i, c)) 
        { 
            matrix[i][c] = 1; 
            if (solve(matrix, c + 1))
            {
                return true; 
            }
            matrix[i][c] = 0;
        } 
    } 
    return false; 
} 
int main() 
{ 
    int matrix[N][N] = { { 0, 0, 0, 0, 0 }, 
                         { 0, 0, 0, 0, 0 }, 
                         { 0, 0, 0, 0, 0 }, 
                         { 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0 },
                         { 0, 0, 0, 0, 0 } }; 
  
    if (solve(matrix, 0) == false) 
    { 
        cout<<"Solution does not exist"; 
        return 0;
    } 
    Print(matrix); 
    return 0; 
} 
